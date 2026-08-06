import heapq
from collections import defaultdict

class Twitter:

    def __init__(self):
        self.time = 0
        self.followMap = defaultdict(set)
        self.tweetMap = defaultdict(list)

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweetMap[userId].append((self.time, tweetId))
        self.time += 1

    def getNewsFeed(self, userId: int) -> List[int]:

        heap = []

        for tweet in self.tweetMap[userId]:
            heapq.heappush(heap, (-tweet[0], tweet[1]))

        for followee in self.followMap[userId]:
            for tweet in self.tweetMap[followee]:
                heapq.heappush(heap, (-tweet[0], tweet[1]))

        ans = []

        while heap and len(ans) < 10:
            ans.append(heapq.heappop(heap)[1])

        return ans

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId != followeeId:
            self.followMap[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].discard(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)