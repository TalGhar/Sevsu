# STRINGS

# #format
# print("{0} {1}".format("Example", "of format method"))
# print("just float => {0} | float with width=12 and 2 symbs after . => {0:012.2f}".format(123.12312))
# print("numbers with {0:+f} {1: f}".format(12.123, -12.123))
# print("Align format method:")
# print("{:5}".format("asd")) 
# print("{:<5}".format("asd"))
# print("{:>5}".format("asd"))
# print("{:= 6.3f}".format(123.12312))

# #strip
# # Удаление пробелов в начале и конце строки
# txt = "  Hello, World!  "
# x = txt.strip()
# print(x)

# # Удаление определенных символов в начале и конце строки
# txt = ",,,,,rrttgg.....banana....rrr"
# x = txt.strip(",.grt")
# print(x)

# #lstrip 
# # Удаление пробелов в начале строки
# txt = "   Hello, World!"
# x = txt.lstrip()
# print(x)

# # Удаление определенных символов в начале строки
# txt = ",,,,,ssaaww.....banana"
# x = txt.lstrip(",.asw")
# print(x)

# # Удаление пробелов и других символов в начале строки
# txt = "   Hi there,   cd ./user/home"
# x = txt.lstrip("   ")
# print(x)


# #rstrip 
# # Удаление пробелов в конце строки
# txt = "Hello, World!   "
# x = txt.rstrip()
# print(x)

# # Удаление определенных символов в конце строки
# txt = "banana...."
# x = txt.rstrip(".")
# print(x)

# #capitalize 
# string = "hello, world!"
# capitalized_string = string.capitalize()
# print(capitalized_string) 

# string = "PYTHON IS AWESOME"
# capitalized_string = string.capitalize()
# print(capitalized_string) 

# string = "123abc"
# capitalized_string = string.capitalize()
# print(capitalized_string) 

# #title 
# txt = "Welcome to my world"
# x = txt.title()
# print(x)
# txt = "234 k3l2 *43 fun"
# x = txt.title()
# print(x)
# txt = "123abc"
# x = txt.title()
# print(x)

# #count
# fruits = ['apple', 'banana', 'cherry']
# x = fruits.count("cherry")
# print("Count of 'cherry':", x)

# txt = "I love apples, apple are my favorite fruit"
# x = txt.count("apple")
# print("Count of 'apple':", x)

# random = ['a', ('a', 'b'), ('a', 'b'), [3, 4]]
# x = random.count([3, 4])
# print("Count of [3, 4]:", x)

# #index
# fruits = ['apple', 'banana', 'cherry']
# x = fruits.index("cherry")
# print(x)

# numbers = [4, 55, 64, 32, 16, 32]
# x = numbers.index(32)
# print(x)

# animals = ["cat", "dog", "tiger"]
# try:
#     x = animals.index("bat")
# except ValueError:
#     x = -1
# print(x)

# #rindex
# quote = 'Let it be, let it be, let it be'
# result = quote.rindex('let it')
# print("Подстрока 'let it':", result) 
# try:
#     result = quote.rindex('small')
# except:
#     result = "ValueError: substring not found"
# print("Подстрока 'small':", result)
# # Поиск подстроки с указанием начального и конечного индексов
# quote = 'Do small things with great love'
# print(quote.rindex('t', 2)) # ищем подстроку 't' начиная с индекса 2
# print(quote.rindex('th', 6, 20)) # ищем подстроку 'th' в диапазоне от индекса 6 до 20
# try:
#     print(quote.rindex('o small ', 10, -1)) # ищем подстроку 'o small ' в диапазоне от индекса 10 до конца строки
# except:
#     print("ValueError: substring not found")

# #startswith
# text = "Python is easy to learn."
# result = text.startswith('Python') # возвращает True
# print(result)

# text = "Python programming is easy."
# result = text.startswith('programming', 7) # возвращает True
# print(result)

# text = "Python programming is easy."
# result = text.startswith('programming is', 7, 18) # возвращает False
# print(result)

# #endswith
# txt = "Hello, welcome to my world."
# print(txt.endswith("."))  # Output: True
# print(txt.endswith("my world."))  # Output: True

# txt = "Hello, welcome to my world."
# print(txt.endswith("my world.", 5, 11))  # Output: False

# #replace 
# txt = "I like bananas"
# x = txt.replace("bananas", "apples")
# print(x)
# txt = "one one was a race horse, two two was one too."
# x = txt.replace("one", "three")
# print(x)
# txt = "one one was a race horse, two two was one too."
# x = txt.replace("one", "three", 2)
# print(x)

# #split 
# txt = "welcome to the jungle"
# x = txt.split()
# print(x)
# txt = "hello, my name is Peter, I am 26 years old"
# x = txt.split(", ")
# print(x) 
# txt = "apple#banana#cherry#orange"
# x = txt.split("#", 2)
# print(x)

# #rsplit 
# txt = "apple, banana, cherry"
# x = txt.rsplit(", ")
# print(x)
# txt = "apple, banana, cherry"
# x = txt.rsplit(", ", 1)
# print(x)

# #join 
# my_list = ['apple', 'banana', 'orange']
# s1 = ''.join(my_list)
# print(s1)
# my_tuple = ('apple', 'banana', 'orange')
# s2 = '#'.join(my_tuple)
# print(s2)
# my_dict = {'name': 'John', 'country': 'Norway'}
# s3 = 'TEST'.join(my_dict)
# print(s3)
# m1 = 'y'
# m2 = 'aaaaa'
# s4 = m1.join(m2)
# print(s4)
# my_set = {'apple', 'banana', 'orange'}
# s5 = ', '.join(my_set)
# print(s5)

