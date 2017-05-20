#include <gtest/gtest.h>
#include "Ksets.h"
TEST(Ksets, works) {
	std::vector<std::pair<int, int>> a(3);
	a[0] = std::pair<int, int>(1, 2);
	a[1] = std::pair<int, int>(0, 4);
	a[2] = std::pair<int, int>(2, 5);
	std::vector<int> res = Ksets(a, 6);
	for (int i = 0; i < 3; ++i)
		EXPECT_TRUE(res[a[i].first] != res[a[i].second]);
} 