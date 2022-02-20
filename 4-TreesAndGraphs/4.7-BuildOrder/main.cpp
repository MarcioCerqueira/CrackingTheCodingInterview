#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

struct Node
{
    int ID;
    int count;
};

void loadGraph(vector<vector<Node>>& adjacencyMatrix, int N)
{

    adjacencyMatrix.resize(N);
    for(auto& row : adjacencyMatrix)
        row.resize(N);
        
    for(int n1 = 0; n1 < N; n1++)
        for(int n2 = 0; n2 < N; n2++)
            adjacencyMatrix[n1][n2].ID = n1;
        
    int numberOfNeighbours, neighbourID;
    for(int node = 0; node < N; node++)
    {

        cout << "Node " << node << " is connected to how many nodes? ";
        cin >> numberOfNeighbours;
        
        for(int neighbourNode = 0; neighbourNode < numberOfNeighbours; neighbourNode++)
        {
        
            cout << "Write the ID of the neighbour of node " << node << ": ";
            cin >> neighbourID;
            //We store the reserve connection
            if(neighbourID >= 0 && neighbourID < N) adjacencyMatrix[neighbourID][node].count = 1;

        }

    }
        
}

//Time complexity: O(N^2)
void printDependencyList(vector<vector<Node>>& adjacencyMatrix)
{

    string finalOrder;
    int nodesRemoved = 0;
    while(adjacencyMatrix.size() > 0)
    {
        for(int node = 0; node < adjacencyMatrix.size(); node++)
        {

            int sum = 0;
            for(int neighbour = 0; neighbour < adjacencyMatrix.size(); neighbour++)
                sum += adjacencyMatrix[node][neighbour].count;
            
            if(sum == 0) 
            {
                finalOrder += to_string(adjacencyMatrix[node][node].ID);
                adjacencyMatrix.erase(adjacencyMatrix.begin() + node);
                for(auto& row : adjacencyMatrix) row.erase(next(row.begin(), node));
                nodesRemoved++;
            }

        }
        if(nodesRemoved == 0) break;
    }

    if(adjacencyMatrix.size() == 0) cout << finalOrder << endl;
    else cout << "There is no valid order" << endl;

}

int main()
{

    cout << "Write the number of nodes in the graph: ";
    int N;
    cin >> N;
   
    vector<vector<Node>> adjacencyMatrix;
    loadGraph(adjacencyMatrix, N);
    printDependencyList(adjacencyMatrix);
    return 0;

}