# TODO
while True:
    card = input("Number: ")
    try:
        if type(int(card)) == int:
            break
    except ValueError:
        ...
total_mul = []
total_sum = 0
for i in range(len(card)):
    if (i + 1) % 2 == 0:
        index = (i + 1) * -1
        num = str(int(card[index]) * 2)
        if len(num) == 2:
            total_mul.append(num[0])
            total_mul.append(num[1])
        else:
            total_mul.append(num)
    else:
        index = (i + 1) * -1
        num = int(card[index])
        total_sum += num

for i in total_mul:
    total_sum += int(i)

if str(total_sum)[1] == "0":
    if (card[:2] == "34" or card[:2] == "37") and len(card) == 15:
        print("AMEX")
    elif (card[:2] in ["51", "52", "53", "54", "55"]) and len(card) == 16:
        print("MASTERCARD")
    elif card[0] == "4" and (len(card) == 16 or len(card) == 13):
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")


