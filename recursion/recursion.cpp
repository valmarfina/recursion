#include <iostream>
#include <fstream>
/*
Напишите программу, выполняющую ввод строк из файла и проверку соответствия каждой введенной строки правилу 
(в соответствии с указанным вариантом).
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

//<буква> :: = a | b | c | d | e | f | x | y | z
bool isLetter(char** s)
{
	if ((**s >= 'a') && (**s <= 'f') || (**s >= 'x') && (**s <= 'z'))
	{
		*s = *s + 1;
		return true;
	}
	return false;
}

//<цифра> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
bool isDigit(char** s)
{
	if (**s >= '0' && **s <= '9')
	{
		*s = *s + 1;
		return true;
	}
	return false;
}

//<целое без знака> ::= <цифра> | <цифра> <целое без знака>
bool isNumber(char** s)
{
	if (isDigit(s))
	{
		isNumber(s);
		return true;
	}
	return false;
}

//<множитель> ::= <целое без знака> | <буква> | (<выражение>)
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

		}

	}
	return false;
}

//<терм> ::= <множитель> | (<множитель> * <терм> ) |( <множитель> / <терм>)
//bool isTerm(char** s)
//{
//
//	if (isMultiplier(s))
//	{
//		if (**s == '*' || **s == '/')
//		{
//			*s = *s + 1;
//			return isTerm(s);
//		}
//		return true;
//	}
//	return false;
//}

//<терм> :: = <множитель> | (<множитель> * <терм>) | (<множитель> / <терм>)
bool isTerm(char** s) {
    if (**s == '(')
    {
        *s += 1;
        if (isMultiplier(s))
        {
            if (**s == '*' || **s == '/')
            {
                *s += 1;
                if (isTerm(s))
                {
                    if (**s == ')')
                    {
                        *s += 1;
                        return true;
                    }
                }
            }
        }
    }
    else if (isMultiplier(s))
    {
        return true;
    }
    return false;
}

//<выражение> ::= <терм> | <терм> +<выражение> | <терм> – <выражение>
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

//проверка на пустуй файл
bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}


int main()
{
	setlocale(LC_ALL, "rus");

	const int size = 1000;
	int count = 1;

	try {
		std::ifstream file("input.txt");
		if (!file)
		{
			throw std::exception("Файл не открыт!");
			return 1;
		}
		if (isEmpty(file))
		{
			throw std::exception("Файл пуст!");
			return 1;
		}

		while (!file.eof())// пробегаем пока не встретим конец файла eof
		{
			char* s = new char[size + 1];
			if (size <= 0)
			{
				throw std::exception("Память не может быть выделена!");
				return 1;
			}
			file.getline(s, size);
			char* s2 = s;

			std::cout << count << ". " << (isExpression(&s) && *s == '\0' ? "Да" : "Нет") << "\n";
			
			s = s2;
			count++;

			delete[] s;
		}

		file.close();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}