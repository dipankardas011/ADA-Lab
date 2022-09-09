def getMinNoOfPandals(a: list):
    """To find the no of minimum pandals required if all the pandals
    can accomodate max of 6 events
    """
    length = len(a)
    counter: int
    counter = 0

    # for visitor 
    visitor = [0] * length


if __name__ == '__main__':
    """Main Func"""
    arr = [
        {
            'start' : 2,
            'end' : 5
        },
        {
            'start' : 9,
            'end' : 10
        },
        {
            'start' : 11,
            'end' : 15
        },
        {
            'start' : 16,
            'end' : 16
        },
        {
            'start' : 20,
            'end' : 22
        }
    ]
    getMinNoOfPandals(arr)

