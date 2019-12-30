#include "ipk_arrays.h"

#include <numeric>
#include <cassert>
#include <limits>
#include <algorithm>

namespace ipk_arrays
{
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
}
