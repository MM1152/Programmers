#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;

	for (int i = 0; i < arr1.size(); i++) {
		vector<int> value;
		
		for (int j = 0; j < arr2[0].size(); j++) {
			int l = 0;
			int sum = 0;
 			for (int k = 0; k < arr2.size(); k++) {
				sum += arr1[i][l] * arr2[k][j];

				l++;
			}
			value.push_back(sum);
		}
		answer.push_back(value);
		value.clear();
	}


	//for (vector<int> vec: answer) {
	//	for (int count : vec) {
	//		cout << count << " ";
	//	}
	//	cout << endl;
	//}
    return answer;
}