class Solution:
    def triangleNumber(self, nums: [int]) -> int:
        import itertools
        nums_sorted = sorted(nums)
        combinations = itertools.combinations(nums_sorted, 3)
        return len([c for c in combinations if self.isTriangle(c)])

    def isTriangle(self, triplet: [int]) -> bool:
        return triplet[2] < triplet[0] + triplet[1]

