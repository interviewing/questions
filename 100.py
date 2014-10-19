#!/usr/bin/env python

def find_count(target, current, numbers):
    total_num = 0
    for i, v in enumerate(numbers):
        new_num = current+v
        if new_num == target:
            total_num += 1
        if new_num >= target:
            break
        total_num += find_count(target, new_num, numbers[i+1:])
    return total_num

print find_count(100, 0, range(1,101))
