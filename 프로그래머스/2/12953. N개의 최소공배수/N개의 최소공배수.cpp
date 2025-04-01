#include <string>
#include <vector>
#include <queue>

using namespace std;

int GCD(int a, int b);

int solution(vector<int> arr) {
	int answer = 0;
	queue<int> que;
	
	que.push(arr[0] * arr[1] / GCD(arr[0], arr[1]));

	for (int i = 2; i < arr.size(); i++) {
		que.push( que.front() * arr[i] / GCD(que.front(), arr[i]) );
		que.pop();
	}
	
	return arr[arr.size() - 1] * que.front() / GCD(que.front(), arr[arr.size() - 1]);

}

int GCD(int a , int b) {
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}

	int gcd = 0;

	while (a % b != 0) {
		gcd = a % b;
		a = b;
		b = gcd;
	}

	return b;
}
