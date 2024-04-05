def binSearch(arr, target):
    left,right=0,len(arr)-1
    while left<=right:
        mid =left+(right-left)//2
        if arr[mid]==target:
            return mid
        elif arr[mid]>target:
            right=mid-1
        else:
            left=mid+1
    return -1

if __name__ == "__main__":
    arr = [2, 3, 4, 10, 40]
    target = 10
    result = binSearch(arr, target)
    print("Element is present at index", result)