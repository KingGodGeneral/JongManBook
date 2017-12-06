def brackets2(input_string):
    li = []
    for i, j in enumerate(input_string):
        if j == '(' or j == '[' or j == '{':
            li.append(j)

        else:
            if len(li) == 0:
                return "NO"
            
            elif (j == ')' and li[-1] == '(') or (j == ']' and li[-1] == '[') or (j == '}' and li[-1] == '{'):
                li.pop()

            else:
                return "NO"

    if len(li) == 0:
        return "YES"

    else:
        return "NO"

for _ in range(int(input())):
    print(brackets2(input()))
