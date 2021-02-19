def insertion_sort(arr):
    # O(n^2)
    for i in range(1, len(arr)):       
        value_to_insert = arr[i]
        pos = i
     
        while pos > 0 and arr[pos-1] > value_to_insert:
            arr[pos] = arr[pos-1]
            pos = pos - 1
            print(arr)
        
        arr[pos] = value_to_insert

    return arr
