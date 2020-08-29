#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M,A,B;
    cin>>N>>M;
    vector <vector<int>> graph;
    vector<int> d;
    vector<int > count_of_ways;
    vector<int> seen;
    for(int i = 0;i<N+1;i++){
        vector<int>x;
        graph.push_back(x);
        d.push_back(9999999999);
        count_of_ways.push_back(0);
        seen.push_back(0);
    }
    cin>>A>>B;
    for (int i = 0;i<M;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    d[A] = 0;
    int cur = A;
    count_of_ways[A] = 1;
    queue<int> q;
    q.push(A);
    seen[A]=1;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(auto x:graph[cur]){
            if (seen[x]==0){
                q.push(x);
                seen[x]=1;
            }

            if (d[x]>d[cur]+1){
                d[x] = d[cur]+1;
                count_of_ways[x] = count_of_ways[cur];
            }
            else if (d[x] == d[cur]+1){
                count_of_ways[x]+=count_of_ways[cur];
            }
        }
    }
    cout<<count_of_ways[B]%1000000007;
}

