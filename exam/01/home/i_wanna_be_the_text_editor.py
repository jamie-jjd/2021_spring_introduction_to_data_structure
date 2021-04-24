# alternative provided by TA 李旺陽
def TextEditor(KeyboardInputs):
    head = []
    tail = []
    insertMod = True
    for c in KeyboardInputs:
        if c == '<':
            if len(head) != 0:
                tail.append(head.pop())
        elif c == '>':
            if len(tail) != 0:
                head.append(tail.pop())
        elif c == '@':
            if len(head) != 0:
                head.pop()
        elif c == '$':
            insertMod = not insertMod
        else:
            head.append(c)
            if not insertMod and len(tail) != 0:
                tail.pop()

    res = head + tail[::-1]
    return ''.join(res)
