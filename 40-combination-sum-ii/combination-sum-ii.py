class Solution:
    def combinationSum2(self, candidates, target):
        candidates.sort()

        ans = []

        def backtrack(index, path, total):
            if total == target:
                ans.append(path[:])
                return

            for i in range(index, len(candidates)):

                if i > index and candidates[i] == candidates[i - 1]:
                    continue

                if total + candidates[i] > target:
                    continue

                path.append(candidates[i])

                backtrack(
                    i + 1,
                    path,
                    total + candidates[i]
                )

                path.pop()

        backtrack(0, [], 0)

        return ans