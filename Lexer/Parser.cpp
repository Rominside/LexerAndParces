#include "Parser.h"
#include <typeinfo>


Parser::Parser()
{
	this->root.setName("root");
}

void Parser::CreateWood(std::vector<Token>::iterator programStart)
{
	try
	{
		//std::cout << "create tree" << std::endl;
		SimpleBranch(&this->root, programStart, Token::Kind::Функция, Token::Kind::КонецПрограммы, true);
	}
	catch (LexerException& ex)
	{
		std::cout << ex.whatPars() << std::endl;
		return;
	}
}

std::vector<Token>::iterator Parser::SimpleBranch(RootObject* parentObject, std::vector<Token>::iterator functionStart,
	Token::Kind childType, Token::Kind endOfSearch, bool typeNextIteration)
{

	std::vector<Token>::iterator peekNextToken = functionStart;
	while (peekNextToken->get_Kind() != endOfSearch)
	{
		//std::cout << "create Simple" << std::endl;

		if (functionStart->get_Kind() == childType)
		{
			if (childType == Token::Kind::Функция)
			{
				//this->currentLine++;
				std::vector<Token>::iterator nextToken = functionStart + 1;
				//std::cout << nextToken->Get_string() << std::endl;

				if (nextToken->get_Kind() != Token::Kind::НоваяСтрока)
				{
					throw LexerException("semantic error", this->currentLine);
					//std::cout << "semantic error" + std::to_string(this->currentLine) << std::endl;
				}

				Function* function = new Function(functionStart->get_name());
				parentObject->AddSon(function);
				function->AddParent(parentObject);
				//std::cout << "create funk" << std::endl;

				functionStart = functionStart + 2;
				this->currentLine += 1;
				try
				{
					functionStart = SimpleBranch(function, functionStart, Token::Kind::НоваяСтрока,
						Token::Kind::ПраваяФигурнаяСкобка, true);
				}
				catch (LexerException& ex)
				{
					std::cout << ex.whatPars() << std::endl;
					return nextToken;
				}
			}

			if (childType == Token::Kind::НоваяСтрока)
			{
				//this->currentLine++;
				std::vector<Token>::iterator nextToken = functionStart + 1;
				if (nextToken->get_Kind() != Token::Kind::Переменная && nextToken->get_Kind() != Token::Kind::Условие &&
					nextToken->get_Kind() != Token::Kind::УсловныйЦикл && nextToken->get_Kind() != Token::Kind::Цикл)
				{
					throw LexerException("semantic error", this->currentLine);
				}

				if (nextToken->get_Kind() == Token::Kind::Переменная)
				{
					Line* line = new Line(functionStart->get_name());
					parentObject->AddSon(line);
					line->AddParent(parentObject);
					this->currentLine += 1;
					//std::cout << "create line" << std::endl;

					try
					{
						functionStart = BinaryBranch(line, functionStart, Token::Kind::БинарныйОператор,
							Token::Kind::БинарныйОператор);
					}
					catch (LexerException& ex)
					{
						std::cout << ex.whatPars() << std::endl;
						return nextToken;
					}
				}
				if (nextToken->get_Kind() == Token::Kind::Условие)
				{
					Condition* condition = new Condition(nextToken->get_name());
					parentObject->AddSon(condition);
					condition->AddParent(parentObject);
					this->currentLine += 1;

					try
					{
						functionStart = ConditionalBranch(condition, functionStart, Token::Kind::НоваяСтрока,
							Token::Kind::ПраваяСкобка, false);
					}
					catch (LexerException& ex)
					{
						std::cout << ex.whatPars() << std::endl;
						return nextToken;
					}
				}
				if (nextToken->get_Kind() == Token::Kind::УсловныйЦикл)
				{
					While* whilee = new While(nextToken->get_name());
					parentObject->AddSon(whilee);
					whilee->AddParent(parentObject);
					this->currentLine += 1;

					try
					{
						functionStart = ConditionalBranch(whilee, functionStart, Token::Kind::НоваяСтрока,
							Token::Kind::ПраваяСкобка, false);
					}
					catch (LexerException& ex)
					{
						std::cout << ex.whatPars() << std::endl;
						return nextToken;
					}
				}
			}
		}
		/*std::cout << functionStart->Get_string() << std::endl;
		if (typeNextIteration == false) { std::cout << "eto iz cond" << std::endl; }
		if (parentObject->getString() == "root") { std::cout << "eto iz root" << std::endl; }*/

		functionStart = functionStart + 1;
		peekNextToken = functionStart + 1;
		//this->currentLine += 1;
	}
	return functionStart;
}

