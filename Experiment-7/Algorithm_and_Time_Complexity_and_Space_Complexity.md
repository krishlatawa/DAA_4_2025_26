# Cheapest Flights Within K Stops - Algorithm

## Approach: Modified BFS

### Steps:

1. **Create Adjacency List**
   - Store graph as `adj[u] = {v, cost}`

2. **Initialize**
   - `dist[]` array with large value (1e9)
   - Set `dist[src] = 0`
   - Use queue → `{stops, {node, cost}}`

3. **Push Source**
   - Start with `{0, {src, 0}}`

4. **BFS Traversal**
   - While queue is not empty:
     - Pop front element
     - Extract `stops`, `node`, `cost`

5. **Stop Condition**
   - If `stops > k`, skip

6. **Explore Neighbors**
   - For each neighbor:
     - If `cost + edgeWeight < dist[neighbor]`:
       - Update distance
       - Push `{stops + 1, neighbor, newCost}` into queue

7. **Return Answer**
   - If `dist[dst] == 1e9` → return `-1`
   - Else return `dist[dst]`

---

## Complexity

- Time: `O(E * K)`
- Space: `O(V + E)`