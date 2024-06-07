s = input()

a = b = 0
for ch in s:
    if ch == 'A':
        a += 1
    elif ch == 'B':
        b += 1
    else:
        pass

print(f"A:{a}")
print(f"B:{b}")

if a > b:
    print("A wins!")
elif a < b:
    print("B wins!")
else:
    print("Draw!")