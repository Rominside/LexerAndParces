#pragma once
#include <string>
#include <iostream>

class Token
{
public:
	enum class Kind
	{
		Ѕинарныйќператор,
		ѕеременна€,
		ѕрава€—кобка,
		Ћева€—кобка,
		„исло,
		Ќова€—трока,
		”словие,
		÷икл,
		”словный÷икл,
		‘ункци€,
		 онецѕрограммы,
		Ћева€‘игурна€—кобка,
		ѕрава€‘игурна€—кобка,
		Ћева€ вадратна€—кобка,
		ѕрава€ вадратна€—кобка
	};
	Token(Kind type, int value, std::string name);
	Token(Kind type, std::string name);
	std::string Get_string();
	Token::Kind get_Kind();
	int get_value();
	std::string get_name();
private:
	Kind type;
	int value;
	std::string name;
};
