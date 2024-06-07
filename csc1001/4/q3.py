"""
You are permitted to write code between Start and End.
Besides, you can write other extra functions or classes outside, 
but don't change the template.
"""
# Utility Class #########################
class Node:
    def __init__(self,element,pointer):
        self.pointer=pointer
        self.element=element
class Stack:
    def __init__(self):
        self.head = None
    def isNotEmpty(self):
        if self.head ==None:
            return False 
        else:
            return True
    def insert(self,data):    
        self.head = Node(data,self.head)
    def top(self):
        if self.isNotEmpty() == False:
            return
        return self.head.element
    def pop(self):
        self.head=self.head.pointer
# Utility Class END #########################

def HanoiTower(n, from_rod ='A',aux_rod ='B',to_rod ='C'):
    result_list = []
    # Start writing your code.
    def find(current,number):
        next=(current+1)%3
        if platform[(current+1)%3].isNotEmpty():
            if platform[(current+1)%3].head.element < number:
                return (next+1)%3
        return next
        ## In this fuction, properties of stacks are used as well.
        # This function helps locate the target plate.
        
    def trans(number,top):
        if number == 0:
            return from_rod
        if number == 1:
            if top == True:
                return to_rod
            return aux_rod
        if number == 2:
            if top == True:
                return aux_rod
            return to_rod
        # This function ensures the numbers corresponding to the rods.

    def operate(number,current,following,up):
        pre_list_1[number] = following
        platform[current].pop()
        platform[following].insert(number)
        strs = str(trans(current,up))+' --> '+str(trans(following,up))
        result_list.append(strs)
        ## In this function, properties of stacks are used. 
        # By using in and out, the output results can be managed orderly.


    
    platform = [Stack(),Stack(),Stack()]
    pre_list_1 = [0 for digit in range(n)]
    pre_list_2=[0 for digit in range(n)]
    for num1 in range(n-1,-1,-1):
        platform[0].insert(num1)
    for num2 in range(n):
        pre_list_2[num2] = 2 ** num2
    step = 2**n
    for Num in range(1,step):
        remain = Num^(Num-1)
        for num in range(n-1,-1,-1):
            if pre_list_2[num] & remain:
                operate(num,pre_list_1[num],find(pre_list_1[num],num),n & 1)
                break
        # Main function for the connection and operation.

    
    # End writing your code.
    return result_list


"""
You should store each line your output in result_list defined above.
For example, if the outputs of print() are: 
                A --> C
                A --> B
then please store them in result_list:

strs = "A --> C"
result_list.append(strs)
strs = "A --> B"
result_list.append(strs)

Thus, once you want to print something, please store them in result_list immediately, 
rather than utilizing print() to print it. 
Don't miss the space! For example, don't output:
                A-->C
                A-->B

We will utilize the code similar to the following to check your answer.
"""

if __name__ == '__main__':
    n = 5
    result_list = HanoiTower(n)
    for item in result_list:
        print(item)
