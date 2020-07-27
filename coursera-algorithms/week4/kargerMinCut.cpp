#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct Node {
    Node(): vertices({}), adjs({}) {};
    Node(const Node& anotherNode): vertices(anotherNode.vertices), adjs(anotherNode.adjs) {};
    // Node(unordered_set<int> _vertices, unordered_set<int> _adjs): vertices(_vertices), adjs(_adjs) {};
    unordered_set<int> vertices;
    unordered_set<int> adjs;
 
    void RemoveSelfLoops()
    {
        for (const auto& v : vertices)
            adjs.erase(v);
    }
};

int Random(int min, int max)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range

    return distr(gen);
}

void Print(const unordered_set<int>& arr)
{
    for (auto e : arr)
    {
        cout << e << ",";
    }
    cout << endl;
}

void Print(const Node& node)
{
    cout << "Vertices ";
    Print(node.vertices);

    cout << "Adjs ";
    Print(node.adjs);
}

int KargerMinCut(vector<Node> graph)
{
    cout << "asdf";
    while (graph.size() > 2)
    {
        cout << "WHile begins :: ";
        int i = Random(0, graph.size());
        const auto& node = graph[i];
        const auto& v = node.vertices;
        const int& u = *node.adjs.cbegin();

        // merge vertices
        // move all u's adj to v, then erase u
        Node superNode(node);
        int j = 0;
        while (j < graph.size())
        {
            const Node& currentNode = graph[j];
            bool isNodeU = count(currentNode.vertices.cbegin(), currentNode.vertices.cend(), u);

            if (isNodeU)
            {
                for (const auto& vertex : currentNode.vertices)
                {
                    superNode.vertices.insert(vertex);
                }
                for (const auto& adj : currentNode.adjs)
                {
                    superNode.adjs.insert(adj);
                }
                break;
            }
            j++;
        }

        if (j == graph.size())
            throw runtime_error("Vertex u not found");

        superNode.RemoveSelfLoops();

        graph[i] = superNode;
        graph.erase(graph.cbegin() + j);
        cout << " graph size " << graph.size() << endl;
    }

    return graph.front().adjs.size();
}

int main()
{
    ifstream file("kargerMinCut.txt");
    string line;
    vector<Node> input;
    while (getline(file, line))
    {
        int element;
        istringstream iss(line);
        Node node;
        iss >> element;
        node.vertices.insert(element);
        while (iss >> element)
        {
            node.adjs.insert(element);
        }
        input.push_back(node);
    }

    int attempts = 10;
    int minCutCrossEdges = KargerMinCut(input);
    while (attempts > 0)
    {
        int result = KargerMinCut(input);
        if (result < minCutCrossEdges)
            minCutCrossEdges = result;
        --attempts;
    }

    cout << "Answer is " << minCutCrossEdges << endl;
    return 0;
}
