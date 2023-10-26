import random
class ecosystem :
  def __init__(self,length,fishnum,bearnum,steps):
      self.river=list()
      river=self.river
      self.length=length
      self.fishnum=fishnum
      self.bearnum=bearnum
      self.steps=steps
      none=length-fishnum-bearnum
   
      i = 0
      while i < fishnum:
          river.append('F')
          i += 1
      k=0
      while k < bearnum:
        river.append('B')
        k += 1
      q = 0
      while q < none:
            river.append('N')
            q+=1
      random.shuffle(river)
      times=0
      while times < steps:
          times += 1
          print("The ecosystem at the beginning of the step ",times,":",sep="")
          print(river)
          self.simulation()

  
  
  def simulation(self):
      animalList = list()
      countitem = -1
      river = self.river
      for i in river:
        countitem += 1
        if i == 'F' or i == 'B':
           animalTuple = (i,countitem)
           animalList.append(animalTuple)
      countanimal = -1
      for animal in animalList :
           countanimal += 1
           position = animal[1]
           
           
           
           if animal[1] == 0:
              myList=[1,2]
              import random
              action = random.choice(myList)
              if action == 1:
                   position += 1
                   print('Animal:',animal[0],'Action: 1')
              else:
                   print('Animal:',animal[0],'Action: 0')
           
           
           elif animal[1]==(len(river)-1):
              myList=[1,2]
              import random
              action=random.choice(myList)
              if action == 2:
                 position -= 1
                 print('Animal:',animal[0],'Action: -1')
              else:
                 print('Animal:',animal[0],'Action: 0')
           
           
           else:
              myList=[1,2,3]
              import random
              action=random.choice(myList)
              
              if action == 1:
                   position += 1
                   print('Animal:',animal[0],'Action: 1')
              
              elif action == 2:
                   position -= 1
                   print('Animal:',animal[0],'Action: -1')
              
              else:
                   print('Animal:',animal[0],'Action: 0')
           
           
           
           
           if animal[1] != position:
             if animal[0] == river[position]:
                       newAnimal = animal[0]
                       noneList = list()
                       counti = -1
                       for i in river:
                           counti += 1 
                           
                           if i == 'N':
                               noneList.append(counti)
                       
                       if len(noneList) != 0:
                        import random
                        newIndex = random.randint(0,(len(noneList)-1))
                        newposition = noneList[newIndex]
                        river[newposition] = newAnimal
             
             
             elif animal[0] == 'F'and river[position] == 'B':
                 river[animal[1]] = 'N'
             
             elif animal[0] == 'B'and river[position] == 'F':
                 river[position] = 'B'
                 river[animal[1]] = 'N'
                 for k in animalList:
                     if position == k[1]:
                        animalList.remove(k)
             
             else:
                river[position] = animal[0]
                river[animal[1]] = 'N'
           print(river)
      
      

