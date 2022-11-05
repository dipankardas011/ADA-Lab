class Items:
  def __init__(self):
    self.data: int = -99
    self.direction: str = '-'

def LCS(str1: str, str2: str) -> str:

  m: int = len(str1) + 1
  n: int = len(str2) + 1

  solMatrix: list[list[Items]]
  solMatrix = [[Items() for _ in range(n)] for _ in range(m)]

  for i in range(0, m):
    solMatrix[i][0].data = 0
    solMatrix[i][0].direction = '*'

  for i in range(0, n):
    solMatrix[0][i].data = 0
    solMatrix[0][i].direction = '*'

  for i in range(1, m):
    for j in range(1, n):
      if str1[i-1] == str2[j-1]:
        solMatrix[i][j].data = 1 + solMatrix[i-1][j-1].data
        solMatrix[i][j].direction = 'c'
      else:
        if solMatrix[i][j-1].data < solMatrix[i-1][j].data:
          solMatrix[i][j].data = solMatrix[i-1][j].data
          solMatrix[i][j].direction = 't'
        else:
          solMatrix[i][j].data = solMatrix[i][j-1].data
          solMatrix[i][j].direction = 'l'

  printIt(solMatrix)

  i: int = m-1
  j: int = n-1
  print("Length: %d"%solMatrix[i][j].data)

  res: str = ""
  while solMatrix[i][j].data > 0 :
    if solMatrix[i][j].direction == 'c':
      res += str1[i-1]
      i-=1
      j-=1
    elif solMatrix[i][j].direction == 'l':
      j-=1
    else:
      i-=1

  return res[::-1]

def printIt(mat: list[list[Items]]):
  for i in range(0, len(mat)):
    for j in range(0, len(mat[0])):
      print(f"[{mat[i][j].data} {mat[i][j].direction}]", end='\t')
    print()

if __name__ == '__main__':
  print("Longest Common Subsequence %s"%LCS("acggtcta", "tccagttac"))
