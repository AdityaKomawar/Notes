## DP Notes
1. Basic Knapsack problem with memoization
```C++   
#include <iostream>
using namespace std;
int knapsack(int v[], int wt[], int n, int w, int **t) {
    if(n == 0 || w == 0) return 0;
    if(t[n-1][w-1] != -1) return t[n-1][w-1];
    else {
        if(wt[n-1] <= w) return t[n-1][w-1] = max(v[n-1] + knapsack(v, wt, n-1, w-wt[n-1], t), knapsack(v, wt, n-1, w, t));
        else return t[n-1][w-1] = knapsack(v, wt, n-1, w, t);
    }
}

int main() {
    int v[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int n = 3;
    int w = 4;
    int **t;
    t = new int *[n+1];
    for(int i = 0; i < n+1; i++) {
        t[i] = new int[w+1];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < w; j++) {
            t[i][j] = -1;
        }
    }
    
    cout << knapsack(v, wt, n, w, t);

    return 0;
}
   ```
