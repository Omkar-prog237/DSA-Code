s1 = set() 
s2 = set()

print("---MENU---")
print("1. To initialize set1")
print("2. To initialize set2")
print("3. To add element in set1")
print("4. To add element in set2")
print("5. To remove element in set1")
print("6. To remove element in set2")
print("7. To check element is in set1")
print("8. To check element is in set2")
print("9. To check size of set1")
print("10. To check size of set2")
print("11. For union of two sets")
print("12. For intersection of two sets")
print("13. For difference of two sets")
print("14. For subset of two sets")
print("15. To exit the program")

loop = True
while loop:
    ch = input("Enter the choice from the menu: ")

    if ch == '1':
        n1 = int(input("Enter the size of set1: "))
        print("Enter", n1, "elements")
        for i in range(n1):          
            x = int(input())
            s1.add(x)
        print("The set1 is:", s1)

    elif ch == '2':
        n2 = int(input("Enter the size of set2: "))
        print("Enter", n2, "elements")
        for i in range(n2):          
            x = int(input())
            s2.add(x)
        print("The set2 is:", s2)

    elif ch == '3':
        a = int(input("Enter the element to be inserted in set1: "))
        s1.add(a)
        print("After inserting the element, set1 is:", s1)

    elif ch == '4':
        b = int(input("Enter the element to be inserted in set2: "))
        s2.add(b)
        print("After inserting the element, set2 is:", s2)

    elif ch == '5':
        c = int(input("Enter the element to be deleted from set1: "))
        s1.discard(c)
        print("After deleting the element, set1 is:", s1)

    elif ch == '6':
        d = int(input("Enter the element to be deleted from set2: "))
        s2.discard(d)
        print("After deleting the element, set2 is:", s2)

    elif ch == '7':
        y = int(input("Enter the value to be checked in set1: "))
        if y in s1:
            print("Element is present in set1")
        else:
            print("Element is not present in set1")

    elif ch == '8':
        z = int(input("Enter the value to be checked in set2: "))
        if z in s2:
            print("Element is present in set2")
        else:
            print("Element is not present in set2")

    elif ch == '9':
        print("The size of set1 is:", len(s1))

    elif ch == '10':
        print("The size of set2 is:", len(s2))

    elif ch == '11':
        u = s1.union(s2)
        print("The union of two sets is:", u)

    elif ch == '12':
        i = s1.intersection(s2)
        print("The intersection of two sets is:", i)

    elif ch == '13':
        d = s1.difference(s2)
        print("The difference of two sets is:", d)

    elif ch == '14':
        sub = s1.issubset(s2) 
        print("The result of set1 subset of set2 is:", sub)

    elif ch == '15':
        print("Program exited..")
        loop = False

    else:
        print("Please enter a valid choice")
