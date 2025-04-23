#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;


string solution(string X, string Y) {
	string answer = "";
	map<int, int> map1;
	map<int, int> map2;

	for (int i = 0; i <= 9; i++) {
		map1.insert({ i, 0 });
		map2.insert({ i, 0 });
	}

	for (int i = 0; i < X.size(); i++) {
		map1[X[i] - 48]++;
	}

	for (int i = 0; i < Y.size(); i++) {
		map2[Y[i] - 48]++;
	}

	for (int i = 9 ; i >= 0; i--) {
		if (min(map1[i], map2[i]) != 0) {
			for (int j = 0; j < min(map1[i], map2[i]); j++) {
				answer += (char)(i + 48);
			}
		}
	}
	if (answer == "\0") return "-1";
	if (answer[0] == '0') return "0";

	
	return answer;
}