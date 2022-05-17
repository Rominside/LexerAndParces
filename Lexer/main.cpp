#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "interpreter.h"

#include "RootObject.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	std::string character_stream = "тсмйжхъ\
                                  \n{ \
                                  \n   Б пюбмн 1  \
		                          \n   Ю пюбмн 10 \
		                          \n   А пюбмн 45 \
                                  \n   еякх Б окчя 10 > 0 \
                                  \n   ( \
                                  \n      Ю пюбмн Ю окчя 5 \
                                  \n      А пюбмн 10 слмнфхрэ  [ 2 окчя 4 ] окчя 34 \
                                  \n   ) \
                                  \n   сякнбмшижхйк Ю < А \
                                  \n   ( \
                                  \n      Ю пюбмн Ю окчя 5 \
                                  \n      А пюбмн А лхмся 2 \
                                  \n   ) \
                                  \n}";
	std::cout << character_stream << std::endl;
	Lexer My_lxer;
	My_lxer.Pars_text(character_stream);
	My_lxer.Lexer_analis();
	My_lxer.Get_Token_mass();

	Parser pr;
	//std::cout << My_lxer.get_Begin()->get_name() << std::endl;
	pr.CreateWood(My_lxer.get_Begin());
	RootObject rt = pr.GetRoot();
	pr.DrawTree(rt, "  ");

	std::cout << std::endl;
	for (int i = 0; i < pr.GetRoot().variableMass.size(); i++)
	{
		std::cout << pr.GetRoot().variableMass.at(i)->getString() << "  ";
	}

	std::cout << pr.GetRoot().sonsMass.at(0)->getString() << std::endl;

	interpreter Interpreter(pr);

	Interpreter.ExecuteFunction(pr.GetRoot().sonsMass.at(0), 0);

	std::cout << std::endl;

	for (int i = 0; i < pr.GetRoot().variableMass.size(); i++)
	{
		std::cout << pr.GetRoot().variableMass.at(i)->getString() << "  ";
	}


	return 0;
}