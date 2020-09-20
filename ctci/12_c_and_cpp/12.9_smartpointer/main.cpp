#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class SmartPointer{
  T* ptr;
  //Number of smartpointers pointing to the shared object
  unsigned* numPtrs;

public:
  SmartPointer():ptr(nullptr),numPtrs(nullptr){}

  SmartPointer(T* Tptr){
    ptr = Tptr;
    numPtrs = new unsigned(1);
  }
  
  T& operator*(){
    return *ptr;
  }

  T* operator->(){
    return ptr;
  }
  
  SmartPointer(const SmartPointer<T>& sptr){
    copyToSelf(sptr);
  }

  SmartPointer<T>& operator=(const SmartPointer<T>& sptr){
    //Prevent deletion if caller tries a = a;
    if(&sptr == this)
      return *this;

    //Manage current object
    this->destroySelf();

    //Copy to self
    this->copyToSelf(sptr);
    
    return *this;
  }
  
  ~SmartPointer(){
    this->destroySelf();
  }

  unsigned getNumReferences(){
    if(numPtrs == nullptr){
      return 0;
    }
    
    return *numPtrs;
  }
  
private:
  void copyToSelf(const SmartPointer<T>& sptr){
    ptr = sptr.ptr;
    numPtrs = sptr.numPtrs;

    if(numPtrs != nullptr){
      ++(*numPtrs);
    }
  }

  //Called by both copy cstor and assignment operator
  void destroySelf(){
    if(numPtrs == nullptr){
      return;
    }

    --(*numPtrs);
    if(*numPtrs == 0){
      delete ptr;
      ptr = nullptr;
      
      delete numPtrs;
      numPtrs = nullptr;
    }

  }
};

struct a{
  int x;
  int y;

  a(int x, int y):x(x),y(y){}

  void foo(){
    cout << "Called foo" << endl;
  }
};

SmartPointer<int>* smartTest(){
  return new SmartPointer<int>(new int(86));
}

int main(){

  SmartPointer<int> n(new int(3));
  assert(*n == 3);
  assert(n.getNumReferences() == 1);


  SmartPointer<int>* n1 = new SmartPointer<int>(n);
  *n = 9;
  assert(**n1 == 9);
  assert(n.getNumReferences() == 2);
  assert(n1->getNumReferences() == 2);
  delete n1;
  n1 = nullptr;

  assert(*n == 9);
  assert(n.getNumReferences() == 1);

  SmartPointer<int> n2(new int(21));
  assert(n2.getNumReferences() == 1);
  n = n2;
  assert(n.getNumReferences() == 2);
  assert(n2.getNumReferences() == 2);

  n2 = n;
  assert(n.getNumReferences() == 2);
  assert(n2.getNumReferences() == 2);


  SmartPointer<a>* ax = new SmartPointer<a>(new a(9,7));
  assert((*ax)->x == 9);
  assert((*ax)->y == 7);
  delete ax;
  ax = 0;

  SmartPointer<double> d(new double(101.12));
  d = d;
  assert(d.getNumReferences() == 1);

  auto p = smartTest();
  assert(p->getNumReferences() == 1);
  assert(**p == 86);
  delete p; p = nullptr;


  SmartPointer<int> z1(new int(902));
  SmartPointer<int> z2 = z1;
  SmartPointer<int> z3 = z2;
  assert(z3.getNumReferences() == z1.getNumReferences());
  assert(z3.getNumReferences() == 3);

  SmartPointer<int> z4;
  assert(z4.getNumReferences() == 0);

  z1 = z4;
  z2 = z4;

  assert(z1.getNumReferences() == 0);
  assert(z2.getNumReferences() == 0);
  assert(z3.getNumReferences() == 1);

  z1 = z3;
  assert(z1.getNumReferences() == 2);

  z2 = z3;
  assert(z1.getNumReferences() == 3);

  assert(z3.getNumReferences() == 3);
  z1 = SmartPointer<int>();
  z2 = SmartPointer<int>();
  assert(z3.getNumReferences() == 1);
  z3 = SmartPointer<int>();
  assert(z3.getNumReferences() == 0);
  assert(z4.getNumReferences() == 0);

  z4 = z4;
  assert(z4.getNumReferences() == 0);

  z1 = SmartPointer<int>(new int(683));
  z2 = SmartPointer<int>(new int(291));
  z3 = SmartPointer<int>(z2);

  assert(z3.getNumReferences() == 2);
  z2 = SmartPointer<int>();
  assert(z3.getNumReferences() == 1);
  assert(*z3 == 291);
  z3 = SmartPointer<int>();
  assert(*z1 == 683);
  //z1 purposely not deleted. Need to check the destructor for it.

  SmartPointer<int> z5 = z4;
  assert(z5.getNumReferences() == 0);
}
