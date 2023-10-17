# TODO
height = 0
while True:
    try:
        height = int(input("Height: "))
        if height > 0 and height <= 8:
            break
    except ValueError:
        ...

for i in range(height):
    for j in range(i+1):
        if j == 0:
            print(" " * (height - (i + 1)), end ='')
        print("#", end= '')
    for j in range(i+1):
        if j == 0:
            print("  ", end = '')
        print("#", end= '')
    print()