# buyLotsOfFruit.py
# -----------------
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


"""
Для выполнения скрипта введите

  python buyLotsOfFruit.py

Если Вы корректно реализуете функцию buyLotsOfFruit,
то скрипт сформирует выход:
    
Cost of [('apples', 2.0), ('pears', 3.0), ('limes', 4.0)] is 12.25
"""
from __future__ import print_function

fruitPrices = {'apples': 2.00, 'oranges': 1.50, 'pears': 1.75,
               'limes': 0.75, 'strawberries': 1.00}


def buyLotsOfFruit(orderList):
    """
        orderList: Список-заказ из кортежей (fruit, numPounds) 

    Возвращает стоимость заказа
    """
    totalCost = 0.0
    "***  ВСТАВЬТЕ ВАШ КОД СЮДА ***"
          
    return totalCost


# Главная функция
if __name__ == '__main__':
    "Этот код выполняется, когда Вы запускаете скрипт из командной строки "
    orderList = [('apples', 2.0), ('pears', 3.0), ('lime', 4.0)]
    print('Cost of', orderList, 'is', buyLotsOfFruit(orderList))
