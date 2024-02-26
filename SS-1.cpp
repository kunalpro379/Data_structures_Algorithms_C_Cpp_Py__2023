#  include<iostream>
using namespace std;
int binarysearch(int p){
int l[]={12,23,34,45,56,67};
// int i=0,end;
// while(l[i]==8585){
// i++;
// end=i;
// }
// cout<<endl<<"lenght of an array is : "<<end;
int end=6;
int start=0;
 //end=i;
int mid;
while(mid<=end){
  //
if(l[mid]<p){ 
    start=mid+1; 

}
else if(l[mid]==p){
cout<<endl<<mid;}
else if(l[mid]>p){end=end-1;}

}
 mid=(start+end)/2;
cout<<mid;

return -1;
}
int main(){
    int p;
    
    cout<<"enter the element to be searched for"<<endl;
    cin>>p;
    
   int returnindex= binarysearch(p);
   if(returnindex==-1){cout<<"element not found";}
else{cout<<"element found at"<<returnindex;}
}