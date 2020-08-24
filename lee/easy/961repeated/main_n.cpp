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
    //O(1) memory i.e. 10000 bits = about 1.25 kb
    //O(n) time. n is size of A
    int repeatedNTimes(vector<int>& A) {
        std::bitset<10000> dupSet;

        for(auto it = A.begin(); it != A.end(); ++it){
            if(dupSet[*it] == 0)
                dupSet[*it] = 1;
            else
                return *it;
        }

        return -100;
    }
};

int main(){
    Solution s;
    std::vector<int> vec = {0,1,4,4,4,7,4,5,2,4};
    cout << s.repeatedNTimes(vec);
    cout << endl;
}
