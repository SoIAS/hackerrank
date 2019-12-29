#include "ipk_warm_up.h"

#include <array>

namespace ipk_warm_up
{
	// using same function signature as in the challenge, so that's why array is copied and added unnecessary size
	int sock_merchant(int /*size*/, const std::vector<int> arr)
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

}