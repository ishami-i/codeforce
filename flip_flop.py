# flips flops game, codeforces problem
#  n = number of monsters
# a = ottez combat power
# c = unknown parameter (appears unused in problem)
# arr_mon = array containing monster combat power

n, a, c = map(int, input().split())
arr_mon = list(map(int, input().split()))

max_c = a
current_power = a

# Sort array to process monsters efficiently
arr_mon.sort()

# if he goes into a fight with each monster (in ascending order of power)
for monster_power in arr_mon:
    if current_power >= monster_power:
        current_power += monster_power
        max_c = max(max_c, current_power)
    else:
        break

# return the maximum combat power achieved
print(int(max_c))