std::vector<Token>::iterator Parser::BinaryBranch(RootObject* parentObject, std::vector<Token>::iterator lineStart,
	Token::Kind childType, Token::Kind endOfSearch)
{
	//std::cout << "create Bin" << std::endl;
	std::vector<Token>::iterator nextToken = lineStart + 1;
	std::vector<Token>::iterator doubleNext = nextToken + 1;
	if (childType == Token::Kind::БинарныйОператор)
	{
		/*std::vector<Token>::iterator nextToken = lineStart + 1;
		std::vector<Token>::iterator doubleNext = nextToken + 1;*/
		// || doubleNext->get_name() != "Равно"
		if (doubleNext->get_Kind() != Token::Kind::БинарныйОператор)
		{
			throw LexerException("semantic error", this->currentLine);
		}

		/*Formula* formula = new Formula(doubleNext->get_name(), 4);
		parentObject->AddSon(formula);
		formula->AddParent(parentObject);*/

		try
		{
			BinaryBranch(parentObject, doubleNext, Token::Kind::Переменная,
				Token::Kind::БинарныйОператор);
		}
		catch (LexerException& ex)
		{
			std::cout << ex.whatPars() << std::endl;
			return doubleNext;
		}
	}

	if (childType == Token::Kind::Переменная)
	{
		/////*std::vector<Token>::iterator nextToken = lineStart + 1;*/
		////std::vector<Token>::iterator previousToken = lineStart - 1;
		/////*std::vector<Token>::iterator doubleNext = nextToken + 1;*/
		//if ((previousToken->get_Kind() != Token::Kind::Переменная && previousToken->get_Kind() != Token::Kind::Число) ||
		//	(nextToken->get_Kind() != Token::Kind::Переменная && nextToken->get_Kind() != Token::Kind::Число))
		//{
		//	throw LexerException("semantic error", this->currentLine);
		//}
		//if (doubleNext->get_Kind() != Token::Kind::НоваяСтрока && doubleNext->get_Kind() != Token::Kind::БинарныйОператор)
		//{
		//	throw LexerException("semantic error", this->currentLine);
		//}

		//if (doubleNext->get_Kind() != Token::Kind::НоваяСтрока)
		//{
		//	Formula* formula = new Formula(doubleNext->get_name(), 4);
		//	parentObject->AddSon(formula);
		//	formula->AddParent(parentObject);
		//	try
		//	{
		//		BinaryBranch(formula, doubleNext, Token::Kind::Переменная,
		//			Token::Kind::БинарныйОператор);
		//	}
		//	catch (LexerException &ex)
		//	{
		//		std::cout << ex.whatPars() << std::endl;
		//		return doubleNext;
		//	}
		//}
		//else
		//{
		//	Variable* variable = new Variable(nextToken->get_name(), nextToken->get_value());
		//	parentObject->AddSon(variable);
		//	variable->AddParent(parentObject);
		//}

		std::vector<Token>::iterator previousToken = lineStart - 1;
		/*Variable* variable = new Variable(previousToken->get_name(), previousToken->get_value());
		parentObject->AddSon(variable);
		variable->AddParent(parentObject);*/
		doubleNext = FormulaTree(parentObject, previousToken) + 2;

	}

	return doubleNext;
}

std::vector<Token>::iterator Parser::ConditionalBranch(RootObject* parentObject, std::vector<Token>::iterator functionStart,
	Token::Kind childType, Token::Kind endOfSearch, bool typeNextIteration)
{
	//std::cout << "create Cond" << std::endl;

	std::vector<Token>::iterator nextToken = functionStart + 1;
	std::vector<Token>::iterator doubleNext = nextToken + 1;
	if (doubleNext->get_Kind() != Token::Kind::Переменная)
	{
		throw LexerException("semantic error", this->currentLine);
	}

	Line* firstLine = new Line(functionStart->get_name());
	parentObject->AddSon(firstLine);
	firstLine->AddParent(parentObject);
	try
	{
		BinaryBranch(firstLine, nextToken, Token::Kind::БинарныйОператор,
			Token::Kind::КонецПрограммы);
	}
	catch (LexerException& ex)
	{
		std::cout << ex.whatPars() << std::endl;
		return nextToken;
	}

	//std::cout << nextToken->Get_string() << std::endl;
	while (nextToken->get_Kind() != Token::Kind::НоваяСтрока)
	{
		nextToken += 1;
	}

	nextToken += 2;
	this->currentLine += 1;
	//std::cout << nextToken->Get_string() << std::endl;
	try
	{
		nextToken = SimpleBranch(parentObject, nextToken, childType, endOfSearch, typeNextIteration);
	}
	catch (LexerException& ex)
	{
		std::cout << ex.whatPars() << std::endl;
		return nextToken;
	}

	this->currentLine += 1;
	return nextToken;
}

