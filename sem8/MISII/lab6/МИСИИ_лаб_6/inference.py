# inference.py
# ------------
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


import itertools
import random
import util
import busters
import game
from numpy import prod

from util import manhattanDistance, raiseNotDefined


class DiscreteDistribution(dict):
    """
    Класс для работы с распределением, 
    представляемым в виде словаря c 
    набором значений ключей и соответсвующих вероятностей
    """

    def __getitem__(self, key):
        self.setdefault(key, 0)
        return dict.__getitem__(self, key)

    def copy(self):
        """
        Возвращает копию распределения
        """
        return DiscreteDistribution(dict.copy(self))

    def argMax(self):
        """
        Возвращает ключ с наибольшим значением
        """
        if len(self.keys()) == 0:
            return None
        all = list(self.items())
        values = [x[1] for x in all]
        maxIndex = values.index(max(values))
        return all[maxIndex][0]

    def total(self):
        """
        Возвращает сумму всех значений вероятностей
        """
        return float(sum(self.values()))

    def normalize(self):
        """
        Нормализуйте распределение таким образом, чтобы суммарное значение
        всех вероятностей ключей равнялось 1. Сотношение значений для всех
        ключей должно остаться прежним. В случае, когда суммарное значение 
        равно 0, ничего не делайте.

        Тесты:

        >>> dist = DiscreteDistribution()
        >>> dist['a'] = 1
        >>> dist['b'] = 2
        >>> dist['c'] = 2
        >>> dist['d'] = 0
        >>> dist.normalize()
        >>> list(sorted(dist.items()))
        [('a', 0.2), ('b', 0.4), ('c', 0.4), ('d', 0.0)]
        >>> dist['e'] = 4
        >>> list(sorted(dist.items()))
        [('a', 0.2), ('b', 0.4), ('c', 0.4), ('d', 0.0), ('e', 4)]
        >>> empty = DiscreteDistribution()
        >>> empty.normalize()
        >>> empty
        {}
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        total = float(self.total())
        if total != 0:
            for key in self.keys():
                self[key] = self[key] / total

    def sample(self):
        """
        Формирует случайную выборку по распределению, представляемому
        в виде словаря, и возвращает ключ,
        соответствующий  случайной выборке.

        Тесты:

        >>> dist = DiscreteDistribution()
        >>> dist['a'] = 1
        >>> dist['b'] = 2
        >>> dist['c'] = 2
        >>> dist['d'] = 0
        >>> N = 100000.0 
        >>> samples = [dist.sample() for _ in range(int(N))]
        >>> round(samples.count('a') * 1.0/N, 1)  # proportion of 'a'
        0.2
        >>> round(samples.count('b') * 1.0/N, 1)
        0.4
        >>> round(samples.count('c') * 1.0/N, 1)
        0.4
        >>> round(samples.count('d') * 1.0/N, 1)
        0.0
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        items = sorted(self.items())

        distribution = [i[1] for i in items]

        item_values = [i[0] for i in items]
        random_choice = random.random()

        i, total = 0, distribution[0]
        if self.total() != 1:
            self.normalize()

        while random_choice > total:
            i += 1
            total += distribution[i]

        return item_values[i]


