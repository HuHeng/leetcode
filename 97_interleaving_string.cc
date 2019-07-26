#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

//s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"  false
//s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"  true


//dp[m][n] m n from 0
//dp[0][i] represent 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        if(s1.size() == 0)
            return s2 == s3;
        if(s2.size() == 0)
            return s1 == s3;

        int len1 = s1.size();
        int len2 = s2.size();
        vector<vector<bool>> dp(len2+1, vector<bool>(len1+1, false));
        dp[0][0] = true;
        for(int i = 0; i <= len2; ++i) {
            for(int j = 0; j <= len1; ++j) {
                if(i == 0 && j == 0)
                    continue;
                dp[i][j] = (i-1 >=0 && dp[i-1][j] && s2[i-1] == s3[i+j-1]) || (j-1 >= 0 && dp[i][j-1] && s1[j-1] == s3[i+j-1]);
            }
        }
        return dp[len2][len1];
    }
};

using namespace std;

int main()
{
    Solution s;

    //string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";  //false
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"; // true
    std::cout << s.isInterleave(s1, s2, s3) << std::endl;
    return 0;
}
