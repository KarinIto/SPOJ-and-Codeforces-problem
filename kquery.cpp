#include<bits/stdc++.h>
using namespace std;
const int N=3e5+6;
struct data{
    int v,l,r,type,id;
}a[N];
int n,q,bit[N],val[N];
bool cmp(data a, data b){
    return (a.v>b.v) or (a.v==b.v && a.type>b.type);
}
void update(int x){
    for(;x<=n;x+=x&(-x)) bit[x]++;
}
int get(int x){
    int ans=0;
    for(;x>0;x-=x&(-x)) ans+=bit[x];
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("nhap.inp","r",stdin);
    //freopen("nhap.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i].v;
        a[i]={a[i].v,i,i,-1,i};
    }
    cin>>q;
    for(int i=n+1;i<=n+q;++i){
        cin>>a[i].l>>a[i].r>>a[i].v;a[i].id=i-n;
    }
    sort(a+1,a+1+n+q,cmp);
    for(int i=1;i<=n+q;++i)
        if (a[i].type==-1) update(a[i].l);
        else val[a[i].id]=get(a[i].r)-get(a[i].l-1);
    for(int i=1;i<=q;++i) cout<<val[i]<<'\n';
}
 
