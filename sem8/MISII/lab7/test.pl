:- dynamic student/7, student_f/7.

student("Иванов И. В", "ИС/Б-20-1-о", 3, 4, 5, 4, 4).
student("Иванов И. В", "ИС/Б-20-2-о", 4, 3, 5, 3, 4).
student("Петров И. В", "ИС/Б-20-2-о", 5, 3, 3, 3, 4).
student("Сидоров И. В", "ИС/Б-20-3-о", 3, 4, 5, 4, 4).
student("Васечкин И. В", "ИС/Б-20-2-о", 3, 4, 5, 4, 3).

% ~ RULES TO CONTROL USER INPUT THROUGH MENU

main_menu:-
    tty_clear,
    write('1 - Добавление записи в базу данных'),nl,
    write('2 - Удаление записи из базы данных'),nl,
    write('3 - Просмотр базы данных'),nl,
    write('4 - Сохранение базы данных в файле'),nl,
    write('5 - Загрузка базы данных из файла'),nl,
    write('6 - Реализация операций реляционной алгебры'),nl,
    write('7 - Корректировка данных в базе по номеру группы'),nl,
    write('8 - Просмотр студентов, имеющих хотя бы одну оценку 2'),nl,
    write('9 - Выход'),nl,
    read(Item), main_menu_item(Item).

main_menu_item(1):-
    add_student, 
    main_menu,!.

main_menu_item(2):-
    delete_student,
    main_menu,!.

main_menu_item(3):-
    show_students,
    main_menu,!.

main_menu_item(4):-
    save_file,
    main_menu,!.

main_menu_item(5):-
    load_file,
    main_menu,!.

main_menu_item(6):-
    relational_algebra,
    main_menu,!.

main_menu_item(7):-
    edit_student,
    main_menu,!.

main_menu_item(8):-
    show_dummies,
    main_menu,!.

main_menu_item(9):-tty_clear,!.

main_menu_item(_Item):-
    tty_clear,
    write('Нет такого пункта меню, выберите пункт в пределах от 1 до 8'),nl,
    main_menu.

% ~ RULE TO ADD STUDENT TO DB

add_student:-
    tty_clear,
    write('Введите Фамилия И.О.'),
    read(FIO),
    write('Введите номер группы'),
    read(Group),
    write('Введите успеваемость по предмету P1'),
    read(P1),
    write('Введите успеваемость по предмету P2'),
    read(P2),
    write('Введите успеваемость по предмету P3'),
    read(P3),
    write('Введите успеваемость по предмету P4'),
    read(P4),
    write('Введите успеваемость по предмету P5'),
    read(P5),
    assert(student(FIO, Group, P1, P2, P3, P4, P5)).

% ~ RULE TO SHOW STUDENTS DB

show_students:-
    tty_clear,
    student(FIO, Group, P1, P2, P3, P4, P5),
    write('Фамилия И.О.         Номер группы         Р1         Р2         Р3         Р4         Р5'),nl,
    write(FIO),tab(10),write(Group),tab(10),write(P1),tab(10),write(P2),tab(10),write(P3),tab(10),write(P4),tab(10),write(P5),nl,
    write('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'),nl,
    fail;
    true,
    get(temp).

% ~ RULE TO DELETE STUDENTS OF EXACT GROUP

delete_student:-
    tty_clear,
    write('Введите номер группы студента для удаления (удалятся все студенты данной группы)'),read(Group),
    retract(student(_,Group,_,_,_,_,_)),
    write('Все студенты группы '),write(Group),write(' были успешно удалены'),nl,
    get(temp),!;
    write('Студентов данной группы не найдено, возврат в меню'),
    get(temp).

% ~ RULE TO SAVE DB TO FILE

save_file:-
    tty_clear,
    tell('students.txt'),
    listing(student(_,_,_,_,_,_,_)),
    told(),    
    write('Таблица студентов была успешно сохранена в файл students.txt'),nl,get(temp).

% ~ RULE TO LOAD DB FROM FILE

load_file:-
    tty_clear,
    retractall(student(_,_,_,_,_,_,_)),
    consult('students.txt'),
    listing(student(_,_,_,_,_,_,_)),
    write('Таблица студентов была успешно загружена из файла students.txt'),nl,get(temp).

% ~ RULE TO SHOW STUDENTS WITH AT LEAST ONE '2' MARK

