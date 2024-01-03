# multiAgents.py
# --------------
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


from util import manhattanDistance
from game import Directions
import random, util

from game import Agent

class ReflexAgent(Agent):
    """
    Рефлекторный агент выбирает действие в каждой точке выбора,
    исследуя альтернативы с помощью функции оценки состояния.

    Приведенный ниже код предоставляется в качестве руководства.
    Вы можете изменить его так, как считаете нужным, при условии,
    что вы не касаетесь заголовков наших методов.
    """

    def getAction(self, gameState):
        """
        Вам не нужно менять этот метод, но вы можете это сделать.

        getAction возвращает одно из лучших действий в соответствии с
        функцией оценки.

        getAction принимает состояние GameState и
        возвращает направления Directions.X для некоторого X из мно-ва
        {NORTH, SOUTH, WEST, EAST, STOP}
       """
        # Получить допустимые действия для состояния
        legalMoves = gameState.getLegalActions()

        # Выбрать одно из лучших действий в состоянии, используя функцию оценки
        scores = [self.evaluationFunction(gameState, action) for action in legalMoves]
        bestScore = max(scores)
        bestIndices = [index for index in range(len(scores)) if scores[index] == bestScore]
        chosenIndex = random.choice(bestIndices) # Случайно выбираем действие среди лучших

        "Добавьте свой код сюда, если хотите"

        return legalMoves[chosenIndex]

    def evaluationFunction(self, currentGameState, action):
        """
        Разработайте здесь более совершенную функцию оценки.
        
        Функция оценки принимает текущее состояние и допустимое действие
        (pacman.py) и возвращает числовое значение функции оценки
        (большим числам отдается предпочтение).

        Приведенный ниже код извлекает некоторую полезную информацию из 
        состояния, такую как оставшаяся еда (newFood) и положение Pacman после
        перемещения (newPos).
        newScaredTimes содержит количество ходов, на которое каждый призрак 
        останется испуганным из-за того, что Пакман съел энерго-гранулу.

        Распечатайте эти переменные, чтобы увидеть и понять их значения, а затем
        комбинируйте их, чтобы создать подходящую функцию оценки.
        
        """
        
        # Полезная информация, которую вы можете извлечь из GameState (pacman.py)
        
        # Формируем дочернее состояниe после действия action
        # пример схемы дочернего состояния для поля testClassic,размером 10x5 :
        #    %%%%%
        #    % . %
        #    %.G.%
        #    % . %
        #    %. .%
        #    %   %
        #    %  .%
        #    %   %
        #    %< .%
        #    %%%%%
        # Здесь G - призрак, < - Пакман, . - еда, % - стены
        successorGameState = currentGameState.generatePacmanSuccessor(action)
        #print("succ:", successorGameState)
        
        # Определяем координаты Пакмана  в виде кортежа (x,y)
        # Для приведенной выше схемы newPos=(1,1)
        newPos = successorGameState.getPacmanPosition()
              
        # Определяем положение точек еды в виде логического массива
        # Для приведенной выше схемы newFood будет равен:
        # FFFFF
        # FFTFF
        # FTFTF
        # FFTFF
        # FTFTF
        # FFFFF
        # FFFTF
        # FFFFF
        # FFFTF
        # FFFFF
        # Здесь Т - есть еда, F - нет еды
        newFood = successorGameState.getFood()
        #print("newFood:", newFood)
        
        # определяем новое состояние для призраков newGhostStates 
        newGhostStates = successorGameState.getGhostStates()
        
        # определяем  время испуга прираков 
        # пример значения для newScaredTimes при 2-х призраках: [40, 40]
        newScaredTimes = [ghostState.scaredTimer for ghostState in newGhostStates]
   
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
        
        currentFood = currentGameState.getFood()
        score = successorGameState.getScore()
        new_ghost_positions = successorGameState.getGhostPositions()
        current_food_list = currentFood.asList()
        new_food_list = newFood.asList()
        closest_food = float('+Inf')
        closest_ghost = float('+Inf')
        add_score = 0

        if newPos in current_food_list:
            add_score += 10.0

        distance_from_food = [manhattanDistance(newPos, food_position) for food_position in new_food_list]
        total_available_food = len(new_food_list)
        if len(distance_from_food):
            closest_food = min(distance_from_food)

        score += 10.0 / closest_food  - 4.0 * total_available_food + add_score

        for ghost_position in new_ghost_positions:
            distance_from_ghost = manhattanDistance(newPos, ghost_position)
            closest_ghost = min([closest_ghost, distance_from_ghost])

        if closest_ghost < 2:
            score -= 50.0

        return score


