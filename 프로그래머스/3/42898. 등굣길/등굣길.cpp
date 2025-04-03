#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

struct node
{
	int y;
	int x;
	int curCount;
};
int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	vector<vector<int>> dp(n, vector<int>(m));
	dp[0][0] = 1;
	vector<vector<int>> map(n, vector<int>(m));

	for (int i = 0; i < puddles.size(); i++) map[puddles[i][1] - 1][puddles[i][0] - 1] = -1;

	queue<node> bfs;
	bfs.push(node{ 0, 0 , 0 });

	int min = 0;

	while (bfs.size() > 0) {
		node curNode = bfs.front();
		bfs.pop();
		
		//printf("curNode : [%d] [%d] Count : [%d]\n", curNode.y, curNode.x, curNode.curCount);
		if (curNode.x + 1 < m && map[curNode.y][curNode.x + 1] != -1 && dp[curNode.y][curNode.x + 1] == 0) {
			bfs.push(node{ curNode.y, curNode.x + 1, curNode.curCount + 1 });
			dp[curNode.y][curNode.x + 1] = dp[curNode.y][curNode.x];
		}
		else if (curNode.x + 1 < m && map[curNode.y][curNode.x + 1] != -1 && dp[curNode.y][curNode.x + 1] != 0) {
			dp[curNode.y][curNode.x + 1] = (dp[curNode.y][curNode.x + 1] + dp[curNode.y][curNode.x]) % 1000000007;
		}

		if (curNode.y + 1 < n && map[curNode.y + 1][curNode.x] != -1 && dp[curNode.y + 1][curNode.x] == 0) {
			bfs.push(node{ curNode.y + 1, curNode.x, curNode.curCount + 1 });
			dp[curNode.y + 1][curNode.x] = dp[curNode.y][curNode.x];
		}
		else if (curNode.y + 1 < n && map[curNode.y + 1][curNode.x] != -1 && dp[curNode.y + 1][curNode.x] != 0) {
			dp[curNode.y + 1][curNode.x] = (dp[curNode.y + 1][curNode.x] + dp[curNode.y][curNode.x]) % 1000000007;
		}
		
	}


    answer = dp[n - 1][m - 1];

	return answer;
}