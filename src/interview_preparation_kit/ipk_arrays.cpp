#include "ipk_arrays.h"

#include <numeric>
#include <cassert>
#include <limits>
#include <algorithm>
#include <functional>

namespace ipk_arrays
{
	// https://www.hackerrank.com/challenges/2d-array
	int hourglass_sum(const std::vector<std::vector<int>> arr)
	{
		// as per specification, arr is not empty
		assert(!arr.empty() && "hourglass arr empty");

		// could use some optimization, since we are effectively iterating every hourglass, 
		// possibly cache missing 3 times each hour glass when the arr gets too big (on the y axis)
		const auto specific_hourglass_sum = [&arr](const size_t begin_x, const size_t begin_y) -> int
		{
			const auto top_of_hourglass_begin = arr[begin_y].begin() + begin_x;
			const auto bottom_of_hourglass_begin = arr[begin_y + 2].begin() + begin_x;

			return
				std::accumulate(top_of_hourglass_begin, top_of_hourglass_begin + 3, int{}) +
				arr[begin_y + 1][begin_x + 1] +
				std::accumulate(bottom_of_hourglass_begin, bottom_of_hourglass_begin + 3, int{});
		};

		// values are no lower than -9, hourglass has 7 values in it, so its never gonna get below min of int
		// alternatively, we could init it with first value (0,0);
		int max_value{ std::numeric_limits<int>::min() };

		// as per specification, nested arrays have the same size as top one
		const size_t length = arr.size() - 2;
		for (size_t x = 0; x < length; ++x)
		{
			for (size_t y = 0; y < length; ++y)
			{
				max_value = std::max(max_value, specific_hourglass_sum(x, y));
			}
		}

		return max_value;
	}

	// https://www.hackerrank.com/challenges/ctci-array-left-rotation
	std::vector<int> rot_left(std::vector<int> arr, int offset)
	{
		offset %= arr.size();
		if (arr.empty() || offset == 0)
		{
			return arr;
		}

		// STL, but that would be too easy
		// std::rotate(arr.begin(), arr.begin() + offset, arr.end());
		// return arr;

		const auto get_new_index = [&](const size_t current_index) -> size_t
		{
			long long new_index = current_index - offset;
			if (new_index < 0)
			{
				new_index += arr.size();
			}

			return new_index;
		};

		const std::function<int(int,int)> gcd_func = [&gcd_func](const int a, const int b) -> int
		{
			if (a == b)
			{
				return a;
			}

			if (a > b)
			{
				return gcd_func(a - b, b);
			}

			return gcd_func(a, b - a);
		};		

		const size_t gcd = static_cast<size_t>(gcd_func(arr.size(), offset));
		for (size_t i = 0; i < gcd; ++i)
		{
			size_t current_index{ i };
			int temp{ arr[current_index] };
			do
			{
				// todo, optimize the temp (since we are using two temps)?
				const auto new_index = get_new_index(current_index);
				int new_temp = arr[new_index];
				arr[new_index] = temp;

				current_index = new_index;
				temp = new_temp;

			} while (current_index != i);
		}

		return arr;
	}
}
