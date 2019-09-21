#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVec(std::vector<int>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        //Doing this is in O(n) time with O(1) memory. Quicksort idea
        int i = 0, j= A.size() - 1;

        while(i < j){
            if(A[i] % 2 && A[j] % 2 == 0){
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }

            if(A[i] % 2 == 0) ++i;
            if(A[j] % 2 != 0) --j; 
        }
        
        return A;
    }
};

int main(){
    Solution s;
    std::vector<int> vec = {3,1,2,4,100,20,133,-1001};
    std::vector<int> output = s.sortArrayByParity(vec);
    printVec(output);
    cout << endl;
}
