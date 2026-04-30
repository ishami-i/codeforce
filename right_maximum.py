n = int(input())
arr = list(map(int, input().split()))

counter = 0
while (len(arr) > 0):
    b = max(arr)
    # Find the rightmost (last) occurrence of the maximum
    index = len(arr) - 1 - arr[::-1].index(b)
    del arr[index:]

    counter += 1

print(counter)