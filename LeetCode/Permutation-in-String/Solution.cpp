class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        
        d = {'a': 2, 'b': 3, 'c': 5, 'd': 7, 'e': 11, 'f': 13, 'g': 17, 'h': 19, 'i': 23, 'j': 29, 'k': 31, 'l': 37, 'm': 41, 'n': 43, 'o': 47, 'p': 53, 'q': 59, 'r': 61, 's': 67, 't': 71, 'u': 73, 'v': 79, 'w': 83, 'x': 89, 'y': 97, 'z': 101}
        
        product = 1
        for x in s1:
            product *= d[x]
            
        windowProduct = 1
        for x in s2[:len(s1)]:
            windowProduct *= d[x]
            
        if windowProduct == product:
                return True
            
        nextchar = len(s1)
        firstchar = 0
        while nextchar < len(s2):
            windowProduct = windowProduct // d[s2[firstchar]]
            windowProduct *= d[s2[nextchar]]
            if windowProduct == product:
                return True
            nextchar += 1
            firstchar += 1
        return False