from collections import deque

class FrontMiddleBackQueue:

    def __init__(self):
        self.front = deque()
        self.back = deque()

    def balance(self):
        if len(self.front) > len(self.back) + 1:
            self.back.appendleft(self.front.pop())
        elif len(self.front) < len(self.back):
            self.front.append(self.back.popleft())

    def pushFront(self, val: int) -> None:
        self.front.appendleft(val)
        self.balance()

    def pushMiddle(self, val: int) -> None:
        if len(self.front) > len(self.back):
            self.back.appendleft(self.front.pop())
        self.front.append(val)

    def pushBack(self, val: int) -> None:
        self.back.append(val)
        self.balance()

    def popFront(self) -> int:
        if not self.front and not self.back:
            return -1

        if self.front:
            ans = self.front.popleft()
        else:
            ans = self.back.popleft()

        self.balance()
        return ans

    def popMiddle(self) -> int:
        if not self.front and not self.back:
            return -1

        ans = self.front.pop()
        self.balance()
        return ans

    def popBack(self) -> int:
        if not self.front and not self.back:
            return -1

        if self.back:
            ans = self.back.pop()
        else:
            ans = self.front.pop()

        self.balance()
        return ans


# Your FrontMiddleBackQueue object will be instantiated and called as such:
# obj = FrontMiddleBackQueue()
# obj.pushFront(val)
# obj.pushMiddle(val)
# obj.pushBack(val)
# param_4 = obj.popFront()
# param_5 = obj.popMiddle()
# param_6 = obj.popBack()