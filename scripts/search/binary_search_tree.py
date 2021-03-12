class Node:
    def __init__(self, v=0):
        self.value = v
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self, r=Node(0)):
        self.root = r

    def __ancestor(self, r: Node, item: Node):
        if item.right:
            self.__ancestor(r, item.right)
            return
        r.value = item.value
        item = item.left

    def __recursive_search(self, sub_tree_root: Node, k: int):
        temp = Node()

        if not sub_tree_root:
            print("This tree doesn't contain the item with the key", k)
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
                self.__recursive_insert(n, r.left)
            else:
                r.left = n
        else:
            if r.right:
                self.__recursive_insert(n, r.right)
            else:
                r.right = n

    def __remove_recursive(self, sub_tree: Node, key: int):
        # Base Case
        if sub_tree is None:
            return sub_tree

        # If the key to be deleted
        # is smaller than the root's
        # key then it lies in  left subtree
        if key < sub_tree.value:
            sub_tree.left = self.__remove_recursive(sub_tree.left, key)

        # If the kye to be delete
        # is greater than the root's key
        # then it lies in right subtree
        elif key > sub_tree.value:
            sub_tree.right = self.__remove_recursive(sub_tree.right, key)

        # If key is same as root's key, then this is the node
        # to be deleted
        else:
            # Node with only one child or no child
            if sub_tree.left is None:
                sub_tree = sub_tree.right

            elif sub_tree.right is None:
                sub_tree = sub_tree.left

            else:
                sub_tree = self.min_value_node(sub_tree)
                sub_tree.right = self.__remove_recursive(sub_tree.right, sub_tree.value)
            
        return sub_tree

    def insert(self, n: Node):
        self.__recursive_insert(n, self.root)

    def in_order_traversal(self):
        self.__in_order(self.root)

    def show(self):
        self.in_order_traversal()

    def search(self, key: int):
        return self.__recursive_search(self.root, key)

    def remove(self, k: int):  # NOT WORKING
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

    def min_value_node(self, r: Node = None):
        """
        Searches for the node with smallest value on subtree if given
        or uses tree root if not
        """
        if r:
            temp = r
        else:
            temp = self.root

        while temp.left:
            temp = temp.left
        return temp
