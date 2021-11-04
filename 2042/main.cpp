#include<bits/stdc++.h>
using namespace std;
int n, m, k;
long long arr[1000005];
long long seg[4000005];

long long make_seg(int s, int e, int node){
    if(s==e) return seg[node] = arr[s];
    int mid = (s+e)/2;
    return seg[node] = make_seg(s, mid, node*2) + make_seg(mid+1, e, node*2+1);
}

void update_seg(int s, int e, int node, int idx, long long num){
    if(idx<s || idx>e) return;
    seg[node] += num;
    if(s==e) return;
    int mid = (s+e)/2;
    update_seg(s, mid, node*2, idx, num);
    update_seg(mid+1, e, node*2+1, idx, num);
}

long long sum_seg(int s, int e, int node, int l, int r){
    if(l>e || r<s) return 0;
    if(l<=s && e<=r) return seg[node]; 
    int mid = (s+e)/2;
    return sum_seg(s, mid, node*2, l, r) + sum_seg(mid+1, e, node*2+1, l, r);
}

int main(){
    scanf(" %d %d %d", &n, &m, &k);
    for(int i=1;i<=n;i++) { 
        scanf(" %lld", &arr[i]);
    }
    make_seg(1, n, 1);
    for(int i=0;i<m+k;i++){
        int type;
        long long a, b;
        scanf(" %d %lld %lld", &type, &a, &b);
        if(type==1){
            update_seg(1, n, 1, a, b-arr[a]);
            arr[a] = b;
        }
        else printf("%lld\n", sum_seg(1, n, 1, a, b));
    }   
}
