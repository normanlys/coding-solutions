import collections

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        counts = {}
        for n in deck:
            if counts[n]:
                counts[n] += 1
            else:
                counts[n] = 1

        if min(counts.values()) == 1:
            return False

        max_x: int = int(len(deck)/2)
        for i in range(2, max_x + 1):
            possible = True
            for count in counts.values():
                if count % i != 0:
                    possible = False

        return
