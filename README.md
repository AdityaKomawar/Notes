# Table of contents

+ [DP](#dp-notes)
<!--    1. [Knapsack](#knapsack-problem)
        - [Recursion + Memoization](#recursion-memoization) -->
## DP Notes
1. Knapsack problem
   + Recursion + Memoization
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
   + Top Down (DP)
        ```C++
        #include <bits/stdc++.h>
        using namespace std;
        int knapsack(int v[], int wt[], int n, int w, int **t) {
            for(int i = 0; i < n+1; i++) {
                for(int j = 0; j < w+1; j++) {
                    if(i == 0 || j == 0) t[i][j] = 0;
                    
                    else if(wt[i-1] <= j) t[i][j] = max(v[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
                    else t[i][j] = t[i-1][j];
                }
            }
            return t[n][w];
        }
        
        int main() {
            int v[] = {1, 2, 3};
            int wt[] = {4, 5, 1};
            int n = 3;
            int w = 4;
            
            int **t;
            t = new int *[n+2];
            for(int i = 0; i < n+2; i++) {
                t[i] = new int[w+2];
            }
            
            for(int i = 0; i < n+2; i++) {
                for(int j = 0; j < w+2; j++) {
                    t[i][j] = -1;
                }
            }
            
            cout << knapsack(v, wt, n, w, t);
        
            return 0;
        }
        ```
2. Subset Sum Problem
   + Top Down (DP)
        ```C++
        #include <iostream>
        
        using namespace std;
        
        int subsetSum(int arr[], int n, int sum, int **t) {
            for(int i = 0; i < n+1; i++) {
                for(int j = 0; j < sum+1; j++) {
                    if(i == 0) t[i][j] = 0;
                    if(j == 0) t[i][j] = 1;
                }
            }
            
            for(int i = 1; i < n+1; i++) {
                for(int j = 1; j < sum+1; j++) {
                    if(arr[i-1] <= j) {
                        t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                    } else {
                        t[i][j] = t[i-1][j];
                    }
                }
            }
            return t[n][sum];
        }
        
        int main() {
            int arr[] = {3, 34, 4, 12, 5, 2};
            int sum = 9;
            int n = 6;
            int **t;
            t = new int *[n+1];
            for(int i = 0; i < n+1; i++) {
                t[i] = new int[sum+1];
            }
            
            cout << subsetSum(arr, n, sum, t);
        
            return 0;
        }
        ```
