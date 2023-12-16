string_list = ["Hello", "World", "It's", "Me", "Again"]
new_list = [str.lower() for str in string_list if len(str) >=5]
print(new_list)

