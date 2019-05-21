#include <algorithm>
#include <string>
#include <iostream>
#include <vector>


int main()
{
    std::string s = "321";
    //std::vector<int> xx{3,2,1};
    //std::vector<int> xx{1,5,4,3, 2};
    std::vector<int> xx{1,5,3,2, 4};
    //std::sort(s.begin(), s.end());
    //do {
    //    std::cout << s << '\n';
    //} while(std::next_permutation(s.begin(), s.end()));
    std::next_permutation(xx.begin(), xx.end());
    for(auto& x : xx){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    //std::cout << xx[] << '\n';
    return 0;
}
