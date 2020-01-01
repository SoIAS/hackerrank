#pragma once

#include <vector>

namespace ipk_arrays
{
	// using same function signature as in the challenge, so that's why there are unnecessary things (like copying a vector that is never modified locally)

	// https://www.hackerrank.com/challenges/2d-array
	int hourglass_sum(std::vector<std::vector<int>> arr);

	// https://www.hackerrank.com/challenges/ctci-array-left-rotation
	std::vector<int> rot_left(std::vector<int> arr, int offset);

	// https://www.hackerrank.com/challenges/minimum-swaps-2
	int minimum_swaps(std::vector<int> arr);

	// https://www.hackerrank.com/challenges/minimum-swaps-2
	// No sorted cache version, slightly slower (especially for already sorted input)
	int minimum_swaps_no_cache(std::vector<int> arr);

	// https://www.hackerrank.com/challenges/new-year-chaos
	int minimum_bribes(std::vector<int> queue);
}