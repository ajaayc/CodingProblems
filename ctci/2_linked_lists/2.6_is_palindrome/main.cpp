#include <unordered_set>
#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

//Definition for singly-linked list.
template <typename T>
struct ListNode {
  T val;
  ListNode *next;
  ListNode() : val(T()), next(nullptr) {}
  ListNode(T x) : val(x), next(nullptr) {}
  ListNode(T x, ListNode *next) : val(x), next(next) {}
};

template <typename T>
void printVec(const std::vector<T>& vec){
  for(auto it = vec.begin(); it != vec.end(); ++it){
    std::cout << *it << " ";
  }
  
  std::cout << std::endl;
}

/*
  This solution takes O(N) time and O(N) memory, where
  N is the number of nodes in the linked list to which
  head points.
 */
template <typename T>
class Solution {
public:
  //This solution creates a reversed version of the input list
  //and then compares the input and reversed list node by node.
  //Uses O(N) time, O(N) memory, where N is the number of nodes
  //in the input list.
  //Assumes that the list is not empty
  bool isPalindrome(ListNode<T>* head) {
    std::stack<ListNode<T>*> s;

    unsigned numNodes = 0;
    
    //Reverse the list with a stack
    ListNode<T>* curr = head;
    while(curr != nullptr){
      s.push(new ListNode<T>(curr->val, nullptr));
      curr = curr->next;
      ++numNodes;
    }

    //Create reversed list
    ListNode<T>* rhead = s.top();
    s.pop();

    curr = rhead;
    
    while(!s.empty()){
      ListNode<T>* next = s.top();
      s.pop();

      curr->next = next;
      curr = curr->next;
    }
    
    //Go through list in order and compare to values in stack for palindrome
    ListNode<T>* curr1 = head;
    ListNode<T>* curr2 = rhead;
    
    bool isPal = true;
    unsigned nodeCount = 0;
    
    //Loop through input and reversed input
    while(curr1 != nullptr){
      if(curr1->val != curr2->val){
	isPal = false;
	break;
      }
      
      ++nodeCount;

      //Small optimization to avoid looping through whole list
      if(nodeCount == (numNodes / 2)){
	break;
      }
      
      curr1 = curr1->next;
      curr2 = curr2->next;
    }

    freeListRecursive(rhead);

    return isPal;
  }

  //This version uses a stack and the values in the input list
  //to determine if the list is a palindrome.
  //Uses O(N) time, O(N) memory, where N is the number of nodes
  //in the input list.
  //Assumes that the list is not empty
  bool isPalindromeStack(ListNode<T>* head) {
    /* To be implemented*/
    std::stack<T> s;

    ListNode<T>* curr = head;
    while(curr != nullptr){
      s.push(curr->val);
      curr = curr->next;
    }

    //Go through list in order and compare to values in stack for palindrome
    curr = head;
    T currVal, listCurrVal;


    bool isPal = true;
    while(curr != nullptr){
      currVal = s.top();
      s.pop();

      listCurrVal = curr->val;
      if(currVal != listCurrVal){
	isPal = false;
	break;
      }

      curr = curr->next;
    }

    return isPal;
  }

};

template <typename T>
ListNode<T>* listFromVec(std::vector<T>& input){
  ListNode<T>* head = nullptr;
  ListNode<T>* curr;
  
  for(unsigned i = 0; i < input.size(); ++i){
    ListNode<T>* nextNode = new ListNode<T>(input[i]);

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

template <typename T>
void freeList(ListNode<T>*& head){
  ListNode<T>* curr = head;
  while(curr != nullptr){
    ListNode<T>* prev = curr;
    curr = curr->next;
    delete prev;
    prev = nullptr;
  }

  head = nullptr;
  
  return;
}

template <typename T>
void freeListRecursive(ListNode<T>*& head){
  if(head == nullptr)
    return;

  ListNode<T>* next = head->next;
  delete head;
  head = nullptr;

  freeListRecursive(next);
}

template <typename T>
void processTest(std::vector<T>& input){
  Solution<T> s;
  int output;
  std::cout << "Input:\n";
  printVec(input);
  ListNode<T>* in = listFromVec(input);
  output = s.isPalindrome(in);
  std::cout << "Output:\n";
  std::cout << (output ? "true" : "false") << std::endl;

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

  input = {1,0,0,0,1};
  processTest(input);

  input = {1,2,0,0,1};
  processTest(input);

  input = {'a','b','a'};
  processTest(input);

  input = {1,0,0,1,0,0,1,0,1,0,0,1,0,0,1};
  processTest(input);

  input = {1,0,0,1,0,0,1,0,0,0,0,1,0,0,1};
  processTest(input);

  input = {1,0,0,1,0,0,1,1,0,0,1,0,0,1};
  processTest(input);

  input = {1,0,0,1,0,0,0,1,0,0,1,0,0,1};
  processTest(input);
  
  std::vector<char> input2;

  input2 = {'a','b','a'};
  processTest(input2);

  input2 = {'a','b','a','c'};
  processTest(input2);

  input2 = {'a','b','b','a'};
  processTest(input2);

  input2 = {'a','b','b','d'};
  processTest(input2);

  input2 = {'1','1'};
  processTest(input2);

  input2 = {'z'};
  processTest(input2);

  input2 = {'d','a','b','a','d'};
  processTest(input2);
}
