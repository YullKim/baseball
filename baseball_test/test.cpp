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


TEST_F(BaseballFixture, ThrowExceiptionWhenInputLengthIsUnmached) {
	assertIllegalArgument("12");
}

TEST_F(BaseballFixture, ThrowExceiptionWhenInputInvalidChar) {
	assertIllegalArgument("12s");
}