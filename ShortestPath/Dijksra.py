
from cmath import inf

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

  noOfLeftVertex = len(graph)

  while noOfLeftVertex > 0:

    minVertexIdx = getIndexOfMin(dist, isVisited)
    noOfLeftVertex -= 1

    for adjVertex,_ in enumerate(graph[minVertexIdx]):

      if isEdgePresent(graph, minVertexIdx, adjVertex) \
          and not isVisited[adjVertex] \
          and dist[adjVertex] > (dist[minVertexIdx] + graph[minVertexIdx][adjVertex]):

        dist[adjVertex] = dist[minVertexIdx] + graph[minVertexIdx][adjVertex]
        predecessor[adjVertex] = minVertexIdx



  DisplayP(predecessor)
  DisplayD(dist)
  print(isVisited)
  return predecessor

def DisplayD(lis: list[int]):
  for vertex, dist in enumerate(lis):
    if dist != -1:
      print(f"{chr(vertex+97)}\t{dist}")
    else:
      print(f"{chr(vertex+97)}\t{dist}")
  print()

def DisplayP(lis: list[int]):
  for vertex, parent in enumerate(lis):
    if parent != -1:
      print(f"{chr(vertex+97)}\t{chr(parent+97)}")
    else:
      print(f"{chr(vertex+97)}\t{parent}")
  print()

def getIndexOfMin(distArr: list[int], visited: list[bool])-> int:
  """
  Returns the index where min is there
  """
  min = MAX
  retIdx = 0
  for idx, distance in enumerate(distArr):
    if not visited[idx] and distance < min:
      min = distance
      retIdx = idx

  visited[retIdx] = True
  return retIdx


if __name__ == '__main__':
  G = [
    [-1, -1, -1, -1, 40, 10, -1],
    [-1, -1, -1, 20, 90, 30, 15],
    [-1, -1, -1, 45, -1, -1, 25],
    [-1, 20, 45, -1, 80, -1, 10],
    [40, 90, -1, 80, -1, 20, -1],
    [10, 30, -1, -1, 20, -1, 60],
    [-1, 15, 25, 10, -1, 60, -1]
  ]


  # choice: int = 1

  # while choice == 1:

  #   u = int(input("FROM"))
  #   v = int(input("TO"))
  #   w = int(input("WEIGHT"))
  #   u -= 1
  #   v -= 1

  #   G[u][v] = G[v][u] = w

  #   choice = int(input("[1/0]"))
  # DisplayGraph(G)
  MinSpanningTree = Prims(G, 1)

