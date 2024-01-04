n = int(input())
# 인풋을 Split()해 리스트로 만들어준 다음, String을 모두 int로 변환해줌
data = list(map(int, input().split()))
data.sort()
print(data[(n-1) // 2])