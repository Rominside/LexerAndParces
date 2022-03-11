#pragma once
#include <iostream>
#include <string>
#include <exception>


class LexerException : public std::exception
{
public:
	LexerException(std::string error);
	std::string what();
private:
	std::string m_error;
};

