class MinStack:

    def __init__(self):
        self.array = []
        self.minStack = []

    def push(self, val: int) -> None:
        if len(self.minStack) == 0 or self.minStack[-1] >= val:
            self.minStack.append(val)
        self.array.append(val)
        
    def pop(self) -> None:
        if self.top() == self.minStack[-1]:
            self.minStack.pop()
        self.array.pop()

    def top(self) -> int:
        return self.array[-1]

    def getMin(self) -> int:
        return self.minStack[-1]
