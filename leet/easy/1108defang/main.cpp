#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    void makeSet(string J, std::unordered_set<char>& jewels){
        for(unsigned i=0; i < J.size(); ++i){
            jewels.insert(J[i]);
        }
    }

    int numJewelsInStones(string J, string S) {
        //Loop through J, make a set of jewels
        std::unordered_set<char> jewels;
        makeSet(J,jewels);

        int jewelCount = 0;
        
        for(unsigned i=0; i < S.size(); ++i){
            if(jewels.find(S[i]) != jewels.end()){
                ++jewelCount;
            }
        }

        return jewelCount;
    }
};

int main(){
    Solution s;
    std::cout << s.numJewelsInStones("aA","aAAbbbb") << std::endl;
    std::cout << s.numJewelsInStones("z","ZZ") << std::endl;
    std::cout << s.numJewelsInStones("bad","abcadabra") << std::endl;
    std::cout << s.numJewelsInStones("al","caprixanol") << std::endl;
    std::cout << s.numJewelsInStones("zap","zapdosarticunomoltres") << std::endl;
}
