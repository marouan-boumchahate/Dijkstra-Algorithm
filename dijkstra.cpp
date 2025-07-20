#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
using namespace std;

unordered_map<int, int> dijkstra(unordered_map<int, vector<pair<int, int>>>& graph, int start) {
    unordered_map<int, int> distances;
    
    // Initialize all distances to infinity
    for (auto& node : graph) {
        distances[node.first] = INT_MAX;
    }
    distances[start] = 0;
    
    // Priority queue to store (distance, node) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int current_distance = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        // Skip if we've already found a shorter path
        if (current_distance > distances[current]) {
            continue;
        }
        
        // Check all neighbors
        for (auto& neighbor_pair : graph[current]) {
            int neighbor = neighbor_pair.first;
            int weight = neighbor_pair.second;
            int new_distance = distances[current] + weight;
            
            // If we found a shorter path, update it
            if (new_distance < distances[neighbor]) {
                distances[neighbor] = new_distance;
                pq.push({new_distance, neighbor});
            }
        }
    }
    
    return distances;
}
