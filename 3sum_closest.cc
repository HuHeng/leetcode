#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if(len <3){
            return 0;
        }

        std::sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        int min_offset = std::abs(ret - target);


        for(int i = 0; i< len - 2; ++i) {
            int two_target = target-nums[i];
            //two sum
            int s = i+1;
            int e = len-1;
            //int min_offset = two_target - nums[e]-nums[s];
            while(s < e){
                int offset = nums[e]+nums[s]-two_target;
                if(std::abs(offset) < min_offset){
                    min_offset = std::abs(offset);
                    ret = nums[e] + nums[s] + nums[i];
                }
                if(offset > 0){
                    e--;

                }else if(offset == 0) {
                    return nums[e] + nums[s] + nums[i];

                }else{
                    s++;
                }

            }
        }
        return ret;
    }
};


int main()
{
    //std::vector<int> a{-1, 2, 1, -4};
    //std::vector<int> a{-1, -1, -1, -1};
    std::vector<int> a{0, 2, 1, -3};
    Solution s;
    auto ret = s.threeSumClosest(a, 1);
    std::cout << ret << std::endl;
    return 0;
}
