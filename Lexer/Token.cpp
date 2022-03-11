#include "Token.h"

Token::Token(Kind type, std::string value)
{
	this->type = type;
	this->value = value;
}

Token::Token(Kind type)
{
	this->type = type;
}

std::string Token::Get_string()
{
	std::string type;
	switch (this->type)
	{
	case Kind::Плюс:
		type = "Плюс";
		break;
	case Kind::Минус:
		type = "Минус";
		break;
	case Kind::ЛеваяСкобка:
		type = "ЛеваяСкобка";
		break;
	case Kind::ПраваяСкобка:
		type = "ПраваяСкобка";
		break;
	case Kind::Переменная:
		type = "Переменная";
		break;
	case Kind::Равно:
		type = "Равно";
		break;
	case Kind::Число:
		type = "Число";
		break;
	case Kind::НоваяСтрока:
		type = "НоваяСтрока";
		break;
	case Kind::Деление:
		type = "Деление";
		break;
	case Kind::Умножение:
		type = "Умножение";
		break;
	case Kind::УсловныйЦикл:
		type = "УсловныйЦикл";
		break;
	case Kind::Цикл:
		type = "Цикл";
		break;
	case Kind::Условие:
		type = "Условие";
		break;
	case Kind::Функция:
		type = "Функция";
		break;
	case Kind::Больше:
		type = "Больше";
		break;
	case Kind::Меньше:
		type = "Меньше";
		break;
	default:
		break;
	}
	return "type of object {" + type + "} value of object {" + this->value + "}";
}
