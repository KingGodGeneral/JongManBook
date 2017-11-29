## 1년 전 쯤에 파이썬으로 푼 코드..
## 파이썬의 list는 사실 vector에 가까움(제가 알기론)

for i in range(int(input())):
    n, k = input().split()
    li = list(range(1, int(n) + 1))
    k = int(k)
    index = 0

    while len(li) > 2:
        del li[index]
        index = (index + k - 1) % len(li)

    print("{0} {1}".format(li[0], li[1]))
