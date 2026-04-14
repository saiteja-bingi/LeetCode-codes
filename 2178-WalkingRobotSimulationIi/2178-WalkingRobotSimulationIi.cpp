// Last updated: 15/04/2026, 00:44:52
class Robot {
public:
    /*
        r=h,c=w 
        n->w->s->e->n
        dx=[0,-1,0,1]
        dy=[1,0,-1,0]

        basically row=y-axis;
        col=x-axis
    */
    int x=0,y=0,dir=3;
    int r,c;
    int dx[4]={0,-1,0,1};
    int dy[4]={1,0,-1,0};
    int per;
    Robot(int width, int height) {
        r=height;
        c=width;
        per=2*(r+c-2);
    }
    
    void step(int num) {
        if (per == 0) return;
        num%=per;
        if(num==0){
            if(x==0&&y==0) dir=2;
            return;
        }
        while(num>0){
            int nx=x+num*dx[dir];
            int ny=y+num*dy[dir];
            if(nx<0){
                num=num-x;
                x=0;
            }
            else if(ny<0){
                num=num-y;
                y=0;
            }
            else if(nx>=c){
                num=num-(c-x-1);
                x=c-1;
            }
            else if(ny>=r){
                num=num-(r-y-1);
                y=r-1;
            }
            else{
                x+=num*dx[dir];
                y+=num*dy[dir];
                num=0;
                break;
            }
            dir=(dir+1)%4;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(dir==0) return "North";
        if(dir==1) return "West";
        if(dir==2) return "South";
        return "East";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */