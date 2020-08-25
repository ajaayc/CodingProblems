#ifndef MINSTACK_H
#define MINSTACK_H

#include <cassert>
#include <vector>

using namespace std;

namespace CTCI{
  template <typename T>
  class minStack{
  private:
    struct stackNode{
      T val;
      bool isMin;
      unsigned prevMin;

    stackNode(const T& val):val(val),isMin(false),prevMin(0){}
    };
      
    std::vector<stackNode> s;

    unsigned minIndex;
  public:
    //O(1) time
    void push(const T& elt);

    //O(1) time
    void pop();

    //O(1) time
    const T& top() const;

    //O(1) time
    const T& min() const;
    
    //O(1) time
    bool empty() const;

    //O(1) time
    unsigned size() const;
  };

}

#endif /* MINSTACK_H */
