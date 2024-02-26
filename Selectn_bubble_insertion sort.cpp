#include<iostream>
using namespace std;
int SelectionSort(int p,int arr[]){
for(int i=0;i<p;i++){
    int min=0;
    for(int j=i+1;j<p;j++){
        if(arr[j]<arr[min]){
            min=j;
           
        }
 swap(arr[min],arr[j]);
    }


}

}
int BubbleSort(){


}
int InsertionSort(){


}
int main(){
int arr[]={12,543,75,2,756767,4,5654,99999,46,252,1,33884,48,997,0,373};
int p=sizeof(arr);
cout<<"using Selectn sort"<<endl;
SelectionSort(p,arr);
cout<<"using bubble sort"<<endl;
BubbleSort();
cout<<"using insertion sort"<<endl;
InsertionSort();

return 0;
}
