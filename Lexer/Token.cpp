#include "Token.h"

Token::Token(Kind type, int value, std::string name)
{
	this->type = type;
	this->value = value;
	this->name = name;
}

Token::Token(Kind type, std::string name)
{
	this->type = type;
	this->name = name;
}

std::string Token::Get_string()
{
	std::string type;
	bool isNumber = false;
	switch (this->type)
	{
	case Kind::ЛеваяСкобка:
		type = "ЛеваяСкобка";
		break;
	case Kind::ПраваяСкобка:
		type = "ПраваяСкобка";
		break;
	case Kind::Переменная:
		type = "Переменная";
		break;
	case Kind::Число:
		type = "Число";
		isNumber = true;
		break;
	case Kind::НоваяСтрока:
		type = "НоваяСтрока";
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
	case Kind::КонецПрограммы:
		type = "КонецПрограммы";
		break;
	case Kind::ЛеваяФигурнаяСкобка:
		type = "ЛеваяФигурнаяСкобка";
		break;
	case Kind::ПраваяФигурнаяСкобка:
		type = "ПраваяФигурнаяСкобка";
		break;
	case Kind::БинарныйОператор:
		type = "БинарныйОператор";
		break;
	case Kind::ЛеваяКвадратнаяСкобка:
		type = "ЛеваяКвадратнаяСкобка";
		break;
	case Kind::ПраваяКвадратнаяСкобка:
		type = "ПраваяКвадратнаяСкобка";
		break;
		// LinkedList
	case Kind::LinkedList:
		type = "LinkedList";
		break;
	case Kind::push_first:
		type = "push_first";
		break;
	case Kind::push_back:
		type = "push_back";
		break;
	case Kind::push_in:
		type = "push_in";
		break;
	case Kind::pop_from:
		type = "pop_from";
		break;
	case Kind::find:
		type = "find";
		break;
	case Kind::size:
		type = "size";
		break;
	case Kind::Точка:
		type = "Точка";
		break;
	case Kind::Запятая:
		type = "Запятая";
		break;
	case Kind::LinkedMethod:
		type = "LinkedMethod";
		break;
	default:
		break;
	}
	if (isNumber == true)
	{
		return "type of object {" + type + "} value of object {" + std::to_string(this->value) + "}" + " name of object {" + this->name + "}";
	}
	return "type of object {" + type + "} value of object {" + "}" + " name of object {" + this->name + "}";
}

Token::Kind Token::get_Kind()
{
	return this->type;
}

int Token::get_value()
{
	return this->value;
}

std::string Token::get_name()
{
	return this->name;
}


