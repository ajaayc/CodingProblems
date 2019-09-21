#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>

using namespace std;

void printVec(std::vector<int>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}

class Solution {
public:
    int getDeriv(const vector<int>& A, float index){
        //If index is a whole number, then derivative is the change from
        //the previous index
        if((index * 1.0) == (static_cast<int>(index) * 1.0)){
            return A[index] - A[index-1];
        }

        //Else not a whole number:
        //Find difference between floor and ceil indexes
        return A[ceil(index)] - A[floor(index)];
    }
    
    //Invariant: derivative at left > 0, derivative at right > 0
    void binSearch(const vector<int>& A, float& left, float& right, float& peak){
        if(ceil(left) == floor(right)){
            peak = ceil(left);
            return;
        }

        //Get midpoint
        float mid = (left + right)/2.0;

        //Get derivative at mid
        int midDeriv = getDeriv(A,mid);

        if(midDeriv < 0){
            binSearch(A,left,mid,peak);
        }
        else/*(midDeriv > 0)*/{
            binSearch(A,mid,right,peak);
        }
    }
    
    int peakIndexInMountainArray(vector<int>& A) {
        float left = 0, right = A.size()-1;
        float peak;

        //Apply a binary search
        binSearch(A,left,right,peak);
        return peak;
    }
};


int main(){
    Solution s;
    //std::vector<int> vec = {18,29,38,59,98,100,99,98,90};
    std::vector<int> vec = {-9,-5,-4,-1,4,6,7,10,11,14,9,1,-10,-14,-21,-25};
    int peak = s.peakIndexInMountainArray(vec);
    cout << "Peak: " << peak << endl;
}
