#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        stringstream ss;

        for(unsigned i=0; i < address.size(); ++i){
            if(address[i] == '.'){
                ss << "[.]";
            }
            else{
                ss << address[i];
            }
        }

        return ss.str(); 
    }
};

int main(){
    Solution s;
    std::cout << s.defangIPaddr("1.1.1.1") << std::endl;
    std::cout << s.defangIPaddr("255.100.50.0") << std::endl;
    std::cout << s.defangIPaddr("25.0.51.0") << std::endl;
    std::cout << s.defangIPaddr("2.10.524.0") << std::endl;
}
