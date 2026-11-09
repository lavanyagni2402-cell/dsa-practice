
import heapq

class Solution:
    def busiestServers(self, k, arrival, load):
        tree = [0] * (4 * k)

        def build(node, start, end):
            if start == end:
                tree[node] = 1
                return

            mid = (start + end) // 2
            build(node * 2, start, mid)
            build(node * 2 + 1, mid + 1, end)
            tree[node] = tree[node * 2] + tree[node * 2 + 1]

        def update(node, start, end, pos, val):
            if start == end:
                tree[node] = val
                return

            mid = (start + end) // 2

            if pos <= mid:
                update(node * 2, start, mid, pos, val)
            else:
                update(node * 2 + 1, mid + 1, end, pos, val)

            tree[node] = tree[node * 2] + tree[node * 2 + 1]

        def find(node, start, end, target):
            if end < target or tree[node] == 0:
                return -1

            if start == end:
                return start

            mid = (start + end) // 2

            res = find(node * 2, start, mid, target)

            if res != -1:
                return res

            return find(node * 2 + 1, mid + 1, end, target)

        build(1, 0, k - 1)

        busy = []
        count = [0] * k

        for i in range(len(arrival)):
            while busy and busy[0][0] <= arrival[i]:
                end, server = heapq.heappop(busy)
                update(1, 0, k - 1, server, 1)

            target = i % k
            server = find(1, 0, k - 1, target)

            if server == -1:
                server = find(1, 0, k - 1, 0)

            if server == -1:
                continue

            count[server] += 1
            update(1, 0, k - 1, server, 0)

            heapq.heappush(
                busy,
                (arrival[i] + load[i], server)
            )

        maximum = max(count)

        return [i for i in range(k) if count[i] == maximum]
