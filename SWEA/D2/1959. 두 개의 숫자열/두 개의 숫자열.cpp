T = int(input())

for test_case in range(1, T + 1) :
    N, M = map(int, input().split())

    A = list(map(int, input().split()))
    B = list(map(int, input().split()))

    ans = 0
    if len(A) > len(B):
        for i in range(0, len(A) - len(B) + 1):
            temp_sum = 0
            for j in range(0, len(B)):
                temp_sum += A[j + i] * B[j]
            ans = max(ans, temp_sum)
    else:
        for i in range(0, len(B) - len(A) + 1):
            temp_sum = 0
            for j in range(0, len(A)):
                temp_sum += B[j + i] * A[j]
            ans = max(ans, temp_sum)
    print(f"#{test_case} {ans}")