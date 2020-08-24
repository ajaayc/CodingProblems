#include <unordered_set>
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cassert>

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
  //Gets the length of the input list in O(N) time, O(1) memory
  //where N is the number of nodes in the list
  unsigned getListLength(ListNode<T>* head){
    unsigned length = 0;

    ListNode<T>* curr = head;
    while(curr != nullptr){
      ++length;
      curr = curr->next;
    }

    return length;
  }  
  
  //SOLUTION 1
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

  //SOLUTION 2
  //This solution creates a reversed version of the input list
  //via a loop and then compares the input and reversed list node by node.
  //Uses O(N) time, O(N) memory, where N is the number of nodes
  //in the input list.
  //Assumes that the list is not empty
  bool isPalindromeReverseIter(ListNode<T>* head) {
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

  //SOLUTION 3
  //This is a recursive solution which uses O(N) memory for stack
  //frames, and O(N) time, where N is the number of nodes in the linked
  //list pointed to by head.
  //This solution first counts the number of nodes in the list. Then,
  //it recurses the list until it reaches the N/2'th node. After it
  //reaches that level, a tail node is populated that refers to the last
  //node of the current "sublist".
  //the recursion then bubbles up and repeatedly checks if the current
  //head and tail nodes are equal, updating tail to tail->next each time
  //the recursive call returns.
  bool isPalindromeRec(ListNode<T>* head){
    //Get length of the list
    unsigned totalLength = getListLength(head);
    
    ListNode<T>* tail;
    return isPalindromeRecHelper(head, totalLength, 0, tail);
  }

  bool isPalindromeRecHelper(ListNode<T>* head, const unsigned totalLength, unsigned currLength, ListNode<T>*& tail){
    ++currLength;

    //Very special case to prevent seg fault
    if(totalLength == 1){
      return true;
    }
    
    //Base Case:
    //Stop recursion at middle of the list
    if(currLength == totalLength / 2){
      if(totalLength % 2 == 0){
	//Check head->next for equality
	tail = head->next;
      }
    
      else if(totalLength % 2 == 1){
	//Check head->next->next
	tail = head->next->next;
      }
      
      return head->val == tail->val;
    }


    bool isSublistPal = isPalindromeRecHelper(head->next, totalLength, currLength, tail);

    //Else compare tail->next and head's value
    tail = tail->next;
    assert(tail != nullptr);

    return isSublistPal && (head->val == tail->val);
  }
  
  //SOLUTION 4
  //This solution uses a stack and the two pointer technique.
  //We use a fast and a slow pointer to determine where the
  //middle of the list is, meanwhile adding nodes to a stack.
  //Then we compare the second half of the list to the values
  //in the stack
  //Uses O(N) memory for the stack, and O(N) time to
  //loop through the list
  //Assuming list is not empty
  bool isPalindromeTwoPointer(ListNode<T>* head){
    ListNode<T>* slow;
    ListNode<T>* fast;
    slow = head;
    fast = head;

    std::stack<T> s;
    
    //Check for size 1 list. Code will still handle a size 1
    //list but, this is a more explicit check
    if(head->next == nullptr){
      return true;
    }
    
    while(fast != nullptr && (fast->next != nullptr)){
      assert(slow != nullptr);
      s.push(slow->val);
	
      slow = slow->next;
      fast = fast->next->next;
    }

    //slow will be in the middle of the list, either at middle
    //if odd no of elements or at first element of second half
    //if even no of elements.

    //if fast == nullptr, there is even number of elements in list
    //and slow will be in first element of second half of list.
    //if fast->next == nullptr, there is an odd number of elements
    //in the list, and slow must be incremented to enter the second half.
    if(fast != nullptr && fast->next == nullptr){
      slow = slow->next;
    }

    bool isPal = true;
    //Compare second half of the list to whatever is in the stack
    while(!s.empty() && slow != nullptr){
      T next = s.top();
      s.pop();

      if(next != slow->val){
	isPal = false;
	break;
      }

      slow = slow->next;
    }

    return isPal;
  }

  //SOLUTION 5
  //This solution reverses the input list via recursion, then does
  //node by node comparison. Unlike solution 2, there is no literal stack.
  //O(N) time, O(N) memory for recursion to reverse and store a reversed
  //version of the input list.
  bool isPalindromeReverseRec(ListNode<T>* head){
    //Reverse the input list
    ListNode<T>* revHead = reverseList(head);
    
    //Loop through both lists side by side
    ListNode<T>* curr = head;
    ListNode<T>* revCurr = revHead;

    bool listIsPalindrome = true;
    while(curr != nullptr){
      assert(revCurr != nullptr);
      
      if(curr->val != revCurr->val){
	listIsPalindrome = false;
	break;
      }

      curr = curr->next;
      revCurr = revCurr->next;
    }
    
    freeListRecursive(revHead);

    return listIsPalindrome;
  }


  ListNode<T>* reverseList(ListNode<T>* head){
    ListNode<T>* tail;
    return reverseListHelper(head, tail);
  }

  //Creates a reversed version of the input list via recursion
  //Assumes input is not empty
  ListNode<T>* reverseListHelper(ListNode<T>* head, ListNode<T>*& tail){
    if(head->next == nullptr){
      ListNode<T>* newHead = new ListNode<T>(head->val);
      tail = newHead;
      return newHead;
    }

    //Reverse the list starting at head->next and then add
    //head to the end of it via the tail
    ListNode<T>* reversed = reverseListHelper(head->next, tail);

    //Create new node from copy of head
    ListNode<T>* copy = new ListNode<T>(head->val);
    tail->next = copy;
    tail = tail->next;
    
    return reversed;
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
  std::cout << "Input:\n";
  printVec(input);
  ListNode<T>* in = listFromVec(input);

  std::vector<bool> results;
  results.push_back(s.isPalindromeStack(in));
  results.push_back(s.isPalindromeReverseIter(in));
  results.push_back(s.isPalindromeRec(in));
  results.push_back(s.isPalindromeTwoPointer(in));
  results.push_back(s.isPalindromeReverseRec(in));

  std::cout << "Output with various methods:\n";
  for(bool currResult : results){
    std::cout << (currResult ? "true" : "false") << std::endl;
  }

  freeListRecursive(in);
}

int main(){
  std::vector<int> input;

  input = {1,0,1};  
  processTest(input);

  input = {1,0,0};  
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

  input = {1,1,1,0,1};
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
