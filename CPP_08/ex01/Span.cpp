#include "Span.hpp"

Span::Span(void) : max(0)
{
}

Span::Span(unsigned int n) : max(n)
{
}

Span::Span(Span const &src) : max(src.max)
{
	this->array = src.array;
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &src)
{
	this->array = src.array;
	this->max = src.max;
	return (*this);
}

void Span::addNumber(int num)
{
	if(this->array.size() >= this->max)
		throw ExeptionalThrow("Out of space");
	this->array.push_back(num);
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	if (std::distance(begin, end) + this->array.size() > this->max)
		throw ExeptionalThrow("Out of space");
	this->array.insert(this->array.end(), begin, end);
}

void Span::addNumber(std::vector<int> const &src)
{
	if (src.size() + this->array.size() > this->max)
		throw ExeptionalThrow("Out of space");
	this->array.insert(this->array.end(), src.begin(), src.end());
}

void Span::addNumber(int from, int to)
{
	if (from < to)
	{
		if ((to - from) + this->array.size() >= this->max)
			throw ExeptionalThrow("Out of space");
		for (int i = from; i <= to; i++)
			this->array.push_back(i);
	}
	else
	{
		if ((from - to) + this->array.size() >= this->max)
			throw ExeptionalThrow("Out of space");
		for (int i = from; i >= to; i--)
			this->array.push_back(i);
	}
}

int Span::shortestSpan(void) const
{
	if (this->array.size() < 2)
		throw ExeptionalThrow("Size < 2");

	int temp = INT_MAX;
	std::vector<int> temp_vec(this->array);

	std::sort(temp_vec.begin(), temp_vec.end());
	for (size_t i = 0; i < temp_vec.size() - 1; i++)
	{
		int dif = temp_vec[i + 1] - temp_vec[i];
		if (dif < temp)
			temp = dif;
	}
	return (temp);
}
int Span::longestSpan(void) const
{
	if (this->array.size() < 2)
		throw ExeptionalThrow("Size < 2");

	int temp;
	temp = *std::max_element(this->array.begin(), this->array.end()) -
		*std::min_element(this->array.begin(), this->array.end());
	return (temp);
}

Span::ExeptionalThrow::ExeptionalThrow(std::string const &message) : std::exception()
{
	this->message = message;
}

Span::ExeptionalThrow::~ExeptionalThrow(void) throw() {}


const char *Span::ExeptionalThrow::what() const throw()
{
	return (message.c_str());
}
