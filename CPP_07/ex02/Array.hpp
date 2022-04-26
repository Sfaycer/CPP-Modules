#include <exception>

template < typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		~Array(void);
		Array(Array<T> const &src);
		Array<T> & operator=(Array<T> const &src);

		T & operator[](unsigned int index);
		T const & operator[](unsigned int index) const;
		unsigned int size() const;

		class OutOfBounds : public std::exception
		{
			virtual const char* what() const throw();
		};
	private:
		unsigned int length;
		T *array;
};

template <typename T>
Array<T>::Array(void) : length(0), array(new T[0])
{
}

template <typename T>
Array<T>::Array(unsigned int n) : length(n), array(new T[n])
{
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] this->array;
}

template <typename T>
Array<T>::Array(Array<T> const &src) : length(0), array(0)
{
	*this = src;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &src)
{
	if (this->array)
		this->~Array();
	this->length = src.length;
	this->array = new T[this->length];
	for (unsigned int i = 0; i < this->length; i++)
		this->array[i] = src.array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->length)
		throw Array<T>::OutOfBounds();
	return (this->array[index]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= this->length)
		throw Array<T>::OutOfBounds();
	return (this->array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->length);
}

template <typename T>
const char *Array<T>::OutOfBounds::what() const throw()
{
	return ("Index out of bounds");
}
