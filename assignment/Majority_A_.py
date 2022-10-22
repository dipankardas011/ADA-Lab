
def isMajority(arr: list[int])-> bool:
    # sort it
    arr.sort() # O(n*log(N))

    curr = 1
    count = 1
    maxItem = arr[0]
    for curr in range(1, len(arr)): # O(N)
        if arr[curr] == maxItem:
            count+=1
        else:
            count-=1
        if count == 0:
            maxItem = arr[curr]
            count = 1
    count = 0
    for _, element in enumerate(arr): # O(N)
        if element == maxItem:
            count+=1
    if count > len(arr)//2:
        return True
    else:
        return False


arr = [3,6,6,1,3,3,3,6,6,6,6]
print(isMajority(arr)) #O(N * Log(N))
