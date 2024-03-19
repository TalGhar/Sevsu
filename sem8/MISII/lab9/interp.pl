%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Интерпретатор (машина вывода) для ЭС продукционного типа
% Метод вывода: обратный вывод
% Вариант 2: интерпретатор обрабатывает правила, в которых
% предпосылки задаются в виде списка условий.
% Это позволяет в условной части правила, задавать произвольное
% количество условий.
% -------------------------------------------------------------------------------
% Примеры правил см. в загружаемой тестовой базе знаний - new_anim.pl
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:-dynamic
сообщено/2.

определить_операторы:-
op(950, xfx, то),
op(960, fx, если),
op(970, xfx, '::').
:-определить_операторы.

%============обратный вывод======================================================
% реализуется предикатом найти(S,Стек,Д),где S - список проверяемых гипотез,
% Стек - стек из имен доказываемых гипотез и правил (используется при ответе на
% вопросы "почему), Д - дерево вывода целевого утверждения (используется при отве-
% те на вопросы "как"). Предикат получает на вход список [Н] и Стек=[H] и в про-
% цессе обратного вывода строит дерево вывода Д.
% Предикат "найти" для доказательства отдельных гипотез из списка S
% использует предикат найти1(Н,Стек,Дерево).
%--------------------------------------------------------------------------------

% случай1:если цель Н была подтверждена пользователем,
% то дерево вывода Д=сообщено(Н).
найти1(H,Стек,сообщено(H)):-сообщено(H,да).
найти1(H,Стек,сообщено(H)):-запрашиваемая(H),
not(сообщено(H,_)),спроси(H,Стек).

% случай2:если цель Н подтверждается фактом, уже известным системе,
% то дерево вывода Д=Факт :: H
найти1(H,Стек,Факт :: H):-Факт :: H.

% случай3: если цель Н соответствует следствию одного из
% правил -> Правило :: если H1 то H
% и если Д1 дерево вывода для подцели Н1,
% то Д= Правило :: если Д1 то H и добавить № правила в Стек
найти1(H,Стек,Правило :: если Д1 то H):-
Правило :: если H1 то H,
найти(H1,[Правило | Стек],Д1).

% случай4: если доказывается конъюнкция гипотез, заданная списком гипотез,
% то найти доказательство первой гипотезы Н1 из списка
% с помощью найти1(H1,Стек,Дерево1), а затем найти доказательство оставшихся
% гипотез Т с помощью найти(T,Стек,Дерево) и
% объединить деревья вывода в общий список [Дерево1 | Дерево].
найти([],Стек,Дерево):-Дерево=[].
найти([H1|T],Стек,[Дерево1 | Дерево]):-
найти1(H1,Стек,Дерево1),найти(T,Стек,Дерево).

% проверка: является ли гипотеза признаком, значение которого можно спросить
запрашиваемая(H):-Факт :: признак(H).

%=========вывод вопросов и обработка ответов "да, нет, почему" ==================
%вывод вопроса и ввод ответа
спроси(H,Стек):-write(H),write('?'),nl,
read(O),ответ(H,O,Стек).

%обработка ответов: да, нет
ответ(H,да,Стек):-assert(сообщено(H,да)),!.
ответ(H,нет,Стек):-assert(сообщено(H,нет)),!,fail.

%обработка ответов - "почему"
% случай1: стек целей пустой
ответ(H,почему,[]):-!,write(' Вы задаете слишком много вопросов'),nl,
спроси(H,[]).

%случай2: в стеке осталась только первая введенная цель, т.е доказываемая гипотеза
ответ(P,почему,[H]):-!,write('моя гипотеза: '),
write(H),nl,спроси(P,[]).

%случай3: вывод заключения и номера правила для доказываемой текущей подцели Н
ответ(H,почему,[Правило | Стек]):-!,
Правило :: если H1 то H2,
write('пытаюсь доказать '),
write(H2),nl,
write('с помощью правила: '),
write(Правило),nl,
спроси(H,Стек).

%неправильный ответ: повторяем вопрос
ответ(H,_,Стек):-write(' правильный ответ: да, нет, почему'),nl,
спроси(H,Стек).

%==============обработка ответов на вопросы "как?"===============================
% предикат как(H,Д)- выполняет поиск подцели Н в построенном
% с помощью предиката "найти" дереве вывода Д и отображает соответствующий
% фрагмент дерева вывода, объясняя, как было получено доказательство Н.
% Дерево вывода Д представляет собой последовательность вложенных правил
% в виде списка, например:
% [правило5::если[правило1::если[сообщено(имеет(шерсть))]то млекопитающее,
%                           сообщено(ест_мясо)]то хищник,...]
%--------------------------------------------------------------------------------
% поиск целевого утверждения Н в дереве
как(H,Дерево):-как1(H,Дерево),!.

% вывод сообщения, если Н не найдено
как(H,_):-write(H),tab(2),write('не доказано'),nl.

% случай1: если Н сообщено пользователем,
% то вывести "Н было введено"
как1(H,_):-сообщено(H,_),!,
write(H),write('было введено'),nl.

% случай2: если дерево вывода Д представлено фактом, подтверждающим Н
как1(H,Факт :: H):-!,
write(H), write( 'является фактом'), write(Факт),nl.

% случай3: если дерево вывода Д - правило в заключение, которого есть Н,
% то отобразить это правило
как1(H,[Правило :: если _ то H]):-!,
write(H),write(' было доказано с помощью'),nl,
Правило :: если H1 то H,
отобрази_правило(Правило :: если H1 то H).

% случай4: если в дереве Д нет правила с заключением Н,
%то поиск Н надо выполнять в дереве вывода предпосылок, т.е. в Дерево
как1(H,[Правило :: если Дерево то _]):-как(H,Дерево).

% случай5: если дерево вывода - список поддеревьев вывода
% каждой конъюнктивной подцели правила из БЗ,
% то поиск Н следует выполнять в каждом из поддеревьев;
% поиск Н следует выполнять сначала в поддереве [Д1], а
% если Н не найдено, то продолжить поиск в оставшихся поддеревьях
как1(H,[]):-!.
как1(H,[Д1|Д2]):-как(H,[Д1]),!;
как1(H,Д2).

%вывод правила на экран
отобрази_правило(Правило :: если H1 то H):-
write(Правило), write( ':'),nl,
write('если '), write(H1), nl,
write('то '), write(H),nl.

/* Вызов интерпретатора*/
инициализация:-retractall(сообщено(_,_)).
start:-

/* Загрузка базы знаний из файла*/
reconsult('./nb.pl'),
info,
%отображение информации о базе знаний*
go_exp_sys.
go_exp_sys:-
    инициализация,
    Факт :: гипотеза(H),
    найти([H],[H],Дерево),
    write('решение:'),write(H),nl,
    объясни(Дерево),
    возврат.
%объяснение вывода утверждения
объясни(Дерево):-write( 'объяснить ? [цель/нет]:'), nl,read(H),
(H\=нет,!,как(H,Дерево),объясни(Дерево));!.
%поиск следующих решений
возврат:-write('Искать ещё решение [да/нет] ?: '),nl, read(нет).