#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

class Solution {
public:
  //Algorithm uses O(N) time where N is len(s), and it uses
  //O(N) memory. Can we reduce this to O(1) memory by
  //modifying the input's characters in place?
  string restoreString(string s, vector<int>& indices) {
    string out(s);

    for(unsigned i = 0; i < indices.size(); ++i){
      out[indices[i]] = s[i];
    }

    return out;
  }
};

void processTestCase(string in, std::vector<int>& indices){
  Solution s;
  string out;

  std::cout << "Input:\n";
  std::cout << in << "\n";
  printVec(indices);
  out = s.restoreString(in, indices);
  std::cout << "Output:\n";
  std::cout << out << std::endl;

  std::cout << "-----------------------------------" << std::endl;
}

int main(){
    string in;
    std::vector<int> indices;
    string out;

    in = "codeleet";
    indices = {4, 5, 6, 7, 0, 2, 1, 3};
    processTestCase(in, indices);
    
    in = "abc";
    indices = {0, 1, 2};
    processTestCase(in, indices);

    in = "aiohn";
    indices = {3, 1, 4, 2, 0};
    processTestCase(in, indices);
    
    in = "aaiougrt";
    indices = {4,0,2,6,7,3,1,5};
    processTestCase(in, indices);

    in = "art";
    indices = {1, 0, 2};
    processTestCase(in, indices);
}
