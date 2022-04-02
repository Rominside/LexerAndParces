#include <regex>
#include "Lexer.h"


void Lexer::Lexer_analis()
{
	setlocale(LC_ALL, "Russian");
	std::string result;
	std::smatch narrow;
	std::regex regular_s("\s");

	for (int it = 0; it < lexem_mass.size(); it++)
	{
		try
		{
			result = Next_token(lexem_mass.at(it));

			if (result == "РАВНО")
			{
				Token_mass.push_back(Token(Token::Kind::БинарныйОператор, "Равно"));
			}
			if (result == "ПЛЮС")
			{
				Token_mass.push_back(Token(Token::Kind::БинарныйОператор, "Плюс"));
			}
			if (result == "МИНУС")
			{
				Token_mass.push_back(Token(Token::Kind::БинарныйОператор, "Минус"));
			}
			if (result == "(")
			{
				Token_mass.push_back(Token(Token::Kind::ЛеваяСкобка, ""));
			}
			if (result == ")")
			{
				Token_mass.push_back(Token(Token::Kind::ПраваяСкобка, ""));
			}
			if ('0' <= result.at(0) and result.at(0) <= '9')
			{
				Token_mass.push_back(Token(Token::Kind::Число, stoi(result), ""));
			}
			if ('а' <= result.at(0) and result.at(0) <= 'я')
			{
				Token_mass.push_back(Token(Token::Kind::Переменная, 0, result));
			}
			if (result == "\n")
			{
				Token_mass.push_back(Token(Token::Kind::НоваяСтрока, "Строка"));
			}
			if (result == "УМНОЖИТЬ")
			{
				Token_mass.push_back(Token(Token::Kind::БинарныйОператор, "Умножение"));
			}
			if (result == "ПОДЕЛИТЬ")
			{
				Token_mass.push_back(Token(Token::Kind::БинарныйОператор, "Деление"));
			}
			if (result == "ЕСЛИ")
			{
				Token_mass.push_back(Token(Token::Kind::Условие, "Условие"));
			}
			if (result == "ЦИКЛ")
			{
				Token_mass.push_back(Token(Token::Kind::Цикл, ""));
			}
			if (result == "УСЛОВНЫЙЦИКЛ")
			{
				Token_mass.push_back(Token(Token::Kind::УсловныйЦикл, "УсловныйЦикл"));
			}
			if (result == "ФУНКЦИЯ")
			{
				Token_mass.push_back(Token(Token::Kind::Функция, result));
			}
			if (result == "<")
			{
				Token_mass.push_back(Token(Token::Kind::БинарныйОператор, "Меньше"));
			}
			if (result == ">")
			{
				Token_mass.push_back(Token(Token::Kind::БинарныйОператор, "Больше"));
			}
			if (result == "{")
			{
				Token_mass.push_back(Token(Token::Kind::ЛеваяФигурнаяСкобка, ""));
			}
			if (result == "}")
			{
				Token_mass.push_back(Token(Token::Kind::ПраваяФигурнаяСкобка, ""));
			}
			if (result == "[")
			{
				Token_mass.push_back(Token(Token::Kind::ЛеваяКвадратнаяСкобка, "["));
			}
			if (result == "]")
			{
				Token_mass.push_back(Token(Token::Kind::ПраваяКвадратнаяСкобка, "]"));
			}
		}
		catch (LexerException& ex)
		{
			std::cout << ex.what() << std::endl;
			Token_mass.clear();
			break;
		}
	}

	Token_mass.push_back(Token(Token::Kind::КонецПрограммы, ""));
}

std::string Lexer::Next_token(std::string text)
{
	std::smatch result;
	std::smatch result_number;
	std::smatch result_variable;
	std::regex regular("\\]|\\[|\\{|\\}|<|>|ФУНКЦИЯ|УСЛОВНЫЙЦИКЛ|ЦИКЛ|ЕСЛИ|УМНОЖИТЬ|ПОДЕЛИТЬ|\\(|\\)|ПЛЮС|РАВНО|МИНУС|[а-я]+|[0-9]+|\\n");
	std::regex regular_number("[0-9]+");
	std::regex regular_variable("[а-я]+");

	if (!std::regex_match(text, result, regular))
	{
		throw LexerException("{" + text + "} error lexem");
	}

	return result.str();
}

void Lexer::Get_Token_mass()
{
	for (int i = 0; i < Token_mass.size(); i++)
	{
		std::cout << Token_mass.at(i).Get_string() << std::endl;
	}
	std::cout << Token_mass.size() << std::endl;
}

void Lexer::Pars_text(std::string text)
{
	std::string word;
	int k = 0;
	std::vector<std::string> mass_word;
	mass_word.push_back("");
	for (int i = 0; i < text.size(); i++)
	{
		if (text.at(i) != '\n')
		{
			mass_word.at(k).push_back(text.at(i));
		}
		else
		{
			k++;
			mass_word.push_back("");
		}
	}

	for (int it = 0; it < mass_word.size(); it++)
	{
		for (int j = 0; j < mass_word.at(it).size(); j++)
		{
			if (mass_word.at(it).at(j) != ' ' and mass_word.at(it).at(j) != '\t')
			{
				word.push_back(mass_word.at(it).at(j));
			}
			else if (word.size() != 0)
			{
				lexem_mass.push_back(word);
				word.clear();
			}
			if (word.size() != 0 and j == mass_word.at(it).size() - 1)
			{
				lexem_mass.push_back(word);
				word.clear();
			}
		}
		if (it != mass_word.size() - 1)
		{
			lexem_mass.push_back("\n");
		}
	}
}

std::vector<Token>::iterator Lexer::get_Begin()
{
	return this->Token_mass.begin()++;
}
