#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> visited;

    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return node;

        if (visited.find(node) != visited.end())
        {
            return visited[node];
        }

        Node *clonedNode = new Node(node->val);
        // 哈希表存储
        visited[node] = clonedNode;

        // dfs
        for (Node *n : node->neighbors)
        {
            clonedNode->neighbors.push_back(cloneGraph(n));
        }
        return clonedNode;
    }
};