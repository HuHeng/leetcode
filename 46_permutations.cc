#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    n * (n-1) * (n-2) * (n-3) ... 1

    for(int i = 0; i < n; ++i){
        v.push(num[i]);
        //get into layer n-1
        remain_nums = nums[] delete the nums already into the ans

        for(int i1 = 0; i1 < n-1; ++i1)
            for(int i2 = 0; i2 < n-2; ++i2)
            ...
            ...
            ...
        //


    }

   */


class Solution {
public:
    void getper(vector<vector<int>>& ans, vector<int>& remain_nums, vector<int>& permute) {
        if(remain_nums.size() == 0) {
            //get the permute
            ans.push_back(permute);
            return;
        }

        for(size_t i = 0; i < remain_nums.size(); ++i) {
            int val = remain_nums[i];
            permute.push_back(val);
            remain_nums.erase(remain_nums.begin()+i);
            //get into next layer
            getper(ans, remain_nums, permute);
            remain_nums.insert(remain_nums.begin()+i, val);
            permute.pop_back();
        
        }
    
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> per;

        getper(ans, nums, per);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,2,3};
    auto vv = s.permute(nums);
    for(auto v : vv) {
        for(auto val : v) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
