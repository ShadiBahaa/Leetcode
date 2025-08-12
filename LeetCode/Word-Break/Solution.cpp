    # Graph
    #   * node: s position
    #   * edge: word
    #   * if we can reach target node (last letter), return True
    def wordBreakBFS(self, s: str, wordDict: List[str]) -> bool:
        queue = deque([0])  # queue represents positions we can cover up to
        visited = set()

        while queue:
            cur = queue.popleft()
            for word in wordDict:
                new = cur+len(word)
                if new not in visited and word == s[cur:new]:
                    if new == len(s):
                        return True
                    else:
                        queue.append(new)
                        visited.add(new)

        return False