def scoreEvaluationFunction(currentGameState):
    """
    Это функция оценки по умолчанию, она просто возвращает оценку состояния.
    Эта оценка также отображается в графическом интерфейсе Pacman.

    Эта функция оценки предназначена для использования состязательными агентами.
    (не рефлекторными агентами).
    """
    return currentGameState.getScore()

class MultiAgentSearchAgent(Agent):
    """
     Вам не нужно вносить в этот класс какие-либо изменения,
     но вы можете это сделать, если хотите добавить функциональность
     ко всем вашим состязательным поисковым агентам.
     Однако, пожалуйста, ничего не удаляйте.

     Примечание: это абстрактный класс: не нужно создавать его экземпляры. 
     Он определен лишь частично и предназначен для наследования.
     Agent (game.py) - еще один абстрактный класс.
     Глубина поиска по умолчанию равна 2
     Функция оценки, используемая  по умолчанию - scoreEvaluationFunction
    """

    def __init__(self, evalFn = 'scoreEvaluationFunction', depth = '2'):
        self.index = 0 # Индекс Пакмана всегда равен 0
        self.evaluationFunction = util.lookup(evalFn, globals())
        self.depth = int(depth)

class MinimaxAgent(MultiAgentSearchAgent):
    """
    Ваш минимаксный агент (задание 2)
    """

    def getAction(self, gameState):
        """
        Возвращает минимаксное действие для текущего состояния gameState,
        используя self.depth и self.evaluationFunction.

        Вот несколько вызовов методов, которые могут быть полезны при реализации
        минимаксного агента.

        gameState.getLegalActions (agentIndex):
        Возвращает список допустимых (легальных) действий для агента
        agentIndex=0 соответсвует Пакману, а для призраков agentIndex > = 1

        gameState.generateSuccessor(agentIndex, action):
        Возвращает состояние-преемник после того, как агент совершит действие action.

        gameState.getNumAgents():
        Возвращает общее количество агентов в игре.

        gameState.isWin():
        Возвращает True если состояние игры является выигрышным.

        gameState.isLose ():
        Возвращает True если состояние игры является проигрышным.
        """
        
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
       
        best_action = self.max_value(gameState=gameState, depth=0, agent_idx=0)[1]
        return best_action

    def is_terminal_state(self, gameState, depth, agent_idx):
        
        if gameState.isWin():
            return gameState.isWin()
        elif gameState.isLose():
            return gameState.isLose()
        elif gameState.getLegalActions(agent_idx) is 0:
            return gameState.getLegalActions(agent_idx)
        elif depth >= self.depth * gameState.getNumAgents():
            return self.depth

    def max_value(self, gameState, depth, agent_idx):

        value = (float('-Inf'), None)
        legal_actions = gameState.getLegalActions(agent_idx)
        for action in legal_actions:
            successor_state = gameState.generateSuccessor(agent_idx, action)
            number_of_agents = gameState.getNumAgents()
            expand = depth + 1
            current_player = (depth + 1) % number_of_agents
            value = max([value, (self.value(gameState=successor_state, depth=expand, agent_idx=current_player), action)], key=lambda idx: idx[0])
        return value

    def min_value(self, gameState, depth, agent_idx):

        value = (float('+Inf'), None)
        legal_actions = gameState.getLegalActions(agent_idx)
        for action in legal_actions:
            successor_state = gameState.generateSuccessor(agent_idx, action)
            number_of_agents = gameState.getNumAgents()
            expand = depth + 1
            current_player = (depth + 1) % number_of_agents
            value = min([value, (self.value(gameState=successor_state, depth=expand, agent_idx=current_player), action)], key=lambda idx: idx[0])
        return value

    def value(self, gameState, depth, agent_idx):

        if self.is_terminal_state(gameState=gameState, depth=depth, agent_idx=agent_idx):
            return self.evaluationFunction(gameState)
        elif agent_idx is 0:
            return self.max_value(gameState=gameState, depth=depth, agent_idx=agent_idx)[0]
        else:
            return self.min_value(gameState=gameState, depth=depth, agent_idx=agent_idx)[0]