# #partition 
# txt = "I could eat bananas all day"
# x = txt.partition("bananas")
# print(x)
# txt = "Python is fun"
# x = txt.partition("is")
# print(x)
# txt = "Python is fun, isn't it"
# x = txt.partition("is")
# print(x)

# #rpartition
# txt = "I could eat bananas all day, bananas are my favorite fruit"
# x = txt.rpartition("bananas")
# print(x)
# string = "Python is fun"
# print(string.rpartition('is '))
# mystr = 'Hello World'
# print(mystr.rpartition('o'))

# LISTS

# #append
# fruits = ['apple', 'banana', 'cherry']
# fruits.append('orange')
# print(fruits)
# a = ["apple", "banana", "cherry"]
# b = ["Ford", "BMW", "Volvo"]c
# a.append(b)
# print(a)

#count
# points = [1, 4, 2, 9, 7, 8, 9, 3, 1]
# x = points.count(9)
# print(x)

# #extend
# fruits = ['apple', 'banana', 'cherry']
# cars = ['Ford', 'BMW', 'Volvo']
# fruits.extend(cars)
# print(fruits) # ['apple', 'banana', 'cherry', 'Ford', 'BMW', 'Volvo']
# fruits = ['apple', 'banana', 'cherry']
# points = (1, 4, 5, 9)
# fruits.extend(points)
# print(fruits) # ['apple', 'banana', 'cherry', 1, 4, 5, 9]
# fruits = ['apple', 'banana', 'cherry']
# string = "orange"
# fruits.extend(string)
# print(fruits) # ['apple', 'banana', 'cherry', 'o', 'r', 'a', 'n', 'g', 'e']

# #index
# fruits = ['apple', 'banana', 'cherry']
# x = fruits.index("cherry")
# print(x) 

# list1 = [1, 2, 3, 4, 1, 1, 1, 4, 5]
# print(list1.index(4, 4, 8))
# list1 = [1, 2, 3, 4, 1, 1, 1, 4, 5]
# try:
#     print(list1.index(10))
# except ValueError as e:
#     print("Element not found") 

# #insert
# fruits = ['apple', 'banana', 'cherry']
# fruits.insert(1, "orange")
# print(fruits) 

# prime_numbers = [2, 3, 5, 7]
# prime_numbers.insert(0, 1)
# print(prime_numbers)

# my_list = [1, 2, 3]
# my_list.insert(3, [4, 5, 6])
# print(my_list)

# #pop
# my_list = [1, 2, 3]
# item = my_list.pop(1)
# print(item)
# print(my_list)
# my_list = [1, 2, 3]
# item = my_list.pop()
# print(item)
# print(my_list)
# my_list = [1, 2, 3]
# try:
#     item = my_list.pop(4)
# except IndexError:
#     print("Индекс вышел за пределы списка")

# #remove
# animals = ['cat', 'cat', 'dog', 'guinea pig', 'cat']
# animals.remove('cat')
# print('Обновленный список:', animals)

# #reverse
# numbers = [1, 2, 3, 4, 5]
# numbers.reverse()
# print(numbers)

# fruits = ['apple', 'banana', 'cherry']
# reversed_fruits = fruits[::-1]
# print(reversed_fruits) 

# cars = ['Ford', 'BMW', 'Volvo']
# reversed_cars = list(reversed(cars))
# print(reversed_cars) 

# #sort
# numbers = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
# numbers.sort()
# print(numbers)  
# numbers.sort(reverse=True)
# print(numbers)


# DICTIONARIES
# #clear
# my_dict = {'a': 1, 'b': 2, 'c': 3}
# print("Словарь до очистки:", my_dict)
# my_dict.clear()
# print("Словарь после очистки:", my_dict)

# #copy
# original_dict = {'a': 1, 'b': 2, 'c': 3}
# copy_dict = original_dict.copy()
# copy_dict['a'] = 10
# print("Original dict:", original_dict)
# print("Copy dict:", copy_dict)

# #fromkeys
# keys = {'a', 'e', 'i', 'o', 'u'}
# value = 'vowel'
# vowels = dict.fromkeys(keys, value)
# print(vowels)

# #get
# car = {"brand": "Ford", "model": "Mustang", "year": 1964}
# x = car.get("model")
# print(x)

# #items
# car = {"brand": "Ford", "model": "Mustang", "year": 1964}
# x = car.items()
# print(x)
# car["year"] = 2018
# print(x)

# #keys
# car = {"brand": "Ford", "model": "Mustang", "year": 1964}
# for key in car.keys():
# print(key)

# #pop
# my_dict = {'a': 1, 'b': 2, 'c': 3}
# removed_value = my_dict.pop('a')
# print(removed_value)
# print(my_dict)

# #popitem
# car = {"brand": "Ford", "model": "Mustang", "year": 1964}
# x = car.popitem()
# print(x)

# #setdefault
# car = {"model": "Mustang", "year": 1964}
# car.setdefault("brand", "Ford")
# print(car)

# #update
# car = {"brand": "Ford", "model": "Mustang", "year": 1964}
# car.update({"model": "Focus"})
# print(car)

# #values
# car = {"brand": "Ford", "model": "Mustang", "year": 1964}
# print(car.values())