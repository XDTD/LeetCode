# 全转set小写，然后作比较
words = ["abdfs","cccd","a","qwwewm"]
set1 = set('qwertyuiop')
set2 = set('asdfghjkl')
set3 = set('ZXCVBNMzxcvbnm')

for idx in range(len(words)-1,-1,-1):
    word = words[idx]
    tmp = set(word.lower())
    if tmp <= set1 or tmp <= set2 or tmp <= set3:
        pass
    else:
        words.remove(word)

print(words)








