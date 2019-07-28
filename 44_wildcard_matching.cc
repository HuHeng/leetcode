#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

//aa *
//cb ?a
//adceb a*b
//acdcb a*c?b

/*
   dp[0][0] represent "" "" true
   dp[0][1] p "" s "a" false dp[0][1] -- dp[0][slen] = false
   dp[1][0] p "*" true else false dp[1][1] = dp[]

   dp[i][j] = (dp[i-1][j-1] && (p[i]==s[j]||p[i]=='?')) || (p[i]=='*' && dp[i-1][j].....)

   */

class Solution {
public:
    bool isMatch(string s, string p) {
        int plen = p.size();
        int slen = s.size();
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1, false));

        dp[0][0] = true;
        for(int j = 1; j <= plen; ++j) {
            bool alltrue = false;
            for(int i = 0; i <= slen; ++i) {
                if(alltrue){
                    dp[j][i]=true;
                    continue;
                }
                if(i > 0 && (p[j-1] == '?'||p[j-1]==s[i-1]) && dp[j-1][i-1]) {
                    dp[j][i] = true;

                } else if(p[j-1] == '*') {
                    dp[j][i] = false;
                    for(int n = 0; n <= i; ++n) {
                        if(dp[j-1][n]){
                            dp[j][i] = true;
                            break;
                        }
                    }
                    if(dp[j][i]){
                        alltrue = true;
                    }

                } else {
                    dp[j][i] = false;
                }
                
            }
        }
        return dp[plen][slen];
    }

};

int main(int argc, char** argv)
{
    std::cout << argv[1] << std::endl;
    std::cout << argv[2] << std::endl;
     Solution s;
     std::cout << s.isMatch(argv[1], argv[2]) << std::endl;
     return 0;
}
