#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
	int answer = 0;
	//int storey = 2554;
	
	while (storey > 0) {
		int lastDigit = storey % 10;
		int nextDigit = storey / 10 % 10;

		if (lastDigit > 5 || (lastDigit >= 5 && nextDigit >= 5)) {
			answer += 10 - lastDigit;
			storey += 10 - lastDigit;
		}
		else {
			answer += lastDigit;
			storey -= lastDigit;
		}

		storey /= 10;
	}

	//cout << "answer : " << answer << endl;
	return answer;
}