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
    bool judgeCircle(string moves) {
        //Maintain an up/down count and a left/right count
        int vertDisplacement = 0;
        int horizDisplacement = 0;

        for(char c : moves){
            switch(c){
            case 'L':
                --horizDisplacement;
                break;
            case 'R':
                ++horizDisplacement;
                break;
            case 'U':
                ++vertDisplacement;
                break;
            case 'D':
                --vertDisplacement;
                break;
            }
        }

        return horizDisplacement == 0 && vertDisplacement == 0;
    }
};

int main(){
    Solution s;
    cout << s.judgeCircle("LLRR") << endl;
    cout << s.judgeCircle("LRLR") << endl;
    cout << s.judgeCircle("LRLRU") << endl;
    cout << s.judgeCircle("LRLRUD") << endl;
    cout << s.judgeCircle("LURD") << endl;
    cout << s.judgeCircle("LL") << endl;
    cout << endl;
}
