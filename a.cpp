#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;

vector<int>row={1,-1,0,0},col={0,0,1,-1};

bool func(int i,int j,int m,int n,vector<vector<int>>&g){
    if(i==-1 && j==m-1)return true;
    
    bool a=false,b=false;
    
    if(i+1<n && g[i+1][j])a=func(i+1,j,m,n,g);
    if(j+1<m && g[i][j+1])b=func(i,j+1,m,n,g);
    
    return a || b;
}

int main(){
    
    int n,m;
    cin>>n>>m;

    vector<string>edge(n);

    for(int i=0;i<n;i++){
        cin>>edge[i];
    }

    queue<vector<int>>q;
    vector<vector<int>>vis(n,vector<int>(m));
    vector<vector<pair<int,int>>>path(n,vector<pair<int,int>>(m,{-1,-1}));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(edge[i][j]=='A'){
                q.push({i,j});
                break;
            }
        }
    }

    int px=-1,py=-1;

    bool flg=true;
    while(!q.empty()){
        int size=q.size();

        for(int i=0;i<size;i++){
            auto v=q.front();
            q.pop();

            if(v[0]==0 || v[1]==0 || v[0]==n-1 || v[1]==m-1){
                px=v[0];
                py=v[1];
                flg=false;
                break;
            }

            for(int k=0;k<4;k++){
                int r=row[k]+v[0],c=col[k]+v[1];

                if(r>=0 && c>=0 && r<n && c<m && edge[r][c]=='.' && !vis[r][c]){
                   
                    q.push({r,c});
                    vis[r][c]=1;
                    auto pr=make_pair(v[0],v[1]);
                    path[r][c]=pr;
                }
            }

        }
    }

    if(flg){
        cout<<"NO\n";
    }

    else{
        cout<<"YES\n";

        int ct=0;
        string res="";
        // cout<<px<<" "<<py<<endl;
        while(true){
            
            if(px == -1 && py == -1)break;

            ct++;
            
            int r=path[px][py].first,c=path[px][py].second;
            if(r>px){
                res+='U';
            }
            else if(r<px){
                res+='D';
            }

            else if(c>py){
                res+='L';
            }
            else{
                res+='R';
            }

            px=r,py=c;

        }

        res.pop_back();
        reverse(res.begin(),res.end());
        cout<<ct-1<<endl;
        cout<<res<<endl;
    }
    cout<<"You are outside the function";

    return 0;
}
