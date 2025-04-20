#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;


int solution(int n) {
	int answer = 0;
	vector<int> decimallist;
	for (int i = 2; i <= n; i++) {
		bool isDecimal = true;
		for (int j = 0; j < decimallist.size(); j++) {
			if (decimallist[j] > sqrt(i)) break;
			if (i % decimallist[j] == 0) {
				isDecimal = false;
				break;
			}
		}

		if (isDecimal) {
			decimallist.push_back(i);
			answer++;
		}

	}

	cout << answer << endl;
	return answer;
}
