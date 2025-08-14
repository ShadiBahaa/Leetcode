class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        max_heap = [-c for c in Counter(tasks).values()]
        heapify(max_heap)
        queue = deque()
        timer = 0
        while queue or max_heap:
            timer += 1
            if max_heap:
                count = -heappop(max_heap) - 1
                if count:
                    queue.append((count, timer + n))
            if queue and queue[0][1] <= timer:
                heappush(max_heap, -queue.popleft()[0])
        return timer