class AlphaBetaAgent(MultiAgentSearchAgent):
    """
    Ваш минимаксный агент, реализующий альфа-бета отсечение (задание 3)
    """

    def getAction(self, gameState):
        """
        Возвращает минимаксное действие, используя
        self.depth and self.evaluationFunction
        """
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
       
        alpha = float('-Inf')
        beta = float('+Inf')
        depth = 0
        best_action = self.max_value(gameState=gameState, depth=depth, agent_idx=0, alpha=alpha, beta=beta)
        return best_action[1]

    def is_terminal_state(self, gameState, depth, agent_idx):

        if gameState.isWin():
            return gameState.isWin()
        elif gameState.isLose():
            return gameState.isLose()
        elif gameState.getLegalActions(agent_idx) is 0:
            return gameState.getLegalActions(agent_idx)
        elif depth >= self.depth * gameState.getNumAgents():
            return self.depth

    def max_value(self, gameState, depth, agent_idx, alpha, beta):

        value = (float('-Inf'), None)
        legal_actions = gameState.getLegalActions(agent_idx)
        for action in legal_actions:
            successor_state = gameState.generateSuccessor(agent_idx, action)
            number_of_agents = gameState.getNumAgents()
            expand = depth + 1
            current_player = expand % number_of_agents
            value = max([value, (self.value(gameState=successor_state, depth=expand, agent_idx=current_player, alpha=alpha, beta=beta), action)], key=lambda idx: idx[0])
            if value[0] > beta:
                return value
            alpha = max(alpha, value[0])
        return value

    def min_value(self, gameState, depth, agent_idx, alpha, beta):

        value = (float('+Inf'), None)
        legal_actions = gameState.getLegalActions(agent_idx)
        for action in legal_actions:
            successor_state = gameState.generateSuccessor(agent_idx, action)
            number_of_agents = gameState.getNumAgents()
            expand = depth + 1
            current_player = expand % number_of_agents
            value = min([value, (self.value(gameState=successor_state, depth=expand, agent_idx=current_player, alpha=alpha, beta=beta), action)], key=lambda idx: idx[0])
            if value[0] < alpha:
                return value
            beta = min(beta, value[0])
        return value

    def value(self, gameState, depth, agent_idx, alpha, beta):

        if self.is_terminal_state(gameState=gameState, depth=depth, agent_idx=agent_idx):
            return self.evaluationFunction(gameState)
        elif agent_idx is 0:
            return self.max_value(gameState=gameState, depth=depth, agent_idx=agent_idx,alpha=alpha, beta=beta)[0]
        else:
            return self.min_value(gameState=gameState, depth=depth, agent_idx=agent_idx, alpha=alpha, beta=beta)[0]


