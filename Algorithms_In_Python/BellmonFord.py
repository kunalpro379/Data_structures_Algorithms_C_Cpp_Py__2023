
#bellomonford algo
#O(|V-1||E|)

#reccurssive approach 
def BellMonFord_Reccursive(graph,src,distance=None):
    if distance is None:
        distance={vertex: float('inf') for vertex in graph}
        distance[src]=0
    noUpdates=True
    for vertex in graph:
        for neighbor,weight in graph[vertex]:
            if distance[vertex]+weight<distance[neighbor]:
                distance[neighbor]=distance[vertex]+weight
                noUpdates=False

    if noUpdates:
        return distance
    else:
        return BellMonFord_Reccursive(graph,src,distance)



#Dynamic Programming Approach
def BellMonFord_Dynamic(graph,src):
        distance={vertex: float('inf') for vertex in graph}
        distance[src]=0

        for _ in range(len(graph)-1):
            noUpdates=True
            for vertex in graph:
                for neighbor,weight in graph[vertex]:
                    if distance[vertex]+weight<distance[neighbor]:
                        distance[neighbor]=distance[vertex]+weight
                        noUpdates=False
            if noUpdates:
                break
        return distance
class Graph:
    def __init__(self, vertices):
        self.graph = []
        self.V = vertices
    def addEdge(self, u, v, w):
        self.graph.append([u, v, w])
    
    def printArr(self, dist):
        print("vertex dist from src")
        for i in range(self.V):
            print(f"{i}\t{dist[i]}")
    
    def BellmanFord(self, src):
        dist = [float("inf")] * self.V
        dist[src] = 0
        for _ in range(self.V - 1):
            for u,v,w in self.graph:
                if dist[u]!=float("inf") and dist[u]+w<dist[v]:
                    dist[v]=dist[u]+w
        for u,v,w in self.graph:
            if dist[u]!=float("inf") and dist[u]+w<dist[v]:
                print("Graph contains negative weight cycle")
                return
        self.printArr(dist)



if __name__ == "__main__":
        
    graph = {
        'A': [('B', 3), ('C', 5)],
        'B': [('C', -2)],
        'C': [('D', 7)],
        'D': [('B', 1)]
    }


    source_vertex = 'A'
    shortest_distances_from_rec = BellMonFord_Reccursive(graph, source_vertex)
    shortest_distances_from_dynamic=BellMonFord_Dynamic(graph, source_vertex)
    print("Shortest distances from source vertex:")
    for vertex, distance in shortest_distances_from_rec.items():
        print(f"{vertex}: {distance}")
    print("\n")
    for vertex, distance in shortest_distances_from_dynamic.items():
        print(f"{vertex}: {distance}")
    print("\n")
    print("approach 3 using cleasses and objects")
    g = Graph(4)
    g.addEdge(0, 1, 3)
    g.addEdge(0, 2, 5)
    g.addEdge(1, 2, -2)
    g.addEdge(2, 3, 7)
    g.addEdge(3, 1, 1)
    g.BellmanFord(0)
    print("\n")



