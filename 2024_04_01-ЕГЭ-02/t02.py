print("x", "y", "z", "w", "F")

for x in [False, True]:
    for y in [False, True]:
        for z in [False, True]:
            for w in [False, True]:
                F = (x or y) and not (y == z) and (not w)
                if F:
                    print(int(x), int(y), int(z), int(w), int(F))