int bellmonFord(int n, int m, int src,int dest, vector<vector<int>>&edges) {

vector<int>dist(n+1,1000000);
dist[src]=0;


//n-1 times 
for(int i=0;i<=n;i++){
    //traverse on edgelists
for(int j=0;j<m;j++ ){

    int u=edges[j][0];
    int v=edges[j][1];
    int wt=edges[j][2];
    if(dist[]!=1000000&&((dist[u]+wt)<dist[v])){

        dist[v]=dist[u]+wt;
    }
}

}

//cheak for -ve cycles
 bool flag=0;
 for(int j=0;j<m;j++ ){

    int u=edges[j][0];
    int v=edges[j][1];
    int wt=edges[j][2];
    if(dist[]!=1000000&&((dist[u]+wt)<dist[v])){

        flag=1;
    }
}
if(flag==0)
return dist[dest];

else return -1;
}