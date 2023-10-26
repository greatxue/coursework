finalAcountValue = float(input("Enter the final accout value:"))
annualInterestRate = float(input("Enter the annual interest rate:"))/100
numberOfYears = float(input("Enter the number of years:"))
initialDepositAmount = finalAcountValue/(1+annualInterestRate)**numberOfYears
print("The initial value is: " + str(initialDepositAmount))