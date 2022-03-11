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
	case Kind::����:
		type = "����";
		break;
	case Kind::�����:
		type = "�����";
		break;
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
		break;
	case Kind::�����:
		type = "�����";
		break;
	case Kind::�����������:
		type = "�����������";
		break;
	case Kind::�������:
		type = "�������";
		break;
	case Kind::���������:
		type = "���������";
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
	case Kind::������:
		type = "������";
		break;
	case Kind::������:
		type = "������";
		break;
	default:
		break;
	}
	return "type of object {" + type + "} value of object {" + this->value + "}";
}
