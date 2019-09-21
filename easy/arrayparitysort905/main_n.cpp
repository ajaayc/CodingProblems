#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        //Create output array
        std::vector<int> output;

        //Loop through A twice, push even elements first, then odd elements
        for(auto it = A.begin(); it != A.end(); ++it){
            if(!(*it % 2)){
                output.push_back(*it);
            }
        }
        
        for(auto it = A.begin(); it != A.end(); ++it){
            if(*it % 2){
                output.push_back(*it);
            }
        }

        return output;
    }
};

int main(){
    Solution s;
    std::vector<int> vec = {3,1,2,4,100,20,133,-1001};
    std::vector<int> output = s.sortArrayByParity(vec);
    for(auto it = output.begin(); it != output.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
