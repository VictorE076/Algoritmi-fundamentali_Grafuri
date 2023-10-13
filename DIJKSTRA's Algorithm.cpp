// DIJKSTRA's Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
//ifstream f("dijkstra.in.txt");
//ofstream g("dijkstra.out.txt");
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");

const int MAX_LIMIT = 2147483647;
int *dist;
struct rule
{
    bool operator()(int a, int b)
    {
        return dist[a] > dist[b];
    }
};

void Print_Graph(vector<pair<int, int>> *graph, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " :  ";
        const int num = graph[i].size();
        for (int j = 0; j < num; j++)
        {
            cout << graph[i][j].first << ", " << graph[i][j].second << "   ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void Dijkstra(vector<pair<int,int>>* graph, int n, int start)
{
    dist = new int[n + 1];
    bool* in_queue;
    in_queue = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dist[i] = MAX_LIMIT;
        in_queue[i] = false;
    }
    priority_queue<int, vector<int>, rule> pq;
    pq.push(start);
    dist[start] = 0;
    in_queue[start] = true;
    while (!pq.empty())
    {
        int node = pq.top();
        in_queue[node] = false;
        pq.pop();
        const int sz = graph[node].size();
        for (int i = 0; i < sz; i++)
        {
            int neighb = graph[node][i].first, cost = graph[node][i].second;
            if (dist[node] + cost < dist[neighb])
            {
                dist[neighb] = dist[node] + cost;
                if (!in_queue[neighb])
                {
                    pq.push(neighb);
                    in_queue[neighb] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == start)
            continue;
        if (dist[i] == MAX_LIMIT)
            g << "0 ";
        else
            g << dist[i] << " ";
    }
    delete[] in_queue;
}
int main()
{
    int n, m; // 'n' nodes, 'm' edges
    int a, b, length;
    vector<pair<int, int>> *graph;
    f >> n >> m;
    graph = new vector<pair<int, int>>[n + 1];
    for (int i = 0; i < m; i++)
    {
        f >> a >> b >> length;
        graph[a].push_back(make_pair(b, length));
    }
    f.close();
    // Print_Graph(graph, n);
    Dijkstra(graph, n, 1);
    ///
    delete[] dist;
    delete[] graph;
    g.close();
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
