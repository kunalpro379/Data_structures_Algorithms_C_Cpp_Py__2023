import heapq
def DJ(graph, src):
    dist={node:float('inf')for node in graph}
    dist[src]=0
    #create pq
    Q=[{0,src}]
    while Q:
      currentDist,currentNode=heapq.heappop(Q)
      if currentDist>dist[currentNode]:
         continue
      
      #exploring of currentNode
      for neighbor, weight in graph(currentNode):
           dist=currentDist+weight
           
           if dist< dist[neighbor]:
                 dist[neighbor]=dist
                 heapq.peahpush(Q,(dist,neighbor))
    return dist
               
              
if __name__=="__main__" :   
    graph = {
    'A': {'B': 5, 'C': 3},
    'B': {'A': 5, 'C': 2, 'D': 1},
    'C': {'A': 3, 'B': 2, 'D': 4, 'E': 2},
    'D': {'B': 1, 'C': 4, 'E': 1, 'F': 4},
    'E': {'C': 2, 'D': 1, 'F': 7},
    'F': {'D': 4, 'E': 7}
     }
    DJ(graph,'A')
          
              
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      

