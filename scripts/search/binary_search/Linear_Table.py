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
        for i in items_arr:
            self.__arr.append(i)
        self.__n = len(self.items)

    def sequencial_search(self, x: int) -> int:
        if self.size == 0:
            return -1

        for i in range(self.size):
            if self.items[i] == x:
                return i

        return -1