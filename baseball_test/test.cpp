#include "pch.h"
#include "../0517_baseball/baseball.cpp"
using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game{"123"};
	void assertIllegalArgument(string guessNumber) {
		//game.guess() 수행 후, Exception이 발생해야 PASS 이다.
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
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnNotSolvedResultWith2Strikes0Ball) {
	GuessResult result = game.guess("143");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnNotSolvedResultWith1Strikes2Ball) {
	GuessResult result = game.guess("132");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(1, result.strikes);
	EXPECT_EQ(2, result.balls);
}
