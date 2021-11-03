#include<bits/stdc++.h>
using namespace std;

long long n;
long long coors[100005];

long long move(long long dist){
    long long moves = 0;
    for(int i=1;i<n;i++){
        moves += abs(coors[i]-coors[0]-dist*i);
    }
    return moves;
} 

long long ternary_search(long long s, long long e){
    if(s==e) return move(s);
    if(e-s==1) return min(move(s), move(e));
    if(e-s==2) return min(move(s), min(move(s+1), move(e)));
    
    long long tri1 = (long long) (2*s + e)/3;
    long long tri2 = (long long) (s + 2*e)/3;
    if(move(tri1)<move(tri2)) return ternary_search(s, tri2);
    else return ternary_search(tri1, e);
}

int main(){
    scanf(" %lld", &n);
    for(int i=0;i<n;i++){
        scanf(" %lld", &coors[i]);
    }
    if(n<3){ printf("0");  return 0; }
    long long dist = (long long)((coors[n-1]-coors[0]) / (n-1));
    printf("%lld", ternary_search(0, coors[n-1]-coors[0]));
}
