#include <iostream>
#include "Lexer.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	std::string character_stream = "Б пюбмн 1\nЮ пюбмн 10\nА пюбмн 55\nеякх Б > 0\n(\n   Ю пюбмн Ю окчя 5\n)\nсякнбмшижхйк Ю < А\n(\n   Ю пюбмн Ю окчя 5\n   Б пюбмн \n)\n";
	std::cout << character_stream << std::endl;
	Lexer My_lxer;
	My_lxer.Pars_text(character_stream);
	My_lxer.Lexer_analis();
	My_lxer.Get_Token_mass();
	return 0;
}