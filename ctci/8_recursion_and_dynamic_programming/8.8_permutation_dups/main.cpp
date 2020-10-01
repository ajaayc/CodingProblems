#include <iostream>
#include <vector>
#include <unordered_map>

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

/*
  This solution is O(n!) time where n is in.size(). Note that it is much
  more efficient though than using the solution for non-duplicate chars
  and removing duplicates whenever we see them. This solution, by construction,
  automatically ensures no duplicates exit.

  Uses O(n) memory for recursion.
 */
class SolutionDuplicateChars : public Solution{
public:
  virtual void getPermutations(const string& in, std::vector<string>& perms){
    if(in.size() == 0){
      return;
    }

    //Get counts of all the characters
    std::unordered_map<char, unsigned> charCounts;
    for(char c: in){
      if(charCounts.find(c) == charCounts.end()){
	charCounts[c] = 0;
      }
      
      charCounts[c] += 1;
    }

    //Initialize a string of same size as in to build
    //permutations from
    string currPerm(in);    
    getPermutations(in, perms, charCounts, currPerm, 0);

    return;
  }

  virtual void getPermutations(const string& in, std::vector<string>& perms, std::unordered_map<char, unsigned>& charCounts, string& currPerm, unsigned charPosition){
    //Base case: charPosition is out of bounds
    if(charPosition >= in.size()){
      perms.push_back(currPerm);
      return;
    }

    //Loop through all characters in charCounts, make a choice for the charPosition
    for(auto it = charCounts.begin(); it != charCounts.end(); ++it){
      char choice = it->first;
      //If count is nonzero, make this as the choice, else go to next character
      if(it->second != 0){
	currPerm[charPosition] = choice;
	--charCounts[choice];

	//Recurse
	getPermutations(in, perms, charCounts, currPerm, charPosition + 1);
	
	++charCounts[choice];
      }
    }
  }

  virtual string getMethod(){
    return "--Permutations with Duplicate Chars--";
  }
};

void processTest(string in, vector<Solution*> sols){
  for(auto it = sols.begin(); it != sols.end(); ++it){
    std::vector<string> permutations;
    cout << "Test case: " << endl;
    cout << in << endl;
    (*it)->getPermutations(in, permutations);
    cout << (*it)->getMethod() << endl;
    printVec(permutations);
    cout << "Number of permutations: " << permutations.size() << endl;
  }
}


int main(){
  //Solution* s1 = new SolutionNoDuplicateChars();
  Solution* s2 = new SolutionDuplicateChars();
  //Solution* s3 = new SolutionNoDuplicateChars_V2();
  std::vector<Solution*> sols = {s2};

  processTest("abbd", sols);
  processTest("abccccaa", sols);
  processTest("a", sols);
  processTest("abcd", sols);  
  processTest("", sols);  

  for(Solution* s: sols){
    delete s;
  }
}
