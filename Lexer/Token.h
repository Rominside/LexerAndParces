#pragma once
#include <string>
#include <iostream>

class Token
{
public:
	enum class Kind
	{
		�����,
		����������,
		������������,
		�����������,
		����,
		�����,
		�����,
		�����������,
		���������,
		�������,
		�������,
		����,
		������������,
		�������,
		������,
		������
	};
	Token(Kind type, std::string value);
	Token(Kind type);
	std::string Get_string();
private:
	Kind type;
	std::string value;
};

