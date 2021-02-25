#include <vector>
#include <iostream>

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void printMat(const std::vector<std::vector<T>>& mat){
  for(auto it = mat.begin(); it != mat.end(); ++it){
    printVec(*it);
  }
}

class Solution{
public:
  //Let r = number of rows in input. Let c = num Cols in output
  //This algorithm uses O(rc) memory and O(r^2 + rc) time...or O(max(r^2,c^2)) time. i.e.
  //If r > c, the algorithm is O(r^2) time and if c > r, the algorithm is O(c^2) time.
  std::vector<std::vector<int>> zeroMatrix(const std::vector<std::vector<int>>& input, unsigned numRows, unsigned numCols){
    std::vector<int> tempRow(numCols, -1);
    std::vector<std::vector<int>> output(numRows, tempRow);

    for(unsigned currRow = 0; currRow < numRows; ++currRow){
      for(unsigned currCol = 0; currCol < numCols; ++currCol){
	if(input[currRow][currCol] == 0){
	  //Zero out row r in output
	  for(unsigned currColInOutput = 0; currColInOutput < numCols; ++currColInOutput){
	    output[currRow][currColInOutput] = 0;
	  }

	  //Zero out col c in output
	  for(unsigned currRowInOutput = 0; currRowInOutput < numRows; ++currRowInOutput){
	    output[currRowInOutput][currCol] = 0;
	  }

	  //Go to next row
	  break;
	}
	
	else if(output[currRow][currCol] != 0){
	  output[currRow][currCol] = input[currRow][currCol];
	}
	
      }
    }

    return output;
  }
};

void processTest(const std::vector<std::vector<int>>& input){
  Solution s;
  std::vector<std::vector<int>> output;
  output = s.zeroMatrix(input, input.size(), input[0].size());
  std::cout << "Input:" << std::endl;
  printMat(input);
  std::cout << "Output:" << std::endl;
  printMat(output);
}


int main(){
  std::vector<std::vector<int>> input;
  input = {{4,7,6,0,1},
	   {9,3,7,2,4},
	   {6,4,12,14,13},
	   {9,0,-1,2,4}};
  processTest(input);


  input = {{4,7,6,0,1},
	   {0,3,7,2,4},
	   {6,4,12,14,13},
	   {9,0,-1,2,4}};
  processTest(input);

  input = {{4,7},
	   {0,3}};
  processTest(input);

  input = {{4}};
  processTest(input);

  input = {{0}};
  processTest(input);

}
