PANDAL_ACCOMODATIOM = 6

def getMinNoOfPandals(a: list) -> int:
    """To find the no of minimum pandals required if all the pandals
    can accomodate max of 6 events
    """
    length = len(a)
    counter: int
    counter = 0

    # for visitor
    visited = [False] * length
    itemsLeft = length
    j = 0
    visited[0] = True
    res = []
    while itemsLeft > 1:
        counter += 1

        currCount = 0
        for i in range (1, length):
            if visited[i] == False:
                itemsLeft -= 1
                if a[j]['end'] <= a[i]['start']:
                    visited[i] = True
                    currCount += 1
                    res.append(a[i]['id'])
                    j = i
                    if currCount == PANDAL_ACCOMODATIOM:
                        break
    print(res)
    return counter


if __name__ == '__main__':
    """Main Func"""
    arr = [
        {
            'id': 'a',
            'start' : 10,
            'end' : 13
        },
        {
            'id': 'b',
            'start' : 2,
            'end' : 6
        },
        {
            'id': 'c',
            'start' : 3,
            'end' : 5
        },
        {
            'id': 'd',
            'start' : 7,
            'end' : 9
        },
        {
            'id': 'e',
            'start' : 11,
            'end' : 14
        },
        {
            'id': 'f',
            'start' : 21,
            'end' : 23
        },
        {
            'id': 'g',
            'start' : 19,
            'end' : 21
        },
        {
            'id': 'h',
            'start' : 5,
            'end' : 8
        },
        {
            'id': 'i',
            'start' : 10,
            'end' : 15
        },
        {
            'id': 'j',
            'start' : 14,
            'end' : 18
        },
        {
            'id': 'k',
            'start' : 4,
            'end' : 9
        }
    ]
    sortedArr = sorted(arr, key=lambda d: d['end'])
    print(sortedArr)
    print("Minimum number of pandals: %d" % getMinNoOfPandals(sortedArr))

