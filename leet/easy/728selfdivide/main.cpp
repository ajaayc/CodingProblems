#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

void printVec(std::vector<int>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> output;

        //Go through all the digits
        for(int currNum = left; currNum <= right; ++currNum){
            //Check digits of current num
            int currNumCp = currNum;

            bool isSelfDividing = true;
            
            //Go through digits of currNumCp
            while(currNumCp != 0){
                int currDigit = currNumCp % 10;

                //Not a selfdividing number because it has zero
                if(currDigit == 0){
                    isSelfDividing = false;
                    break;
                }

                //Check divisibility of currDigit
                if(currNum % currDigit != 0){
                    isSelfDividing = false;
                    break;
                }

                currNumCp /= 10;
            }

            if(isSelfDividing){
                output.push_back(currNum);
            }
        }

        return output;
    }
};


int main(){
    Solution s;
    int left = 1, right = 22;
    std::vector<int> output = s.selfDividingNumbers(left,right);
    printVec(output);
    cout << endl;
}
