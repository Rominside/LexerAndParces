#pragma once
#include <string>
#include <iostream>

class Token
{
public:
	enum class Kind
	{
		����������������,
		����������,
		������������,
		�����������,
		�����,
		�����������,
		�������,
		����,
		������������,
		�������,
		��������������,
		�������������������,
		��������������������,
		���������������������,
		����������������������
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
