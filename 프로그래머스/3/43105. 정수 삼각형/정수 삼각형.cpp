#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[501][501] = { 0, };

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i-1].size() ; j++) {
            if (dp[i][j] == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
            if (dp[i][j + 1] == 0) dp[i][j + 1] = dp[i - 1][j] + triangle[i][j + 1];

            if (dp[i][j] != 0 && dp[i][j] < dp[i - 1][j] + triangle[i][j]) dp[i][j] = dp[i - 1][j] + triangle[i][j];
            if (dp[i][j + 1] != 0 && dp[i][j + 1] < dp[i - 1][j] + triangle[i][j + 1]) dp[i][j + 1] = dp[i - 1][j] + triangle[i][j + 1];
        }
    }
    int max = 0;

    for (int i = 0; i < 501; i++) {
        if (dp[triangle.size() - 1][i] == 0) return max;
        
        if (max < dp[triangle.size() - 1][i]) max = dp[triangle.size() - 1][i];
    }

    return answer;
}
    