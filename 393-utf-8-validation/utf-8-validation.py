class Solution:
    def validUtf8(self, data):
        remaining = 0

        for byte in data:

            if remaining == 0:

                mask = 128
                count = 0

                while byte & mask:
                    count += 1
                    mask >>= 1

                if count == 0:
                    continue

                if count == 1 or count > 4:
                    return False

                remaining = count - 1

            else:

                if byte >> 6 != 0b10:
                    return False

                remaining -= 1

        return remaining == 0