def SelectionSort(arr):
    n=len(arr)
    for i in range(n):
        minInd=i
        for j in range(i+1,n):
            if arr[j]<arr[minInd]:
                minInd=j
        arr[i],arr[minInd]=arr[minInd],arr[i]
    return arr

if __name__ == "__main__":
    arr = [64, 25, 12, 22, 11]
    sorted_arr = SelectionSort(arr)
    print("Sorted array:", sorted_arr)