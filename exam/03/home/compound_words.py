# alternative provided by TA 鄧晉杰
def CompoundWords (n, Words):
    compound_words = []
    word_set = set()
    for word in Words:
        word_set.add(word)
    for word in Words:
        for middle in range(1, len(word)):
            if word[0:middle] in word_set and word[middle:] in word_set:
                compound_words.append(word)
                break
    return compound_words
