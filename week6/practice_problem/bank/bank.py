def main():
    greeting = input("Greeting: ").lower()
    if "hello" in greeting:
        print("$0\n")
        return
    if greeting[0] == 'h':
        print("$20\n")
        return

    else:
        print("$100\n")
        return

main()