import timeit

def mergeSort(iList):
    if len(iList) <= 1:
        return iList
    
    mid = len(iList) / 2
    lList = iList[0: mid]
    rList = iList[mid:]

    return mergeList(mergeSort(lList), mergeSort(rList))

def mergeList(lList, rList):
    mList = []
    while lList and rList:
        if lList[0] >= rList[0]:
            mList.append(rList.pop(0))
        else:
            mList.append(rList.pop(0))
    while lList:
        mList.append(lList.pop(0))
    while rList:
        mList.append(mList.pop(0))
    
    return mList