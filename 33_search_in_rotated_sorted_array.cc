#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int l = nums.size()-1;

        if(l < 0)
            return -1;

        while(s <= l) {
            int ret = (s + l) / 2;
            if(nums[ret] == target){
                return ret;
            }

            if(nums[s] == target){
                return s;
            }

            if(nums[l] == target){
                return l;
            }

            if((nums[s] < target && target < nums[ret] && nums[ret] < nums[l]) || 
                      (nums[ret] < nums[l] && nums[l] < nums[s] &&(target > nums[l] || target < nums[ret])) ||
                      (nums[l] < nums[s] && nums[s] < target && target < nums[ret])
                    ) {
                l = ret -1;
            } else {
                s = ret+1;
            }

        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> xx{4,5,6,7,0,1,2};
    for(auto& i : xx) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    //vector<int> xx{1};
    for(int i=0; i<=7; ++i){
        std::cout << s.search(xx, i) << std::endl;
    }
    std::cout << s.search(xx, 5) << std::endl;
    return 0;
}
