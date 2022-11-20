alphabet = {i : chr(i + 96) for i in range(1,27)}
numeric =  {chr(i + 96) : i for i in range(1,27)}

class Graph:

    def __init__(self, vertices):
        self.V = vertices + 1 # No. of vertices
        self.graph = [] # to store graph

    # function to add an edge to graph
    def addEdge(self,path):
        self.graph.append(path)

    # A utility function to find set of an element i
    def find(self, parent, i):
        if parent[i] != i:
            parent[i] = self.find(parent, parent[i])  # Reassignment of node's parent to root node as
        return parent[i]

    # A function that does union of two sets of x and y (uses union by rank)
    def union(self, parent, rank, x, y):
        # Attach smaller rank tree under root of high rank tree (Union by Rank)
        if rank[x] < rank[y]:
            parent[x] = y
        elif rank[x] > rank[y]:
            parent[y] = x

        # If ranks are same, then make one as root and increment its rank by one
        else:
            parent[y] = x
            rank[x] += 1

    # The main function to construct MST using Kruskal's algorithm
    def KruskalMST(self):

        MST = []  # This will store the resultant MST

        i = 0 # An index variable, used for sorted edges
        j = 0 # An index variable, used for MST[]

        # Sort all the edges in non-decreasing order of their weight. 
        self.graph = sorted(self.graph, key=lambda item: int(item[2]))

        parent = []
        rank = []

        # Create V subsets with single elements
        for node in range(self.V):
            parent.append(node)
            rank.append(0)

        # Number of edges to be taken is equal to V-1
        while j < self.V - 1 and i < len(self.graph) :
            # Pick the smallest edge and increment the index for next iteration
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)

            # If including this edge doesn't cause cycle, then include it in MST and increment the index of MST for next edge
            if x != y:
                j = j + 1
                MST.append([u, v, w])
                self.union(parent, rank, x, y)
            # Else discard the edge

        minimumCost = 0
        print("\nEdges in the MST")
        for u, v, weight in MST:
            minimumCost += weight
            print(f"{alphabet[u]} -- {alphabet[v]} == {weight}")
        print("\nMinimum Spanning Tree", minimumCost)

def __main__():
    print("Enter the number of nodes : ", end="")
    nodes = int(input())
    print("Enter the number of edges : ", end="")
    edges = int(input())
    print(f"Enter the start, end and weight of edges : ")
    g = Graph(nodes)
    for i in range(edges) :
        e = list(map(str, input().split()))
        g.addEdge([numeric[e[0]], numeric[e[1]], int(e[2])])
    # print(f"graph = {g.graph}")

    g.KruskalMST()


__main__()
