from typing import List

class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        
        n = len(code)
        result = [0] * n;

        if k == 0:
            return result

        if k > 0:
            for i in range(0, n):
                for j in range(1, k+1):
                    result[i] += code[(i+j) % n]

        elif k < 0:
                for i in range(0, n):
                    for j in range(1, abs(k)+1):
                        result[i] += code[(i-j) % n]
                    

        return result






code = [5,7,1,4]
k = 3
resolve = Solution().decrypt(code, k)
print(resolve)