#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
#define V 4
bool isSafe(int v,bool graph[V][V],int color[],int cl){
    for(int i=0;i<v;i++)
        if(graph[v][i]&& cl==color[i])
            return false;

    return true;
}
bool graphColoringGet(bool graph[V][V],int m, int color[], int v){
    if(v==V)//if all the vertices are assigned a color
        return true;

    for(int cl=1;cl<=m;cl++){
            if(isSafe(v, graph,color,cl)){
                color[v]=cl;

                if(graphColoringGet(graph,m,color,v+1)==true){
                    return true;
                }
            color[v]=0;

            }

    }
    return false;
}
void printSolution(int color[]){
cout<<"SOLUTION IS __________________"<<endl;
    for(int i=0;i<V;i++)
        cout<<color[i]<<" ";
    cout<<endl;
}
bool graphColoring(bool graph[V][V], int m){
    int color[V];
    for(int i=0;i<V;i++)
        color[i]=0;
        //all colors intitially 0
    if(graphColoringGet(graph, m,color,0)==false){
        return false;
    }
    printSolution(color);
    return true;
}

int main(){
        bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
 
    // Number of colors
    int m = 3;
 
    // Function call
    graphColoring(graph, m);
    return 0;
}
