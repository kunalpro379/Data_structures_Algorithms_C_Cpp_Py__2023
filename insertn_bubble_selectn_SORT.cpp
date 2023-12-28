#include<iostream>
using namespace std;
void SelectionSort(int p,int arr[]){
for(int i=0;i<p;i++){
    int min=0;
    for(int j=i+1;j<p;j++){
        if(arr[j]<arr[min]){
            min=j;
           
        }
 swap(arr[min],arr[j]);
    }


}}




void BubbleSort(int arr[],int p){
    
for (int i=1;i<p;i++){
for(int j=0;j<p-i;j++){
if (arr[j+1]<arr[j]){
swap(arr[j+1],arr[j]);
}

}
}
 
   
}

void InsertionSort(int arr[],int p){
int j,i;
 
for( i=1;i<p;i++){
int temp=arr[i];
for(j=(i-1);j>=0;j--){
    if(temp<arr[j]){
    arr[j+1]=arr[j];
    //right shift
}
else
break;}
arr[j+1]=temp;
}
}
int main(){
int arr[]={12,543,75,2,75,67,67,4,54,999,46,252,1,384,48,97,0,3};
int p=18;
cout<<p;

cout<<"initially  array is "<<endl;
for(int i=0;i<p;i++){
    cout<<arr[i]<<endl;
    
}

//test 1
cout<<"using Selectn sort"<<endl;
SelectionSort(p,arr);
for(int i=p;i>=0;i--){
    cout<<arr[i]<<endl;
    
}

//test 2

cout<<"using bubble sort"<<endl;
BubbleSort(arr, p);
for(int i=0;i<p;i++){
    cout<<arr[i]<<endl;
    
}
//test 3

cout<<"using insertion sort"<<endl;
InsertionSort(arr,p);
for(int i=0;i<p;i++){
    cout<<arr[i]<<endl;
    
}
return 0;
}
