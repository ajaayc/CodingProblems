#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

class Solution{
public:
  virtual void getPermutations(const string& in, std::vector<string>& perms) = 0;
  virtual string getMethod() = 0;

  virtual ~Solution(){}
};

class SolutionDuplicateChars : public Solution{
public:
  virtual void getPermutations(const string& in, std::vector<string>& perms){
    return;
  }

  virtual string getMethod(){
    return "--Permutations with Duplicate Chars--";
  }
};

//O((N + 1)!) time
//O(N) memory
//N is the length of the input string.
class SolutionNoDuplicateChars_V2 : public Solution{
public:
  virtual void getPermutations(const string& inStr, std::vector<string>& perms){
    if(inStr.size() == 0){
      return;
    }

    string inStrCopy(inStr);
    getPermutationsHelper(inStrCopy, perms, 0);
    return;
  }

  virtual void getPermutationsHelper(string& in, std::vector<string>& perms, unsigned index){
    if(index == in.size() - 1){
      perms.push_back(in);
      return;
    }

    for(unsigned currIndex = index; currIndex < in.size(); ++currIndex){
      //Swap currIndex with first character to signify making a "choice"
      std::swap(in[index], in[currIndex]);

      //Permute and make choices for substring
      getPermutationsHelper(in, perms, index + 1);
      
      //Undo swap
      std::swap(in[currIndex], in[index]);
    }
  }

  virtual string getMethod(){
    return "--Permutations Duplicate Chars Version 2--";
  }
};

class SolutionNoDuplicateChars : public Solution{
public:
  virtual void getPermutations(const string& in, std::vector<string>& perms){
    if(in.size() == 0){
      return;
    }

    std::vector<string>* permptr = new vector<string>();
    getPermutations(in, 0, permptr);
    perms = *permptr;
    delete permptr;
    permptr = nullptr;
    return;
  }

  virtual void getPermutations(const string& in, unsigned begin, std::vector<string>*& subPerms){
    if(begin == (in.size() - 1)){
      stringstream temp;
      temp << in[begin];
      subPerms->push_back(temp.str());
      return;
    }

    getPermutations(in, begin + 1, subPerms);

    //Loop through permutations, append in[currIndex] in each part
    vector<string>* newPerms = new vector<string>();
    for(unsigned subPermsIndex = 0; subPermsIndex < subPerms->size(); ++subPermsIndex){
      string& currPerm = (*subPerms)[subPermsIndex];

      stringstream s;
      s << in[begin] << currPerm;
      
      string newPerm = s.str();
      newPerms->push_back(newPerm);
      
      for(unsigned currChar = 1; currChar < newPerm.size(); ++currChar){
	std::swap(newPerm[currChar - 1], newPerm[currChar]);
	newPerms->push_back(newPerm);
      }
    }
      
    delete subPerms;
    subPerms = newPerms;

    return;
  }

  virtual string getMethod(){
    return "--Permutations No Duplicate Chars--";
  }
};
  
void processTest(string in, vector<Solution*> sols){
  for(auto it = sols.begin(); it != sols.end(); ++it){
    std::vector<string> permutations;
    (*it)->getPermutations(in, permutations);
    cout << (*it)->getMethod() << endl;
    printVec(permutations);
  }
}


int main(){
  Solution* s1 = new SolutionNoDuplicateChars();
  //Solution* s2 = new SolutionDuplicateChars();
  Solution* s3 = new SolutionNoDuplicateChars_V2();
  std::vector<Solution*> sols = {s1, s3};

  processTest("abcd", sols);
  processTest("abc", sols);
  processTest("ab", sols);
  processTest("a", sols);  
  processTest("", sols);  

  for(Solution* s: sols){
    delete s;
  }
}
