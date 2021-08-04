#include <bits/stdc++.h>

using namespace std;

int INF = 100000000;

int main() {
    cout << "Print the number of cities" << '\n';
    int n;
    cin >> n;
    if(n <= 0){
        cout << "Go play Minecraft";
        return 0;
    }

    int parent[1 << n][2];
    int dp[1 << n];
    for(int i = 1; i < (1 << n); ++i){
        dp[i] = INF;
    }
    dp[1] = 0;
    parent[1][1] = 0;
    parent[1][0] = 0;
    int graph[n][n];

    cout << "Print the adjacency matrix" << '\n';
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
            if(graph[i][j] < 0){
                cout << "I told you, go play Minecraft";
                return 0;
            }
        }
    }

    for(int i = 1; i < (1 << n); ++i){
        if(dp[i] == INF){
            continue;
        }
        for(int j = 1; j < n; ++j){
            if((i & (1 << j)) == 0){
                if(dp[i + (1 << j)] > dp[i] + graph[parent[i][1]][j] && (i + (1 << j)) != (1 << n) - 1){
                    dp[i + (1 << j)] = dp[i] + graph[parent[i][1]][j];
                    parent[i + (1 << j)][0] = i;
                    parent[i + (1 << j)][1] = j;
                }
                else if((i + (1 << j)) == (1 << n) - 1 && dp[i + (1 << j)] > dp[i] + graph[parent[i][1]][j] + graph[j][0]){
                    dp[i + (1 << j)] = dp[i] + graph[parent[i][1]][j] + graph[j][0];
                    parent[i + (1 << j)][0] = i;
                    parent[i + (1 << j)][1] = j;
                }
            }
        }
    }

    cout << "Minimal distance is: " << dp[(1 << n) - 1] << '\n';
    cout << "Way:" << '\n';
    int index = (1 << n) - 1;
    cout << "1 ";
    while(index != 0){
        cout << parent[index][1] + 1 << " ";
        index = parent[index][0];
    }
    return 0;
}