#include <gtest/gtest.h>
#include "islands.h"
#include <time.h>

TEST(Percolation, works) {
	std::vector<std::vector<int>> m(5, std::vector<int>(5, 0));
	m[0][3] = 1;
	m[1][3] = 1;
	m[2][3] = 1;
	m[3][3] = 1;
	m[4][3] = 1;
	m[1][1] = 1;
	m[2][1] = 1;
	std::vector<std::vector<int>> exp = m;
	exp[1][1] = 0;
	exp[2][1] = 0;
	std::vector<std::vector<int>> res = PercolationUF(m);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			EXPECT_EQ(exp[i][j], res[i][j]);
}

TEST(Percolation, works2) {
	std::vector<std::vector<int>> m(5, std::vector<int>(5, 0));
	m[0][3] = 1;
	m[1][3] = 1;
	m[2][3] = 1;
	m[3][3] = 1;
	m[4][3] = 1;
	m[1][1] = 1;
	m[2][1] = 1;
	std::vector<std::vector<int>> exp = m;
	exp[1][1] = 0;
	exp[2][1] = 0;
	std::vector<std::vector<int>> res = PercolationWidth(m);
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			EXPECT_EQ(exp[i][j], res[i][j]);
}
