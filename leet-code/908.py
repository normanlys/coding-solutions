class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        return max(max(A) - min(A) - K*2, 0)
