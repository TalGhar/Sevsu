def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quicksort(less) + [pivot] + quicksort(greater)

arr = [6, 2, 5, 7, 31, 16, 45, -12, 24, -54, 2, 4]
sorted_arr = quicksort(arr)
print(sorted_arr)
