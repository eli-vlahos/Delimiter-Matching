#include <iostream>
#include <cassert>
#include "project_1.hpp"

int main();
void print_program();
bool does_delimiter_match(char del);
bool do_delimiters_nest();

int main() {

	print_program();
	std::cout << does_delimiter_match('(') << std::endl;
	std::cout << does_delimiter_match('[') << std::endl;
	std::cout << does_delimiter_match('{') << std::endl;
	std::cout << do_delimiters_nest() << std::endl;
	return 0;
}
void print_program()
{
	ece150::start_reading_file();

	while (!ece150::at_eof())
	{
		char c = ece150::get_next_character();
		std::cout << c;

	}
	std::cout << std::endl;
}

bool does_delimiter_match(char del)
{
	ece150::start_reading_file();


	int counter1 = 0, counter2 = 0, counterf = 0;
	char closing;
	int sum = 0;

	if (del == '(')
		closing = char(')');
	else if (del == char('{'))
		closing = char('}');
	else
		closing = ']';

	if (del != char(('[')) && del != (char('{')) && del != (char('(')))
		return false;
	else {
		while (!ece150::at_eof())
		{

			char temp = del;
			temp = ece150::get_next_character();
			{
				if (temp == ((del)))
					counter1++;
				else if (temp == ((closing)))
				{
					counter2++;

				}

			}

			if (counter1 < counter2)
			{
				std::cout << "Unmatched " << closing << std::endl;
				counterf++;
				counter2--;
			}

		}
		if (ece150::at_eof())
		{
			if (counter1 > counter2) {
				int sum = counter1 - counter2;
				std::cout << "Missing ";
				counterf++;
				while (sum > 0)
				{
					std::cout << closing;
					sum--;
				}


			}

		}

	}
	std::cout << std::endl;

	if (counterf == 0)
		return true;
	else
		return false;
}

bool do_delimiters_nest()
{
	ece150::start_reading_file();
	ece150::initialize_table();
	int counter = 0;


	while (!ece150::at_eof())
	{
		char right = ece150::get_right_most_character();
		char del = ece150::get_next_character();


		if (del == '[' || del == '(' || del == '{')
		{
			ece150::place_character(del);
		}
		else
		{
			if ((del == char('}') && right == char('{')) || (del == char(')') && right == char('(')) || (del == char(']') && right == char('[')))
				ece150::erase_right_most_character();
			else if (del == '}' || del == ']' || del == ')')
			{
				std::cout << "Unmatched " << del << std::endl;
				counter++;
			}

		}

	}
	if (!ece150::is_table_empty())
	{
		std::cout << "Missing ";

		while (!ece150::is_table_empty())
		{
			if (ece150::get_right_most_character() == '(')
				std::cout << ")";
			else if (ece150::get_right_most_character() == '[')
				std::cout << "]";
			else if (ece150::get_right_most_character() == '{')
				std::cout << "}";

			ece150::erase_right_most_character();
		}
	}
	std::cout << std::endl;

	if (ece150::is_table_empty() && counter == 0)
		return true;
	else
	{
		return false;
	}



}
