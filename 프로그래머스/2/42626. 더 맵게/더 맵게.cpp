#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> list;

void Add(int value) {
	list.push_back(value);
	
	int index = list.size() - 1;
	while (index > 0) {
		int parent = (index - 1) / 2;

		if (list[parent] >= list[index]) {
			int temp = list[parent];
			list[parent] = list[index];
			list[index] = temp;
		}

		index = parent;
	}
}

int Pop() {
	if (list.size() == 0) return -1;

	int returnValue = list[0];

	if (list.size() >= 2) {
		list[0] = list[list.size() - 1];
		list.erase(list.end() - 1);
		
		int index = 0;
		while (index < list.size())
		{
			int left = index * 2 + 1;
			int right = index * 2 + 2;
			int parent = index;

			if (left < list.size() && list[left] < list[parent]) parent = left;
			if (right < list.size() && list[right] < list[parent]) parent = right;

			if (index == parent) break;

			int temp = list[parent];
			list[parent] = list[index];
			list[index] = temp;

			index = parent;
		}

		return returnValue;
	}
	
	list.erase(list.end() - 1);
	return returnValue;
}

int solution(vector<int> scoville, int K) {
    int answer = 0;

    for (int i : scoville) {
        Add(i);
    }

    while (list.size() > 0 && list[0] < K) {
        answer++;
        int firstPopValue = Pop();

        int secondPopValue = Pop();
        if (secondPopValue == -1) {
            answer = -1;
            return -1;
        }

        int sum = firstPopValue + (secondPopValue * 2);
        Add(sum);
    }
    return answer;
}