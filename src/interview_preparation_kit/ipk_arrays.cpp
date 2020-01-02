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

		const size_t gcd = gcd_func(static_cast<int>(arr.size()), offset);
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

	// https://www.hackerrank.com/challenges/minimum-swaps-2
	// optimized toward speed, will hug twice as memory as opposed to no cache one
	int minimum_swaps(std::vector<int> arr)
	{
		if (arr.empty())
		{
			return 0;
		}

		int min_swaps{};
		
		auto sorted_cache{ arr };
		std::sort(sorted_cache.begin(), sorted_cache.end());

		size_t last_unsorted_index{ arr.size() - 1 };
		while (last_unsorted_index > 0)
		{
			size_t max_element_index{ 0 };
			size_t back_index{ last_unsorted_index };
			for (int i = 0; i <= last_unsorted_index; ++i)
			{
				if (sorted_cache[last_unsorted_index] == arr[i])
				{
					max_element_index = i;
					break;
				}
				else if (sorted_cache[last_unsorted_index] == arr[back_index])
				{
					// Gotta deal with ascendingly sorted arrays (to meet hackerrank speed requirement)
					max_element_index = back_index;
					break;
				}

				--back_index;
			}

			if (max_element_index != last_unsorted_index)
			{
				std::swap(arr[max_element_index], arr[last_unsorted_index]);
				++min_swaps;
			}

			--last_unsorted_index;
		}

		return min_swaps;
	}

	// https://www.hackerrank.com/challenges/minimum-swaps-2
	/* No sorted cache version, but didn't meet speed requirement for already sorted input */
	// Todo, there is probably a way to optimize it even more, without using big ass cache
	int minimum_swaps_no_cache(std::vector<int> arr)
	{
		if (arr.empty())
		{
			return 0;
		}

		int min_swaps{};

		size_t last_sorted_index{};
		size_t last_unsorted_index{ arr.size() - 1 };
		while (last_unsorted_index > 0)
		{
			size_t max_element_index{ 0 };
			for (int i = 0; i <= last_unsorted_index; ++i)
			{
				if (arr[max_element_index] < arr[i])
				{
					max_element_index = i;

					// found max possible value
					if (last_sorted_index > 0 && arr[last_sorted_index] - 1 <= arr[max_element_index])
					{
						break;
					}
				}
			}

			if (max_element_index != last_unsorted_index)
			{
				std::swap(arr[max_element_index], arr[last_unsorted_index]);
				++min_swaps;
			}

			last_sorted_index = last_unsorted_index--;
		}

		return min_swaps;
	}

	// https://www.hackerrank.com/challenges/new-year-chaos
	int minimum_bribes(std::vector<int> queue)
	{
		constexpr int too_chaotic{ -1 };
		constexpr int max_bribes{ 2 };

		// Todo, is there a {quick} way to do this without an additional array?
		std::vector<int> initial_queue{};
		initial_queue.reserve(queue.size());
		for (int i = 0; i < queue.size(); ++i)
		{
			initial_queue.push_back(i + 1);
		}

		int min_bribes{};
		for (size_t i = 0; i < queue.size(); ++i)
		{
			if (initial_queue[i] == queue[i])
			{
				continue;
			}

			const auto result_it = std::find(initial_queue.begin() + i, initial_queue.end(), queue[i]);
			if (result_it == initial_queue.end())
			{
				throw std::runtime_error{ "Didn't find expected value" };
			}

			size_t found_index = std::distance(initial_queue.begin(), result_it);
			for (size_t bribe = 0; bribe < max_bribes; ++bribe)
			{
				if (initial_queue[i] == queue[i])
				{
					break;
				}

				std::swap(initial_queue[found_index], initial_queue[found_index - 1]);
				--found_index;
				++min_bribes;
			}

			if (initial_queue[i] != queue[i])
			{
				return too_chaotic;
			}
		}

		return min_bribes;
	}

	// https://www.hackerrank.com/challenges/crush
	long long array_manipulation(const int n, const std::vector<std::vector<int>> queries)
	{
		if (n == 0)
		{
			return {};
		}

		const long long cache_chunk{ std::max(1, static_cast<int>(n*0.0005)) };
		std::vector<long long> values(n, 0);
		if (cache_chunk > 1)
		{
			std::vector<long long> cache(n / cache_chunk + 1, 0);
			for (const auto& query : queries)
			{

				const long long query_min = query[0] - 1; // 502
				const long long query_max = query[1] - 1; // 2509

				long long current_chunk_begin = query_min; // 502
				long long chunk_index = current_chunk_begin / cache_chunk; // 502 / 1000 = 0
				while (current_chunk_begin <= query_max)
				{
					const long long chuck_ceiling_value = std::min(query_max + 1, chunk_index * cache_chunk + cache_chunk);//chunk_index * cache_chunk + cache_chunk - std::min(chunk_index, 1LL); // 0 * 1000 + 999, 2509 = 1000
					const long long chunk_value = chuck_ceiling_value - current_chunk_begin;

					if (chunk_value != cache_chunk)
					{
						const auto modifier = query[2];
						std::transform(values.begin() + current_chunk_begin, values.begin() + current_chunk_begin + chunk_value, values.begin() + current_chunk_begin,
							[modifier](long long previous_value) { return previous_value + modifier; });
					}
					else
					{
						cache[chunk_index] += query[2];
					}

					current_chunk_begin = (chunk_index + 1) * cache_chunk;
					++chunk_index;
				}
			}

			for (size_t chunk = 0; chunk < cache.size(); ++chunk)
			{
				if (cache[chunk] == 0)
				{
					continue;
				}

				const auto offset = chunk * cache_chunk;
				const auto end_offset = std::min(chunk * cache_chunk + cache_chunk, static_cast<unsigned long long>(values.size()));
				const auto modifier = cache[chunk];
				std::transform(values.begin() + offset, values.begin() + end_offset, values.begin() + offset,
					[modifier](long long previous_value) { return previous_value + modifier; });
			}
		}
		else
		{
			for (const auto& query : queries)
			{
				const auto& modifier = query[2];
				std::transform(values.begin() + query[0] - 1, values.begin() + query[1], values.begin() + query[0] - 1,
					[modifier](long long previous_value) { return previous_value + modifier; });
			}
		}

		return *std::max_element(values.begin(), values.end());
	}

	// https://www.hackerrank.com/challenges/crush
	long long array_manipulation_slow_but_correct(const int n, const std::vector<std::vector<int>> queries)
	{
		if (n == 0)
		{
			return {};
		}

		std::vector<long long> values(n, 0);
		for (const auto& query : queries)
		{
			const auto& modifier = query[2];
			std::transform(values.begin() + query[0] - 1, values.begin() + query[1], values.begin() + query[0] - 1,
				[modifier](long long previous_value) { return previous_value + modifier; });
		}

		return *std::max_element(values.begin(), values.end());
	}
}