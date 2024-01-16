def solution(n, arr1, arr2):
    answer = []
    
    for r1, r2 in zip(arr1, arr2):
        line = ""
        for _ in range(n):
            if r1 % 2 == 1 or r2 % 2 == 1:
                line += "#"
            else:
                line += " "
            r1 //= 2
            r2 //= 2
        line = line[::-1]
        answer.append(line)
    
    return answer