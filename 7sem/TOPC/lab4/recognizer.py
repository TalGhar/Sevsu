import numpy
import scanner
import relations

def number_row_col(code):
    match code:
        case '100':
            return 7
        case '200':
            return 8
        case '300':
            return 9
        case '400':
            return 10
        case '501':
            return 11
        case '502':
            return 12
        case '503':
            return 13
        case '504':
            return 14
        case '701':
            return 0
        case '702':
            return 1
        case '703':
            return 2
        case '704':
            return 3
        case '705':
            return 4
        case '706':
            return 5
        case '707':
            return 6
        case '999':
            return 15
                  
def find_rule(gramm, stack, stack_pointer, head_pointer):
    for rule in gramm:
        if rule[1:] == stack[head_pointer: stack_pointer + 1]:  
            return rule[0]
    

def find_head_pointer(stack, stack_pointer):
    k = 0
    for i in range(stack_pointer):
        if stack[i] == 1:
            k = i + 1
    return k

def main():
    relation_matrix = numpy.array(relations.execute()).astype(int)
    
    gramm = [
        ['701', '707', '702'],
        ['702', '703', '702'],
        ['702', '200', '501'],
        ['703', '300', '502', '705', '704'],
        ['704', '706', '705', '704'],
        ['704', '501'],
        ['705', '300'],
        ['705', '400'],
        ['706', '503'],
        ['706', '504'],
        ['707', '100', '501']
    ]
    
    test_sequence = scanner.execute()
    print('\nАнализируемая последовательность кодов:\n')
    print(f'{test_sequence}')
    test_sequence = '999 ' + test_sequence + ' 999'

    if test_sequence[0] in ('7', '8'):
        print(test_sequence)
        exit()

    test_sequence = test_sequence.split(' ')  
    stack = [test_sequence[0]]
    test_sequence.pop(0)
    
    stack_pointer = 0
    head_pointer = 0
    i = 0
    while i < len(test_sequence):
        code = test_sequence[i]
        i += 1
        row_number = number_row_col(stack[stack_pointer])
        col_number = number_row_col(code)
        relation = relation_matrix[row_number, col_number]
        
        match relation:
            case 1:
                stack_pointer += 1
                stack.append(1)
                stack_pointer += 1
                stack.append(code)
                head_pointer = stack_pointer
                
            case 2:
                stack_pointer += 1
                stack.append(code)
    
                
            case 3:
                nonterminal = find_rule(gramm, stack, stack_pointer, head_pointer)
                while stack[-1] != stack[head_pointer]:
                    stack.pop()
            
                if relation_matrix[number_row_col(stack[head_pointer - 2]), number_row_col(nonterminal)] == 1:
                    stack[head_pointer] = nonterminal
                    stack_pointer = head_pointer
                    i -= 1
                else:
                    head_pointer -= 1
                    stack[head_pointer] = nonterminal
                    stack.pop()
                    i -= 1
                    stack_pointer = head_pointer
                    head_pointer = find_head_pointer(stack, stack_pointer)
            
            case 4:
                print('\n\nРезультат работы восходящего распознавателя:')
                print('\n\nНеверная структура программы\n')
                exit()
            case 5:
                print('\n\nРезультат работы восходящего распознавателя:')
                print('\n\nОшибка компоновки тела модуля\n')
                exit()
            case 6:
                print('\n\nРезультат работы восходящего распознавателя:')
                print('\n\nОшибка составления выражения\n')
                exit()
            case 7:
                print('\n\nРезультат работы восходящего распознавателя:')
                print('\n\nНедопустимая комбинация знаков\n')
                exit()
            case 99:
                print('\n\nРезультат работы восходящего распознавателя:')
                print('\n\nОшибок не обнаружено\n')
                exit()
            case _:
                print('\n\nРезультат работы восходящего распознавателя:')
                print('\n\nНеизвестная ошибка\n')
                exit()

if __name__=="__main__": 
    main()