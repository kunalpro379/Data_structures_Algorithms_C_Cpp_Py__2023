import sys

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def printSolution(self, dist):   
        print("Vertex \tDistance from Source")
        for node in range(self.V):
            print(node, "\t", dist[node])

    def minDistance(self, dist, sptSet):
        minDist = sys.maxsize
        minInd = -1
        for u in range(self.V):
            if dist[u] < minDist and not sptSet[u]:
                minDist = dist[u]
                minInd = u
        return minInd

    def DjstrasAlgo(self, src):
        dist = [sys.maxsize] * self.V
        dist[src] = 0
        sptSet = [False] * self.V

        for _ in range(self.V):
            # Pick the vertex with the minimum distance from the set of vertices not yet processed
            u = self.minDistance(dist, sptSet)
            sptSet[u] = True  # Mark the picked vertex as processed
            
            # Update the distance value of the adjacent vertices of the picked vertex
            # Only if the current distance is greater than new distance and the vertex is not in the sptSet
            for v in range(self.V):
                if not sptSet[v] and self.graph[u][v] > 0:
                    dist[v] = min(dist[v], dist[u] + self.graph[u][v])

        self.printSolution(dist)

if __name__ == "__main__":
    g = Graph(9)
    g.graph = [
        [0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 14, 10, 0, 2, 0, 0],
        [0, 0, 0, 0, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]
    ]
    g.DjstrasAlgo(0)
