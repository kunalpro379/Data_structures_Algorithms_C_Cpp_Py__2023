import sys
import heapq

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def addEdge(self, u, v, weight):
        self.graph[u][v] = weight
        self.graph[v][u] = weight

    def primMST(self):
        mstSet = [False] * self.V
        minHeap = [(0, 0)]  # (weight, vertex)
        minCost = 0

        while minHeap:
            weight, u = heapq.heappop(minHeap)
            if not mstSet[u]:
                mstSet[u] = True
                minCost += weight
                for v in range(self.V):
                    if self.graph[u][v] > 0 and not mstSet[v]:
                        heapq.heappush(minHeap, (self.graph[u][v], v))

        return minCost

if __name__ == "__main__":
    g = Graph(5)
    g.addEdge(0, 1, 2)
    g.addEdge(0, 3, 6)
    g.addEdge(1, 2, 3)
    g.addEdge(1, 3, 8)
    g.addEdge(1, 4, 5)
    g.addEdge(2, 4, 7)
    g.addEdge(3, 4, 9)
    
    min_cost = g.primMST()
    print("Minimum cost of MST:", min_cost)
