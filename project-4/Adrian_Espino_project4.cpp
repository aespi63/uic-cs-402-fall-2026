
// be sure to change FIRSTNAME and LASTNAME with your own first and last name
#include "Adrian_Espino_project4.h"
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

const string who_am_i() {
    return "Adrian_Espino";
}

/****************
 * INSTRUCTIONS *
 ****************
 *
 * - Replace all instances of "Firstname_Lastname" with your firstname and
 *   your last name. This include the .h and .cpp files, along with the
 *   header guards at the top of the .h file.
 *
 * - Implement the appropriate algorithms as described below.
 *   You must follow the specifications as written below.
 *
 * - Certain function signatures may not be modified (as it will affect auto
 *   grading). These functions will be specified.
 *
 * - You are allowed to add helper functions. Be sure to add the appropriate
 *   function prototypes in "Fistname_Lastname_project4.h."
 *
 * - The file "testing.cpp" has various functions you can utilize to test
 *   your code. You can also add your own tests!
 *
 * - If you are working in a group, please modify the comments directly below.
 *   
 * - IMPORTANT: If you are working in a group, every member is expected to submit their
 *   source code individually.
 *
 */


/*** GROUP PROJECT ***/
// Please list ALL of your other group members as comments below.
//   Member 1
//   Member 2



/*** PROJECT 4: Graphs ***/

/* Topological Sorting
 *
 * 10 Points
 *
 * In this problem, you are tasked with reading the description of a
 * directed graph as input, then outputting a valid topological
 * sort of the graph, if one exists.
 *
 * Input
 *  - int n: number of nodes/vertices in the graph, labeled from 0 to n-1
 *  - vector<Edge> edges: a list of directed edges in the graph
 *
 * Output
 *  - vector<int>: a valid topological sorting of the graph. If
 *    no topological sorting exists, output an empty list.
 *    If multiple topological sortings exist, you only need to
 *    output a single one.
 *
 * Note: Edge is a struct defined in Firstname_Lastname_project2.h.
 *
 */


vector<int> topological_sort(int n, vector<Edge> edges) {
    // Your code here!
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);
    // Make an adjacency list and indegree vector
    for (const Edge& e : edges) {
        adj[e.from].push_back(e.to);
        indegree[e.to]++;
    }

    vector<int> result;
    queue<int> q;
    // Add nodes with no incoming edges to the queue
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    // While the list is not empty we store the first node in the que
    // and pop it off the que and add it to the result vector.
    // Then we decrement the indegree of all the nodes connected to it and
    // if any of those nodes have no incoming edges we add them to the que
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (result.size() != n) {
        return {}; // No topological sort exists (graph has a cycle)
    }

    return result;
}


/* Single Source Shortest Paths on DAGs
 *
 * 15 points
 *
 * In this problem, you will be given a directed acyclic graph with 
 * arbitrary integer edge weights (i.e., they can be negative!), as
 * well as a single source node. Your goal will be to output the
 * shortest distance from the source to every other vertex in the
 * graph.
 *
 * Input
 *  - int n: number of nodes in the graph, labeled from 0 to n-1
 *  - vector<Edge> edges: list of weighted directed edges in the graph
 *  - int source: ID of the source node
 *
 * Output
 *  - vector<int>: vector of size n such that entry i is the distance
 *    from source to i in the given graph. Use the value "INT_MAX" to
 *    indicate that there is no path from source to i.
 *
 * Algorithm
 *  - Topological Sorting + BFS is enough to solve this problem.
 *
 * Assumptions
 *  - The graph given as input will always be a DAG
 *
 */
vector<int> dag_single_source(int n, vector<Edge> edges, int source) {
    //your code here!
    // Get the topological order of the graph
    vector<int> order = topological_sort(n, edges);
    // Make all distances INT_MAX and set the source distance to 0
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    // Make an adjacency list of the grpah 
    vector<vector<Edge>> adj(n);
    for (const Edge& e : edges) {
        adj[e.from].push_back(e);
    }
    // For each node in the topological order, we check if the distance to that node
    // is INT_MAX, if it is we continue to the next node. If it is  not, we check
    // all the edges connected to that node and check if the distance to the node
    // plus the weight of the edge is less than the distance to the node connected
    // to the edhe. 
    for (int u : order) {
        if (dist[u] == INT_MAX) {
            continue;
        }
        for (const Edge& e : adj[u]) {
            if (dist[u] + e.weight < dist[e.to]) {
                dist[e.to] = dist[u] + e.weight;
            }
        }
    }
    return dist;
}


