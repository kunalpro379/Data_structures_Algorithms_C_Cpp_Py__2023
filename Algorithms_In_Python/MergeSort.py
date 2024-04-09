def mergeSort(arr):
    if len(arr)>1:
        mid=len(arr)//2
        leftHalf=arr[:mid]
        rightHalf=arr[mid:]
        mergeSort(leftHalf)
        mergeSort(rightHalf)
        i=j=k=0
        while i<len(leftHalf) and j<len(rightHalf):
            if leftHalf[i]<rightHalf[j]:
                arr[k]=leftHalf[i]
                i+=1
            else:
                arr[k]=rightHalf[j]
                j+=1
            k+=1
        while i<len(leftHalf):
            arr[k]=leftHalf[i]
            i+=1
            k+=1
        while j<len(rightHalf):
            arr[k]=rightHalf[j]
            j+=1
            k+=1


    return arr

arr = [64, 25, 12, 22, 11]
sorted_arr = mergeSort(arr)
print("Sorted array:", sorted_arr)


