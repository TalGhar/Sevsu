class FruitShop:

    def __init__(self, name, fruitPrices):
        """
            name: Название магазина фруктов
            
            fruitPrices: Словарь с ключами в виде названий фруктов
            и ценами в виде значений, например:
            {'apples':2.00, 'oranges': 1.50, 'pears': 1.75}

        """
        self.fruitPrices = fruitPrices
        self.name = name
        print('Welcome to %s fruit shop' % (name))

    def getCostPerPound(self, fruit):
        """
         Возвращает стоимость фрукта 'fruit',
         если он в словаре, иначе - None
            
         fruit:строка с названием фрукта
    
        """
        if fruit not in self.fruitPrices:
            print("Sorry we don't have %s" % (fruit))
            return None
        return self.fruitPrices[fruit]

    def getPriceOfOrder(self, orderList):
        """
         Возвращает стоимость заказа orderList, включая только
        фрукты, которые есть в магазине.
        
        orderList: Список из кортежей (fruit, numPounds)

        """
        totalCost = 0.0
        for fruit, numPounds in orderList:
            costPerPound = self.getCostPerPound(fruit)
            if costPerPound != None:
                totalCost += numPounds * costPerPound
        return totalCost

    def getName(self):
        return self.name

    def __str__(self):
        return "<FruitShop: %s>" % self.getName()
