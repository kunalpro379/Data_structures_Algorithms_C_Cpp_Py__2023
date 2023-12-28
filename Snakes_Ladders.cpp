#include<iostream>
using namespace std;
 #include "snakesladders.h"
#include<cstdlib>
#include<ctime>
#include<unordered_map>

#include<queue>

int main(){
int ladders, snakes;
cin>>ladders;
unordered_map<int , int>ladder;
unordered_map<int ,int>snake;


for(int i=0;i<ladders;i++){
int u,v;
cin>>u>>v;
ladder[u]=v;

}
for(int i=0;i<snakes;i++){
int u,v;
cin>>u>>v;
ladder[u]=v;

}
cin>>snakes;

int moves=0;
queue<int>Q;
Q.push(1);
bool found=false;
vector<int>visited(101,0);
visited[1]=true;

while(!Q.size() && !found){
int Size=Q.size();
while(Size--){
int t=Q.size();
while(Size--){
    int T=Q.front();
    Q.pop();
    for (int die=0; die<6;die++){
if(T+die==100){found =true;}
if(T+die<=100&& ladder[T+die] && !visited[ladder[T+die]]){visited[ladder[T+die]]=true;
if(ladder[T+die]==100){found=true;}
Q.push(ladder[T+die]);
}
else if(T+die<=100&& snake[T+die] && !visited[snake[T+die]]){visited[snake[T+die]]=true;
if(snake[T+die]==100)
found=true;
Q.push(snake[T+die]);
}
else if(T+die<=100&& !visited[T+die]&&!snake[T+die]&&!ladder[T+die]){
visited[T+die]=true;
Q.push(T+die);

}
    }


}



}
moves++;

}
if(found)
cout<<moves<<endl;

else 
cout<<-1;
}