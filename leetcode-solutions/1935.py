class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        
        words = text.split()

        c = 0

        for word in words:
            can = True
            i = 0
            while i < len(word) and can:
                if word[i] in brokenLetters:
                    can = False

                i+=1

            if can:
                c += 1

        return c




Solution().canBeTypedWords("hello world", "ad")