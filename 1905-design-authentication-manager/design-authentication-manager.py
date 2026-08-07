class AuthenticationManager:

    def __init__(self, timeToLive: int):
        self.ttl = timeToLive
        self.tokens = {}

    def generate(self, tokenId: str, currentTime: int) -> None:
        self.tokens[tokenId] = currentTime + self.ttl

    def renew(self, tokenId: str, currentTime: int) -> None:
        if tokenId in self.tokens and self.tokens[tokenId] > currentTime:
            self.tokens[tokenId] = currentTime + self.ttl

    def countUnexpiredTokens(self, currentTime: int) -> int:
        expired = []

        for token, expiry in self.tokens.items():
            if expiry <= currentTime:
                expired.append(token)

        for token in expired:
            del self.tokens[token]

        return len(self.tokens)


# Your AuthenticationManager object will be instantiated and called as such:
# obj = AuthenticationManager(timeToLive)
# obj.generate(tokenId, currentTime)
# obj.renew(tokenId, currentTime)
# param_3 = obj.countUnexpiredTokens(currentTime)