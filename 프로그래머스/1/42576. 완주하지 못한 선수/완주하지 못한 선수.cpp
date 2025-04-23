#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

string str[100001];

void mergeSort(vector<string>& arr, int left, int mid, int right);

void merge(vector<string>& arr , int left , int right) {

	if (left < right) {
		int mid = (left + right) / 2;
		merge(arr, left , mid);
		merge(arr, mid + 1, right);
		mergeSort(arr, left, mid , right);
	}
}

void mergeSort(vector<string>& arr, int left , int mid , int right) {
	int i = left;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			str[k++] = arr[i++];
		}
		else {
			str[k++] = arr[j++];
		}
	}

	if (i <= mid) {
		for (int l = i; l <= mid; l++) {
			str[k++] = arr[l];
		}
	}
	else {
		for (int l = j; l <= right; l++) {
			str[k++] = arr[l];
		}
	}

	for (int l = left; l <= right; l++) {
		arr[l] = str[l];
	}
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	merge(participant , 0 , participant.size() - 1);
	merge(completion, 0, completion.size() - 1);

	int i = 0;
	while (i < completion.size() && participant[i] == completion[i]) {
		i++;
	}

	return participant[i];
}