class Node:
    def __init__(self, v=0):
        self.value = v
        self.left = None
        self.right = None


class Tree:
    def __init__(self, r=Node(0)):
        self.root = r

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

    def pre_order(self, r):
        if r is None:
            pass
        else:
            print(r.value)
            self.pre_order(r.left)
            self.pre_order(r.right)

    def in_order(self, r):
        if r is None:
            pass
        else:
            self.in_order(r.left)
            print(r.value)
            self.in_order(r.right)

    def post_order(self, r):
        if r is None:
            pass
        else:
            self.post_order(r.left)
            self.post_order(r.right)
            print(r.value)

    def level(self):
        if self.root is not None:
            q = []
            temp = self.root
            q.append(temp)
            while q != []:
                temp = q[0]
                q = q[1:]
                if temp != None:
                    print(temp.value)
                    q.append(temp.left)
                    q.append(temp.right)