class InferenceModule:
    """
    Модуль вывода, отслеживающий распределенние степеней доверия 
    локаций призраков
    """
    ############################################
    # Полезные методы для всех модулей вывода  #
    ############################################

    def __init__(self, ghostAgent):
        """
        Определяет агента-призрака 
        """
        self.ghostAgent = ghostAgent
        self.index = ghostAgent.index
        self.obs = []  # most recent observation position

    def getJailPosition(self):
        return (2 * self.ghostAgent.index - 1, 1)

    def getPositionDistributionHelper(self, gameState, pos, index, agent):
        try:
            jail = self.getJailPosition()
            gameState = self.setGhostPosition(gameState, pos, index + 1)
        except TypeError:
            jail = self.getJailPosition(index)
            gameState = self.setGhostPositions(gameState, pos)
        pacmanPosition = gameState.getPacmanPosition()
        ghostPosition = gameState.getGhostPosition(
            index + 1)  # The position you set
        dist = DiscreteDistribution()
        if pacmanPosition == ghostPosition:  # The ghost has been caught!
            dist[jail] = 1.0
            return dist
        pacmanSuccessorStates = game.Actions.getLegalNeighbors(pacmanPosition,
                                                               gameState.getWalls())  # Positions Pacman can move to
        if ghostPosition in pacmanSuccessorStates:  # Ghost could get caught
            mult = 1.0 / float(len(pacmanSuccessorStates))
            dist[jail] = mult
        else:
            mult = 0.0
        actionDist = agent.getDistribution(gameState)
        for action, prob in actionDist.items():
            successorPosition = game.Actions.getSuccessor(
                ghostPosition, action)
            if successorPosition in pacmanSuccessorStates:  # Ghost could get caught
                denom = float(len(actionDist))
                dist[jail] += prob * (1.0 / denom) * (1.0 - mult)
                dist[successorPosition] = prob * \
                    ((denom - 1.0) / denom) * (1.0 - mult)
            else:
                dist[successorPosition] = prob * (1.0 - mult)
        return dist

    def getPositionDistribution(self, gameState, pos, index=None, agent=None):
        """
        Return a distribution over successor positions of the ghost from the
        given gameState. You must first place the ghost in the gameState, using
        setGhostPosition below.
        """
        if index == None:
            index = self.index - 1
        if agent == None:
            agent = self.ghostAgent
        return self.getPositionDistributionHelper(gameState, pos, index, agent)

    def getObservationProb(self, noisyDistance, pacmanPosition, ghostPosition, jailPosition):
        """
        Возвращает вероятность P(noisyDistance | pacmanPosition, ghostPosition).
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        if ghostPosition == jailPosition:
            if noisyDistance == None:
                return 1.0
            else:
                return 0.0

        if noisyDistance == None:
            return 0.0

        return busters.getObservationProbability(noisyDistance, manhattanDistance(pacmanPosition, ghostPosition))

    def setGhostPosition(self, gameState, ghostPosition, index):
        """
        Set the position of the ghost for this inference module to the specified
        position in the supplied gameState.

        Note that calling setGhostPosition does not change the position of the
        ghost in the GameState object used for tracking the true progression of
        the game.  The code in inference.py only ever receives a deep copy of
        the GameState object which is responsible for maintaining game state,
        not a reference to the original object.  Note also that the ghost
        distance observations are stored at the time the GameState object is
        created, so changing the position of the ghost will not affect the
        functioning of observe.
        """
        conf = game.Configuration(ghostPosition, game.Directions.STOP)
        gameState.data.agentStates[index] = game.AgentState(conf, False)
        return gameState

    def setGhostPositions(self, gameState, ghostPositions):
        """
        Sets the position of all ghosts to the values in ghostPositions.
        """
        for index, pos in enumerate(ghostPositions):
            conf = game.Configuration(pos, game.Directions.STOP)
            gameState.data.agentStates[index +
                                       1] = game.AgentState(conf, False)
        return gameState

    def observe(self, gameState):
        """
        Collect the relevant noisy distance observation and pass it along.
        """
        distances = gameState.getNoisyGhostDistances()
        if len(distances) >= self.index:  # Check for missing observations
            obs = distances[self.index - 1]
            self.obs = obs
            self.observeUpdate(obs, gameState)

    def initialize(self, gameState):
        """
        Initialize beliefs to a uniform distribution over all legal positions.
        """
        self.legalPositions = [
            p for p in gameState.getWalls().asList(False) if p[1] > 1]
        self.allPositions = self.legalPositions + [self.getJailPosition()]
        self.initializeUniformly(gameState)

    ########################################
    # Методы, которые нужно переопределить #
    ########################################

    def initializeUniformly(self, gameState):
        """
        Set the belief state to a uniform prior belief over all positions.
        """
        raise NotImplementedError

    def observeUpdate(self, observation, gameState):
        """
        Update beliefs based on the given distance observation and gameState.
        """
        raise NotImplementedError

    def elapseTime(self, gameState):
        """
        Predict beliefs for the next time step from a gameState.
        """
        raise NotImplementedError

    def getBeliefDistribution(self):
        """
        Return the agent's current belief state, a distribution over ghost
        locations conditioned on all evidence so far.
        """
        raise NotImplementedError


class ExactInference(InferenceModule):
    """
    Модуль точного динамического вывода должен использовать
    прямой алгоритм обновления для вычисления точной степени доверия 
    на каждом временном шаге
    """

    def initializeUniformly(self, gameState):
        """
        Начинаем с равномерного распределения всех допустимых
        позиций призрака (т.е. позиция тюрьмы не включается)
        """
        self.beliefs = DiscreteDistribution()
        for p in self.legalPositions:
            self.beliefs[p] = 1.0
        self.beliefs.normalize()

    def observeUpdate(self, observation, gameState):
        """
        Обновляет степени уверенности агента в отношении позиций призраков
        на основе наблюдания observation и позиции Пакмана.
        observation – это зашумленное манхеттенское расстояние до
        отслеживаемого призрака.

        self.allPositions  - список возможных позиций призрака, включающий 
        позицию тюрьмы. Вам необходимо рассматривать только те позиции, 
        которые есть в self.allPositions.

        Модель обновления не является полностью стационарной: она может 
        зависисеть от текущей позиции Пакмана. Это не проблема, если текущая
        позиция Пакмана известна
        """

        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        pacmanPosition = gameState.getPacmanPosition()
        jailPosition = self.getJailPosition()
        positions = self.allPositions
        noisyDistance = observation

        for possibleGhostPos in positions:
            self.beliefs[possibleGhostPos] = self.getObservationProb(
                noisyDistance, pacmanPosition, possibleGhostPos, jailPosition)*self.beliefs[possibleGhostPos]
            self.beliefs.normalize()

        self.beliefs.normalize()

    def elapseTime(self, gameState):
        """
        Предсказывает степени уверенности агента в отношении позиций призраков
        в ответ на один шаг призрака, совершаемый из текущего состояния

        Модель перехода не обязательно стационарна: она может зависеть
        от текущей позиции Пакмана. Однако, это не проблема, т.к. 
        позиция Пакмана известна.
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        # определяем возможные позции призрака
        positions = self.allPositions
        # создаем экземпляр распределения
        beliefDict = DiscreteDistribution()

        # выполняем итерации по всем возможным позициям призрака
        for ghostPos in positions:
         # определяем распределение новых позиций призрака
         # по предыдущей позиции ghostPos
            newPosDist = self.getPositionDistribution(gameState, ghostPos)
         # для всех элементов распределения newPosDist
            for newPos, prob in newPosDist.items():
             # обновляем степени доверия возможных новых позиций
                beliefDict[newPos] = beliefDict[newPos] + \
                    self.beliefs[ghostPos]*prob
         # нормализуем распределение
        beliefDict.normalize
        # сохраняем обновленное распределение
        self.beliefs = beliefDict

    def getBeliefDistribution(self):
        return self.beliefs


