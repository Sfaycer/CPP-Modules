#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	this->_tree = 
"          .     .  .      +     .      .          .\n"
"     .       .      .     #       .           .\n"
"        .      .         ###            .      .      .\n"
"      .      .   \"#:. .:##\"##:. .:#\"  .      .\n"
"          .      . \"####\"###\"####\"  .\n"
"       .     \"#:.    .:#\"###\"#:.    .:#\"  .        .       .\n"
"  .             \"#########\"#########\"        .        .\n"
"        .    \"#:.  \"####\"###\"####\"  .:#\"   .       .\n"
"     .     .  \"#######\"\"##\"##\"\"#######\"                  .\n"
"                .\"##\"#####\"#####\"##\"           .      .\n"
"    .   \"#:. ...  .:##\"###\"###\"##:.  ... .:#\"     .\n"
"      .     \"#######\"##\"#####\"##\"#######\"      .     .\n"
"    .    .     \"#####\"\"#######\"\"#####\"    .      .\n"
"            .     \"      000      \"    .     .\n"
"       .         .   .   000     .        .       .\n"
".. .. ..................O000O........................ ......\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->_target = src._target;
	this->_tree = src._tree;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);

	std::ofstream out(this->_target + "_shrubbery", std::fstream::trunc);
	if (!out.is_open())
		throw ShrubberyCreationForm::FileStreamException();
	out << this->_tree;
	out.close();
}

const char* ShrubberyCreationForm::FileStreamException::what() const throw()
{
	return (std::strerror(errno));
}

Form *ShrubberyCreationForm::newForm(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}