class ExpectimaxAgent(MultiAgentSearchAgent):
    """
      Ваш expectimax агент (задание 4)
    """

    def getAction(self, gameState):
        """
        Возвращает  действие Пакмана, используя expectimax поиск и
        self.depth и self.evaluationFunction

        Все призраки должны выбирать свои случайные
        допустимые действия с равной вероятностью
        """
        
        "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
      
        best_action = self.max_value(gameState=gameState, depth=0, agent_idx=0)[1]
        return best_action

    def is_terminal_state(self, gameState, depth, agent_idx):

        if gameState.isWin():
            return gameState.isWin()
        elif gameState.isLose():
            return gameState.isLose()
        elif gameState.getLegalActions(agent_idx) is 0:
            return gameState.getLegalActions(agent_idx)
        elif depth >= self.depth * gameState.getNumAgents():
            return self.depth

    def max_value(self, gameState, depth, agent_idx):

        value = (float('-Inf'), None)
        legal_actions = gameState.getLegalActions(agent_idx)
        for action in legal_actions:
            successor_state = gameState.generateSuccessor(agent_idx, action)
            number_of_agents = gameState.getNumAgents()
            expand = depth + 1
            current_player = (depth + 1) % number_of_agents
            value = max([value, (self.value(gameState=successor_state, depth=expand, agent_idx=current_player), action)], key=lambda idx: idx[0])
        return value

    def expected_value(self, gameState, depth, agent_idx):

        value = list()
        legal_actions = gameState.getLegalActions(agent_idx)
        for action in legal_actions:
            successor_state = gameState.generateSuccessor(agent_idx, action)
            number_of_agents = gameState.getNumAgents()
            expand = depth + 1
            current_player = (depth + 1) % number_of_agents
            value.append(self.value(gameState=successor_state, depth=expand, agent_idx=current_player))
        expected_value = sum(value) / len(value)
        return expected_value

    def value(self, gameState, depth, agent_idx):

        if self.is_terminal_state(gameState=gameState, depth=depth, agent_idx=agent_idx):
            return self.evaluationFunction(gameState)
        elif agent_idx is 0:
            return self.max_value(gameState=gameState, depth=depth, agent_idx=agent_idx)[0]
        else:
            return self.expected_value(gameState=gameState, depth=depth, agent_idx=agent_idx)


def betterEvaluationFunction(currentGameState):
    """
    Ваша усовершенствованная функция оценки (вопрос 5)

     ОПИСАНИЕ: <втавьте сюда описание Вашей функции>
    """
    
    "*** ВСТАВЬТЕ ВАШ КОД СЮДА ***"
   
    pacman_position = currentGameState.getPacmanPosition()
    food_positions = currentGameState.getFood().asList()
    capsules_positions = currentGameState.getCapsules()
    ghost_states = currentGameState.getGhostStates()
    remaining_food = len(food_positions)
    remaining_capsules = len(capsules_positions)
    scared_ghosts = list()
    enemy_ghosts = list()
    enemy_ghost_positions = list()
    scared_ghosts_positions = list()
    score = currentGameState.getScore()

    closest_food = float('+Inf')
    closest_enemy_ghost = float('+Inf')
    closest_scared_ghost = float('+Inf')

    distance_from_food = [manhattanDistance(pacman_position, food_position) for food_position in food_positions]
    if len(distance_from_food) is not 0:
        closest_food = min(distance_from_food)
        score -= 1.0 * closest_food

    for ghost in ghost_states:
        if ghost.scaredTimer is not 0:
            enemy_ghosts.append(ghost)
        else:
            scared_ghosts.append(ghost)

    for enemy_ghost in enemy_ghosts:
        enemy_ghost_positions.append(enemy_ghost.getPosition())

    if len(enemy_ghost_positions) is not 0:
        distance_from_enemy_ghost = [manhattanDistance(pacman_position, enemy_ghost_position) for enemy_ghost_position in enemy_ghost_positions]
        closest_enemy_ghost = min(distance_from_enemy_ghost)
        score -= 2.0 * (1 / closest_enemy_ghost)

    for scared_ghost in scared_ghosts:
        scared_ghosts_positions.append(scared_ghost.getPosition())

    if len(scared_ghosts_positions) is not 0:
        distance_from_scared_ghost = [manhattanDistance(pacman_position, scared_ghost_position) for scared_ghost_position in scared_ghosts_positions]
        closest_scared_ghost = min(distance_from_scared_ghost)
        score -= 3.0 * closest_scared_ghost

    score -= 20.0 * remaining_capsules
    score -= 4.0 * remaining_food
    return score


# Abbreviation
better = betterEvaluationFunction
