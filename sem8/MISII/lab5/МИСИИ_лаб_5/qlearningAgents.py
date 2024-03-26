# qlearningAgents.py
# ------------------
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


from game import *
from learningAgents import ReinforcementAgent
from featureExtractors import *

import random
import util
import math


class QLearningAgent(ReinforcementAgent):
    """
      Агент с Q-обучением

      Функции, которые необходимо дополнить:   
        - computeValueFromQValues
        - computeActionFromQValues
        - getQValue
        - getAction
        - update


      Переменные, к которым у вас есть доступ
        - self.epsilon (вероятность исследования)
        - self.alpha (скорость обучения)
        - self.discount (коэффициент дисконтирования)

       Фукнции, которые Вам следует использовать
        - self.getLegalActions(state)
          возвращает допустимые действия в состоянии state

    """

    def __init__(self, **args):
        "Здесь можно инициализировать Q-ценности"
        ReinforcementAgent.__init__(self, **args)

        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
        self.QValue = util.Counter()

    def getQValue(self, state, action):
        """
          Возвращает Q(state,action)
          Должен вернуть 0.0, если состояние никогда не встречалось
          или  Q-ценность  в ином случае
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        return self.QValue[(state, action)]

    def computeValueFromQValues(self, state):
        """
          Возвращает ценность состояния state
          путем вычиления  max_action Q(state,action)
          где максимум ищется по всем допустимым дейтствиям.
          Если нет допустимых действий,
          что имеет место в терминальных состояних,
          метод должен вернуть значение 0.0

        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        best = float("-inf")

        actions = self.getLegalActions(state)
        for action in actions:
            if best < self.getQValue(state, action):
                best = self.getQValue(state, action)

        if best != float("-inf"):
            return best
        else:
            return 0.0

    def computeActionFromQValues(self, state):
        """
         Вычисляет лучшее действие, которое нужно предпринять в состоянии.
         Обратите внимание, если нет допустимых действий, что имеет место
         в терминальных состояниях, метод должен вернуть None.
        """

        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        best = float("-inf")
        act = []

        actions = self.getLegalActions(state)
        if len(actions) == 0:
            return None

        for action in actions:
            if best < self.getQValue(state, action):
                best = self.getQValue(state, action)
                act = [action]
            elif best == self.getQValue(state, action):
                act.append(action)

        return random.choice(act)

    def getAction(self, state):
        """
          Возвращает действие, которое нужно предпринять в текущем состоянии.
          С вероятностью self.epsilon предпринимается случайное действие
          и в противном случае предпринимается наилучшее  действие.
          Обратите внимание, что если нет никаких допустимых действий,
          что имеет место в терминальном состоянии, вы должны 
          вернуть в качестве действия None.

           ПОДСКАЗКА: вы можете использовать util.flipCoin(prob)
           ПОДСКАЗКА: для случайного выбора из списка используйте random.choice (list) 

        """

        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        legalActions = self.getLegalActions(state)

        if util.flipCoin(self.epsilon):
            return random.choice(legalActions)
        else:
            return self.computeActionFromQValues(state)

    def update(self, state, action, nextState, reward):
        """

          Родительский класс вызывает этот метод, чтобы выполнить
          q-обновление в соответствии с переходом
          state => action => nextState =.reward.
          Вы должны реализовать здесь q-обновление.

          ПРИМЕЧАНИЕ: вы никогда не должны вызывать этот метод 

        """

        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        self.QValue[(state, action)] = (1-self.alpha)*self.QValue[(state, action)] + \
            self.alpha*(reward + self.discount *
                        self.computeValueFromQValues(nextState))

    def getPolicy(self, state):
        return self.computeActionFromQValues(state)

    def getValue(self, state):
        return self.computeValueFromQValues(state)


class PacmanQAgent(QLearningAgent):
    "Exactly the same as QLearningAgent, but with different default parameters"

    def __init__(self, epsilon=0.05, gamma=0.8, alpha=0.2, numTraining=0, **args):
        """
        These default parameters can be changed from the pacman.py command line.
        For example, to change the exploration rate, try:
            python pacman.py -p PacmanQLearningAgent -a epsilon=0.1

        alpha    - learning rate
        epsilon  - exploration rate
        gamma    - discount factor
        numTraining - number of training episodes, i.e. no learning after these many episodes
        """
        args['epsilon'] = epsilon
        args['gamma'] = gamma
        args['alpha'] = alpha
        args['numTraining'] = numTraining
        self.index = 0  # This is always Pacman
        QLearningAgent.__init__(self, **args)

    def getAction(self, state):
        """
        Simply calls the getAction method of QLearningAgent and then
        informs parent of action for Pacman.  Do not change or remove this
        method.
        """
        action = QLearningAgent.getAction(self, state)
        self.doAction(state, action)
        return action


class ApproximateQAgent(PacmanQAgent):
    """
       Агент Q-обучения с аппроксимацией

       Вам нужно только переопределить getQValue
        и update.  Все другие функции QLearningAgent 
       должны работать без изменнения.
       Также, при желании, допишите метод final(self, state),
       чтобы отображать итоговые значения весов признаков и
       такие параметры как: alpha, epsilon, gamma,
       число эпизодов обучения.
    """

    def __init__(self, extractor='IdentityExtractor', **args):
        self.featExtractor = util.lookup(extractor, globals())()
        PacmanQAgent.__init__(self, **args)
        self.weights = util.Counter()

    def getWeights(self):
        return self.weights

    def getQValue(self, state, action):
        """
          Должен возвращать Q(state,action) = w * featureVector
          где * оператор матричного умножения
        """

        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        weights = self.getWeights()
        features = self.featExtractor.getFeatures(state, action)
        q = weights * features
        return q

    def update(self, state, action, nextState, reward):
        """
           Обновляет веса признаков на основе данных переходов (s,a,s',r)
        """

        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        weights = self.getWeights()
        features = self.featExtractor.getFeatures(state, action)

        nextActions = self.getLegalActions(nextState)
        maxNextQ = float("-inf")

        for act in nextActions:
            q = self.getQValue(nextState, act)
            maxNextQ = max(maxNextQ, q)

        if len(nextActions) == 0:
            maxNextQ = 0.0

        difference = reward + self.discount * \
            maxNextQ - self.getQValue(state, action)
        for feature in features:
            weights[feature] = weights[feature] + \
                self.alpha * difference * features[feature]

    def final(self, state):
        "Вызывается в конце игры"

        # вызов метода final супер-класса
        PacmanQAgent.final(self, state)

        # проверяем, завершилось ли обучение?
        if self.episodesSoFar == self.numTraining:
            # здесь, если захотите, вы можете распечатать веса при отладке

            "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

            pass
