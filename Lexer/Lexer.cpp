#include <regex>
#include "Lexer.h"


void Lexer::Lexer_analis()
{
	setlocale(LC_ALL, "Russian");
	std::string result;
	std::smatch narrow;
	std::regex regular_s("\s");
	//
	std::vector<std::string> fun1;
	std::vector<std::string> fun2;
	for (int i = 0; i < lexem_mass.size(); i++)
	{
		fun1 = Next_tokens(lexem_mass.at(i));
		for (int j = 0; j < fun1.size(); j++)
		{
			fun2.push_back(fun1.at(j));
		}
	}
	//

	for (int it = 0; it < fun2.size(); it++)
	{
		try
		{
			result = Next_token(fun2.at(it));

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
			// LinkedList
			if (result == ".")
			{
				Token_mass.push_back(Token(Token::Kind::Точка, "."));
			}
			if (result == ",")
			{
				Token_mass.push_back(Token(Token::Kind::Запятая, ","));
			}
			if (result == "List")
			{
				Token_mass.push_back(Token(Token::Kind::LinkedList, "LinkedList"));
			}
			if (result == "push_first")
			{
				Token_mass.push_back(Token(Token::Kind::LinkedMethod, "push_first"));
			}
			if (result == "push_back")
			{
				Token_mass.push_back(Token(Token::Kind::LinkedMethod, "push_back"));
			}
			if (result == "push_in")
			{
				Token_mass.push_back(Token(Token::Kind::LinkedMethod, "push_in"));
			}
			if (result == "pop_from")
			{
				Token_mass.push_back(Token(Token::Kind::LinkedMethod, "pop_from"));
			}
			if (result == "find")
			{
				Token_mass.push_back(Token(Token::Kind::LinkedMethod, "find"));
			}
			if (result == "size")
			{
				Token_mass.push_back(Token(Token::Kind::LinkedMethod, "size"));
			}
			// LinkedList
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

std::vector<std::string> Lexer::Next_tokens(std::string words)
{
	std::smatch result;
	std::smatch result_number;
	std::smatch result_variable;
	std::regex regular("\\]|\\[|\\{|\\}|<|>|ФУНКЦИЯ|УСЛОВНЫЙЦИКЛ|ЦИКЛ|ЕСЛИ|УМНОЖИТЬ|ПОДЕЛИТЬ|\\(|\\)|ПЛЮС|РАВНО|МИНУС|[а-я]+|[0-9]+|\\n");
	std::regex regular_number("[0-9]+");
	std::regex regular_variable("[а-я]+");
	// LinkedList
	std::regex regular_LinkedList("\\,|\\.|List|push_first|push_back|push_in|pop_from|find|size");
	// LinkedList   token.push_back(text[i]);

	int k = 0;
	std::vector<std::string> mass_token;
	std::string token;
	std::string cope_text = words;
	bool direction = true;
	std::string word;
	while (cope_text.size() != 0)
	{
		word.push_back(cope_text[0]);
		//std::cout << word << std::endl;
		//token.push_back(text[i]);
		if (std::regex_match(word, result, regular) || std::regex_match(word, result, regular_LinkedList))
		{
			//std::cout << word << "if bloc" << std::endl;
			do
			{
				//std::cout << word << std::endl;			
				token.push_back(cope_text[k]);
				k = k + 1;
				if (k == cope_text.size())
					break;
				word.clear();
				//std::cout << word << std::endl;
				word.push_back(cope_text[k]);
			} while ((std::regex_match(token, result, regular) || std::regex_match(token, result, regular_LinkedList)) &&
				    (std::regex_match(word, result, regular) || std::regex_match(word, result, regular_LinkedList)));

			if ((std::regex_match(word, result, regular) || std::regex_match(word, result, regular_LinkedList)) &&
				(!std::regex_match(token, result, regular) && !std::regex_match(token, result, regular_LinkedList)))
			{
				if (k > 1)
				{
					/*if (word == ".")
					{
						token.pop_back();
						k = k - 1;
					}*/
					token.pop_back();
					k = k - 1;
				}
			}
			
			//std::cout << token << std::endl;
			//std::cout << words.size() << std::endl;
			mass_token.push_back(token);
		}
		else
		{
			//std::cout << word << std::endl;
			while (!std::regex_match(word, result, regular) && !std::regex_match(word, result, regular_LinkedList))
			{
				//std::cout << word << "else block" << std::endl;
				token.push_back(cope_text[k]);
				k++;
				word.clear();
				if (k == cope_text.size())
					break;
				word.push_back(cope_text[k]);
				//std::cout << token << "fff" << std::endl;
			}
			//token.pop_back();
			//std::cout << token << std::endl;
			//std::cout << token.size() << std::endl;
			//std::cout << words.size() << std::endl;
			if (std::regex_match(token, result, regular) || std::regex_match(token, result, regular_LinkedList))
			{
				mass_token.push_back(token);
			}
			else
			{
				std::cout << "chto to ne tak" << std::endl;
				throw LexerException("{" + cope_text + "} error lexem");
			}
		}

		cope_text.erase(0, k);
		//std::cout << cope_text << std::endl;
		//std::cout << "next" << std::endl;
		k = 0;
		token.clear();
		word.clear();
	}

	return mass_token;
}

std::string Lexer::Next_token(std::string text)
{
	std::smatch result;
	std::smatch result_number;
	std::smatch result_variable;
	std::regex regular("\\]|\\[|\\{|\\}|<|>|ФУНКЦИЯ|УСЛОВНЫЙЦИКЛ|ЦИКЛ|ЕСЛИ|УМНОЖИТЬ|ПОДЕЛИТЬ|\\(|\\)|ПЛЮС|РАВНО|МИНУС|[а-я]+|[0-9]+|\\n");
	std::regex regular_number("[0-9]+");
	std::regex regular_variable("[а-я]+");
	// LinkedList
	std::regex regular_LinkedList("\\,|\\.|List|push_first|push_back|push_in|pop_from|find|size");
	// LinkedList   token.push_back(text[i]);

	//int k = 0;
	//std::vector<std::string> mass_token;
	//std::string token;
	//std::string cope_text = text;
	//bool direction = true;
	//std::string word;
	//while (cope_text.size() != 0)
	//{
	//	word.push_back(cope_text[0]);
	//	std::cout << word << std::endl;
	//	//token.push_back(text[i]);
	//	if (std::regex_match(word, result, regular) || std::regex_match(word, result, regular_LinkedList))
	//	{
	//		std::cout << word << "if bloc" << std::endl;
	//		while (std::regex_match(word, result, regular) || std::regex_match(word, result, regular_LinkedList))
	//		{
	//			std::cout << word << std::endl;
	//			token.push_back(cope_text[k]);
	//			k = k + 1;
	//			word.clear();
	//			std::cout << word << std::endl;
	//			word.push_back(cope_text[k]);
	//		}
	//		mass_token.push_back(token);
	//	}
	//	else
	//	{
	//		std::cout << word << std::endl;
	//		while (!std::regex_match(word, result, regular) && !std::regex_match(word, result, regular_LinkedList))
	//		{
	//			std::cout << word << "else block" << std::endl;
	//			token.push_back(cope_text[k]);
	//			k++;
	//			word.clear();
	//			if (k > cope_text.size())
	//				break;
	//			word.push_back(cope_text[k]);
	//			std::cout << token << "fff" << std::endl;
	//		}
	//		token.pop_back();
	//		std::cout << token.size() << std::endl;
	//		std::cout << text.size() << std::endl;
	//		if (std::regex_match(token, result, regular) || std::regex_match(token, result, regular_LinkedList))
	//		{
	//			mass_token.push_back(token);
	//		}
	//		else
	//		{
	//			std::cout << "chto to ne tak" << std::endl;
	//			throw LexerException("{" + cope_text + "} error lexem");
	//		}
	//	}

	//	cope_text.erase(0, k);
	//	std::cout << cope_text << std::endl;
	//	std::cout << "next" << std::endl;
	//	k = 0;
	//	//if (std::regex_match(word, result, regular) || std::regex_match(word, result, regular_LinkedList))
	//	//{
	//	//	direction = true;
	//	//}
	//	//else
	//	//{
	//	//	direction = false;
	//	//}

	//	token.clear();
	//	word.clear();
	//}
	//for (int i = 0; i < mass_token.size(); i++)
	//	std::cout << mass_token[i] << std::endl;

	if (!std::regex_match(text, result, regular))
	{
		if (!std::regex_match(text, result, regular_LinkedList))
		{
			throw LexerException("{" + text + "} error lexem");
		}
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

// List a = [5, 6, 19]
// a.push_first(b) => a = [b, 5, 6, 19]