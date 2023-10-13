// 2316 Leetcode DFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
// Leetcode
class Solution {
    int COUNT = 0;
    void DFS(vector<int>* gr, bool* visited, int node)
    {
        COUNT++;
        int sz = gr[node].size();
        visited[node] = true;
        for (int i = 0; i < sz; i++)
        {
            if (!visited[gr[node][i]])
            {
                DFS(gr, visited, gr[node][i]);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long total = 0;
        vector<int>* graph;
        bool* visited;
        graph = new vector<int>[n];
        visited = new bool[n];
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        int sz = edges.size();
        for (int i = 0; i < sz; i++)
        {
            int x, y;
            x = edges[i][0];
            y = edges[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            COUNT = 0;
            DFS(graph, visited, i);
            total += (long long)COUNT * (n - COUNT);
        }
        delete[] graph;
        delete[] visited;
        return total / 2;
    }
};
int main()
{
    // Example:
    int n1 = 7;
    vector<vector<int>> edges1 = { {0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4} };
    Solution a1;
    long long sol1 = a1.countPairs(n1, edges1);
    cout << "Sol 1: " << sol1 << endl;
    //
    int n2 = 3;
    vector<vector<int>> edges2 = { {0, 1}, {0, 2}, {1, 2} };
    Solution a2;
    long long sol2 = a2.countPairs(n2, edges2);
    cout << "Sol 2: " << sol2 << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
