#include "pch.h"
#include "gtest/gtest.h"
using namespace std;

TEST(Test1, TestName1) {
	ASSERT_DOUBLE_EQ(620844, onethreadsumm());
}
TEST(Test2, TestName2) {
	ASSERT_DOUBLE_EQ(620844, manythreadsumm());
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}