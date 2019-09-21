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
    int hammingDistance(int x, int y) {
        int diff = x ^ y;

        //Count number of 1's in diff
        int diffCp = diff;

        int hammingDist = 0;
        
        while(diffCp != 0){
            int currBit = (diffCp & 1);
            hammingDist += currBit;
            diffCp >>= 1;
        }

        return hammingDist;
    }
};



int main(){
    Solution s;
    int dist = s.hammingDistance(1,4);
    cout << "Hamming Distance: " << dist << endl;
}
