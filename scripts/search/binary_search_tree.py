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
            return sub_tree_root  # Item found

    def __in_order(self, r: Node):
        if r is None:
            pass
        else:
            self.__in_order(r.left)
            print(r.value)
            self.__in_order(r.right)

    def __recursive_insert(self, n: Node, r: Node):
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

    def __remove_recursive(self, sub_tree: Node, key: int):
        pass

    def insert(self, n: Node):
        self.__recursive_insert(n, self.root)

    def in_order_traversal(self):
        self.__in_order(self.root)
    
    def show(self):
        self.in_order_traversal()

    def search(self, key: int):
        return self.__recursive_search(self.root, key)

    def remove(self, k: int):
        """
        Checks if there's a node N with the key k in the tree and
        removes it.
        We have 3 cases if the node is present:
            - No children.
            - Left XOR Right child. Remove node and bring subtree up
            - Both children. We need to get either the leftiest descendant
              from the right subtree or the rightiest descendant of left
              subtree.
        """
        return self.__remove_recursive(self.root, k)