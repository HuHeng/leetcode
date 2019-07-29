#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*

   */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
            return 0;

        int dp[101][101] = {{0}};
        int nlen = obstacleGrid.size();
        int mlen = obstacleGrid[0].size();

        for(int n = nlen-1; n >= 0; --n) {
            for(int m = mlen-1; m >= 0; --m) {

            }
        }
        return dp[0][0];

    }
};


int main()
{

    Solution s;

    //std::cout << s.uniquePaths(3,2) << std::endl;

    return 0;
}
