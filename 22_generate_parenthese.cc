#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void generateParenthesisDFS(int left, int right, std::string out, vector<string>& s){
        if(left > right)
            return;

        if(left == 0 && right == 0) {
            s.push_back(out);
            return;
        }


        if(left==0){
            generateParenthesisDFS(left, right-1, out+')', s);
            return;
        }

        generateParenthesisDFS(left, right-1, out+')', s);
        generateParenthesisDFS(left-1, right, out+'(', s);
    }

    vector<string> generateParenthesis(int n) {
        std::vector<string> ret;
        generateParenthesisDFS(n, n, "", ret);
        return ret;
    }
};


int main()
{

    Solution s;
    auto ret = s.generateParenthesis(3);
    for(auto& x:ret) {
        std::cout << x << std::endl;
    }
    return 0;
}
