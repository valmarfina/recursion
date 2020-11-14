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
bool isInteger(char**);
bool isDigit(char**);
bool isLetter(char**);

//<буква> ::= a | b | c | d | e | f | x | y | z
bool isLetter(char** s)
{
	if ((**s >= 'a' && **s <= 'f') || **s == 'x' || **s == 'y' || **s == 'z') {
		*s += 1;
		return true;
	}
	else
		return false;
}

//<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
bool isDigit(char** s)
{
	if (**s >= '0' && **s <= '9')
	{
		*s += 1;
		return true;
	}
	else
		return false;
}

//<целое без знака> ::= <цифра>
bool isInteger(char** s)
{
	if (isDigit(s))
	{
		isInteger(s);
		return true;
	}
	else
		return false;
}

//<множитель> ::= <цифра>| <буква> | (<выражение>)
bool isMultiplier(char** s)
{
	if (isInteger(s) || isLetter(s))
	{
		return true;
	}
	else if(**s == '(')
	{
		*s += 1;
		if (isExpression(s))
		{
			if (**s == ')')
			{
				*s += 1;
				return true;
			}
		}
		return isExpression;
	}
	else
	{
		return false;
	}
}

//<терм> ::= <множитель> | (<множитель> * <терм>) |(<множитель> / <терм>)
bool isTerm(char** s) {
	if (isMultiplier(s))
	{
		if (**s == '(')
		{
			*s += 1;
			if ((isMultiplier(s)) && (**s == '*' || **s == '/'))
			{
				*s += 1;
				if (**s == ')')
				{
					*s += 1;
					return isTerm;
				}

			}

		}
		return true;
	}
	else
	{
		return false;
	}
}

//<выражение> ::= <терм> | <терм> +<выражение> | <терм> – <выражение>
bool isExpression(char** s) {
	if (isTerm(s)) {
		if (**s == '+' || **s == '-') {
			*s = *s + 1;
			return isExpression(s);
		}
		return true;
	}
	else
		return false;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	const int size = 1000;
	int count = 1;

	std::ifstream fin("input.txt");

	while (!fin.eof())
	{
		char* s = new char[size + 1];
		fin.getline(s, size);

		char* s2 = s;

		std::cout << count << ". " << (isExpression(&s) && *s == '\0' ? "Да" : "Нет") << "\n";

		s = s2;
		count++;

		delete[] s;
	}

	return 0;
}