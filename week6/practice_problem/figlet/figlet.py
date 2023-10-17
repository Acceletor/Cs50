from sys import exit,argv
from pyfiglet import Figlet
from random import choice

lists = ["avatar","contessa","ogre"]

if len(argv) == 1:
    words = input("Input: ")
    font = Figlet(font=choice(lists))
    print("Output: ")
    print(font.renderText(words))
    exit(0)
if len(argv) == 3:
    if argv[1] == "-f" and len(argv) == 3:
        try:
            font = Figlet(font= argv[2])
        except:
            print("Invalid usage")
            exit(1)
        else:
            words = input("Input: ")
            print("Output: ")
            print(font.renderText(words))
            exit(0)
    else:
        print("Invalid usage")
        exit(1)
else:
    print("Invalid usage")
    exit(1)
