#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
struct ii{
	long long x,y;
	ii(){};
	ii(long long x,long long y):x(x),y(y){};
	bool operator < (const ii &a) const{
		return x<a.x || (x==a.x && y<a.y);
	}
}a[N],org,b[N];
int n,m;
 
void operator -= (ii &a, ii &b){a.x-=b.x;a.y-=b.y;}
bool ccw(ii o, ii a, ii b){a-=o;b-=o;return a.x*b.y>a.y*b.x;}
bool cmp(ii a, ii b) {return ccw(org,a,b);}
long long S(ii a, ii b, ii c){
	long long sum=(a.x-b.x)*(a.y+b.y);
	sum+=(b.x-c.x)*(b.y+c.y);
	sum+=(c.x-a.x)*(c.y+a.y);
	return abs(sum);
}
bool kt(ii tp){
	int d=2,c=n,mid,tg=-1;
	while(d<=c){
		mid=(d+c)/2;
		if (!cmp(tp,b[mid])) d=mid+1;
		else{
			c=mid-1;
			tg=mid;
		}
	}
	if (tg==2 || tg==-1) return false;
	long long t1=S(tp,b[tg],b[tg-1]);
	long long t2=S(tp,b[tg],b[1]);
	long long t3=S(tp,b[1],b[tg-1]);
	long long t4=S(b[1],b[tg],b[tg-1]);
	if (t1+t2+t3==t4) return true;
	return false;
}
bool kt2(ii tp){
    int l=1,r=n;
    while (r-l>1){
        int m=(l+r)/2;
        if (cmp(tp,b[m])) r=m;
        else l=m;
    }
    long long t1=S(tp,b[l],b[r]);
	long long t2=S(tp,b[r],b[1]);
	long long t3=S(tp,b[1],b[l]);
	long long t4=S(b[1],b[r],b[l]);
	if (t1+t2+t3==t4) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen("nhap.inp","r",stdin);
	//freopen("nhap.out","w",stdout);
	cin>>n;for(int i=1;i<=n;++i)
		cin>>a[i].x>>a[i].y;
 
	int z=1;
    for (int i=2; i <= n; i++)
        if ((a[i].x < a[z].x)||((a[i].x == a[z].x)&&(a[i].y < a[z].y)))
            z=i;
    swap(a[1],a[z]);org=a[1];
    sort(a+2,a+1+n,cmp);
    z=2;
    b[1]=a[1], b[2]=a[2];
    for (int i=2; i <= n; i++){
        while ((z > 1)&&(!ccw(b[z-1],b[z],a[i])))
            z--;
        b[++z]=a[i];
    }
    n = z;
 
    cin>>m;for(int i=1;i<=m;++i){
        ii t;cin>>t.x>>t.y;
        if (kt2(t)) cout<<"YES"; else cout<<"NO";
        cout<<'\n';
    }
 
}
