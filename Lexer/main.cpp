#include <iostream>
#include "Lexer.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	std::string character_stream = "� ����� 1\n� ����� 10\n� ����� 55\n���� � > 0\n(\n   � ����� � ���� 5\n)\n������������ � < �\n(\n   � ����� � ���� 5\n   � ����� \n)\n";
	std::cout << character_stream << std::endl;
	Lexer My_lxer;
	My_lxer.Pars_text(character_stream);
	My_lxer.Lexer_analis();
	My_lxer.Get_Token_mass();
	return 0;
}