#include<bits/stdc++.h>

using namespace std;


int main(){
    int n, ans, t, count;
    string s, c, w1;
    cin>>t;
    for(int _ = 0; _<t; _++){
        cin>>n>>s;
        ans = 0;
        count = 0;
        for(auto  w = s.begin(); w != s.end(); w++){
            if(*w == 'R' || *w == 'O' || *w == 'P' || *w == 'A')
                count++;
            else{
                if(count>0){
                    ans += 1;
                    count = 0;
                }
            }
        }
        if(count>0)
            ans += 1;
        count = 0;
        for(auto  w = s.begin(); w != s.end(); w++){
            if(*w == 'Y' || *w == 'O' || *w == 'G' || *w == 'A')
                count++;
            else{
                if(count>0){
                    ans += 1;
                    count = 0;
                }
            }
        }
        if(count>0)
            ans += 1;
        count = 0;
        for(auto  w = s.begin(); w != s.end(); w++){
            if(*w == 'B' || *w == 'G' || *w == 'P' || *w == 'A')
                count++;
            else{
                if(count>0){
                    ans += 1;
                    count = 0;
                }
            }
        }
        if(count>0)
            ans += 1;
        
        printf("Case #%d: %d\n", _+1, ans);
    }
    
    return 0;
}
