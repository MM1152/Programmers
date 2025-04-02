#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = -1;
	int count = 0;
	
	char pastChar = s[0];

	stack<char> ch;

	ch.push(s[0]);
	
	for (int i = 1; i < s.size(); i++) {
		ch.push(s[i]);
		if (pastChar != 0) {
			if (ch.top() == pastChar) {
				ch.pop();
				ch.pop();
				if (!ch.empty()) {
					pastChar = ch.top();
				}
				else {
					pastChar = 0;
				}
			}
			else {
				pastChar = ch.top();
			}
		}
		else {
			pastChar = s[i];
		}
	}
	return ch.empty();
}