/* Dijkstra's Algorithm
 *
 * 25 Points
 *
 * In this problem, you are simply tasked to implement Dijkstra's Algorithm.
 *
 * Input
 *  - int n: number of nodes in the graph, labeled from 0 to n-1
 *  - vector<Edge> edges: list of weighted directed edges in the graph
 *  - int source: ID of the source node
 *
 * Output
 *  - vector<Node>: a list of size n such that entry i contains a Node node
 *    with the following properties:
 *      - node.id = i
 *      - node.path_cost = cost of the shortest path from source to i
 *      - node.pred = id of the predecessor of i on the shortest path from
 *        source to i
 *
 * Assumptions
 *  - You are guaranteed that the graph contains only non-negative edges
 *    (i.e., weight at least 0). For simplicity, all weights will be
 *    integers.
 * 
 * Note: Node is a struct defined in Firstname_Lastname_project2.h.
 */


vector<Node> dijkstras_algorithm(int n, vector<Edge> edges, int source) {
    // Your code here!
    // Note: see the LeetCode from in-class for the problem "Cheapest Flights
    // K stops" to see how you can create a priority_queue with the Node struct.

    // make an adjacency list of the graph
    vector<vector<Edge>> adj(n);
    for (const Edge& e : edges) {
        adj[e.from].push_back(e);
    }
    // Make a result vector of Nodes and set the path_cost to INT_MAX
    // and the predecessor to -1. Set the source path_cost to 0
    vector<Node> result(n);
    for (int i = 0; i < n; ++i) {
        result[i].id = i;
        result[i].path_cost = INT_MAX;
        result[i].pred = -1;
    }
    result[source].path_cost = 0;

    // Use a priority queue to store the nodes to be processed
    // It is ordered by the path_cost of the nodes, so that the node with the
    // smallest oath_cost is processed first. We use the greater<Node>
    // comparator to make the priority queue a min-heap.
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({source, 0, -1});

    // While the priority queue is not empty, we pop the node with the smallest
    // path_cost and process it.
    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();
        int u = cur.id;

        if (cur.path_cost > result[u].path_cost) {
            continue;
        }
        // For each neighbor of u, we check if the path_cost to that neighbor can be
        // improved by going through u. If it can, we update the path_cost and
        // predecessor of that neighbor and push it onto the priority queue.
        for (const Edge& e : adj[u]) {
            int new_cost = result[u].path_cost + e.weight;
            if (new_cost < result[e.to].path_cost) {
                result[e.to].path_cost = new_cost;
                result[e.to].pred = u;
                pq.push({e.to, new_cost, u});
            }
        }
    }
    return result;
}


