#include <iostream>
using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	Baseball(const string& question)
		: question(question)
	{
	}
	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return {true, 3, 0};
		}

		int strikeCnt = checkStrikesCnt(guessNumber);
		int ballCnt = checkBallsCnt(guessNumber);

		return { false, strikeCnt ,ballCnt };
	}
	int checkBallsCnt(const std::string& guessNumber)
	{
		int ballCnt = 0;
		for (int left = 0; left < 3; left++) {
			for (int right = 0; right < 3; right++) {
				if (left == right) continue;
				if (guessNumber[left] == question[right]) {
					ballCnt++;
				}
			}
		}
		return ballCnt;
	}
	int checkStrikesCnt(const std::string& guessNumber)
	{
		int strikeCnt = 0;
		for (int index = 0; index < 3; index++) {
			if (guessNumber[index] == question[index]) {
				strikeCnt++;
			}
		}
		return strikeCnt;
	}
	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters");
		}

		for (char ch : guessNumber) {
			if ('0' <= ch && ch <= '9') continue;
			throw invalid_argument("Must be Number");
		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

private:
	string question;

};

