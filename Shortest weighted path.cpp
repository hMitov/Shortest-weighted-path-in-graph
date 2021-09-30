#include <iostream>
#include <vector>

using namespace std;

#define INF 100000;
#define MAX 1000;
int i, j, n, m, weight, r, C[MAX][MAX], p[MAX], U[MAX], d[MAX], v, w, Min;
vector <int> G[MAX];
vector <int> finall;



void Spisuk_ot_Susedi() {

    int v1, v2;

    for (i = 1; i <= n; i++) {
        G[i].push_back(0);
        for (j = 1; j <= n; j++) {
            C[i][j] = INF;
            if (i == j) {
                C[i][j] = 0;
            }
        }
    }


    for (i = 0; i < m; i++) {
        cin >> v1 >> v2 >> weight;

        G[v1].at(0) += 1;
        G[v1].push_back(v2);
        G[v2].at(0) += 1;
        G[v2].push_back(v1);
        C[v1][v2] = weight;
        C[v2][v1] = weight;
    }
}


void deijkstra(int r) {
    for (i = 1; i <= n; i++) {
        U[i] = 0; p[i] = r; d[i] = INF;
    }
    d[r] = p[r] = 0;
    for (int i = 1; i <= n; i++) {
        v = 0; Min = INF;
        for (j = 1; j <= n; j++) {
            if (U[j] == 0 && d[j] < Min) {
                v = j; Min = d[j];
            }
        }
        U[v] = 1;
        for (j = 1; j <= G[v][0]; j++) {
            w = G[v][j];
            if (U[w] == 0 && d[v] + C[v][w] < d[w]) {
                d[w] = d[v] + C[v][w];
                p[w] = v;
            }
        }
    }
}


void print(int v) {
    if (v > 1) {
        finall.push_back(v);
        print(p[v]);
    }
}


int main()
{
    cout << "Enter the number of V: ";
    cin >> n;
    cout << "Enter the number of ribs: ";
    cin >> m;
    cout <<  "Enter the initial V for starting shortest path: ";
    cin >> r;

    Spisuk_ot_Susedi();

    deijkstra(1);

    print(r);

    finall.push_back(1);

    for (auto it = finall.rbegin(); it != finall.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << d[r] << endl;



    return 0;
}
