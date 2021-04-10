import sys

def riqi(iList):
    iLen = len(iList)
    if iLen == 1:
        return iList
    res = [iList[0].split('-')[0]]
    for i in range(iLen-1):
        if iList[i+1].split('-')[0] > iList[i].split('-')[1]:
            res.append(iList[i].split('-')[1])
            res.append(iList[i+1].split('-')[0])
    res.append(iList[-1].split('-')[1])
    
    res2 = []
    for i in range(0, len(res), 2):
        res2.append(str(res[i]) + '-' + str(res[i+1]))
    return res2

if __name__ == "__main__":
    try:
        while True:
            iList = [str(t) for t in sys.stdin.readline().strip().split(',')]
            res = riqi(iList)
            for i in range(len(res)-1):
                print(res[i], end=",")
            print(res[-1])
    except:
        pass