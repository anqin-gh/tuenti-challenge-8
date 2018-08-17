#!/usr/bin/env python3

def string_to_max_list(s):
    """Given an input string, convert it to a descendant list of numbers
    from the length of the string down to 0"""
    out_list = list(range(len(s) - 1, -1, -1))
    return out_list


def string_to_min_list(s):
    out_list = list(range(len(s)))
    out_list[0], out_list[1] = out_list[1], out_list[0]
    return out_list


def list_to_base10_int(in_list):
    my_int = 0
    base = len(in_list)
    exp = base - 1
    for item in in_list:
        my_int += item*base**exp
        exp -= 1

    return my_int

def main():
    t = int(input())
    for i in range(1, t + 1):
        s = input()
        my_max_int = list_to_base10_int(string_to_max_list(s))
        my_min_int = list_to_base10_int(string_to_min_list(s))
        my_diff = my_max_int - my_min_int

        print("Case #{}: {}".format(i, my_diff))


if __name__ == "__main__":
    main()