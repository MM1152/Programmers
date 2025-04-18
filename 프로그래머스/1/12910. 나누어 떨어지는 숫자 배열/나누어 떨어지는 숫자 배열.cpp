#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;
	priority_queue<int> pq;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % divisor == 0) pq.push(arr[i]);
	}

	if (pq.size() == 0) answer.push_back(-1);
	else {
		while (pq.size() > 0) {
			int value = pq.top();
			pq.pop();
			answer.push_back(value);
		}

	}
	reverse(answer.begin(), answer.end());
	return answer;
}
