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
        std::unordered_set<int> usedInts;
        std::vector<int> output;

        int currNum = 0;
        output.push_back(currNum);
        usedInts.insert(currNum);

        int minNum = currNum;
        
        for(char currChar:S){
            if(currChar == 'I'){
                ++currNum;
                while(usedInts.find(currNum) != usedInts.end()){
                    ++currNum;
                }
            }
            else if(currChar == 'D'){
                --currNum;
                while(usedInts.find(currNum) != usedInts.end()){
                    --currNum;
                }
            }

            minNum = std::min(minNum,currNum);
            output.push_back(currNum);
            usedInts.insert(currNum);
        }

        //Add abs(minNum) to whole array if it's negative
        if(minNum < 0){
            for(unsigned i = 0; i < output.size(); ++i){
                output[i] += (-minNum);
            }
        }

        return output;
    }
};

int main(){
    Solution s;
    vector<int> diString= s.diStringMatch("DIIDDIDIIDDDIDDIIIDDDIDDIIDIIDIIIDIIDIDDDDIDIDDIIDDIDDDIIIIDIIDIIIIDDIDIIDDDIDDDIIIIDDIDIDDDIIIIIIDDDIDDDIDIDDDIIIDIDDIDIIDIDDIIIDDIIIIIIIIDIDDDIIDDDDIIDDIIIDDIIIDIIIDIIIIIDDDIIDIDIDDDIDDDIIIIDDIIIIDDDIDDDDIIIIDDDDDDDIDDIDIDIIDDDDDDDDIDIDDIIDDDDIIIDDDDIIDIDIDIIDDIIIIIIDDIDIDIIDIIIDIIDDDDIDDDDDDDDDIIIIDDIDIDIDIDDIDDIDDIDIDDDIIDDDIDDIIIDDIDIDIIIDDDIDIIDIIDIIDDIDIDDDIDIDIIDIDDIIIIIIIDIIDDIDDDIDIDDIIDIIIDDDIIDIIIDDDDIIIIIDIDDIDIIDIDIDIIIDIDDIIIDIDDIDIDDIDIDIDIDIIDDDDIDDDIDDIDIDDIDIIDIIDDDDDDIIDDDDDIIDDDIIDIIIIIDDIDIDIDIIDDDDIIDIIIDIIDDDIDIDIDIDIDDIDIIIIIIIIIIDDIDIIIIIDIDDDDIIIDIDIDIIIIDIDDDIIDDDDDDIIIIIDDIIDDDDDIIIDIIIDDIDDIDIIDDIIIIDDIIDDIIDIDDDDIIDIIIDIDIDIIIDIDDIDIIDIDIDIDIIIIIIIIIIIDIIIIIIIIIDIDDDDIIDDIIDIDIDIIDDIIDDIIIIIDIIIIDIIIDDDDDDIIDIDIIIDDDDDDDIDDIDIDIDDIDDDIIIDIIIIIDDDIDIDIDIDDDIDIIDDDDDIIIIDIDDIIIDIIDIDIDIDDDDIDIIDIIDDDIDDIIIIIIDDIIDDIDIDIIDDDIIDIDIIIDDDIIDIIDDIIDDIDDIIIDDIIIDDDDIIDDDIIDIDIIDIDDIDIIDIDIDDIDIDIIIIIIIIDDDIIIIDDIDIIDIDIIDIDDDDIIDDIDIDIIDIDIIIIDIDIDDDIDDDDDDDDIDDIIDDIIDIDDIIIDIDIDDDIDIIIDDIIIIIDDDIDDIDDDIDIIIIIIIDDIDDDIIIDDDIDIDIIIDIDIIIIDDDDIIIIDDDDIDIDIDDDDDIIDIIIIDDIDDIIDIIIIDDIDIDIDIIDDIIDDDIIIDIDDIDDDDDDIDIDIDIDDIIIDIDDIIDIIDIDDIIDIIDIDIIDDIIIIDIDDDIDIIIDDDDIDDDIDIIIIDDDDIDIIDDIDIIDDIDDIDDIDDIIIDDDDIIIDIIDDIDDIDDDDIIDIIIIIIIDIDIDDIDDDIIIIIIDDDIIIIDDDDDDIIDIIDDDDDDIDIDDDDIDIDDDDDDIDDIDDIDDIDIIIDIDDDDDIIDDDIIDDDDDDIDDIDDDDDIIDDDIIIIDIIIDDIIIIDIDIDIDIDDDDDIDDDDIIDIDIDDIIIDIIDIIDDDIDDIDIIIIIDDIIDDDIIIIIDDDDDIDIIIIDIIDDDIIDIIIDDDIIDDIDIDDIDIDIDIIIIDIIDDIIDDIDIIIIDIDIIDIDDIDIDDIDIDIDDIIIDIIDDDIDIIIDIDDIDIDIIIIIDIDIIIIDDIIDIIDDIIIDDDIIIIIIIDDIIIIDDDIIIDDIDDDIIDIIIIIDIDDDIDDIIIIDIDIIDDDIDIDIDDDDDDDDIIIIIIIIIDIDIIDIIIIIIIDIDDIIDDIDDIIDDIDIDDDIDIDIDDDIDIDIIDDIIDIDIDDDDIDIDDDDDDIIIIIDDIIIDDDDIDDDDDDIDIIDIDDIDIIDIIDIIIDIDDIDIDDDIDIDIDIIIIIIIDIDIIDIDIDIIDDDDDDDIDDIIIIDDDIDDIIDIIDIIDIDIDDIDIIIIDDDDDDIIIIIIIDIIDDIDDIIDDDDDIIIIIIDDIDIIIDDDDIIIIIIIDIDIDDDIDIDIIDIIIIDIIDIDIIDIDIDDDIDDIIIDDIIIDDDDDIDDDDIIDDIDDIIDDDDDIIIIDIIIDDIIDDDDDIDDDIIDDDDDDIDIDIDDDDDDIIIIIDIIDDDDIDIIDIIDIDIDDDDDDDIDIDDIIIIDIDIIDDDIDIDDIDDIDDIDIDIIDDIDDDDDIDIDIDIDDDDDDIIDIIIIIIIIDDDIIIDIIIDDIDDDDIIIDDIDIIIDIIIDDDIDIIDDIIIDIDDIIIIDDDIIDIIIDDIDIIIIDDIDIIIIIIIDDIIIDIDDDDDDIDIIDIDIIIDIIIDDIDDIIIIIIIDIIIDIIDIIDDIDIDIDIIIDDDIIDDDIIIIIIIIIDDDIIDIDDDDDIIDDIDIDIDIIIDIDIIIDIIIDDIDIDIDDDDDDIIDDIIIIDDDDIIIDIIDIDDIDIIDIIIDIDIDIIIIDIIIIIDIIIIDDIDIDDDDDIDIDIDIIIDIDDDDDIIDIIDDDIIIDIIIDDIDIIDDDDDDIIIIDDIDDDIIDIIDIDDDDIIDIDDIIIDDDIDDDDDIDDDDDDDDIDDIDDIDDDIDIIIIIDDDIIIIDIIIIIIDDDIIIIIIIDDDIIDDDIIDIIDIIIDDIDIDIDDDDDIIIIDIIDDIIIDDIIIIDIIIIDIIDDDIDIDIDDIIIIDIIDIDDDIDDDDDIDIDDIIIDIDDDDDDDIDIDDDDIIIIIDIIIIDDDIDIDIIIIIDIDIDDIIIDDDDIIDDIDIIDDDDDIIIDDDDDDIDIIIDIIIIIDIDIIDDIIIIIIIIDDDDIIDIIDDDDIDDIDDIDIIIIDIDIIDDDIDIDIIIDDDIIDDIDIDDIDIIDIDDDDDDIDIIDIDDDIDIIIIDDIIDIIIDDDDIDIIIDIDIIDIIIDIIDIDDDDIIDIIIIIDDDIDDIIDDDDIIIDDDIDDDIIIIIDDIDIIDIDIDDIIDIIDIDIDDIIDDDDIDDIIIIIIIIDIIIDIIDIIDDDIIDDDIDIDIIDIIDDDIDIIDIDIDIIIIIIIDDIDIIDIIIIDIIDDDDIIIIDDDDDDDIDIIIIIDDDIDIDIIIDIDIIIDIDDIIDIIIDDIDDDIDIDDIIIIIIIDIDIDIDDIDDDIDIDIDIDIDIDIIIIIIIDIDIDIIIIDDIIDIDIIIDIDDDIDIIIDIIDDIDIIIIDIIIIDIDDDIDDDIDIDDIIDIIDDDDDIIIDIDDIIDIDDIIDIIIDDDDIIIDDDDIDIIDIIDDDDDIIIDIDDDIIDIDIDDIIDDDDDIIDDIDDDDIIDDIDDIDDDIDIIIDIIIIDIDIDIDIIIDIDDIDDIDDIIDIIDDIDIIIIDIIDIIIDDIDIDDIDIDIDIIDIDIIDDIIIIDDIIIDIDIDIIIDIIDDDDIIIIDDIDIIDDDIDIIDDDDDDDDIIDIIDIDIDDDIIIIIDIDIIDIDDDIDIDIDIIDDIIIIIDIDDDDIDIDDDDDDDDDIDDIDIDIDDIIIIDDDIDDIDDDDIIDIDIIIDIIIDDIDDIIIIIIDIDDDIDIIIDDDIIDIDDDIDDIDDDIIIIIIDDDIDIDDIDIDDIDDIDDDDDIIDIDDDDDIIIIIIIDIIIIDIDIDIDDIDDDDDIIIIDDIIIDDIIDDIIIDIIDDDDDDIDIDDIDIIIDDIDDDIDDDIIIIIDIDDIIDIIDIDDIIDIIDDIDDIDDIIDDIDDDIIIDIIIDIDIIIIDIDDIDDIIDIIIIDIDDDDDDIDDDDIDDIIDIDIDDIDIDIDDDDIDDIDIDDIDIDDIIIIDIIDDDDIDIIDDDDIDIDIDIDDIDIIIDIDDDDIIDIIIIDIDDDIDIDIIDDIDDIIIDIIDDDIIDDIDDDIIDDDDIIDDDDIDIIDIDDDDIIIIIDDDDDIIIIIDDDDIIDDIIDIIIIDDDIDIDIDIDDIDDIDIDIIDIIDDIIDIDIDDIDDDIIIDIIDIDIIIIDIDDIIDIDDDDIIDIDDDIDIIIDDDIDDIIDIIDDDIDIDIDIDIIDIIDIIDIDDDIDDDDIIIIDIDIDIIIDIDIIDIDIDIIDIIIDIDIDDIIDDDIDIDIDDDDIDDIIDIIIDDIIIDIDDIDIIDIDDIIDDIIIIDDDDDDDIDIIIIDDIIIIDDDIIDIIIDIDIDIIIIDDDDIDIDIIDIDDIIDIDDIDIIIIIIDDDIDIIDIIDIIDDIDIIIDDIIDIDDIIIIIDIIIDDIIIIIIIIIDIIIDIIIIIDIDDIDDDDIIIIDIDIIIIDDDIIDDDDIIIIIDIDDIDDDIIIDDIIDDDDIIDIIDDIIIDIDIDDIIDIDDIDDIIIIDIDIDDIDIIDIDDDIIDIDDDDDIDIDDIDDIIDIDDIDIIDDDDIDDIIDDDIIIDIDIIDIDIDIIDDIDDDIIIDIIDIIIIIDDIDIIIDDDDIIDIDIIIDIIIDDDDIDIDDDIDDIIIDIDDIIIIDIDDIDIDIDDDDDDDDDIDDIDIIIDDIDIIDIDDIDIIDIIDDDDIIIIIDIDIDIDDIDIDIDDIIDIIIIIIIIIIIDDIIDDDDIDIIDDDDIIIDIIDDDIIDIDDDIDIDDDIDDDIIDIDIIIIDDIDIDIIDDDDIDDIIIDIIIIDIDIDDDIDDIIDDIDDIIDDIIDDIDDDDDDDIDIDDIIDIDIDDIDIIIDDIIIDDDIDDIIIDDDDIDIDDDDDDDIIIIDIIDDDIDIDDIIIIDIIIIIDDIIIIDDDIIDIDIIDDIIDDDIDDIDDDIDDIIDIIIDDDDIIDDDIIIDDIIIIDIIDDIIIIDIIIDIDIIIIIDDDDIDIDIDIDDIIDIIDDIDDDDIDIIIIDDIDIIDIIDIIIDDDDDIIDDDIIDDDIDIDIDIIDIIDIDDDIDIDDIIIIIDIDDIDDDDIIDIIDDIIDIIIIDDIIIIDIIIIIIDDIDDDIIDIDIIDDDIDDIDIDIDDDDDDDDDDIDIIIIIDDDIIIDDDDDDDIDDIIIDDIIDIIDDDIDDDDDDIDIIDDDIIIDDIIDDDIDIIDDDDIIIIDIDIIIDIDIDIIDDDDIIDIDIDIIDDIIIDIIIIDIDIDDIIIDDIIIIIIIIIIIIDIIIIDIDDDIIDIIDIDDDIDIIIDIDIDDIIDDDIDDDIIDIDDIIIIDDIIIDIDDIDIIDDDIDIDIDDIDIIDDIDIIIIIDIDDIIIDIDDIIDDIDDDIDDIDDDDDDIDIIDDIDDIIIDIDDDDIIDDDDDDDIIIIDIIIIDDIIDDDDDIDIIIIIDIIDIDDIIDDDDIIDIIIIIIDIDIIDIIIIDDIIDIDIDDIIIIDIDDIIIIDDIDIIIIIDIDIDDIDDIIIDDIDIDIDDIDIDDDIDDDIIIDIIIDDIDDIIDDIDDDIIIDDIIDIDDIDDIIDDDIDIDDDIIDDDIIDIIDIDDIDIIIDDDDIIDIDDIDDDIDDIDDIDDDIIDIDDDDIDIDDDIDDIDIDDIDDIDIIIDDDIDDDIIDIDDDIDIDDIDDIDDDDDDDDIDIDIDDDDDDDIDIIIDIIDDDIIDIDIIIIDDDDIDDIDIIDDDDIIIIDIIIIDDIIDDDDDDIDIIIIIDDIIDDIIIDIIIIDDIIDDIDDDIDIDIIDIIIDDDIDDDIIDDDIIIDIDDIDDDIDIIIDIDDDDIDDIIIDIIDDDIDIDIIIDIDDDIIIIDIDDDIDIDIDIIIIDIDDDIIDDDIDIIDDDDDIIDIDIDIIDDIDDIDDDIIIIIIIIIDDIIDIIIDIDIIDIIIIIIIDDIIDDIIDIIDIDIIDIIDDIIIIIDIDDDDDIDDIDDIDDDIIIIDIDIDDIIDDIIDDIIIDIDDDIIDIDIDIIIDIDIDDIDIIDIDIIIDDIDIIIDIIDDIDIDDDIDDDIDIDIDDDIDDIIIIDIDIDIDIDDIIDDIDIIIIIDIDDIIIIIDIIIIDDIIDDIDDIDIIDIIDDIDDDDIIIIDIDIIDDDDDIIIIDIIIDDIIIDIIIIDIDIIIIIIDDIIDDIDDIIIDIIDIDIIIDIIIIDIIDDIIIIIDDIIIDDIIDIDIDDDDDIIIIDIIDDDIIDDIIDIIDIIDIIDIIIDDDIIDIDDDIIDDIDIDIIIDIIIDIIIDDIDIDIDDDIDDDIIDIDDDIDIIDIDIDDDIIDDIDIIDIIDDIDDIIDDDDDDDDDDDIIDDDDIDIIIIIDDDDDIDIIIDDIDIIIIIIDIIIDDDIDDIIIDIIIDIDIDDDDDIIIIIDDIDIDDDDIIIIDIDDDIIIIDDIIDIDIIIIDDDDDDDDIIIIDIDIDDIDDDDIIIDDDIIIIIDDIDIDIDIDIIIDIDDDIIIIIIDDIDDDIIIDIIDDDIIIDIDDIDDDIDIIIIIIIIDIDDIIIDIIIIDDDDIIIDIIDIDIIIIIIDIDDDDDIIIIIDIDDDIDDIIDIDDIDDIDIDDIIIDDDDIDIDDDDDDDDIIDIDIDDIDIDDDDIIDIIIDDDIDDDIIIIIIDIIDIIDDDIDDIIDDIIDIDDIDIIIIDDIDDIIIIIIDDDDDIDDDIDIDDDIDIIIIIIDDDIIIIDIDIIDDIIIIIIDDDIIIDDDIIDIDDDIIIIIDIIIDIIIIIIDIDIDIIDDDDIIIIIDDDIDDIIIDIIDDDIDDIIIDDIIIIDDDDIIDDIIIIDIIIDIDDIDIIDDDDIDDIDDDDIDDIDDIIDDIIDIIIIDDDDDIIIDIIIDIDIIIDDDIDIDDDDDDIIDIIIIDDDDDDDIIIDIIIDIIIIDDIIIDDDIIIIDDDIIIIIIIDDDIIDIDIIDIIIIDIIIIIIDDIIDIDDIIDDDIIDDIDIDDIIIIDIDIIDIDDIIDDDDDDDDIIIIIIDIIDDDDIIIDIDIIDIIDIIDIIDDDDDDIIIDDIIIIIDDDIIIIDIDIDDDDDIIDDDDDDIDIIDIIIIIDIIDDIIIDIDDIDDIDDIDIDDDDDIIIIIIIIDDIDDDDDDIDIIDIIIIIIIDDIDIIIDDDIIDDDIDDDDIDDDIDDIIIDIIDDDDIDDIDDIIIIIIDIIIIDDIIIIIDDDDDIIDDIDIIIDIDDDIDDIIIIDIDIIIDIIDIIDDIDIIIDIIDDIIIDIIDIIIDIDDIIIIIIDIIDDIIDIDDDDIDDIDDDIDIIDIDIDDDDDIDDIDIDDIIIIDDIDIDDIDIIDDDDDDDIDDDIIIDDIIDIDIDDDIIIIIIDDIIIIIDIDDIIIIDDIIDIDIIDDIIDIIDDIDIDDDDDIDDIDIDIDDIDDIDDIIDIDDDIDDIIIIIIIDIIIIDDIDIDDDDDIIDDIIIDDIIDDDDIDDIDIDIIDDIIIIIDIDDDDDDDIDIIIDIDDDDDDDDIIDIIDDIDDIIIIDIIDDIIDIDIIDIIIIDDDDDDIDIDIDIIIIIIDIDIIDIDDDDIDDIDIIIIIIDDDIIDIDDDIDDIDDDDDIIIIIIDIIDDIDDIIIIIIIDDIIIIIIIIDDDIDIIDIIDDIIIIIIIDIDIIIIIIDIDIDDIDDDIIIDDDIDDIIIDIIDIDDIIDDDDDDDIDIIIIIIIIIDDDDIIIDDIIIIDIIIDIDIIDIDIIIDDDDIDIIDIIIDIIDIDIDDDDDIIDDIIIDIDIIDDDDIDIDDIIDIIDDIDDDDIDIDDIIDIDDDIIIDDDIIIIDIIDDIIDDDIDDIIDDDDDDIDIDDIDDIDIIIIIIIIIIDIIIDDDIDIIIIIDDDIIDDIDIIIDIDIDIDDDDDDDIIDDDDIDDIIDDIDDDDIDDIIDDDIDDIDDDIIIIIDIIDDIDDDDIIDDDDDIDIDDDDIIIIIDDIDDIDIDIIIIDIIDIDIDDDDDIDIDIDDDIIIIDIDDIDDDIIDIDDDDDIDDIDIIIDIIIDDIIIDIIIIIIDIIIDDDIDIIIDDIDIDIDDIIIIDDDIIDIIIDDIDIDIIIIDIDIDIDIDIIDDIIDIIIIIDDIDIDIIDDIDIIDDIIDDIDDIIDDIDDIDIIDDDDDDIIIDIDIIIIIDIDDDDIDIIDDIDDIDIIDDDDIIDDDDDIIDIIDIIIDIIIDIDIDIIIDDIIDDIIIDIIDDDDDIIIDDDIIDDDDDIIDDIIIIDDIDIDDDDDDDDDDDIDDIDIDDIDDDDIDIDDIIDIDIIIIIDDDDIDDIDDIDDIDIDIDIIIIIIDIDDDDIDIDDDIIDIDIDIDIIDIIDIDDIDIDDIDDDIIIIIIIDIIDIIDIDIDDIIIIDIDIDIIDDDIIIIDIDIIDIDIIIIIDDDIIDDIDIIIIIIDIIIDDIIIDDDDIDIIIDIDIDIDDIDDIIIDIDIDIIDDDDDIDIDDDIIDDDDDIIDDDDDDDIIIIIDDIIDIDDIDDDIIIIIDIDIDDDIDDDIIDIIIDDIIDDDDIIIIDIIIDDDDDIIIIIIIIIDIDDIIIIDIIDIIDIIIDIIIDIDDDDIDDDDDIIIIDDDIIIIDDIDDDDDDDIDDDDDDIDIIIDDIDIDDDDIDIIDIIDIDDIDDDIIDDIDIIIDIIIIDDIDDIIIDDIDDIDIDDDDIIIIIDDDIDDDIIDIIIIDDDIIDDIIDIIDIIDIDIIDDDDDIIDDDIDIIIIDIDDDDDIIIIDIIIDDIDIDDDDIDDIDIIIDIDDIDIIDDDDDDDDDDIDIDDDIIIIDDDIIDIDDDIDIIIDIIIDDDIDDIDDIIIDIIDIIDDDIIDIDDIIDIDDDIDIDIIDDIIIDDIIDIDDIIDIIIDDIDDDIDDDIIDIIIIDDIIDDDDIDIDIIDIDDIIIDDDDDDDIDDDIIDDDIIDDIDDIDDDIDIDIDDDIDDDDDIIIDDDIDDIDIDDDDIDDDDDDIDIDIIIIIIDDIIDDDIIDIIIDIIIDIDIIDIDIDDDIIIIDDIIIDDIDIIDIIDDDIDIDIDIDDDDDIIIDDDDDIDDDDDDDIIIDDIIIDIIIIIIIIIDIDIIIDDIDDIIIDDDDDIDDIIIDIIDIIIIIDIDIDIIDIDDDDDIIIDDDDIDIIIDDDIIIDDIDDIIIDIDIIDIDDDIDDIIIIDIDIIDIDIIDDDDIDIDDDDDDDDDIDDDDDDDIDDIDDIIIIIIIDDIDIIDDIDIDIDIDDIDDDIIIIIDDDDIIDIDIIDIIIDIIIDIDDIDDDIDDDDIIIDDDIDDIDDIDIDDIIIDDIDIDDIDDIDDIIDDDDIIDDIIDIIIIDIIDIDIIDDIDDIDIIDIIIDIIDIDIDIDIDIDDIIIIIDDIIIIIIDIIDDDDDIDDIIDIDDDDDIDIDDDDIIDIDDDDDDIDDDIIDDIIIDIDIIDDDDIIDIIIDIDDIIIDDDIIDIDDDDDDDDDDDDIDDIIDIIDDDDIIDIDIDIIDIDDIDIDIIIIDDDIDIDIIIIIIIIIDDIDDDDDDIIIIDIDDDIIIDDDIDIDIDIIIIDIIIIIDDDIIIIIDIIIDIIIDDDDIDDIIDDIDIDIIIIIIIDIIIIDIIDDIIIDIDIDIIDDIIIDIDDDDIDDDDIIDIIIDIDIDDIIDDDDDDDIIDIDIIDDIIDIDDIDDIIIIDDDDDIDDIIDDDDIIDIDDDDDDDDDIDIDIIDIDIIDDDDDDIDDDIDIIDIDDDDIIDIIIDDIIDDIIDIIIDIIIDIIDIIIDDIDIIDDIDDIDIDIIIDDDDDDDDDIDDIIIIIIDIDDIIIDDIDDIDIDDDIIDIDDDIIDIIIDIIIIDIDIIDDIDIIIIIDDIDDIIDDIIIIDDDDIDIDDDDDDDDDDDDIIIDIDDDIIIIDDDDDIIDIIIIDIDIIDDDDIIIIDDDDIDDIDIDIIDIDDDDDDIIIIDIIDIDDDDIDDDDDDIDIDIDIIIIIIDDIDIDIDIDDIIDIIIIDDIIDDIIDDIIDIDDDDDIIDIDDDIDIIIIIDDIDIIIIIIIDIIIIIIIIIIIDIDIIIDDDDDDDDIDDIDIIDIDDIIIIIIIDIIDDIIDIIIDDIDIIIIIIIIDDDIDIIDIIDDDDDIIDIIIIDDDIIIIIDIDDDDDIIIIDDIIDIIDDDIIDDDDDDDIDDIDIDDDIDDDIDIIDIDIIIDIIIIIDIDIIDIDDIDIIIDIDDDIIIDDDDIIDDIIIDDIIIIDDIIDIIDIIIDIDDIDDIDIDDDDDIIIIIDIIDIIDDIIDIDIIDDIDIDDDDIDDDDIDIDIDDIIDDDIDIDIIDDDDIIDIDIIIIIDIIIDIDIIDDDIDDDDIIDIDI");
    cout << "DI Vector:" << endl;
    printVec(diString);
    std::cout << std::endl;
}
