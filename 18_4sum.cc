#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> xx(vector<int>& nums, int target, int n){
        vector<vector<int>> ret;
        if(n > 1){
            int len = nums.size();
            for(int i = 0; i < len - n + 1; ++i){
                if(i-1 >= 0 && nums[i] == nums[i-1])
                    continue;
                vector<int> sub;
                sub.assign(nums.begin() + i + 1, nums.end());
                auto rr = xx(sub, target - nums[i], n-1);
                for(auto& r : rr){
                    r.push_back(nums[i]);
                    ret.push_back(r);
                }
            }

        } else if(n == 1){
            int len = nums.size();
            if(len < 1)
                return ret;
            for(int i = 0; i< len; ++i){
                if(i-1 >= 0 && nums[i] == nums[i-1])
                    continue;
                if(nums[i]==target){
                    //find
                    vector<int> a{nums[i]};
                    ret.push_back(a);
                    break;
                }
            }
        }
        return ret;
    }


    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        return xx(nums, target, 4);
    }
};

int main()
{
    vector<int> aa = {1, 0, -1, 0, -2, 2};
    Solution s;
    auto xx = s.fourSum(aa, 0);
    for(auto& x : xx){
        for(auto i : x) {
            std::cout << i<< " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
