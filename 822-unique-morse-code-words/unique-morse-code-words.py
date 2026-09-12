class Solution:
    def uniqueMorseRepresentations(self, words):
        morse = [
            ".-","-...","-.-.","-..",".","..-.","--.","....",
            "..",".---","-.-",".-..","--","-.","---",".--.",
            "--.-",".-.","...","-","..-","...-",".--","-..-",
            "-.--","--.."
        ]

        transformations = set()

        for word in words:
            current = ""

            for ch in word:
                current += morse[ord(ch) - ord('a')]

            transformations.add(current)

        return len(transformations)