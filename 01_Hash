# Hash function 
def hash(value, M): 
    return value % M 
# Linear probing (with comparison counting)
def linear_probing(key, M, tele_book): 
    comparisons = 0  
    i = 1 
    while tele_book[key] != -1: 
        comparisons += 1  
        new_key = (key + i) % M 
        if tele_book[new_key] == -1: 
            return new_key, comparisons  
        i += 1 
    return key, comparisons  
# Quadratic probing (with comparison counting)
def quadratic_probing(key, M, tele_book): 
    comparisons = 0  
    i = 1 
    while tele_book[key] != -1: 
        comparisons += 1  
        new_key = (key + i * i) % M 
        if tele_book[new_key] == -1: 
            return new_key, comparisons  
        i += 1 
    return key, comparisons  

# Main function
n = int(input("Enter the number of clients:")) 
tele_book = [-1] * n 
tele_numbers = [] 

for i in range(n): 
    x = int(input("Enter telephone number:")) 
    tele_numbers.append(x) 

print("Original telephone book is:", tele_numbers) 

# Linear probing with comparison count
linear_comparisons = 0  
for x in tele_numbers:
    loc = hash(x, n) 
    if tele_book[loc] == -1: 
        tele_book[loc] = x 
    else: 
        new_loc, comparisons = linear_probing(loc, n, tele_book) 
        tele_book[new_loc] = x 
        linear_comparisons += comparisons  

print("After linear probing:", tele_book)
print("Total comparisons during linear probing:", linear_comparisons)
tele_book = [-1] * n
# Quadratic probing with comparison count
quadratic_comparisons = 0  
for x in tele_numbers: 
    loc = hash(x, n) 
    if tele_book[loc] == -1: 
        tele_book[loc] = x 
    else: 
        new_loc, comparisons = quadratic_probing(loc, n, tele_book) 
        tele_book[new_loc] = x 
        quadratic_comparisons += comparisons  

print("After quadratic probing:", tele_book)
print("Total comparisons during quadratic probing:", quadratic_comparisons)

