#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
//        int d = 0;
//        for(int i = 0; i < digits.size(); ++i) {
//            d *= 10;
//            d += digits[i];
//        }
//
//        //plus one
//        d++;
//
//        vector<int> ans;
//        for(; d!=0; d = d/10) {
//            ans.push_back(d %10);
//        }
//        std::reverse(ans.begin(), ans.end());
//        return ans;
        vector<int> ans;
        int length = digits.size();
        int c = 1;
        for(int i = length -1; i >=0; --i) {
            digits[i] += c;
            if(digits[i] < 10){
                c = 0;
                break;
            }
            digits[i] = 0;
        }
        if(c)
            digits.insert(digits.begin(), 1);
        
        return digits;
    }

};

int main()
{

    Solution s;
    vector<int> d{9,9,9};
    auto v = s.plusOne(d);
    for(auto i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