std::vector<Token>::iterator Parser::FormulaTree(RootObject* parentObject, std::vector<Token>::iterator lineStart)
{
	std::vector<RootObject*> OperandStack;
	std::vector<RootObject*> OperatorStack;

	while (lineStart->get_Kind() != Token::Kind::НоваяСтрока)
	{
		if (lineStart->get_Kind() == Token::Kind::Переменная || lineStart->get_Kind() == Token::Kind::Число)
		{
			bool alredyExists = false;
			for (int i = 0; i < this->root.variableMass.size(); i++)
			{
				if (this->root.variableMass.at(i)->getName() == lineStart->get_name() && this->root.variableMass.at(i)->getName() != "")
				{
					alredyExists = true;
					OperandStack.push_back(root.variableMass.at(i));
					break;
				}
			}
			if (alredyExists == false)
			{
				Variable* variable = new Variable(lineStart->get_value(), lineStart->get_name());
				OperandStack.push_back(variable);
				this->root.variableMass.push_back(variable);
			}

		}
		else
			if (lineStart->get_Kind() == Token::Kind::БинарныйОператор)
			{
				int operationPriority = 0;
				if (lineStart->get_name() == "Равно" || lineStart->get_name() == "Меньше" || lineStart->get_name() == "Больше")
				{
					operationPriority = 0;
				}
				if (lineStart->get_name() == "Плюс" || lineStart->get_name() == "Минус")
				{
					operationPriority = 1;
				}
				if (lineStart->get_name() == "Умножение" || lineStart->get_name() == "Деление")
				{
					operationPriority = 2;
				}

				Formula* formula = new Formula(lineStart->get_name(), operationPriority);
				//std::cout << OperatorStack.back()->GetOperationPriority() << OperatorStack.back()->getString() << std::endl;
				if (OperatorStack.size() != 0)
				{
					while (OperatorStack.back()->GetOperationPriority() > formula->GetOperationPriority() &&
						OperatorStack.back()->GetOperationPriority() >= 0)
					{
						OperandStack.back()->AddParent(OperatorStack.back());
						OperatorStack.back()->AddSon(OperandStack.back());
						OperandStack.pop_back();

						OperandStack.back()->AddParent(OperatorStack.back());
						OperatorStack.back()->AddSon(OperandStack.back());
						OperandStack.pop_back();

						OperandStack.push_back(OperatorStack.back());
						OperatorStack.pop_back();

						if (OperatorStack.size() == 0)
						{
							break;
						}
					}
					OperatorStack.push_back(formula);
				}
				else
				{
					OperatorStack.push_back(formula);
				}

			}
			else
				if (lineStart->get_Kind() == Token::Kind::ЛеваяКвадратнаяСкобка ||
					lineStart->get_Kind() == Token::Kind::ПраваяКвадратнаяСкобка)
				{
					if (lineStart->get_Kind() == Token::Kind::ЛеваяКвадратнаяСкобка)
					{
						Formula* formula = new Formula(lineStart->get_name(), -1);
						OperatorStack.push_back(formula);
					}
					else
					{
						while (OperatorStack.back()->GetOperationPriority() != -1)
						{
							OperandStack.back()->AddParent(OperatorStack.back());
							OperatorStack.back()->AddSon(OperandStack.back());
							OperandStack.pop_back();

							OperandStack.back()->AddParent(OperatorStack.back());
							OperatorStack.back()->AddSon(OperandStack.back());
							OperandStack.pop_back();

							OperandStack.push_back(OperatorStack.back());
							OperatorStack.pop_back();
						}
						OperatorStack.pop_back();
					}
				}
				else
				{
					throw LexerException("semantic error", this->currentLine);
				}

		lineStart += 1;
	}
	if (OperandStack.size() != OperatorStack.size() + 1)
	{
		throw LexerException("semantic error", this->currentLine);
	}

	parentObject->AddSon(OperatorStack[0]);
	OperatorStack[0]->AddParent(parentObject);
	while (OperatorStack.size() != 0)
	{
		OperandStack.back()->AddParent(OperatorStack.back());
		OperatorStack.back()->AddSon(OperandStack.back());
		OperandStack.pop_back();

		OperandStack.back()->AddParent(OperatorStack.back());
		OperatorStack.back()->AddSon(OperandStack.back());
		OperandStack.pop_back();

		OperandStack.push_back(OperatorStack.back());
		OperatorStack.pop_back();
	}

	return lineStart;
}

void Parser::DrawTree(RootObject root, std::string ot)
{
	std::string indent = "   ";
	RootObject* parent = root.getParent();
	while (parent != nullptr)
	{
		parent = parent->getParent();
		std::cout << indent;
	}
	if (root.getName() != "")
	{
		std::cout << root.getName();
	}
	else
	{
		std::cout << root.getValue();
	}
	for (int i = 0; i < root.sonsMass.size(); i++)
	{
		std::cout << std::endl;
		DrawTree(*root.sonsMass.at(i), ot);
	}
}

