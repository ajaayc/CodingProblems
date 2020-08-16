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

class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main(){
    Solution s;
    std::vector<string> input = {"rrjk","furt","guzm"};
    cout << "Deletions: " << s.minDeletionSize(input);
    std::cout << std::endl;
}
