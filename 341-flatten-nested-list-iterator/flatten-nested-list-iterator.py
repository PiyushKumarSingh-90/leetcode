class NestedIterator:

    def __init__(self, nestedList):
        self.arr = []
        self.flatten(nestedList)

        self.index = 0

    def flatten(self, nestedList):

        for item in nestedList:

            if item.isInteger():
                self.arr.append(item)

            else:
                self.flatten(item.getList())

    def next(self) -> int:
        value = self.arr[self.index]
        self.index += 1
        return value

    def hasNext(self) -> bool:
        return self.index < len(self.arr)