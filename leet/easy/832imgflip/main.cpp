#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printMatrix(vector<vector<T>>& mat){
    for(auto currRow = mat.begin(); currRow != mat.end(); ++currRow){
        for(auto currCol = currRow->begin(); currCol != currRow->end(); ++currCol){
            std::cout << *currCol << " ";
        }
        std::cout << std::endl;
    }
}

class Solution {
public:
    int flipNum(int num){
        num = 1 - num;
        return num;
    }
    
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        //Loop through all rows
        for(unsigned currRow=0; currRow < A.size(); ++currRow){
            for(unsigned currCol=0; static_cast<float>(currCol) < A[0].size()/2.0; ++currCol){
                //Swap
                int temp = flipNum(A[currRow][currCol]);
                A[currRow][currCol] = flipNum(A[currRow][A[0].size()-currCol-1]);
                A[currRow][A[0].size()-currCol-1] = temp;
            }
        }
        
        return A;
    }
};

int main(){
    Solution s;
    vector<vector<int>> one = {{0,1,0,0,0},{1,0,0,0,1}};
    vector<vector<int>> two = {{0,0,1,0},{1,0,1,0}};

    cout << "Original:" << endl;
    printMatrix(one);
    s.flipAndInvertImage(one);
    cout << "Flipped:" << endl;
    printMatrix(one);

    cout << "Original:" << endl;
    printMatrix(two);
    s.flipAndInvertImage(two);
    cout << "Flipped:" << endl;
    printMatrix(two);
}
