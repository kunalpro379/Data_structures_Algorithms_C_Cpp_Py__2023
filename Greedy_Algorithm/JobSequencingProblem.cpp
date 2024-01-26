/*Input: Four Jobs with following deadlines and profits

JobID  Deadline  Profit

  a           4          20   
  b           1          10
  c           1          40  
  d          1          30

Output: Following is maximum profit sequence of jobs: c, a   

Input:  Five Jobs with following deadlines and profits

JobID   Deadline  Profit

  a            2          100
  b            1          19
  c            2          27
 d            1          25
 e            3          15

Output: Following is maximum profit sequence of jobs: c, a, e*/
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include<vector>
#include<queue>
using namespace std;
struct Job {
   
    char id; 
    int dead; 
    int profit; 
};
 
bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

void JobShedulling1(Job InputA[], int n){
    //***
sort(InputA,InputA+n,comparison);  //sorting all jobs first
//***
 vector<int>JobSeq;
 vector<bool>slot;//free time slots

 //initially all slots free
 for(int i=0;i<n;i++)
    slot.push_back(false);

for(int i=0;i<n;i++){
    //find the freee slot for the job
    for(int j = min(n,InputA[i].dead);j>=0;j--){
        if(slot[j]==false)
            JobSeq[j]=(i);
            slot[j]=true;
            break;
    }

}

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << InputA[JobSeq[i]].id << " ";
}

//*************************approach 2**************************//

struct JobProfit{
    bool help()(Job const  & a,Job const & b){return( a.profit<b.profit);}
};
void JobShedulling2(Job InputA[], int n){
vector<Job>Seq;
sort(InputA,InputA+n,comparison);  //sorting all jobs first

priority_queue<Job,vector<Job>,JobProfit>PQ;

    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << InputA[JobSeq[i]].id << " ";
}
int main()
{ //n-> total no of slots
    Job A[] = { { 'a', 2, 100 },
                  { 'b', 1, 19 },
                  { 'c', 2, 27 },
                  { 'd', 1, 25 },
                  { 'e', 3, 15 } };
   
    int n = sizeof(A) / sizeof(A[0]);
    cout << "Following is maximum profit sequence of jobs "
            "\n";
 
    // Function call
    JobShedulling1(A, n);
    cout<<endl<<"approach2"<<endl;
    JobShedulling2(A, n);

    return 0;
}