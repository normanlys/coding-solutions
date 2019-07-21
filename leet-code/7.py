class Solution:
    def reverse(self, x: int) -> int:
        sign = 1 if x > 0 else -1
        string = str(x * sign)
        reversed_int = int(string[::-1]) * sign
        return 0 if abs(reversed_int) > 2 ** 31 - 1 else reversed_int
        