def QuickSort(arr):
    if len(arr)<=1:
        return arr
    else:
        pivot=arr[0]
        left=[x for x in arr[1:] if x<=pivot]
        right=[x for x in arr[1:] if x>pivot]
        return QuickSort(left)+[pivot]+QuickSort(right)

if __name__ == "__main__":
    arr = [10, 7, 8, 9, 1, 5]
    sorted_arr = QuickSort(arr)
    print("Sorted array:", sorted_arr)