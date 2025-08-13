class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        adj = defaultdict(list)
        indegree = [0] * (len(edges) + 1)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            indegree[v] += 1
            indegree[u] += 1

        q = deque()
        for node in range(1, len(edges) + 1):
            if indegree[node] == 1:
                q.append(node)
        
        while q:
            node = q.popleft()
            for nextNode in adj[node]:
                indegree[nextNode] -= 1
                indegree[node] -= 1
                if indegree[nextNode] == 1:
                    q.append(nextNode)
        
        for u, v in reversed(edges):
            if indegree[u] > 0 and indegree[v] > 0:
                return [u, v]