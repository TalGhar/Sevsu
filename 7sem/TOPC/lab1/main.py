import numpy

regex = numpy.array([
    [1, 99, 2, 4, 99, 99, 7, 99],
    [99, 2, 2, 5, 3, 99, 99, 7],
    [6, 99, 3, 99, 99, 5, 99, 99],
])

end_nodes = (3, 4, 5, 7)

test_sequences = open("test_sequence.txt", "r").read().splitlines()
for test_sequence in test_sequences:
    node = 0
    print('\n')
    for symbol in test_sequence:
        match symbol:
            case 'a':
                node = regex[0][node]
            case 'b':
                node = regex[1][node]
            case 'c':
                node = regex[2][node]
            case _:
                node = 999
        if node == 999:
            print('\nНе символ алфавита')
            break
        elif node == 99:
            print('\nНеправильная вершина цепочки')
            break
        else:
            print(f'-{node}-', end="")

    if (node not in end_nodes) and (node != 999) and (node != 99):
        print('\nНеполная цепочка')
    elif (node != 999 and node != 99):
        print(f'\n{test_sequence}')
