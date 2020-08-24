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
    int abs(int x){
        return (x < 0 ? -x : x);
    }
    
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> output;

        vector<int> negatives;
        vector<int> positives;

        for(unsigned i = 0; i < A.size(); ++i){
            if(A[i] < 0)
                negatives.push_back(abs(A[i]));
            else
                positives.push_back(A[i]);
        }

        std::reverse(negatives.begin(),negatives.end());
        
        //Merge sort into output, using absolute value from negatives
        unsigned negIndex = 0, posIndex= 0;

        while(negIndex < negatives.size() && posIndex < positives.size()){
            if(negatives[negIndex] < positives[posIndex]){
                output.push_back(negatives[negIndex]);
                ++negIndex;
            }
            else{
                output.push_back(positives[posIndex]);
                ++posIndex;
            }
        }

        //Put all remaining elements in negatives or positives into output
        while(negIndex < negatives.size()){
            output.push_back(negatives[negIndex]);
            ++negIndex;
        }
        while(posIndex < positives.size()){
            output.push_back(positives[posIndex]);
            ++posIndex;
        }

        //Square output array
        for(unsigned i = 0; i < output.size(); ++i){
            output[i] = output[i] * output[i];
        }

        //This approach uses O(n) time and O(n) memory

        return output;
    }
};

int main(){
    Solution s;
    std::vector<int> vec = {-9,-5,-1,-1,4,6,7,7,7,7,7,8,10};
    std::vector<int> output = s.sortedSquares(vec);
    printVec(output);
    cout << endl;
}