/* A-star Algorithm
 *
 * 25 Points
 *
 * In this problem, you are asked to implement a modified version of Dijkstras,
 * known as A* (A-star). The A* algorithm is very similar to Dijkstras, with
 * two notable differences:
 *  (a) A* uses some heuristic function h to estimate the distance between any
 *      two nodes; and
 *  (b) A* only finds a path from a specified source node and a target node.
 *
 * Recall in Dijkstras, the algorithm finds the shortest path from a single
 * source to all other nodes in the graph.
 *
 * Given a source s and a target t, A* is guaranteed to output a shortest path
 * from s to t as long as the heuristic h underestimates the distance between 
 * any two nodes u,v in the graph. If d(u,v) represents the actual distance
 * between u and v, then h(u,v) <= d(u,v) for all u,v is enough to guarantee
 * that A* outputs a shortest path from s to t.
 *
 * For this specific version of A*, you will be given two points on a grid (a
 * start point and an end point). The grid will be specified by a graph, with
 * nodes being a GridNode (each with their own x and y value on the grid), and
 * edges being a GridEdge. Each GridEdge has a weight that is of a double type.
 * A GridEdge will only connect adjacent or diagonal nodes. Formally, for a
 * GridNode at point (x,y), all of the following edges are possible:
 *
 *  - (x+1, y) (cost = 1.0)
 *  - (x-1, y) (cost = 1.0)
 *  - (x, y+1) (cost = 1.0)
 *  - (x, y-1) (cost = 1.0)
 *  - (x+1, y+1) (cost = 1.5)
 *  - (x-1, y+1) (cost = 1.5)
 *  - (x+1, y-1) (cost = 1.5)
 *  - (x-1, y-1) (cost = 1.5)
 * 
 * Here, edges all have an implicit movement cost, described above. Moving along
 * a diagonal edge has a cost of 1.5, while moving along a cardinally adjacent  
 * edge (north, south, east, west) has a cost of 1.
 *
 * Note that GridEdge and GridNode are structs defined in Firstname_Lastname_project2.h.
 *
 * Input:
 *  - int m: number of columns (x-axis)
 *  - int n: number of rows in the grid (y-axis)
 *  - vector<GridEdge> edges: list of edges in the graph
 *  - GridNode source: source node of the algorithm
 *  - GridNode target: target node of the algorithm
 *  - function<double(GridNode, GridNode)> h: h is a function which takes as input
 *      two GridNodes and outputs a double. This represents the heruistic_cost
 *      function for A*.
 *
 * Output:
 *  - vector<GridNode>: a list of nodes containing the path from source to target.
 *                      Note that if variable "output" is your output vector, then
 *                      it must satisfy the following properties:
 *                          - if a path from source to target exists, then
 *                              - output[0] = source
 *                              - output[output.size()-1] = target
 *                              - Moreover, output[output.size()-1].path_cost is the cost
 *                                of the path from source to target.
 *                          - if no path from source to target exists, then
 *                              - output = {} (the empty list)
 *
 * Algorithm:
 *  The algorithm is nearly identical to Dijkstra's Algorithm, with the following changes.
 *      - Suppose in Dijkstra's you are currently considering node u and expanding the 
 *        frontier along the neighbors of u.
 *      - Let v be a neighbor of u.
 *      - In Dijkstra's, you check if u.cost + weight(u,v) < v.cost, where weight(u,v) 
 *        is the weight of the edge from u to v. If this is true, you update v.cost as
 *        v.cost = u.cost + weight(u,v), update it in / add it to the priority queue,
 *        and continue.
 *      - In A*, this is modified as: v.cost = u.cost + weight(u,v) + heuristic_cost(v, target),
 *        where heuristic_cost(v, target) is a heuristic distance from node v to the target node
 *        target.
 *          - Note you also change the dijkstra's check to u.cost+weight(u,v)+heuristic_cost(v,target) < v.cost
 *  
 *  As part of your implementation of A*, you are required to implement the function
 *  heuristic_cost(GridNode start, GridNode dest) defined below. Your heuristic should never
 *  over estimate the distance between any two nodes start and dest. Remember, in theory you
 *  can move north, south, east, west, or along any diagonal (so long as there is an edge).
 *  Use this information to write a heuristic function that never over estimates the distance.
 *
 *
 * Additional Resources:
 *  - Wikipedia: https://en.wikipedia.org/wiki/A*_search_algorithm
 *  - GeeksForGeeks: https://www.geeksforgeeks.org/dsa/a-search-algorithm/
 *  - Stanford: https://theory.stanford.edu/~amitp/GameProgramming/AStarComparison.html
 *
 */



// You must implement this function.
double heuristic_cost(GridNode start, GridNode dest) {
    // Your code here!
    int dx = abs(start.x - dest.x);
    int dy = abs(start.y - dest.y);
    int diagonal_moves = min(dx, dy);
    int straight_moves = max(dx, dy) - diagonal_moves;
    return 1.5 * diagonal_moves + 1.0 * straight_moves;

}

// To test your algorithm with the function "heruistic_cost" above,
// simply pass "heuristic_cost" as a parameter to the function.
vector<GridNode> a_star_algorithm(
    int m, 
    int n, 
    vector<GridEdge> edges, 
    GridNode source, 
    GridNode target,
    function<double(GridNode,GridNode)> h
) 
{
    // Your code here!
    // Be sure to use "h" from the inputs in your implementation; do not
    // directly use "heruistic_cost" above!
    int total = m * n;


}

int main() {
    return 0;
}

