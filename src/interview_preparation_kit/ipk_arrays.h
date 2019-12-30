#pragma once

#include <vector>

namespace ipk_arrays
{
	// using same function signature as in the challenge, so that's why there are unnecessary things (like copying a vector that is never modified locally)

	// https://www.hackerrank.com/challenges/2d-array
	int hourglass_sum(std::vector<std::vector<int>> arr);
}