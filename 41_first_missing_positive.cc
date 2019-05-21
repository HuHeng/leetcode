#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        if(length < 1){
            return 1;
        }

        //for(int i = 0; i < length; ++i) {
        //    int v = nums[i];
        //    if(0 < v && v < length){
        //        std::swap(nums[i], nums[v]);
        //    }
        //}       
        int i = 0; 
        while(i<length) {
            int v = nums[i];
            if(0 < v && v <= length && v != i+1 && nums[i] != nums[v-1]) {
                std::swap(nums[i], nums[v-1]);

            }else {
                ++i;
            }
            
        }


        //for(auto x : nums) {
        //    std::cout << x << " ";
        //}
        //std::cout << std::endl;

        int m=0;
        for(m = 0; m < length; ++m) {
            if(nums[m] != m+1) {
                return m+1;
            }
        }
        return m+1;

    }
};

int main()
{
    Solution s;
    vector<int> v1{1,2,0};
    vector<int> v2{3,4,-1,1};
    vector<int> v3{7,8,9,11,12};
    vector<int> v4{1,2,3,4};
    vector<int> v5{-1,4,1};
    vector<int> v6{0};
    vector<int> v7{};
    vector<int> v8{1,1};

    std::cout << s.firstMissingPositive(v1) << std::endl;
    std::cout << s.firstMissingPositive(v2) << std::endl;
    std::cout << s.firstMissingPositive(v3) << std::endl;
    std::cout << s.firstMissingPositive(v4) << std::endl;
    std::cout << s.firstMissingPositive(v5) << std::endl;
    std::cout << s.firstMissingPositive(v6) << std::endl;
    std::cout << s.firstMissingPositive(v7) << std::endl;
    std::cout << s.firstMissingPositive(v8) << std::endl;
    return 0;
}
