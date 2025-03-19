#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class LRU {
	vector<string> list;
	int cacheSize;

public:
	LRU(int size) {
		cacheSize = size;
	}
	void Pop();
	bool Add(string index);
};


int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
	if (cacheSize == 0) return cities.size() * 5;
	
    LRU lur = {cacheSize};

	for (string city : cities) {
        transform(city.begin(), city.end(), city.begin(), ::tolower);
		if (lur.Add(city)) {
			answer++;
		}
		else {
			answer += 5;
		}
	}

    return answer;
}

void LRU::Pop () {
	list.erase(list.begin());
}

bool LRU::Add(string index) {
	for (int i = 0; i < list.size(); i++) {
		if (index == list[i]) {
			list.erase(list.begin() + i);
			list.push_back(index);
			return true;
		}
	}

	if (list.size() >= cacheSize) Pop();
	
	list.push_back(index);
	return false;
}
