import heapq

class Solution:
    def minimumPairRemoval(self, nums):
        n = len(nums)

        if n <= 1:
            return 0

        prev = [-1] * n
        nxt = [-1] * n

        heap = []
        bad = 0

        # Build linked list + heap
        for i in range(n - 1):
            prev[i + 1] = i
            nxt[i] = i + 1

            if nums[i] > nums[i + 1]:
                bad += 1

            heapq.heappush(
                heap,
                (nums[i] + nums[i + 1], i, i + 1)
            )

        ans = 0

        while bad > 0:

            # Find the current valid minimum pair
            while True:
                s, a, b = heapq.heappop(heap)

                if (nxt[a] == b and
                    prev[b] == a and
                    s == nums[a] + nums[b]):
                    break

            # Remove old comparisons
            if prev[a] != -1:
                p = prev[a]
                if nums[p] > nums[a]:
                    bad -= 1

            if nums[a] > nums[b]:
                bad -= 1

            if nxt[b] != -1:
                c = nxt[b]
                if nums[b] > nums[c]:
                    bad -= 1

            # Merge a and b
            nums[a] += nums[b]

            # Remove b
            c = nxt[b]
            nxt[a] = c

            if c != -1:
                prev[c] = a

            # Add new left pair
            if prev[a] != -1:
                p = prev[a]

                if nums[p] > nums[a]:
                    bad += 1

                heapq.heappush(
                    heap,
                    (nums[p] + nums[a], p, a)
                )

            # Add new right pair
            if c != -1:

                if nums[a] > nums[c]:
                    bad += 1

                heapq.heappush(
                    heap,
                    (nums[a] + nums[c], a, c)
                )

            ans += 1

        return ans