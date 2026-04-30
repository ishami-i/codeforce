n = int(input())
arr = list(map(int, input().split()))

for i in arr:
    if i == 0:
        print('0')
    elif len(arr) < 3:
        print("0")
    # else:
    #     # choose the subarray
    #     from arr