#include "interpreter.h"

interpreter::interpreter(Parser link_on_tree)
{
	this->link_on_tree = link_on_tree;
}

void interpreter::ExecuteFunction(RootObject* parent, int StartPosition)
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

bool interpreter::ExecuteBoolLine(RootObject* parent)
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

int interpreter::ExecuteValueLine(RootObject* parent)
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

void interpreter::ExecuteIf(RootObject* parent)
{
	//std::cout << "ExecuteIf" << std::endl;
	if (ExecuteBoolLine(parent->sonsMass.at(0)->sonsMass.at(0)) == true)
	{
		ExecuteFunction(parent, 1);
	}
	//std::cout << std::to_string(ExecuteBoolLine(parent->sonsMass.at(0)->sonsMass.at(0))) << std::endl;
}

void interpreter::ExecuteWhile(RootObject* parent)
{
	//std::cout << "ExecuteWhile" << std::endl;
	while (ExecuteBoolLine(parent->sonsMass.at(0)->sonsMass.at(0)) == true)
	{
		ExecuteFunction(parent, 1);
		ExecuteBoolLine(parent->sonsMass.at(0)->sonsMass.at(0));
	}
}