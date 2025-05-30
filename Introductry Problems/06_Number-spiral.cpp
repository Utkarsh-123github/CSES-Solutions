#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>y>>x;
        if(y>x){
            ll ans = (y-1)*(y-1);
            if(y % 2 != 0){
                ans += x;
            }
            else ans += (2*y-x);
            cout<<ans<<endl;
        }
        else{
            ll ans = (x-1)*(x-1);
            if(x % 2 == 0){
                ans += y;
            }
            else ans += (2*x-y);
            cout<<ans<<endl;
        }
    }
    return 0;
}