#pragma once
#include <string>
#include <iostream>

class Token
{
public:
	enum class Kind
	{
		Равно,
		Переменная,
		ПраваяСкобка,
		ЛеваяСкобка,
		Плюс,
		Минус,
		Число,
		НоваяСтрока,
		Умножение,
		Деление,
		Условие,
		Цикл,
		УсловныйЦикл,
		Функция,
		Больше,
		Меньше
	};
	Token(Kind type, std::string value);
	Token(Kind type);
	std::string Get_string();
private:
	Kind type;
	std::string value;
};

