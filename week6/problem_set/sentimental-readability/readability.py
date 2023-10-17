# TODO
text = input("Text: ")
words = len(text.split())
letter = 0
sentence = 0

for word in text.split():
    for ch in word:
        if ch not in ['?','!','.',"'",","]:
            letter += 1
for ch in text:
    if ch in ['?','!','.']:
        sentence += 1
letter_per_100_word = letter/words*100
sentence_per_100_word = (sentence/words)*100
index = round(0.0588 * letter_per_100_word - 0.296 * sentence_per_100_word - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
