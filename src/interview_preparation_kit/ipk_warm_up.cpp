#include "ipk_warm_up.h"

#include <array>
#include <algorithm>

namespace ipk_warm_up
{
	// https://www.hackerrank.com/challenges/sock-merchant
	int sock_merchant(const int /*size*/, const std::vector<int> arr)
	{
		constexpr int max_color_value = 100;

		// obviously wouldn't work if the [min,max] colors would change
		std::array<int, max_color_value + 1> amount_of_socks_per_color{};
		for (const auto sock_color : arr)
		{
			++amount_of_socks_per_color[sock_color];
		}

		int amount_of_socks_to_sell{};
		for (const auto socks_of_color : amount_of_socks_per_color)
		{
			amount_of_socks_to_sell += socks_of_color / 2;
		}

		return amount_of_socks_to_sell;
	}

	// https://www.hackerrank.com/challenges/repeated-string
	long long repeated_string(const std::string str, const long long n)
	{
		auto repeated_count = std::count(str.begin(), str.end(), 'a') * (n / str.size());

		const size_t leftover = n % str.size();
		repeated_count += std::count(str.begin(), str.begin() + leftover, 'a');

		return repeated_count;
	}

}