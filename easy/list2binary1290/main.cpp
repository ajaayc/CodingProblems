#include <unordered_set>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

/*
  This solution takes O(N) time and O(1) memory, where
  N is the number of nodes in the linked list to which
  head points.
 */
class Solution {
public:
  //Assumes that the list is not empty
  int getDecimalValue(ListNode* head) {
    ListNode* curr = head;
    int num = 0;

    while(curr != nullptr){
      int bit = curr->val;
      num = ((num << 1) | bit);
      curr = curr->next;
    }

    return num;
  }
};

ListNode* listFromVec(std::vector<int>& input){
  ListNode* head = nullptr;
  ListNode* curr;
  
  for(unsigned i = 0; i < input.size(); ++i){
    ListNode* nextNode = new ListNode(input[i]);

    if(head == nullptr){
      head = nextNode;
      curr = head;
    }
    else{
      curr->next = nextNode;
      curr = curr->next;
    }

  }

  return head;
}

void freeList(ListNode*& head){
  ListNode* curr = head;
  while(curr != nullptr){
    ListNode* prev = curr;
    curr = curr->next;
    delete prev;
    prev = nullptr;
  }

  head = nullptr;
  
  return;
}

void freeListRecursive(ListNode*& head){
  if(head == nullptr)
    return;

  ListNode* next = head->next;
  delete head;
  head = nullptr;

  freeListRecursive(next);
}


void processTest(std::vector<int>& input){
  Solution s;
  int output;
  std::cout << "Input:\n";
  printVec(input);
  ListNode* in = listFromVec(input);
  output = s.getDecimalValue(in);
  std::cout << "Output:\n";
  std::cout << output << std::endl;

  freeListRecursive(in);
}

int main(){
  std::vector<int> input;

  input = {1,0,1};  
  processTest(input);

  input = {0};
  processTest(input);

  input = {1};
  processTest(input);

  input = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
  processTest(input);

  input = {0,0};
  processTest(input);

  input = {1,1};
  processTest(input);

  input = {1,1,1,1};
  processTest(input);

  input = {1,0,0,0,0};
  processTest(input);
}
