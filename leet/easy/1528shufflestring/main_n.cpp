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
  //Algorithm uses O(1) memory, O(N) time, where
  //N is s.size(). In the worst case, the inner while loop
  //will rearrange the whole list and process N-1 swaps
  //until s[0] is in place...in which case the rest of s
  //will automatically be in the correct place.
  //The outer loop goes through the list once, and the
  //inner loop will only process at most N swaps.
  //Together, the number of loop iterations is linear in time.
  string restoreString(string s, vector<int>& indices) {
    for(unsigned i = 0; i < s.size(); ++i){
      while(indices[i] != static_cast<int>(i)){
	std::swap(s[indices[i]], s[i]);
	std::swap(indices[indices[i]], indices[i]);
      }
    }

    return s;
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
