class Solution(object):
    def findIntegers(self, n):
        """
        :type n: int
        :rtype: int
        """

        if n <2:
            return n+1
        bits = bin(n)[2:]
        k = len(bits)

        dp = [0] * (k+1)
        dp[0] = 1
        dp[1] = 2
        for i in range(2, k+1):
            dp[i] = dp[i-1] + dp[i-2]
        ans = 0
        prev_bit  = False
        for i in range(k):
            if bits[i] == '1':
                ans += dp[k-1-i]
                if prev_bit:
                    return ans
                prev_bit = True
            else:
                prev_bit = False
        ans += 1
        return ans
        