# recursion
Задание.
Напишите программу, выполняющую ввод строк из файла и проверку соответствия каждой введенной строки правилу (в соответствии с указанным вариантом).
Входные данные: Символьная строка. Ввести из файла потока cin.
Выходные данные: «ДА», если строка соответствует правилу, «НЕТ», если строка НЕ соответствует правилу.
Замечания:
• Ввод и вывод информации разместить в функции main().
• Каждое определение должно быть оформлено в виде отдельной функции.
• Данные для проверки вводить из файлов, читая анализируемую строку целиком.

#Индивидуальное задание вариант 13
Понятие выражение определено следующим образом:
<выражение> ::= <терм> | <терм> +<выражение> | <терм>–<выражение>
<терм> ::= <множитель> | (<множитель>*<терм>) |(<множитель>/<терм>)
<множитель> ::= <целое без знака> | <идентификатор> | (<выражение>)
<целое без знака> ::= <цифра> | <цифра><целое без знака>
<идентификатор> ::= <буква>
<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<буква> ::= a | b | c | d | e | f | x | y | z

#Спецификация.
1.1	Если не удалось открыть файл, то вывести сообщение: “ Файл не открыт!”. 
1.2	Если файл пуст, то вывести сообщение: “ Файл пуст!”.
1.3	Результат функции должен быть выведен в поток cout.
1.4	Каждое определение должно быть оформлено в виде отдельной функции.
1.5	Данные для проверки вводить из файлов, читая анализируемую строку целиком.
1.6	Вывести “Да”, если строка соответствует заданию.
1.7	Вывести “Нет”, если строка соответствует заданию.

