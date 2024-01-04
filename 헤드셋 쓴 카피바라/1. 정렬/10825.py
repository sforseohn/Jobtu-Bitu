n =int(input())

students = [input().split() for _ in range(n)]

students.sort(key = lambda s:( -int(s[1]), int(s[2]), -int(s[3]), s[0]))

for i in range(n):
    print(students[i][0])