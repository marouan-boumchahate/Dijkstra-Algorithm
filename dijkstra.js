function dijkstra(graph, start) {
    const distances = {};
    const visited = new Set();
    
    // Initialize all distances to infinity
    for (let node in graph) {
        distances[node] = Infinity;
    }
    distances[start] = 0;
    
    // Priority queue implementation using array (for simplicity)
    const priorityQueue = [{distance: 0, node: start}];
    
    while (priorityQueue.length > 0) {
        // Sort by distance to get minimum (simple priority queue)
        priorityQueue.sort((a, b) => a.distance - b.distance);
        const {distance: currentDistance, node: current} = priorityQueue.shift();
        
        // Skip if already visited
        if (visited.has(current)) {
            continue;
        }
        visited.add(current);
        
        // Skip if we've already found a shorter path
        if (currentDistance > distances[current]) {
            continue;
        }
        
        // Check all neighbors
        if (graph[current]) {
            for (let neighbor of graph[current]) {
                const neighborNode = neighbor.node;
                const weight = neighbor.weight;
                const newDistance = distances[current] + weight;
                
                // If we found a shorter path, update it
                if (newDistance < distances[neighborNode]) {
                    distances[neighborNode] = newDistance;
                    priorityQueue.push({distance: newDistance, node: neighborNode});
                }
            }
        }
    }
    
    return distances;
}
