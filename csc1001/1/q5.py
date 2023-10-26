while True:
   N=input("Enter a positive integer: ")
   try:
       N=int(N)
       if N>0:
          num = 0
          for i in range(2, N):
            isPrime = True 
            for k in range(2,i): 
               if i % k == 0:
                   isPrime = False 
                   break 
            if isPrime: 
               num += 1 
               if num % 8 == 0: 
                   print('%-5d' % i)
               else:
                   print('%-5d' % i, end = '')
          break
       else:
           print("Please enter a positive integer.")
   except: 
        print("Please enter a positive integer.")            
