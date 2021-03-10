class Node:
    def __init__(self, v=0):
        self.value = v
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self, r=Node(0)):
        self.root = r

    def __recursive_search(self, sub_tree_root: Node, k: int):
        temp = Node()

        if not sub_tree_root:
            return None

        if k < sub_tree_root.value:
            return self.__recursive_search(sub_tree_root.left, k)
        elif k > sub_tree_root.value:
            return self.__recursive_search(sub_tree_root.right, k)
        else:
            return sub_tree_root

    def insert(self, n, r):
        if n.value < r.value:
            if r.left:
                self.insert(n, r.left)
            else:
                r.left = n
        else:
            if r.right:
                self.insert(n, r.right)
            else:
                r.right = n

    def in_order_traversal(self, r):
        if r is None:
            pass
        else:
            self.in_order_traversal(r.left)
            print(r.value)
            self.in_order_traversal(r.right)

    def search(self, key: int):
        return self.__recursive_search(self.root, key)