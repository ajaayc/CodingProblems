#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_set>

using namespace std;

void printVec(std::vector<int>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        unsigned numCols = A[0].size();

        int deletionCount = 0;
        
        //Loop through all the columns, then all the rows
        for(unsigned currCol = 0; currCol < numCols; ++currCol){
            for(unsigned currRow = 1; currRow < A.size(); ++currRow){
                //Check that all the rows are in non-decreasing order
                if(A[currRow][currCol] - A[currRow-1][currCol] < 0){
                    ++deletionCount;
                    break;
                }
            }
        }

        return deletionCount;
    }
};

int main(){
    Solution s;
    std::vector<string> input = {"rrjk","furt","guzm"};
    cout << "Deletions: " << s.minDeletionSize(input);
    std::cout << std::endl;
}
