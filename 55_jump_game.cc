#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) 
            return false;

        int max = 0;
        max += nums[0];

        for(int i = 1; i < len; ++i) {
            if(i > max)
                break;
            max = std::max(max, i+nums[i]);
        }

        return max >= len-1;
    }
};

int main()
{
    std::vector<int> l1{2,3,1,1,4};
    std::vector<int> l2{3,2,1,0,4};

    Solution s;
    std::cout << s.canJump(l1) << std::endl; 
    std::cout << s.canJump(l2) << std::endl; 

    return 0;
}
