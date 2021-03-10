from typing import Iterable


class Linear_Table:
    def __init__(self, size=0, items=[]):
        self.__n = size
        self.__arr = [0 for i in range(size)]

    @property
    def items(self):
        return self.__arr

    @property
    def size(self) -> int:
        return self.__n

    def add_items(self, items_arr: Iterable[int]):
        try:
            for i in items_arr:
                self.__arr.append(i)
            self.__n = len(self.items)
        except TypeError:
            print(
                "Items must be passed as inside an iterable. e.g: f([1, 2, 3]) and not f(1, 2, 3)"
            )

    def sequencial_search(self, x: int) -> int:
        if self.size == 0:
            return -1

        for i in range(self.size):
            if self.items[i] == x:
                return i

        return -1

    def binary_search(self, x: int) -> int:
        """
        Since it's not guaranteed I'll have sorted arrays and this is just
        for practice, I'll sorte the array before running the actual thing
        """
        if self.items[0] == x:
            return 0

        self.items.sort()

        left = 0
        right = self.size
        i = right // 2

        while left <= right:
            if self.items[i] == x:
                return i
            if self.items[i] > x:
                right = i - 1
            else:
                left = i + 1

            i = (left + right) // 2

        return -1
