def is_palindrome(s):
    delka = len(s)
    for i in range(delka):
        if s[i] != s[delka-1-i]:
            return False
    return True

# Testy:
print(is_palindrome("anna")) # True
print(is_palindrome("prst")) # False
print(is_palindrome("oko")) # True
print(is_palindrome("oka")) # False            