show_dummies:-
    tty_clear,
    student(FIO, Group, P1, P2, P3, P4, P5),
    member(2,[P1,P2,P3,P4,P5]),
    write('Фамилия И.О.         Номер группы         Р1         Р2         Р3         Р4         Р5'),nl,
    write(FIO),tab(10),write(Group),tab(10),write(P1),tab(10),write(P2),tab(10),write(P3),tab(10),write(P4),tab(10),write(P5),nl,
    write('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~'),nl,get(temp),fail,!;
    write('Больше нет студентов с оценками 2'),get(temp).

% ~ RULE TO EDIT STUDENT BY HIS GROUP NUMBER

edit_student:-
    tty_clear,
    write('Введите номер группы студента для изменения (изменяться будет первый встреченный студент выбранной группы)'),nl,read(EditGroup),
    retract(student(_,EditGroup,_,_,_,_,_)),
    write('Введите Фамилия И.О.'),
    read(FIO),
    write('Введите номер группы'),
    read(Group),
    write('Введите успеваемость по предмету P1'),
    read(P1),
    write('Введите успеваемость по предмету P2'),
    read(P2),
    write('Введите успеваемость по предмету P3'),
    read(P3),
    write('Введите успеваемость по предмету P4'),
    read(P4),
    write('Введите успеваемость по предмету P5'),
    read(P5),
    assert(student(FIO, Group, P1, P2, P3, P4, P5)).

% ~ RELATIONAL ALGEBRA RULES

relational_algebra:-
    tty_clear,
    write('Формирование отношения r1: студенты группы "ИС/Б-20-2-о"'),nl,
    student_subset("ИС/Б-20-2-о", R1),
    list_to_db(R1),
    print_list(R1),
    write('Формирование отношения r2: студенты группы "ИС/Б-20-1-о"'),nl,
    student_subset("ИС/Б-20-1-о", R2),
    list_to_db(R2),
    print_list(R2),
    write('Объединенное отношение r1_или_r2'),nl,
    union(Rez1),
    print_list(Rez1),
    write('Пересечение отношерний r1_и_r2'),nl,
    intersect(Rez2),
    print_list(Rez2),
    write('Разность отношений r1_и_не_r2'),nl,
    minus(Rez3),
    print_list(Rez3),

    get(temp).

student_subset(Group, R):-
    bagof(student_f(FIO,Group,P1,P2,P3,P4,P5),
        student(FIO,Group,P1,P2,P3,P4,P5),R).
    
list_to_db([]).
list_to_db([H|T]):-
    H=student_f(FIO,Group,P1,P2,P3,P4,P5),
    assertz(student_f(FIO,Group,P1,P2,P3,P4,P5)),
    list_to_db(T).

print_list([]).
print_list([H|T]):-
    write(H),nl,print_list(T).

union_r1_r2(X1,X2,X3,X4,X5,X6,X7):-
    student_f(X1,"ИС/Б-20-2-о",X3,X4,X5,X6,X7),X2="ИС/Б-20-2-о";
    student_f(X1,"ИС/Б-20-1-о",X3,X4,X5,X6,X7),X2="ИС/Б-20-1-о".

union(Rez):-
    bagof(student_f1_or_f2(X1,X2,X3,X4,X5,X6,X7),
        union_r1_r2(X1,X2,X3,X4,X5,X6,X7),Rez).

intersect_r1_r2(X11,X12,X13,X14,X15,X16,X17,X22,X23,X24,X25,X26,X27):-
    student_f(X11,"ИС/Б-20-1-о",X13,X14,X15,X16,X17),X12="ИС/Б-20-1-о",
    student_f(X11,"ИС/Б-20-2-о",X23,X24,X25,X26,X27),X22="ИС/Б-20-2-о".

intersect(Rez):-
    bagof(student_f1_and_f2(X11,X12,X13,X14,X15,X16,X17,X22,X23,X24,X25,X26,X27),
        intersect_r1_r2(X11,X12,X13,X14,X15,X16,X17,X22,X23,X24,X25,X26,X27),Rez).

minus_r1_r2(X11,X12,X13,X14,X15,X16,X17):-
    student_f(X11,"ИС/Б-20-2-о",X13,X14,X15,X16,X17),X12="ИС/Б-20-2-о",
    not(student_f(X11,"ИС/Б-20-1-о",X23,X24,X25,X26,X27)),X22="ИС/Б-20-1-о".

minus(Rez):-
    bagof(student_f1_and_not_f2(X11,X12,X13,X14,X15,X16,X17),
        minus_r1_r2(X11,X12,X13,X14,X15,X16,X17),Rez).

:- main_menu.