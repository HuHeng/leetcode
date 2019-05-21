#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses_2(string s) {
        int len = s.size();
        int max = 0;
        for(int i = 0; i < len; ++i) {
            if(s[i] == ')')
                continue;

            if(len-i <= max)
                continue;
            
            int valid_num = 1; // '(' +1, ')' -1
            for(int m = i+1; m < len; ++m) {
                if(s[m] == '('){
                    valid_num++;

                }else if (s[m] == ')') {
                    valid_num--;
                }

                if(valid_num == 0){
                    max = std::max(max, m-i+1);
                }

                if(valid_num < 0){
                    break;
                }

            }
        }
        return max;
    }

    int longestValidParentheses(string s) {
        stack<int> x;
        int max = 0;
        int len = s.size();
        int valid = 0;
        for(int i = 0; i < len; ++i) {
            if(s[i] == ')'){
                if(x.empty()){
                    valid = 0;

                } else {
                    x.pop();
                    valid++;
                    if(x.empty()){
                        max = std::max(max, valid);
                    }
                }

            }else {
                x.push(1);
                valid++;
            }
        }
        int c = valid - x.size();
        max = std::max(max, c);
        return max;

    }
};



int main()
{
    Solution solution;
    
    //std::string s = ")(())))(()";
    std::string s = ")(()";
    std::cout << solution.longestValidParentheses(s) << std::endl;
    return 0;

}
