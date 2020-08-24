#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        char A = 'A';
        char Z = 'Z';
        
        //Loop through all the letters and set to lower case
        for(unsigned currIndex = 0; currIndex < str.size(); ++currIndex){
            if(A <= str[currIndex] && str[currIndex] <= Z){
                str[currIndex]=str[currIndex]+32;
            }
        }

        return str;
    }
};


int main(){
    Solution s;
    std::cout << s.toLowerCase("AlCaponDeR") << std::endl;
    std::cout << s.toLowerCase("ZeeerrRMAT") << std::endl;
    std::cout << s.toLowerCase("BAD%guY$$Wx*") << std::endl;
    std::cout << s.toLowerCase("yuPP`/\\") << std::endl;
    std::cout << s.toLowerCase("zapDoS") << std::endl;
}
