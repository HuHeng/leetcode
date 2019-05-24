#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;


//use two pointer

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while(left < right) {
            if(height[left] <= height[right]) {
                if(height[left] < left_max){
                    ans += left_max - height[left];

                }else {
                    left_max = height[left];
                }
                left++;

            } else {
                if(height[right] < right_max) {
                    ans += right_max - height[right];
                } else {
                    right_max = height[right];
                }

                right--;
            }
        }
        return ans;
    
    }
};

int main()
{
    Solution s;
    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << s.trap(height) << std::endl;
}
