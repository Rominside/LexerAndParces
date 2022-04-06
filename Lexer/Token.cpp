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
	case Kind::�����������:
		type = "�����������";
		break;
	case Kind::������������:
		type = "������������";
		break;
	case Kind::����������:
		type = "����������";
		break;
	case Kind::�����:
		type = "�����";
		isNumber = true;
		break;
	case Kind::�����������:
		type = "�����������";
		break;
	case Kind::������������:
		type = "������������";
		break;
	case Kind::����:
		type = "����";
		break;
	case Kind::�������:
		type = "�������";
		break;
	case Kind::�������:
		type = "�������";
		break;
	case Kind::��������������:
		type = "��������������";
		break;
	case Kind::�������������������:
		type = "�������������������";
		break;
	case Kind::��������������������:
		type = "��������������������";
		break;
	case Kind::����������������:
		type = "����������������";
		break;
	case Kind::���������������������:
		type = "���������������������";
		break;
	case Kind::����������������������:
		type = "����������������������";
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


