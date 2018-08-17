#!/usr/bin/env python3

NOTES = ['A', 'A#', 'B', 'C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#']
MODES = ('MAJOR', 'MINOR')
MAJOR_MODE = [2, 2, 1, 2, 2, 2, 1]
MINOR_MODE = [2, 1, 2, 2, 1, 2, 2]


def make_scale(tonic, mode):
    out_scale = []
    index = NOTES.index(tonic)
    if mode == 'MAJOR':
        my_mode = MAJOR_MODE
    else:
        my_mode = MINOR_MODE

    for step in my_mode:
        out_scale.append(NOTES[index % len(NOTES)])
        index += step

    return out_scale


SCALES_DICTIONARY = {}
for note in NOTES:
    for mode in MODES:
        if mode == 'MAJOR':
            SCALES_DICTIONARY['M' + note] = make_scale(note, mode)
        else:
            SCALES_DICTIONARY['m' + note] = make_scale(note, mode)


def fix_in_notes(in_set):
    out_set = set()
    for note in in_set:
        if note[-1] == 'b':
            index_in_NOTES = NOTES.index(note[0])
            out_set.add(NOTES[index_in_NOTES - 1])
        else:
            out_set.add(note)

    if 'B#' in out_set:
        out_set.remove('B#')
        out_set.add('C')

    if 'E#' in out_set:
        out_set.remove('E#')
        out_set.add('F')

    return out_set


def main():
    cases = int(input())
    for case in range(1, cases + 1):
        n = int(input())
        if n == 0:
            notes = set()
        else:
            notes = {n for n in input().split(" ")}

        my_notes = fix_in_notes(notes)
        possible_scales = []
        for tonic, scale in SCALES_DICTIONARY.items():
            if my_notes.intersection(set(scale)) == my_notes:
                possible_scales.append(tonic)

        if not possible_scales:
            print("Case #{}: {}".format(case, 'None'))
        else:
            print("Case #{}: {}".format(case, " ".join(sorted(possible_scales))))


if __name__ == "__main__":
    main()