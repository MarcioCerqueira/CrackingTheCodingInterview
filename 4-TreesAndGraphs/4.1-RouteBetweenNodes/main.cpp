#include <iostream>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

struct Node
{
    int ID;
    bool visited = false;
    vector<shared_ptr<Node>> neighbours;
};

struct Graph
{
    vector<shared_ptr<Node>> nodes;
};

void loadGraph(Graph& graph, int N)
{

    int numberOfNeighbours, neighbourID;
    
    graph.nodes.resize(N);
    for(int node = 0; node < graph.nodes.size(); node++) 
    {
        graph.nodes[node] = make_shared<Node>();
        graph.nodes[node]->ID = node;
    }
        
    for(int node = 0; node < graph.nodes.size(); node++)
    {

        cout << "Node " << node << " is connected to how many nodes? ";
        cin >> numberOfNeighbours;
        
        for(int neighbourNode = 0; neighbourNode < numberOfNeighbours; neighbourNode++)
        {
        
            cout << "Write the ID of the neighbour of node " << node << ": ";
            cin >> neighbourID;
            if(neighbourID >= 0 && neighbourID < graph.nodes.size())
            {
                graph.nodes[node]->neighbours.push_back(graph.nodes[neighbourID]);
            } 

        }

    }
        
}

void printGraph(const Graph& graph)
{

    cout << endl;
    cout << "Graph: " << endl;
    cout << endl;

    for(int node = 0; node < graph.nodes.size(); node++)
    {
        cout << "Node " << graph.nodes[node]->ID << ": ";
        for(const shared_ptr<Node>& neighbour : graph.nodes[node]->neighbours)
            cout << neighbour->ID << " ";
        cout << endl;
    }

}

//Time complexity: O(V + E) 
void DFS(shared_ptr<Node>& node, int searchID)
{

    if(node->ID == searchID)
    {
        cout << "DFS: There is a route between those nodes!" << endl;
        return;
    }

    node->visited = true;
    for(shared_ptr<Node>& adjacentNode : node->neighbours)
        if(!adjacentNode->visited)
            DFS(adjacentNode, searchID);

}

//Time complexity: O(V + E) 
void BFS(shared_ptr<Node>& node, int searchID)
{

    queue<shared_ptr<Node>> queue;
    queue.push(node);

    while(!queue.empty())
    {

        shared_ptr<Node> n = queue.front(); 
        queue.pop();

        n->visited = true;
        if(n->ID == searchID)
        {
            cout << "BFS: There is a route between those nodes!" << endl;
            return;
        }

        for(shared_ptr<Node>& adjacentNode : n->neighbours)
            if(!adjacentNode->visited)
                queue.push(adjacentNode);

    }

}

int main()
{

    cout << "Write the number of nodes in the graph: ";
    int N;
    cin >> N;

    Graph graph;
    loadGraph(graph, N);
    printGraph(graph);
    
    int a, b;
    cout << endl;
    do
    {

        cout << "Write two node IDs: ";
        cin >> a >> b;
        if(a < 0 || b < 0 || a >= N || b >= N || a == b) return 0;

        for(shared_ptr<Node>& node : graph.nodes) node->visited = false;
        DFS(graph.nodes[a], b);
        
        for(shared_ptr<Node>& node : graph.nodes) node->visited = false;
        BFS(graph.nodes[a], b);

    } while (true);
    
    return 0;

}