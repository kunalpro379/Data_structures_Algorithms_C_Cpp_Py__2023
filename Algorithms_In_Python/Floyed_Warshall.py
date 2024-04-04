#floyed warshall algorithm
#Time Complexity: O(V^3)

#steps->
#adjacency matrix prepare
#initialize the distance matrix
'''
lets take an example
V=4
1<-->2
1<-->4
2-->3
3-->4
3-->1

G=[[0,3,INF,7],[8,0,2,INF],[5,INF,0,1],[2,INF,INF,0]]
Anot[2,3]=2
#here there is node 1 in between nodes 2 and 3 
therefore
Anot[2,1]+Anot[1,3]=3+oo=oo

and 2<oo  therefor no updation

Anot[2,4]=oo
there is node 1 between 2 and 4 
therefore
Anot[2,1]+Anot[1,4]=8+7=15
here oo>15
there for updation Anot[2,4]=15
#similarly
Anot[3,2]=oo
Anot[3,1]+Anot[1,2]=o5+3=8
oo>8
therefore Anot[3,2]=8
#similarly


'''
INF=float('inf')

'''

def Matrix(V, G):
        dist=[row[:] for row in G]

        for k in range (V):
                for i in range (V):
                        for j in range (V):
                            #if vertex k is on the shortest path froom i to j update dist
                            if dist[i][k]+dist[k][j]<dist[i][j]:
                                dist[i][k]=dist[i][k]+dist[k][j]
        return dist

if __name__ == "__main__":
      V=4
      G=[[0,3,INF,7],
         [8,0,2,INF],
         [5,INF,0,1],
         [2,INF,INF,0]]
      
      short_dist=Matrix(V,G)
      for row in short_dist:
        print(row)
'''

def Florida(V,G):
    dist=[row[:] for row in G]
    InitializeMat=[[None]*V for _ in range(V)]

    #updating dist and predecessor mat
    for k in range(V): #intemediate vertex
        for i in range(V): #source vertex
            for j in range(V):#destination vertex
                if  dist[i][k]+dist[k][j]<dist[i][j]:
                    dist[i][j]=dist[i][k]+dist[k][j]
                    InitializeMat[i][j]=k

    return dist,InitializeMat

def printShortestPath(distance, predecessor):
    V = len(distance)
    for i in range(V):
        for j in range(V):
            if i != j:
                path = []
                current = j
                while current is not None:
                    path.insert(0, current + 1)  
                    current = predecessor[i][current]
                if path:
                    path.insert(0, i + 1)  
                print(f'Shortest path from {i + 1} to {j + 1}: {path}, Distance: {distance[i][j]}')


if __name__ == "__main__":
    V = 4
    G = [
        [0, 3, INF, 7],
        [8, 0, 2, INF],
        [5, INF, 0, 1],
        [2, INF, INF, 0]
    ]

    distance,InitializeMat  = Florida(V, G)
    printShortestPath(distance, InitializeMat)
