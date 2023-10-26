from math import sin
from math import cos
from math import tan
#finishing import

print("Help you calculate the integration!")
string_to_function = {
        'sin': sin,
        'cos': cos,
        'tan': tan
    }
while True:
      function_name = input("Choose from the functions'sin','cos'or'tan': ")
      if function_name in string_to_function:
            break
      print("Select between'sin','cos'and'tan'.")
#finishing fuction selection and check

while True:
   try:
     a=float(input("Please enter interval left end point: "))
     b=float(input("Please enter interval left end point: "))
     break
   except:
     print("a,b must be a real numbers.")  
while True:   
   try:
     n = int(input("Please enter the number of sub-intervals N: "))
     break
   except:
     print("N must be a positive integer.")      
#finishing other inputs and check

i=1
integration=0
while i<=n:
        sub=(b-a)/n* string_to_function[function_name](a+(b-a)/n*(i-1/2))
        i=i+1
        integration=integration+sub
#calculating the result

print("The integration","is",integration)





