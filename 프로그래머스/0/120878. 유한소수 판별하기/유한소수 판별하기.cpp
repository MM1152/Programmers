#include <string>
#include <vector>
#include <cmath>

using namespace std;

int GCD(int a, int b);

int solution(int a, int b) {
	int answer = 0;
    
	int gcd = GCD(a, b);
    
	b /= gcd;

	while (b % 2 == 0) b /= 2;
	while (b % 5 == 0) b /= 5;

	return b == 1 ? 1 : 2;
}

int GCD(int a , int b) {
	int c = 0;
    if (a > b) {
		c = b;
		b = a;
		a = c;
	}
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return c;
}