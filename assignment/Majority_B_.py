def isMajority(ar: list[int])-> bool:

    i = 0
    arr = []
    while i+1 < len(ar):
        if ar[i] == ar[i+1]:
            arr.append(ar[i])
        i += 2
    maj_index = 0
    count = 1;
    for i in range(1, len(arr)):
        if arr[maj_index] == arr[i]:
            count+=1
        else:
            count-=1
        if count == 0:
            maj_index = i
            count = 1

    count = 0
    compare = arr[maj_index]
    for indx, val in enumerate(ar):
        if val == compare:
            count+=1
    print(f"Majority ELemenet: {compare}")
    if count > len(ar) // 2:
        return True
    else:
        return False

arr = [3,6,6,1,3,3,3,6,6,6,6]
#arr = [1,3,6,6,1,3,3,3,6,6,6,6] -> False
print(isMajority(arr))