RootObject Parser::GetRoot()
{
	return this->root;
}


void Parser::ExecuteFunction(RootObject* parent, int StartPosition)
{
	//std::cout << "ExecuteFunction" << std::endl;
	for (int i = StartPosition; i < parent->sonsMass.size(); i++)
	{
		if (parent->sonsMass.at(i)->getName() == "Строка")
		{
			ExecuteValueLine(parent->sonsMass.at(i)->sonsMass.at(0));
		}
		if (parent->sonsMass.at(i)->getName() == "УсловныйЦикл")
		{
			ExecuteWhile(parent->sonsMass.at(i));
		}
		if (parent->sonsMass.at(i)->getName() == "Условие")
		{
			ExecuteIf(parent->sonsMass.at(i));
		}
	}
}

bool Parser::ExecuteBoolLine(RootObject* parent)
{
	//std::cout << "ExecuteBoolLine" << std::endl;
	int firstOperand = ExecuteValueLine(parent->sonsMass.at(1));
	int secondOperand = ExecuteValueLine(parent->sonsMass.at(0));
	//std::cout << firstOperand << std::endl;
	//std::cout << secondOperand << std::endl;

	if (parent->getName() == "Больше")
	{
		if (firstOperand > secondOperand)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (parent->getName() == "Равно")
	{
		if (firstOperand == secondOperand)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if (parent->getName() == "Меньше")
	{
		if (firstOperand < secondOperand)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	return false;
}

int Parser::ExecuteValueLine(RootObject* parent)
{
	//std::cout << "ExecuteValueLine" << std::endl;
	/*std::cout << parent->getString() << std::endl;*/
	/*std::cout << typeid(*parent).name() << std::endl;*/
	if (parent->getName() == "Равно" || parent->getName() == "Плюс" || parent->getName() == "Минус" ||
		parent->getName() == "Умножение" || parent->getName() == "Деление")
	{
		if (parent->getName() == "Равно")
		{
			if (parent->sonsMass.at(0)->getName() == "Плюс")
			{
				parent->sonsMass.at(1)->setValue(ExecuteValueLine(parent->sonsMass.at(0)));
			}
			else if (parent->sonsMass.at(0)->getName() == "Умножение")
			{
				parent->sonsMass.at(1)->setValue(ExecuteValueLine(parent->sonsMass.at(0)));
			}
			else if (parent->sonsMass.at(0)->getName() == "Минус")
			{
				parent->sonsMass.at(1)->setValue(ExecuteValueLine(parent->sonsMass.at(0)));
			}
			else
			{
				parent->sonsMass.at(1)->setValue(parent->sonsMass.at(0)->getValue());
			}
			//parent->sonsMass.at(1)->setValue(parent->sonsMass.at(0)->getValue());
			/*std::cout << parent->sonsMass.at(1)->getName() << std::endl;
			std::cout << parent->sonsMass.at(1)->getValue() << std::endl;
			std::cout << parent->sonsMass.at(0)->getValue() << std::endl;*/
			return parent->sonsMass.at(1)->getValue();
		}
		if (parent->getName() == "Плюс")
		{
			return ExecuteValueLine(parent->sonsMass.at(0)) + ExecuteValueLine(parent->sonsMass.at(1));
		}
		if (parent->getName() == "Минус")
		{
			int t = ExecuteValueLine(parent->sonsMass.at(1)) - ExecuteValueLine(parent->sonsMass.at(0));
			//std::cout << t << std::endl;
			return t;
		}
		if (parent->getName() == "Умножение")
		{
			return ExecuteValueLine(parent->sonsMass.at(0)) * ExecuteValueLine(parent->sonsMass.at(1));
		}
		if (parent->getName() == "Деление")
		{
			return ExecuteValueLine(parent->sonsMass.at(1)) + ExecuteValueLine(parent->sonsMass.at(0));
		}
	}
	else
	{
		return parent->getValue();
	}

	return 0;
}

void Parser::ExecuteIf(RootObject* parent)
{
	//std::cout << "ExecuteIf" << std::endl;
	if (ExecuteBoolLine(parent->sonsMass.at(0)->sonsMass.at(0)) == true)
	{
		ExecuteFunction(parent, 1);
	}
	//std::cout << std::to_string(ExecuteBoolLine(parent->sonsMass.at(0)->sonsMass.at(0))) << std::endl;
}

void Parser::ExecuteWhile(RootObject* parent)
{
	//std::cout << "ExecuteWhile" << std::endl;
	while (ExecuteBoolLine(parent->sonsMass.at(0)->sonsMass.at(0)) == true)
	{
		ExecuteFunction(parent, 1);
		ExecuteBoolLine(parent->sonsMass.at(0)->sonsMass.at(0));
	}
}