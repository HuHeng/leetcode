#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101] = {{0}};
        for(int i = 1; i < 101; ++i) {
            dp[1][i] = 1;
            dp[i][1] = 1;
        }
        for(int i = 2; i <= n; ++i) {
            for(int j = 2; j <= m; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};


int main()
{

    Solution s;

    std::cout << s.uniquePaths(3,2) << std::endl;

    return 0;
}
