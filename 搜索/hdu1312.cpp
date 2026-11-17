#include<iostream>
#include<queue>
using namespace std;
char room[23][23];
int dir[4][2]{
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
int wx,hy,num;
#define check(x,y)(x<wx&&x>=0&&y<hy&&y>=0)
struct node{int x,y;};
void bfs(int dx,int dy){
    num=1;
    node start,next;
    queue<node>q;
    start.x=dx;
    start.y=dy;
    q.push(start);
    while(!q.empty()){
        start=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            next.x=start.x+dir[i][0];
            next.y=start.y+dir[i][1];
            if(check(next.x,next.y)&&room[next.x][next.y]=='.'){
                room[next.x][next.y]='#';
                num++;
                q.push(next);

            }

        }
    }
}
int main(){
    int x,y,dx,dy;
    while(cin>>wx>>hy){
        if(wx==0&&hy==0)
        break;
        for(y=0;y<hy;y++){
            for(x=0;x<wx;x++){
                cin>>room[x][y];
                if(room[x][y]=='@'){
                    dx=x;
                    dy=y;
                }
            }
        }
        num=0;
        bfs(dx,dy);
        cout<<num<<endl;
    }

    return 0;
}