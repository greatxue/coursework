"""
You are permitted to write code between Start and End.
Besides, you can write other extra functions or classes outside, 
but don't change the template.
"""


class Node:
    def __init__(self, element, pointer):
        self.element = element
        self.pointer = pointer


class SinglyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insert(self, data):
        # Start writing your code.
        newest = Node(data,None)
        if self.size == 0:
            self.head = newest
        else:
            self.tail.pointer = newest
        self.tail = newest
        self.size += 1    
        # End writing your code.


##### Additional function ###########
def quicksortRaw(head, tail):
    if head == tail:
        return None
    if head.pointer == tail:
        return None
    key = head.element
    left = head
    pre_node = head.pointer
    
    while pre_node != tail:
        if pre_node.element < key:
            left = left.pointer
            tempo_element = left.element
            left.element = pre_node.element
            pre_node.element = tempo_element
        pre_node = pre_node.pointer
    tempo_element = head.element
    head.element = left.element
    left.element = tempo_element
    quicksortRaw(head,left)
    quicksortRaw(left.pointer,tail)
##### Additional function END #########


def quick_sort(node):
    # Start writing your code.
    tempo_list = SinglyLinkedList()
    while node != None:
        tempo_list.insert(node.element)
        node = node.pointer
    quicksortRaw(tempo_list.head,None)
    return tempo_list.head   
    # End writing your code.


# We will utilize the code similar to the following to check your answer.
if __name__ == '__main__':
    test_list = SinglyLinkedList()
    nums = [4,2,3,1,0,5]  # An example.
    for num in nums:
        test_list.insert(num)
    first_node = test_list.head  # Get the first node of the linked list.
    p = quick_sort(first_node)
    while p.pointer != None:
        print(p.element)
        p = p.pointer
    print(p.element)
    
