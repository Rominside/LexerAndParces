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
	case Kind::Ћева€—кобка:
		type = "Ћева€—кобка";
		break;
	case Kind::ѕрава€—кобка:
		type = "ѕрава€—кобка";
		break;
	case Kind::ѕеременна€:
		type = "ѕеременна€";
		break;
	case Kind::„исло:
		type = "„исло";
		isNumber = true;
		break;
	case Kind::Ќова€—трока:
		type = "Ќова€—трока";
		break;
	case Kind::”словный÷икл:
		type = "”словный÷икл";
		break;
	case Kind::÷икл:
		type = "÷икл";
		break;
	case Kind::”словие:
		type = "”словие";
		break;
	case Kind::‘ункци€:
		type = "‘ункци€";
		break;
	case Kind:: онецѕрограммы:
		type = " онецѕрограммы";
		break;
	case Kind::Ћева€‘игурна€—кобка:
		type = "Ћева€‘игурна€—кобка";
		break;
	case Kind::ѕрава€‘игурна€—кобка:
		type = "ѕрава€‘игурна€—кобка";
		break;
	case Kind::Ѕинарныйќператор:
		type = "Ѕинарныйќператор";
		break;
	case Kind::Ћева€ вадратна€—кобка:
		type = "Ћева€ вадратна€—кобка";
		break;
	case Kind::ѕрава€ вадратна€—кобка:
		type = "ѕрава€ вадратна€—кобка";
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


