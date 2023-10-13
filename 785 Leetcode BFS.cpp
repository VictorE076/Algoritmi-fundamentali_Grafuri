// 785 Leetcode BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Leetcode
class Solution {
    bool BFS(vector<vector<int>>& gr, char* color, int start)
    {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            int sz = gr[node].size();
            for (int i = 0; i < sz; i++)
            {
                int vecin = gr[node][i];
                if (color[vecin] == -1)
                {
                    color[vecin] = 1 - color[node];
                    q.push(vecin);
                }
                else if (color[vecin] == color[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int sz = graph.size();
        char* color;
        color = new char[sz];
        for (int i = 0; i < sz; i++)
        {
            color[i] = -1;
        }
        for (int i = 0; i < sz; i++)
        {
            if (color[i] != -1)
                continue;
            bool isBpt = BFS(graph, color, i);
            if (!isBpt)
            {
                delete[] color;
                return false;
            }    
        }
        delete[] color;
        return true;
    }
};

int main()
{
    // Example:
    vector<vector<int>> graph1 = { {1, 2, 3}, {0, 2}, {0, 1, 3}, { 0, 2 } };
    Solution a1;
    cout << "Sol. 1: " << a1.isBipartite(graph1) << endl;
    //
    vector<vector<int>> graph2 = { {1, 3}, {0, 2}, {1, 3}, { 0, 2 } };
    Solution a2;
    cout << "Sol. 2: " << a2.isBipartite(graph2) << endl;
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
