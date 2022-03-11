#include "LexerExecpions.h"


LexerException::LexerException(std::string error)
{
	this->m_error = error;
}

std::string LexerException::what()
{
	return this->m_error.c_str();
}