#include "pch.h"
#include "../0517_baseball/baseball.cpp"
using namespace std;

TEST(BaseballGame, ThrowExceiptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);

}