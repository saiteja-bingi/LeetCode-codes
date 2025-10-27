# Last updated: 10/27/2025, 7:05:56 PM
class Solution:
    def isValid(self, word: str) -> bool:
        count=0
        if len(word)>=3:
            count+=1
        vowels='aeiouAEIOU'
        for ch in word:
            if ch.isalpha() and ch in vowels:
                count+=1
                break
        for ch in word:
            if ch.isalpha() and ch not in vowels:
                count+=1
                break
        for ch in word:
            if (ch.isalpha() or ch.isdigit()) == False:
                return False
        if count==3:
            return True
        else:
            return False
        