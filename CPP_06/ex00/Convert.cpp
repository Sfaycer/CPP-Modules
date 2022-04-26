#include "Convert.hpp"

Convert::Convert(void)
{
}

Convert::Convert(char *numstr)
{
	this->convert(numstr);
}

Convert::Convert(Convert const &src)
{
	(void)src;
}

Convert::~Convert(void)
{
}

Convert &Convert::operator=(const Convert &src)
{
	(void)src;
	return (*this);
}

void Convert::convert(char *numstr)
{
	std::string str(numstr);
	
	if (str.empty())
		throw Convert::InputError();
	else if (str.size() == 1 && !std::isdigit(str[0]))
		this->isChar(str);
	else if (std::isdigit(str[0]) || (str[0] == '-' && std::isdigit(str[1])))
		this->isNumber(str);
	else if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf"
			|| str == "+inff" || str == "-inff")
		this->isFloatWord(str);
	else
		throw Convert::InputError();
}

void Convert::isChar(std::string str)
{
	std::stringstream s;

	this->num_char = str[0];
	this->num_int = static_cast<int>(this->num_char);
	this->num_float = static_cast<float>(this->num_char);
	this->num_double = static_cast<double>(this->num_char);

	//char
	s << "'" << this->num_char << "'";
	this->str_char = s.str();
	s.str("");

	//int
	s << this->num_int;
	this->str_int = s.str();
	s.str("");
	
	//float
	s << this->num_float << ".0f";
	this->str_float = s.str();
	s.str("");

	//double
	s << this->num_double << ".0";
	this->str_double = s.str();
}

void Convert::isNumber(std::string str)
{
	double test;
	char *end;

	this->toChar(str);
	this->toInt(str);

	test = strtod(str.c_str(), &end);
	if ((end[0] != 0 && end[0] != 'f') ||
		(end[0] == 'f' && end[1] != 0))
		throw Convert::InputError();
	size_t f, comma;

	if ((f = str.find("f")) == std::string::npos)
		f = str.size();
	if ((comma = str.find(".")) == std::string::npos)
		this->precision = 1;
	else
		this->precision = str.substr(comma, f - comma - 1).size();
	if (this->precision == 0)
		this->precision = 1;
	this->toFloat(str);
	this->toDouble(str);
}

void Convert::isFloatWord(std::string str)
{
	std::stringstream s;
	std::string sign;

	this->num_double = strtod(str.c_str(), 0);
	this->num_float = static_cast<float>(this->num_double);

	this->str_char = "impossible";
	this->str_int = "impossible";
	
	if (str[0] == '+')
		sign = "+";
	
	s << sign << this->num_float << "f";
	this->str_float = s.str();
	s.str("");

	s << sign << this->num_double;
	this->str_double = s.str();
}

void Convert::toChar(std::string str)
{
	std::stringstream s;
	char *end;
	long l;

	errno = 0;
	l = strtol(str.c_str(), &end, 10);
	if ((errno == ERANGE && l == LONG_MAX) || l > CHAR_MAX)
	{
		this->str_char = "overflow";
		return ;
	}
	else if ((errno == ERANGE && l == LONG_MIN) || l < CHAR_MIN)
	{
		this->str_char = "underflow";
		return ;
	}

	this->num_char = static_cast<char>(l);
	if (!std::isprint(this->num_char))
		this->str_char = "Non displayable";
	else
	{
		s << "'" << this->num_char << "'";
		this->str_char = s.str();
	}
}

void Convert::toInt(std::string str)
{
	std::stringstream s;
	char *end;
	long l;

	errno = 0;
	l = strtol(str.c_str(), &end, 10);
	if ((errno == ERANGE && l == LONG_MAX) || l > INT_MAX)
	{
		this->str_int = "overflow";
		return ;
	}
	else if ((errno == ERANGE && l == LONG_MIN) || l < INT_MIN)
	{
		this->str_int = "underflow";
		return ;
	}

	this->num_int = static_cast<int>(l);
	s << this->num_int;
	this->str_int = s.str();
}

//Fun fact: FLT_MIN на самом деле минимальное положительное число, которое можно уложить в float
//Потому использую -FLT_MAX для минимального отрицательного
void Convert::toFloat(std::string str)
{
	std::stringstream s;
	char *end;
	double d;

	errno = 0;
	d = strtod(str.c_str(), &end);
	if ((errno == ERANGE && d == HUGE_VAL) || d > FLT_MAX)
	{
		this->str_float = "overflow";
		return ;
	}
	else if ((errno == ERANGE && d == -HUGE_VAL) || d < -FLT_MAX)
	{
		this->str_float = "underflow";
		return ;
	}

	this->num_float = static_cast<float>(d);
	s << std::fixed << std::setprecision(this->precision) << this->num_float << "f";
	this->str_float = s.str();
}

void Convert::toDouble(std::string str)
{
	std::stringstream s;
	char *end;
	double d;

	errno = 0;
	d = strtod(str.c_str(), &end);
	if (errno == ERANGE && d == HUGE_VAL)
	{
		this->str_double = "overflow";
		return ;
	}
	else if (errno == ERANGE && d == -HUGE_VAL)
	{
		this->str_double = "underflow";
		return ;
	}

	this->num_double = d;
	s << std::fixed << std::setprecision(this->precision) << this->num_double;
	this->str_double = s.str();
}

std::string const &Convert::getChar(void) const
{
	return (this->str_char);
}
std::string const &Convert::getInt(void) const
{
	return (this->str_int);
}

std::string const &Convert::getFloat(void) const
{
	return (this->str_float);
}

std::string const &Convert::getDouble(void) const
{
	return (this->str_double);
}

const char *Convert::InputError::what() const throw()
{
	return ("Incorrect input");
}

std::ostream & operator<<(std::ostream &o, Convert const & rhs)
{
	o << "char: " << rhs.getChar() << std::endl;
	o << "int: " << rhs.getInt() << std::endl;
	o << "float: " << rhs.getFloat() << std::endl;
	o << "double: " << rhs.getDouble();
	return (o);
}
