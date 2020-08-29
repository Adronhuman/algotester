#include <bits/stdc++.h>
using namespace std;
const int n = 1000000;

int d[n+1];
vector<int> p;
int suma(int n) {
    vector<pair<int,int>> popa;
    int x = n;
    int dil = d[x];
    int countt = 0;
    while (d[x]!=0 && x%d[x]==0){
        if (dil!=d[x]){
            popa.push_back(make_pair(dil,countt));
            dil = d[x];
            countt =1;
        }
        else{
            countt+=1;
        }
        x /= d[x];
    }
    if (countt !=0) {
        popa.push_back(make_pair(dil,countt));
    }
    if (popa[popa.size()-1].first!=dil){
        popa.push_back(make_pair(dil,1));
    }
    int answer = 1;
    for (auto x: popa) {
        answer *= (float) (pow(x.first,x.second+1)-1)/(x.first -1);
//        cout<<x.first<<" "<<x.second<<endl;
    }
    return answer - n;
}
int main()
{

int N;
cin>>N;

for (int k = 2; k <= n; k++) {
    if (d[k] == 0) {
        d[k] = k;
        p.push_back(k);
    }
    for (int x : p) {
        if (x > d[k] || x * d[k] > n)
            break;
        if (k*x <= 1000000)
        d[k * x] = x;
    }
}
int counter = 0;
for (int i = 11;i < N+1;i++) {
    if (suma(i) > i) {
        counter+=1;
    }
}
cout<<counter;
}

