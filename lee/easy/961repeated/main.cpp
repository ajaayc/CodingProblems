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
    int repeatedNTimes(vector<int>& A) {
        //Loop through array and compare each element to up to 3 steps ahead of it
        for(int offset = 1; offset <= 3; ++offset){
            for(unsigned i = 0; i < A.size() - offset; ++i){
                if(A[i] == A[i+offset]){
                    return A[i];
                }
            }
        }
        return -100;
    }
};

int main(){
    Solution s;
    //std::vector<int> vec = {0,1,4,4,4,7,4,5,2,4};
    //std::vector<int> vec = {0,1,2,2};
    std::vector<int> vec = {4,0,4,1,4,7,4,5,2,4};
    cout << s.repeatedNTimes(vec);
    cout << endl;
}
