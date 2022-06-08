#pragma once
#include <string>
#include <iostream>

class Token
{
public:
	enum class Kind
	{
		БинарныйОператор,
		Переменная,
		ПраваяСкобка,
		ЛеваяСкобка,
		Число,
		НоваяСтрока,
		Условие,
		Цикл,
		УсловныйЦикл,
		Функция,
		КонецПрограммы,
		ЛеваяФигурнаяСкобка,
		ПраваяФигурнаяСкобка,
		ЛеваяКвадратнаяСкобка,
		ПраваяКвадратнаяСкобка,
		// LinkedList
		Точка,
		Запятая,
		LinkedList,
		LinkedMethod,
		push_first,
		push_back,
		push_in,
		pop_from,
		find,
		size
	};
	Token(Kind type, int value, std::string name);
	Token(Kind type, std::string name);
	std::string Get_string();
	Token::Kind get_Kind();
	int get_value();
	std::string get_name();
private:
	Kind type;
	int value;
	std::string name;
};
