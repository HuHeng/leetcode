#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

/*
   newton
   step 1: y = x^2-n
   step 2: 2x1(x-x1)) = y-y1 ==> x = x1-y1/2x1
   step 3: (x1, y1) ==> (x1-y1/2x1, y2) ==> (x3, y3) ....
*/

class Solution {
public:
    double mySqrtD(int x) {
        double last_ans = x;
        double y = last_ans * last_ans -x;
        double ans;

        while(1) {
            ans = last_ans - y / 2.0/last_ans;
            if(fabs(ans - last_ans) < 1e-6)
                break;
            last_ans = ans;
            y = last_ans*last_ans -x;
        } 
        return ans;

    }
    int mySqrt(int x) {
        if(x == 0) 
            return 0;
        return mySqrtD(x);

    }
};

int main(int argc, char** argv)
{

    Solution s;
    std::cout << s.mySqrtD(atoi(argv[1])) << std::endl;

    return 0;
}
