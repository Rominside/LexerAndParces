#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "interpreter.h"

#include "RootObject.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	std::string character_stream = "�������\
                                  \n{ \
                                  \n   � ����� 1  \
		                          \n   � ����� 10 \
		                          \n   � ����� 45 \
                                  \n   ���� � ���� 10 > 0 \
                                  \n   ( \
                                  \n      � ����� � ���� 5 \
                                  \n      � ����� 10 ��������  [ 2 ���� 4 ] ���� 34 \
                                  \n   ) \
                                  \n   ������������ � < � \
                                  \n   ( \
                                  \n      � ����� � ���� 5 \
                                  \n      � ����� � ����� 2 \
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