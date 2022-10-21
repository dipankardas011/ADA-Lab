
from cmath import inf

# class HeapDS:
#   def __init__(self, u: int, v: int, w: int):
#     self.From = u
#     self.To = v
#     self.Weight = w

# class Heap(HeapDS):
#   def __init__(self):
#     self.Arr: list[HeapDS]

#   def makeHeap(self, graph: list[list[int]]):
#     """
#     make a array to be used for creating the heap
#     """
#     return

global MAX
MAX = (1 << 32) - 1

def isEdgePresent(graph: list[list[int]], start: int, end: int)-> bool:
  return graph[start][end] != -1

def DisplayGraph(graph: list[list[int]])-> None:
  for start in range(len(graph)):
    for end in range(len(graph[0])):
      if isEdgePresent(graph, start, end):
        print(f"{start+1}--{graph[start][end]}-->{end+1}")
  return None



def Prims(graph: list[list[int]], vertex: int)-> list[int]:
  """
  Graph is 0 based vertex indexing
  vertex is 1 based
  """

  startVertex = vertex - 1
  dist: list[int] = [MAX for _ in range(len(graph))]
  predecessor: list[int] = [-1 for _ in range(len(graph))]
  isVisited: list[bool] = [False for _ in range(len(graph))]

  dist[startVertex] = 0

  noOfLeftVertex = len(graph) - 1

  while noOfLeftVertex > 0:
    # find the min and then ()-- noOfLeftVertex
    minVertexIdx = getIndexOfMin(dist, isVisited)
    noOfLeftVertex -= 1
    isVisited[minVertexIdx] = True
    for adjVertex,_ in enumerate(graph[minVertexIdx]):
      if isEdgePresent(graph, minVertexIdx, adjVertex) and not isVisited[adjVertex] and dist[adjVertex] > graph[minVertexIdx][adjVertex]:
        dist[adjVertex] = graph[minVertexIdx][adjVertex]
        predecessor[adjVertex] = minVertexIdx

  return predecessor


def getIndexOfMin(distArr: list[int], visited: list[bool])-> int:
  """
  Returns the index where min is there
  """
  min = distArr[0]
  retIdx = 0
  for idx, distance in enumerate(distArr):
    if not visited[idx] and distance < min:
      min = distance
      retIdx = idx

  return retIdx


if __name__ == '__main__':
  """
  Graph in adjacency matrix
     1  2  3  4  5  6  7
  1 -1 -1 -1 -1 -1 35 45
  2 -1 -1 35 -1 25 10 20
  3 -1 35 -1 10 20 15 -1
  4 -1 -1 10 -1 30 -1 -1
  5 -1 25 20 30 -1 -1 10
  6 35 10 15 -1 -1 -1 15
  7 45 20 -1 -1 10 15 -1
  """
  G: list[list[int]] = [
    [-1, -1, -1, -1, -1, 35, 45],
    [-1, -1, 35, -1, 25, 10, 20],
    [-1, 35, -1, 10, 20, 15, -1],
    [-1, -1, 10, -1, 30, -1, -1],
    [-1, 25, 20, 30, -1, -1, 10],
    [35, 10, 15, -1, -1, -1, 15],
    [45, 45, 20, -1, -1, 10, 15, -1]
  ]
  # DisplayGraph(G)
  MinSpanningTree = Prims(G, 4)
  for vertex, parent in enumerate(MinSpanningTree):
    if parent != -1:
      print(f"{vertex+1}\t{parent+1}")
    else:
      print(f"{vertex+1}\t{parent}")
