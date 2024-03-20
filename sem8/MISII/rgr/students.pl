:- dynamic student/6.

student(1, "Галенин А.К.", "ИС/Б-20-1-о", 4, 3, 7777).
student(2, "Ильина А.Н.", "ПОрЛ/Б-21-4-о", 3, 5, 1500).
student(3, "Озеров В.В.", "ИС/Б-20-1-о", 4, 3, 7777).
student(4, "Петров П.П.", "Абвгдеж-1", 4, 4, 4001).
student(5, "Иванов И.И.", "Абвгдеж-2", 5, 5, 3999).
student(6, "Васечкин. В.В.","ИС/Б-20-1-о", 4, 2, 2489).

menu:-
    tty_clear,
    write('#############################################################################'),nl,
    write('1. Студенты со стипендией > 2000 и < 4000                                    '),nl,
    write('2. Студенты со стипендией > 4000 или < 2000                                  '),nl,
    write('3. Студенты, у которых совпадает номер курса и порядковый номер              '),nl,
    write('4. Студенты, обучающиеся на заданном курсе                                   '),nl,
    write('5. Студенты, обучающиеся в одной группе и имеющие одинаковый размер стипендии'),nl,
    write('6. Выход                                                                     '),nl,
    write('{Для выбора пункта меню, необходимо написать соответствующую цифру пункта, С ТОЧКОЙ в конце}'),nl,
    write('#############################################################################'),nl,
    read(Item), menu_item(Item).

menu_item(1):-
    more_and_less,
    menu,!.

menu_item(2):-
    more_or_less,
    menu,!.

menu_item(3):-
    student_with_same_course_and_id,
    menu,!.
        
menu_item(4):-
    find_students_by_course,
    menu,!.        

menu_item(5):-
    matching_students_of_same_group_with_same_studentship,
    menu,!.

menu_item(6):-!.

menu_item(_Item):-
    tty_clear,
    write('Нет такого пункта меню, выберите пункт в пределах от 1 до 6'),nl,
    menu.

more_and_less:-
    tty_clear,
    write('Вывести фамилии студентов, у которых стипендия от 2000 до 4000? {да/нет}'),nl,
    read(Answer),
    (Answer = да ->
        student(_,FIO,Group,_,_,Studentship),
        Studentship > 2000, Studentship < 4000,
        write(FIO),write(' '),write(Group),write(' -> '),write(Studentship),nl,    
        write('Введите любой символ'),get(temp),
        fail;
    Answer = нет ->
        student(_,FIO,Group,_,_,Studentship),
        (Studentship > 2000, Studentship < 4000),!,
        write('В базе данных есть хотя бы один студент, размер стипендии у которого больше 2000, но меньше 4000'),nl,
        write('Введите любой символ'),get(temp)
    ).

more_or_less:-
    tty_clear,
    write('Вывести фамилии студентов, у которых стипендия или меньше 2000 или больше 4000? {да/нет}'),nl,
    read(Answer),
    (Answer = да ->
        student(_,FIO,Group,_,_,Studentship),
        (Studentship > 4000; Studentship < 2000), 
        write(FIO),write(' '),write(Group),write(' -> '),write(Studentship),nl,
        write('Введите любой символ'),get(temp),
        fail;
    Answer = нет ->
        student(_,FIO,Group,_,_,Studentship),
        (Studentship > 4000; Studentship < 2000),!,
        write('В базе данных есть хотя бы один студент, размер стипендии у которого большее 4000 или меньше 2000'),nl,
        write('Введите любой символ'),get(temp)
    ).

student_with_same_course_and_id:-
    tty_clear,
    write('Вывести фамилии студентов, у которых совпадает порядковый номер и номер курса? {да/нет}'),nl,
    read(Answer),
    (Answer = да ->
        student(N,FIO,_,Course,_,_),
        N = Course,
        write(FIO),nl,
        write('Введите любой символ'),get(temp),
        fail;
    Answer = нет ->
        student(N,FIO,_,Course,_,_),
        N = Course,!,
        write('В базе данных есть хотя бы один студент, у которого порядковый номер и номер курса совпадают'),nl,
        write('Введите любой символ'),get(temp)
    ).

find_students_by_course:-
    tty_clear,
    write('Введите номер курса, список студентов которого необходимо вывести'),nl,read(User_Course),
    student(N, FIO, Group, Course, Average, Studentship),
    member(User_Course, [Course]),
    write(FIO),nl,write('Введите любой символ'),get(temp),fail,!;
    write('Больше нет студентов данного курса'),nl,write('Введите любой символ'),get(temp).

matching_students_of_same_group_with_same_studentship:-
    tty_clear,
    write('Вывести фамилии студентов из одной группы и имеющих одинаковый размер стипендии? {да/нет}'),nl,
    read(Answer),
    (Answer = да ->
        student(_,FIO,Group,_,_,Studentship),
        student(_,FIO_,Group,_,_,Studentship),
        FIO \= FIO_,
        write(FIO),write(' '),write(FIO_),write(' -> '),write(Studentship),nl,
        write('Введите любой символ'),get(temp);
    Answer = нет ->
        student(_,FIO,Group,_,_,Studentship),
        student(_,FIO_,Group,_,_,Studentship),
        FIO \= FIO_,!,
        write('В базе данных есть два студента, обучающихся в одной группе и имеющих одинаковый размер стипендии'),nl,
        write('Введите любой символ'),get(temp)
    ).

:- menu.