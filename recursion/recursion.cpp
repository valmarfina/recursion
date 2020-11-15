#include <iostream>
#include <fstream>

//ВАРИАНТ 13

/*
Напишите программу, выполняющую ввод строк из файла и проверку соответствия каждой введенной строки правилу (в соответствии с указанным вариантом).
Входные данные: Символьная строка. Ввести из файла потока cin.
Выходные данные: «ДА», если строка соответствует правилу, «НЕТ», если строка НЕ соответствует правилу.

Замечания:
• Ввод и вывод информации разместить в функции main().
• Каждое определение должно быть оформлено в виде отдельной функции.
• Данные для проверки вводить из файлов, читая анализируемую строку целиком.

13 вариант

Понятие выражение определено следующим образом:
<выражение> ::= <терм> | <терм> +<выражение> | <терм> – <выражение>
<терм> ::= <множитель> | (<множитель> * <терм> ) |( <множитель> / <терм>)
<множитель> ::= <целое без знака> | <буква> | (<выражение>)
<целое без знака> ::= <цифра> | <цифра> <целое без знака>
<идентификатор> ::= <буква>
<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<буква> ::= a | b | c | d | e | f | x | y | z
*/

bool isExpression(char**);
bool isTerm(char**);
bool isMultiplier(char**);
bool isNumber(char**);
bool isDigit(char**);
bool isLetter(char**);

bool isLetter(char** s)
{
    if ((**s >= 'a') && (**s <= 'f') || (**s >= 'x') && (**s <= 'z'))
    {
        *s = *s + 1;
        return true;
    }
    return false;
}

bool isDigit(char** s)
{
    if (**s >= '0' && **s <= '9')
    {
        *s = *s + 1;
        return true;
    }
    return false;
}

bool isNumber(char** s)
{
    if (isDigit(s))
    {
        isNumber(s);
        return true;
    }
    return false;
}



bool isMultiplier(char** s)
{
    if (isLetter(s))
        return true;
    else if (isNumber(s))
        return true;
    else if (**s == '(')
    {
        *s = *s + 1;
        if (isExpression(s))
        {
            if (**s == ')')
            {
                *s = *s + 1;
                return true;
            }
            return false;
        }
        return false;
    }
    return false;
}

bool isTerm(char** s)
{
    if (isMultiplier(s))
    {
        if (**s == '*' || **s == '/')
        {
            *s = *s + 1;
            return isTerm(s);
        }
        return true;
    }
    return false;
}

//bool isTerm(char** s) {
//    if (**s == '(')
//    {
//        *s += 1;
//        if (isMultiplier(s))
//        {
//            if (**s == '*' || **s == '/')
//            {
//                *s += 1;
//                if (isTerm(s))
//                {
//                    if (**s == ')')
//                    {
//                        *s += 1;
//                        return true;
//                    }
//                }
//            }
//        }
//    }
//    else if (isMultiplier(s))
//    {
//        return true;
//    }
//    return false;
//}

bool isExpression(char** s)
{
    if (isTerm(s))
    {
        if (**s == '+' || **s == '-')
        {
            *s = *s + 1;
            return isExpression(s);
        }
        return true;
    }
    return false;
}

int main()
{
    setlocale(LC_ALL, "rus");

    const int size = 1000;
    int count = 1;

    std::ifstream fin("input.txt");

    while (!fin.eof())
    {
        char* s = new char[size + 1];

        //fin.ignore('\n');
        fin.getline(s, size);

        char* s2 = s;

        std::cout << count << ". " << (isExpression(&s) && *s == '\0' ? "Да" : "Нет") << "\n";

        s = s2;
        count++;

        delete[] s;
    }

    fin.close();
    return 0;
}