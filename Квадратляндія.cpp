#include <bits/stdc++.h>
using namespace std;

long long f(long int k,long int m){
    return k*(8*m+7);
}
long long kvadrat(long int n){
int popa[] = {1, 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 1048576, 4194304, 16777216};
    if ((int)sqrt(n)==sqrt(n)){
        cout<<1<<endl;
        return 0;
    }
    for (int i = 0;i< sqrt(n)+1;i++){
        for (int j = 0;j<sqrt(n)+1;j++){
            if (i*i+j*j==n){
                cout<<2<<endl;
                return 0;
            }
        }
    }

    int m = 0;
    for (int k:popa){
        unsigned long long int z = 0;
        m = 0;
        while(z<n){
            z = f(k,m);
            if (z==n){
                cout<<4<<endl;
                return 1;
            }
            m++;
        }
    }
    cout<<3<<endl;
}
int main(){
    int n;
    cin>>n;
    kvadrat(n);
}




