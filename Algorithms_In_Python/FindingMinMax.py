def FindMinMax(arr):
    if not arr:
        return None
    min_val = arr[0]
    max_val = arr[0]
    for num in arr:
        if num < min_val:
            min_val = num
        if num > max_val:
            max_val = num
    return (min_val, max_val)

if __name__ == "__main__":
    arr = [64, 25, 12, 22, 11]

    min_val, max_val = FindMinMax(arr)
    print("Minimum value:", min_val)
    print("Maximum value:", max_val)