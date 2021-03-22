#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void printStack(std::stack<unsigned>& st){
  cout << "TOP<---------------BOTTOM" << endl;
  while(!st.empty()){
    std::cout << st.top() << " ";
    st.pop();
  }
  std::cout << std::endl;
}

void printTowers(std::vector<std::stack<unsigned>> towers){
  cout << "-----------------------------------" << endl;
  cout << "Tower 1" << endl;
  printStack(towers[0]);
  cout << "Tower 2" << endl;
  printStack(towers[1]);
  cout << "Tower 3" << endl;
  printStack(towers[2]);
  cout << "-----------------------------------" << endl;
}

//Requires bufferIndex and targetIndex towers are both empty
//Moves disks in startIndex to targetIndex, using bufferIndex as needed
void towersOfHanoi_Helper(const unsigned numDisks, std::vector<std::stack<unsigned>>& towers, unsigned startIndex, unsigned bufferIndex, unsigned targetIndex){
  //Base case
  if(numDisks == 3){
    towers[targetIndex].push(towers[startIndex].top());
    towers[startIndex].pop();
    towers[bufferIndex].push(towers[startIndex].top());
    towers[startIndex].pop();
    towers[bufferIndex].push(towers[targetIndex].top());
    towers[targetIndex].pop();
    towers[targetIndex].push(towers[startIndex].top());
    towers[startIndex].pop();
    towers[startIndex].push(towers[bufferIndex].top());
    towers[bufferIndex].pop();
    towers[targetIndex].push(towers[bufferIndex].top());
    towers[bufferIndex].pop();
    towers[targetIndex].push(towers[startIndex].top());
    towers[startIndex].pop();
    return;
  }

  //Solving towers of hanoi for N disks is same as solving towers of hanoi for N-1 disks where we move the top N-1 disks to the buffer
  //tower (new target) and use the current targetIndex as the new buffer. Then we move the Nth disk to the targetTower and proceed to move the N-1 disks from the
  //buffer tower to the target tower using the start tower as the new buffer tower


  towersOfHanoi_Helper(numDisks - 1, towers, startIndex, targetIndex, bufferIndex);

  //Move top of startIndex tower to the targetIndex tower
  towers[targetIndex].push(towers[startIndex].top());
  towers[startIndex].pop();

  //Move towers from bufferIndex to targetIndex. Use startIndex as new buffer
  towersOfHanoi_Helper(numDisks - 1, towers, bufferIndex, startIndex, targetIndex);
}

void towersOfHanoi(const unsigned numDisks, std::vector<std::stack<unsigned>>& towers){
  towersOfHanoi_Helper(numDisks, towers, 0, 1, 2);
}


int main(){
  unsigned numDisks = 27;

  std::vector<std::stack<unsigned>> towers(3, std::stack<unsigned>());

  //Initialize tower 1
  for(unsigned i = numDisks; i >= 1; --i){
    towers[0].push(i);
  }
  printTowers(towers);

  towersOfHanoi(numDisks, towers);

  printTowers(towers);
}
