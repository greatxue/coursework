while True:
   try:
     N=int(input("Enter a positive number N: "))
     if N>0:
       print("m",3*" ","m+1"," ","m**(m+1)")
       i=1
       while i<=N:
         print("%-5d" %i, "%-5d" % (i+1), "%-5d" % (i**(i+1)))
         i=i+1
       break
     else:
       print("Please enter a positive number.")
   except:
     print("Please enter a positive number.")

  
