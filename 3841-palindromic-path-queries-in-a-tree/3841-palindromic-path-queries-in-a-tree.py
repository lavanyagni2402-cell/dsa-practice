class Solution:
    def palindromePath(self, n: int, edges: list[list[int]], s: str,
                       queries: list[str]) -> list[bool]:
        from collections import defaultdict, deque

        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        parent = [-1] * n
        depth = [0] * n
        parent[0] = 0
        q = deque([0])

        while q:
            u = q.popleft()
            for v in graph[u]:
                if parent[v] == -1:
                    parent[v] = u
                    depth[v] = depth[u] + 1
                    q.append(v)

        s = list(s)
        LOG = n.bit_length()
        up = [[0] * n for _ in range(LOG)]
        for i in range(n):
            up[0][i] = parent[i]

        for j in range(1, LOG):
            for i in range(n):
                up[j][i] = up[j - 1][up[j - 1][i]]

        def lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u

            diff = depth[u] - depth[v]
            for j in range(LOG):
                if diff & (1 << j):
                    u = up[j][u]

            if u == v:
                return u

            for j in range(LOG - 1, -1, -1):
                if up[j][u] != up[j][v]:
                    u = up[j][u]
                    v = up[j][v]

            return parent[u]

        # Euler tour + Fenwick tree for character updates
        tin = [0] * n
        tout = [0] * n
        timer = 0
        stack = [(0, 0)]

        while stack:
            u, state = stack.pop()
            if state == 0:
                tin[u] = timer
                timer += 1
                stack.append((u, 1))
                for v in reversed(graph[u]):
                    if parent[v] == u:
                        stack.append((v, 0))
            else:
                tout[u] = timer

        bit = [0] * (n + 2)

        def add(i, val):
            i += 1
            while i < len(bit):
                bit[i] ^= val
                i += i & -i

        def prefix(i):
            res = 0
            i += 1
            while i > 0:
                res ^= bit[i]
                i -= i & -i
            return res

        def range_xor(l, r, val):
            add(l, val)
            if r < n:
                add(r, val)

        for i, ch in enumerate(s):
            range_xor(tin[i], tout[i], 1 << (ord(ch) - 97))

        ans = []

        for query in queries:
            parts = query.split()

            if parts[0] == "update":
                u = int(parts[1])
                ch = parts[2]
                if s[u] != ch:
                    delta = (1 << (ord(s[u]) - 97)) ^ (
                        1 << (ord(ch) - 97)
                    )
                    range_xor(tin[u], tout[u], delta)
                    s[u] = ch
            else:
                u, v = int(parts[1]), int(parts[2])
                w = lca(u, v)

                mask_u = prefix(tin[u])
                mask_v = prefix(tin[v])
                mask_w = prefix(tin[w])

                path_mask = mask_u ^ mask_v ^ (1 << (ord(s[w]) - 97))

                ans.append((path_mask & (path_mask - 1)) == 0)

        return ans