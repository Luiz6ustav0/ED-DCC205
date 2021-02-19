def bubble_sort(arr):
    # O(n^2)
    for i in range(0, len(arr)):
        for j in range(1, len(arr)-i):
            if arr[j] < arr[j-1]:
                arr[j] += arr[j-1] 
                arr[j-1] = arr[j] - arr[j-1]
                arr[j] -= arr[j-1] # Just a fun "mathy" way to switch the values

    return arr
