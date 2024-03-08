:- dynamic student/7.

main_menu:-
    tty_clear,
    write('1 - Добавление записи в базу данных'),nl,
    write('2 - Удаление записи из базы данных'),nl,
    write('3 - Просмотр базы данных'),nl,
    write('4 - Сохранение базы данных в файле'),nl,
    write('5 - Загрузка базы данных из файла'),nl,
    write('6 - Реализация операций реляционной алгебры'),nl,
    write('7 - Корректировка данных в базе по номеру группы'),nl,
    write('8 - Выход'),nl,
    read(Item), main_menu_item(Item).

main_menu_item(1):-
 
    add_student, 
    main_menu,!.

main_menu_item(2):-

    main_menu,!.

main_menu_item(3):-
    show_students,
    main_menu,!.

main_menu_item(4):-
    

    main_menu,!.

main_menu_item(5):-
    

    main_menu,!.

main_menu_item(6):-
    

    main_menu,!.

main_menu_item(7):-
    

    main_menu,!.

main_menu_item(8):-!.

main_menu_item(_Item):-
    
    write('Нет такого пункта меню, выберите пункт в пределах от 1 до 8'),nl,
    main_menu.

add_student:-
    
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

show_students:-
    
    student(FIO, Group, P1, P2, P3, P4, P5),
    write(FIO), write(Group), write(P1), write(P2), write(P3), write(P4), write(P5).

:- main_menu.