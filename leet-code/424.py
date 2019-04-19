import sys


class Solution:
    def get_letter_counts(self, s: str) -> list:
        letter_counts = []
        prev_letter = s[0]
        length = 0
        for letter in s:
            if letter == prev_letter:
                length += 1
            else:
                letter_counts.append((prev_letter, length))
                length = 1
            prev_letter = letter

        if len(letter_counts) == 0:
            letter_counts.append((prev_letter, length))
        elif letter_counts[-1][0] != prev_letter:
            letter_counts.append((prev_letter, length))

        return letter_counts

    def characterReplacement(self, s: str, k: int) -> int:
        if len(s) == 0:
            return 0

        letter_counts = self.get_letter_counts(s)
        unique_letters = set(s)
        letter_lengths = dict.fromkeys(unique_letters, [])
        for count in letter_counts:
            index = letter_counts.index(count)
            # check backwards
            back_step = 1
            max_length_back = count[1]
            quota = k
            while index - back_step >= 0:
                prev_count = letter_counts[index - back_step]
                if count[0] == prev_count[0]:
                    max_length_back += prev_count[1]
                else:
                    if quota >= prev_count[1]:
                        max_length_back += prev_count[1]
                        quota -= prev_count[1]
                    else:
                        break
                back_step += 1

            # check forward
            forward_step = 1
            max_length_forward = count[1]
            quota = k
            while index + forward_step < len(letter_counts):
                forward_count = letter_counts[index + forward_step]
                if count[0] == forward_count[0]:
                    max_length_forward += forward_count[1]
                else:
                    if quota >= forward_count[1]:
                        max_length_forward += forward_count[1]
                        quota -= forward_count[1]
                    else:
                        break
                forward_step += 1

            letter_lengths[count[0]].append(max(max_length_back, max_length_forward))

        return max(self.flat_list(letter_lengths.values()))

    def flat_list(self, list_of_list):
        return [item for sublist in list_of_list for item in sublist]

if __name__ == '__main__':
    print(Solution().characterReplacement(sys.argv[1], int(sys.argv[2])))
