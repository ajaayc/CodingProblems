#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool parityComparator(int one,int two){
    //Get the parity of one and two
    bool onePar = one % 2;
    bool twoPar = two % 2;

    //Odd and Even
    if(onePar && !twoPar){
        return false;
    }
    //Even and Odd
    else if(!onePar && twoPar){
        return true;
    }
    //Both are the same parity
    else{
        return one < two;
    }
}

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        std::sort(A.begin(),A.end(),parityComparator);
        return A;
    }
};

int main(){
    Solution s;
    std::vector<int> vec = {3,1,2,4,100,20,133,-1001};
    s.sortArrayByParity(vec);
    for(auto it = vec.begin(); it != vec.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
