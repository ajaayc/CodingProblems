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
    int peakIndexInMountainArray(vector<int>& A) {
        //Loop through A, find difference beteen consecutive elements
        for(unsigned i = 1; i < A.size(); ++i){
            if(A[i] < A[i-1])
                return i-1;
        }

        return -10000;
    }
};


int main(){
    Solution s;
    std::vector<int> vec = {-9,-5,-1,-1,4,6,7,10,11,14,9,1,-10,-14,-21,-25};
    int peak = s.peakIndexInMountainArray(vec);
    cout << "Peak: " << peak << endl;
}
