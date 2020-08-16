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
    vector<int> diStringMatch(string S) {
        int N = S.length();
        int lo = 0, hi = N;
        std::vector<int> ans(N + 1);
        for (int i = 0; i < N; ++i) {
            if (S[i] == 'I')
                ans[i] = lo++;
            else
                ans[i] = hi--;
        }

        ans[N] = lo;
        return ans;
    }

};

int main(){
    Solution s;
    std::vector<int> diString = s.diStringMatch("IIIID");
    cout << "DI Vector:" << endl;
    printVec(diString);
    std::cout << std::endl;
}
