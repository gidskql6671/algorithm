#include <string>
#include <vector>

using namespace std;

int dp[100001][2];

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    if (tops[0] == 0) {
        dp[0][0] = 2;
        dp[0][1] = 1;
    }
    else {
        dp[0][0] = 3;
        dp[0][1] = 1;
    }
    
    for(int i = 1; i < n; i++) {
        if (tops[i] == 0) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][0]) % 10007;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % 10007;
        }
        else {
            dp[i][0] = (2 * (dp[i - 1][0] + dp[i - 1][1]) + dp[i - 1][0]) % 10007;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % 10007;
        }
    }
    
    return (dp[n - 1][0] + dp[n - 1][1]) % 10007;
}