class Solution:
    def exclusiveTime(self, n, logs):
        ans = [0] * n
        stack = []
        prev = 0

        for log in logs:
            fid, typ, time = log.split(":")

            fid = int(fid)
            time = int(time)

            if typ == "start":

                # Current function runs until new function starts
                if stack:
                    ans[stack[-1]] += time - prev

                stack.append(fid)
                prev = time

            else:

                # End timestamp is inclusive
                ans[stack[-1]] += time - prev + 1

                stack.pop()

                # Next execution starts after this timestamp
                prev = time + 1

        return ans