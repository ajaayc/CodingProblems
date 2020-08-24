#include <queue>
#include <algorithm>
#include <iostream>
#include <stack>
#include <limits>
#include <map>
#include <deque>
#define COUNT 10 

using namespace std;

void printVec(std::vector<int>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

bool lessComp(int a, int b){
    return a > b;
}

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        std::deque<int> result;
        //Sort list in descending order
        std::sort(deck.begin(),deck.end(),lessComp);

        result.push_back(deck[0]);
        
        for(unsigned currIndex = 1; currIndex < deck.size(); ++currIndex){
            int backElt = result.back();
            result.pop_back();
            result.push_front(backElt);
            result.push_front(deck[currIndex]);
        }

        return std::vector<int>(result.begin(), result.end());
    }
};

int main(){
    Solution s;
    std::vector<int> deck = {17,13,11,2,3,5,7};
    std::vector<int> ans = s.deckRevealedIncreasing(deck);
    cout << "Result:" << endl;
    printVec(ans);
}
