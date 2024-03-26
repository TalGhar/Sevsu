# valueIterationAgents.py
# -----------------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
#
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


# valueIterationAgents.py
# -----------------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
#
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).


import mdp
import util

from learningAgents import ValueEstimationAgent
import collections


class ValueIterationAgent(ValueEstimationAgent):
    """
        * Пожалуйста, прочтите learningAgents.py перед тем, как читать это. *

         ValueIterationAgent принимает марковский процесс принятия решений
         (см. mdp.py) при инициализации и выполняет итерацию по значениям
         для заданного количества итераций с использованием 
         коэффициента дисконтирования.

    """

    def __init__(self, mdp, discount=0.9, iterations=100):
        """
          Ваш агент итераций по значениям должен принимать mdp при
          вызове конструктора, запустите его с указанным количеством итераций,
          а затем действуйте в соответствии с полученной политикой.

           Некоторые полезные методы mdp, которые вы будете использовать:
              mdp.getStates() - возвращает список состояний MDP
              mdp.getPossibleActions(state) - возвращает кортеж возможных действий в состоянии
              mdp.getTransitionStatesAndProbs(state, action)- возвращает список из пар (nextState, prob) - s' и вероятности переходов T(s,a,s')
              mdp.getReward(state, action, nextState) - вовращает награду R(s,a,s')
              mdp.isTerminal(state)- проверяет, является ли состояние терминальным
        """
        self.mdp = mdp
        self.discount = discount
        self.iterations = iterations
        # Counter - словарь ценностей состояний, по умолчанию содержит 0
        self.values = util.Counter()
        self.runValueIteration()

    def runValueIteration(self):
        # Напишите код, реализующий итерации по значениям
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
        states = self.mdp.getStates()

        for i in range(self.iterations):
            temp = util.Counter()

            for state in states:
                best = float("-inf")
                actions = self.mdp.getPossibleActions(state)

                for action in actions:
                    transitions = self.mdp.getTransitionStatesAndProbs(
                        state, action)
                    sum = 0

                    for transition in transitions:
                        reward = self.mdp.getReward(
                            state, action, transition[0])
                        sum += transition[1]*(reward + self.discount *
                                              self.values[transition[0]])

                    best = max(best, sum)

                if best != float("-inf"):
                    temp[state] = best

            for state in states:
                self.values[state] = temp[state]

    def getValue(self, state):
        """
          Возвращает ценность состояния (вычисляется в  __init__).
        """
        return self.values[state]

    def computeQValueFromValues(self, state, action):
        """
          Вычисляет Q-ценность в состоянии по
          значению ценности состояния, сохраненному в self.values.
        """
        transitions = self.mdp.getTransitionStatesAndProbs(state, action)
        sum = 0

        for transition in transitions:
            reward = self.mdp.getReward(state, action, transition[0])
            sum += transition[1]*(reward + self.discount *
                                  self.values[transition[0]])

        return sum

    def computeActionFromValues(self, state):
        """
          Определяет политику - лучшее действие в  состоянии
          в соответствии с ценностями, хранящимися в  self.values.

          Обратите внимание, что если нет никаких допустимых действий,
          как в случае  терминального состояния, необходимо вернуть None.
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        best = float("-inf")
        act = None
        actions = self.mdp.getPossibleActions(state)
        for action in actions:
            q = self.computeQValueFromValues(state, action)
            if q > best:
                best = q
                act = action

        return act

    def getPolicy(self, state):
        return self.computeActionFromValues(state)

    def getAction(self, state):
        "Возвращает политику в состоянии (без исследования)"
        return self.computeActionFromValues(state)

    def getQValue(self, state, action):
        return self.computeQValueFromValues(state, action)


class AsynchronousValueIterationAgent(ValueIterationAgent):
    """
         * Пожалуйста, прочтите learningAgents.py перед тем, как читать это. *

         AsynchronousValueIterationAgent принимает марковский процесс принятия решений
         (см. mdp.py) при инициализации и выполняет итерацию по значениям
         для заданного количества итераций с использованием 
         коэффициента дисконтирования.
    """

    def __init__(self, mdp, discount=0.9, iterations=1000):
        """
          Ваш агент итераций по значениям должен принимать mdp при
          вызове конструктора, запустите его с указанным количеством итераций,
          а затем действуйте в соответствии с полученной политикой.
          Каждая итерация обновляет значение только одного состояния,
          которое циклически выбирается из списка состояний. 
          Если выбранное состояние является конечным, на этой итерации ничего
          не происходит.


          Некоторые полезные методы mdp, которые вы будете использовать:    
              mdp.getStates() - возвращает список состояний MDP
              mdp.getPossibleActions(state) - возвращает кортеж возможных действий в состоянии
              mdp.getTransitionStatesAndProbs(state, action)- возвращает список из пар (nextState, prob) - s' и вероятности переходов T(s,a,s')
              mdp.getReward(state, action, nextState) - вовращает награду R(s,a,s')
              mdp.isTerminal(state)- проверяет, является ли состояние терминальным
        """
        ValueIterationAgent.__init__(self, mdp, discount, iterations)

    def runValueIteration(self):
        # Напишите код, реализующий асинхронные итерации по значениям
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
        states = self.mdp.getStates()
        for i in range(self.iterations):
            v = self.values.copy()
            s0 = states[i % len(states)]
            if self.mdp.isTerminal(s0):
                continue
            v[s0] = -float("inf")
            for a in self.mdp.getPossibleActions(s0):
                val = 0
                for s, p in self.mdp.getTransitionStatesAndProbs(s0, a):
                    val += p * (self.mdp.getReward(s0, a, s) +
                                self.discount * self.values[s])
                v[s0] = max(v[s0], val)
            self.values = v.copy()


class PrioritizedSweepingValueIterationAgent(AsynchronousValueIterationAgent):
    """
        * Пожалуйста, прочтите learningAgents.py перед тем, как читать это. *

        Агент PrioritizedSweepingValueIterationAgent принимает марковский
        процесс принятия решения (см. Mdp.py) при инициализации и выполняет 
        итерации по значениям  с разверткой приоритетных состояний при 
        заданном числе  итераций с использованием предоставленных параметров.
    """

    def __init__(self, mdp, discount=0.9, iterations=100, theta=1e-5):
        """
          Ваш агент итерации по развертке приоритетных значений должен 
          принимать на вход МДП при создании, выполнять заданое количество итераций, 
          а затем действовать в соответствии с полученной политикой.
        """
        self.theta = theta
        ValueIterationAgent.__init__(self, mdp, discount, iterations)

    def runValueIteration(self):
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
        pred = self.generatePredecessors()
        pQ = util.PriorityQueue()
        states = self.mdp.getStates()
        for s in states:
            if self.mdp.isTerminal(s):
                continue
            pQ.push(s, -self.getDiff(s))
        for i in range(self.iterations):
            if pQ.isEmpty():
                break
            v = self.values.copy()
            s0 = pQ.pop()
            v[s0] = -float("inf")
            for a in self.mdp.getPossibleActions(s0):
                val = 0
                for s, p in self.mdp.getTransitionStatesAndProbs(s0, a):
                    val += p * (self.mdp.getReward(s0, a, s) +
                                self.discount * self.values[s])
                v[s0] = max(v[s0], val)
            self.values = v.copy()
            for p in pred[s0]:
                diff = self.getDiff(p)
                if diff > self.theta:
                    pQ.update(p, -diff)

    def getDiff(self, s):
        qV = -float('inf')
        for a in self.mdp.getPossibleActions(s):
            qV = max(qV, self.getQValue(s, a))
        return abs(qV - self.values[s])

    def generatePredecessors(self):
        pred = {}
        for s in self.mdp.getStates():
            for a in self.mdp.getPossibleActions(s):
                for next, p in self.mdp.getTransitionStatesAndProbs(s, a):
                    if p > 0:
                        if next not in pred:
                            pred[next] = {s}
                        else:
                            pred[next].add(s)
        return pred
