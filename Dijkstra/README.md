Dijkstra — Shortest Path in a Weighted Graph
🔍 Problem Overview
The goal of this problem is to find the minimum cost path from vertex 1 to vertex n in a weighted undirected graph.

In other words:
👉 “What is the least total edge weight required to go from vertex 1 to vertex n, and what is the exact path?”

📥 Input Description
Symbol	Meaning
n	Number of vertices (2 ≤ n ≤ 10⁵)
m	Number of edges (0 ≤ m ≤ 10⁵)
a, b	Two connected vertices
w	Weight of the edge (1 ≤ w ≤ 10⁶)
Multiple edges and loops may exist.

📤 Output Description
If no path exists from 1 → n, print:
Otherwise print the shortest path (sequence of vertices).
🧠 Problem Nature
This is a Single Source Shortest Path (SSSP) problem with positive weights.

If all weights were equal, BFS would work.
But here weights vary (1 to 10⁶), so Dijkstra’s Algorithm is the best approach.
⚙️ Dijkstra’s Algorithm (Brief)
Dijkstra's is a Greedy Algorithm that works as follows:

Start from vertex 1.
Always pick the vertex with the smallest known distance.
Relax/update all its neighbors.
Continue until vertex n is reached.
🧩 Graph Representation (Adjacency List)
Example representation:

🧮 Key Variables
Variable	Meaning
dist[i]	Minimum distance from vertex 1 to vertex i
orig[i]	Parent of vertex i (to reconstruct path)
pq	Min-heap priority queue
INF	A very large value (e.g., 1e18)
💡 PseudoCode
FUNCTION Dijkstra(n, m, edges):
    Initialize graph as adjacency list
    For each edge (a, b, w):
        Add (b, w) to graph[a]
        Add (a, w) to graph[b]

    For i = 1 to n:
        dist[i] = INF
        orig[i] = -1

    dist[1] = 0
    pq = priority_queue()
    pq.push((0, 1)) // (distance, vertex)

    WHILE pq is not empty:
        (d, u) = pq.top()
        pq.pop()

        IF d > dist[u]:
            CONTINUE

        FOR each (v, w) in graph[u]:
            IF dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                orig[v] = u
                pq.push((dist[v], v))

    IF dist[n] == INF:
        RETURN -1
    ELSE:
        BUILD path using orig[]
        REVERSE path
        PRINT path
