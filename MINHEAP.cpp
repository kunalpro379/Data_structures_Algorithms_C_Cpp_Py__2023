
#include<iostream>
#include<vector>
using namespace std;

#define INT_MAX 1222222222222222222;
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        
    }
    
    int add(int val) {
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */



void swap(int *x , int *y){
int temp=*x;
*x=*y;
*y=temp;
}


class MinHeap{
    public:
int* HArr;
int capacity;
int heap_size;

 MinHeap(int A[], int size){

heap_size=size;
HArr=A;
}
void BuildHeap();
void MinHeapify(int i);
int parent(int i){return (i-1)/2;}
int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
int extractMIn();
int getMIn(){return HArr[0];}
void ReplaceMin(int x){
    HArr[0]=x;
    MinHeapify(0);
}


};
void MinHeap::BuildHeap(){

int i=(heap_size-1)/2;
while (i>=0)
{
    MinHeapify(i);
    i--;
}

}

void MinHeap:: MinHeapify(int i){
int l=left(i);
int r=right(i);
int smallest=i;

if(l<heap_size&& HArr[l]<HArr[i]){
smallest=l;

}

if(r<heap_size&&HArr[r]<HArr[i]){
smallest=r;
}

if(smallest!=i){
swap(&HArr[i],&HArr[smallest]);
MinHeapify(smallest);

}


}
int MinHeap:: extractMIn(){
if(heap_size==0){
    return INT_MAX;
}

int root=HArr[0];
if(heap_size>1){
    HArr[0]=HArr[heap_size-1];
    MinHeapify(0);
}
heap_size--;
return root;


}
void KthLargest(int k, vector<int>&A){
    int count =0;
    int* arr=new int[k];
    MinHeap hip(arr,k);

    for(auto &x : A){
if(count<k-1){
    arr[count]=x;
    count++;
    cout<<"Kth Largest Element is -1 :"<<endl;

}else {
    if(count==k-1){
        arr[count]=x;
        hip.BuildHeap();
    
    }
    else{
        if(x>hip.getMIn())
        hip.ReplaceMin(x);
    }
    cout<<"Kth largest element is :"<<hip.getMIn()<<endl;
    count++;
}


    }


}










 class soln2{
public:

 };



int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int K = 3;

    KthLargest(K, arr);

    return 0;
}

