class Solution:
    def triangleNumber(self, nums: [int]) -> int:
        import itertools
        combinations = itertools.combinations(nums, 3)
        return len([c for c in combinations if self.isTriangle(c)])

    def isTriangle(self, triplet: [int]) -> bool:
        dummy = sorted(triplet)
        return dummy[2] < dummy[0] + dummy[1]