class ParticleFilter(InferenceModule):
    """
    Фильтр частиц для приближенного отслеживания одного призрака
    """

    def __init__(self, ghostAgent, numParticles=300):
        InferenceModule.__init__(self, ghostAgent)
        self.setNumParticles(numParticles)

    def setNumParticles(self, numParticles):
        self.numParticles = numParticles

    def initializeUniformly(self, gameState):
        """
        Инициализирует список частиц self.particles .Частицы должны быть
        равномерно (не случайно) распределены по допустимым позициям. 
        Использует self.numParticles для хранения числа частиц, 
        а self.legalPositions для хранения допустимых позиций частиц. 
        """
        self.particles = []
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        num = 0
        while num < self.numParticles:
            for p in self.legalPositions:
                if num >= self.numParticles:
                    break
                self.particles.append(p)
                num += 1

    def observeUpdate(self, observation, gameState):
        """
        Обновление списка частиц с учетом весов наблюдений. 
        Наблюдение - это зашумленное манхеттенское расстояние
        до отслеживаемого призрака.
        Имеется специальный случай, который необходимо учесть. Когда все 
        частицы получают нулевой вес, список частиц слудует повторно
        инициализировать, вызвав initializeUniformly.
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        weights = DiscreteDistribution()
        resample = []
        # определяем позиции Пакмана и тюрьмы

        pacmanPosition = gameState.getPacmanPosition()
        jailPosition = self.getJailPosition()
        # для каждой позиции частицы
        for pos in self.particles:
            # определяем степень уверенности наблюдения при заданных
            # pacmanPosition, pos, jailPosition и аккумулируем в виде веса
            weights[pos] += self.getObservationProb(
                observation, pacmanPosition, pos, jailPosition)
            # если частицы получают нулевой вес
        if weights.total() == 0:
            # то инициализаируем повторно список частиц
            self.initializeUniformly(gameState)
        # иначе
        else:
            # нормазизуем распределение весов
            weights.normalize()
            # формируем список частиц путем выборки из распределния весов
            self.particles = [weights.sample()
                              for _ in range(int(self.numParticles))]

    def elapseTime(self, gameState):
        """
        Выполняет выборку следующего состояния каждой частицы на основе
        её текущего состояния и состояния игры
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        elapseDist = DiscreteDistribution()
        sample = self.particles
        for pos in sample:
            newPosDist = self.getPositionDistribution(gameState, pos)
            for newPos, prob in newPosDist.items():
                elapseDist[newPos] += prob
        elapseDist.normalize()
        self.particles = [elapseDist.sample()
                          for _ in range(int(self.numParticles))]

    def getBeliefDistribution(self):
        """
        Метод преобразует список частиц в соответствующее 
        распределение степеней уверенности. Метод должен возвращать 
        нормализованное распределение типа DiscreteDistribution.
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        answer = util.Counter()
        for particle in self.particles:
            answer[particle] += 1
        answer.normalize()
        return answer


class JointParticleFilter(ParticleFilter):
    """

    JointParticleFilter отслеживает совместное распределение 
    всех позиций призраков
    """

    def __init__(self, numParticles=600):
        self.setNumParticles(numParticles)

    def initialize(self, gameState, legalPositions):
        """
        Сохраняет информацию об игре, затем инициализирует частицы
        """
        self.numGhosts = gameState.getNumAgents() - 1
        self.ghostAgents = []
        self.legalPositions = legalPositions
        self.initializeUniformly(gameState)

    def initializeUniformly(self, gameState):
        """
        Инициализирует частицы равномерным априорным распределением.
        Частицы должны быть равномерно распредены по позициям, чтобы
        гарантировать равномерное априорное распреление.
        """
        self.particles = []
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        permutations = list(itertools.product(
            self.legalPositions, repeat=self.numGhosts))
        random.shuffle(permutations)
        size = self.numParticles
        i = 0
        while i < size:
            for particle in permutations:
                self.particles.append(particle)
                i += 1

    def addGhostAgent(self, agent):
        """
        Each ghost agent is registered separately and stored (in case they are
        different).
        """
        self.ghostAgents.append(agent)

    def getJailPosition(self, i):
        return (2 * i + 1, 1)

    def observe(self, gameState):
        """
        Resample the set of particles using the likelihood of the noisy
        observations.
        """
        observation = gameState.getNoisyGhostDistances()
        self.observeUpdate(observation, gameState)

    def observeUpdate(self, observation, gameState):
        """
        Обновляет степени доверия на основе позцции Пакмана и
        наблюдений расстояний.

        Наблюдения - это зашумленное манхеттенское расстояние до всех 
        отслеживаемых призраков

        Есть особый случай, который необходимо учесть при реализции метода.
        Когда все частицы получают нулевой вес, список частиц должен быть 
        переинициализирован заново путем вызова initializeUniformly. При этом
        могут использоваться общие методы класса DiscreteDistribution 
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

        pacmanPosition = gameState.getPacmanPosition()
        newPD = DiscreteDistribution()

        for ghostPositions in self.particles:

            prob = 1
            for i in range(self.numGhosts):
                prob *= self.getObservationProb(
                    observation[i], pacmanPosition, ghostPositions[i], self.getJailPosition(i))
            newPD[ghostPositions] += prob

        if newPD.total() == 0:
            self.initializeUniformly(gameState)
        else:

            newPD.normalize()

            self.particles = [newPD.sample() for _ in range(self.numParticles)]

    def elapseTime(self, gameState):
        """
        Формирует выборку следующего состояния частицы на основе её текущего
        состояния и состояния игры
        """
        newParticles = []
        for oldParticle in self.particles:
            newParticle = list(oldParticle)  # Список позиций призраков

            # цикл обновления всех частиц
            "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"

            for i in range(self.numGhosts):
                newPosDist = self.getPositionDistribution(
                    gameState, newParticle, i, self.ghostAgents[i])
                newParticle[i] = newPosDist.sample()

            """*** КОНЕЦ ВАШЕГО КОДА ***"""
            newParticles.append(tuple(newParticle))
        self.particles = newParticles


# One JointInference module is shared globally across instances of MarginalInference
jointInference = JointParticleFilter()


class MarginalInference(InferenceModule):
    """
    A wrapper around the JointInference module that returns marginal beliefs
    about ghosts.
    """

    def initializeUniformly(self, gameState):
        """
        Set the belief state to an initial, prior value.
        """
        if self.index == 1:
            jointInference.initialize(gameState, self.legalPositions)
        jointInference.addGhostAgent(self.ghostAgent)

    def observe(self, gameState):
        """
        Update beliefs based on the given distance observation and gameState.
        """
        if self.index == 1:
            jointInference.observe(gameState)

    def elapseTime(self, gameState):
        """
        Predict beliefs for a time step elapsing from a gameState.
        """
        if self.index == 1:
            jointInference.elapseTime(gameState)

    def getBeliefDistribution(self):
        """
        Return the marginal belief over a particular ghost by summing out the
        others.
        """
        jointDistribution = jointInference.getBeliefDistribution()
        dist = DiscreteDistribution()
        for t, prob in jointDistribution.items():
            dist[t[self.index - 1]] += prob
        return dist
