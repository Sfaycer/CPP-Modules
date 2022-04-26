#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, const int &num)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), num);

	return (it);
}
