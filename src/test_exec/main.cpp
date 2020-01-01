#include <vector>
#include <iostream>
#include <iterator>

#include <ipk_arrays.h>

int main()
{
	std::vector<int> arr{ 41, 73, 89, 7 ,10 ,1, 59, 58,84, 77, 77, 97, 58, 1 ,86, 58, 26, 10, 86, 51 };

	arr = ipk_arrays::rot_left(arr, 10);

	std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
}