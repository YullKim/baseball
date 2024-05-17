#include "pch.h"
#include "../0517_baseball/baseball.cpp"
using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		//game.guess() ���� ��, Exception�� �߻��ؾ� PASS �̴�.
		try {
			game.guess(string(guessNumber));
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};


TEST_F(BaseballFixture, ThrowExceiptionWhenInputInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMaatchedNumber) {
	Baseball game;
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);

}
