#include <iostream>
using namespace std;
template <typename T>
/*
shared_ptr kya karta hai?

Heap object ko manage karta hai

| Part                           | Purpose                                      |
| ------------------------------ | -------------------------------------------- |
| Raw Pointer (`T* ptr`)         | Actual object ka address                     |
| Reference Count (`int* count`) | Kitne shared_ptr us object ko point kar rahe |
*/

class SharedPointer{
    private:
        T* ptr;//pointing to the object in the heap
            int* refCount; //pointer to reference counter
                public :
                    SharedPointer(T* p=nullptr){
                            this->ptr=p;
                                    if(p!=nullptr){
                                                refCount=new int(1);//first owner
                                                        }else{
                                                                    refCount=nullptr;
                                                                            }
                                                                                }
                                                                                    // SharedPtr<int> sp(new int(5));, ptr ko object milta hai ptr → int(5)
                                                                                       // refCount create hota hai, refCount → 1

                                                                                           //copy constructor
                                                                                               SharedPointer(const SharedPointer& other){
                                                                                                       ptr=other.ptr;
                                                                                                               refCount=other.refCount;
                                                                                                                       if(refCount!=nullptr){
                                                                                                                                   (*refCount)++;
                                                                                                                                           }
                                                                                                                                               }
                                                                                                                                                   ~SharedPointer() {
                                                                                                                                                       releasepointer();
                                                                                                                                                       }

                                                                                                                                                       /*
                                                                                                                                                           Jab tu copy karta hai:
                                                                                                                                                           SharedPtr<int> sp2 = sp1;
                                                                                                                                                           sp1 → Object
                                                                                                                                                           sp2 → Object
                                                                                                                                                           refCount = 2

                                                                                                                                                           whitout shared pointer 
                                                                                                                                                           int* p1 = new int(10);
                                                                                                                                                           int* p2 = p1;


                                                                                                                                                           */
                                                                                                                                                           //Dereference operator
                                                                                                                                                           T& operator*(){
                                                                                                                                                               return *ptr;
                                                                                                                                                               }
                                                                                                                                                               T* operator->() {
                                                                                                                                                                   return ptr;
                                                                                                                                                                   }

                                                                                                                                                                   int use_count() const {
                                                                                                                                                                       return (refCount != nullptr) ? *refCount : 0;
                                                                                                                                                                       }
                                                                                                                                                                       SharedPointer& operator=(const SharedPointer&other){
                                                                                                                                                                           if(this==&other){
                                                                                                                                                                                   return *this;
                                                                                                                                                                                       }
                                                                                                                                                                                           releasepointer();
                                                                                                                                                                                               ptr=other.ptr;
                                                                                                                                                                                                   refCount=other.refCount;
                                                                                                                                                                                                       if(refCount!=nullptr){
                                                                                                                                                                                                               (*refCount)++;
                                                                                                                                                                                                                   }
                                                                                                                                                                                                                       return *this;
                                                                                                                                                                                                                       }


                                                                                                                                                                                                                       private:
                                                                                                                                                                                                                           void releasepointer(){
                                                                                                                                                                                                                                   if(refCount){
                                                                                                                                                                                                                                               (*refCount)--;
                                                                                                                                                                                                                                                           if(*refCount==0){
                                                                                                                                                                                                                                                                          delete ptr;
                                                                                                                                                                                                                                                                                          delete refCount; 
                                                                                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                                                                              }
                                                                                                                                                                                                                                                                                                                  }
                                                                                                                                                                                                                                                                                                                  };
                                                                                                                                                                                                                                                                                                                  class Test{
                                                                                                                                                                                                                                                                                                                      public:
                                                                                                                                                                                                                                                                                                                          Test(){
                                                                                                                                                                                                                                                                                                                                  cout<<"Test Object Created"<<endl;
                                                                                                                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                                                                                                          ~Test(){
                                                                                                                                                                                                                                                                                                                                                  cout<<"Test Object Destroyed"<<endl;
                                                                                                                                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                                                                                                                          void greet(){   
                                                                                                                                                                                                                                                                                                                                                                  cout<<"Hello from Test"<<endl;
                                                                                                                                                                                                                                                                                                                                                                      }
                                                                                                                                                                                                                                                                                                                                                                      };
                                                                                                                                                                                                                                                                                                                                                                      int main(){
                                                                                                                                                                                                                                                                                                                                                                          SharedPointer<Test>sp1(new Test());
                                                                                                                                                                                                                                                                                                                                                                              cout<<"Count:"<<endl<<sp1.use_count()<<endl;
                                                                                                                                                                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                                                                                                                                                                          SharedPointer<Test> sp2 = sp1;

                                                                                                                                                                                                                                                                                                                                                                                                  cout << "Count after copy: " << sp2.use_count() << endl;

                                                                                                                                                                                                                                                                                                                                                                                                          sp2->greet();
                                                                                                                                                                                                                                                                                                                                                                                                              }

                                                                                                                                                                                                                                                                                                                                                                                                                  cout << "Count after block: " << sp1.use_count() << endl;

                                                                                                                                                                                                                                                                                                                                                                                                                      return 0;
                                                                                                                                                                                                                                                                                                                                                                                                                      }