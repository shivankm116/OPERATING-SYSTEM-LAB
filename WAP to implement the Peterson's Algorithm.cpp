//7.WAP to implement the Peterson's Algorithm.
using namespace std;

int flag[2]={0,1};
int turn;

void* first(void* data){
    flag[0]=1;
    turn=1;
    while(flag[1] && turn==1){}
    string &str=*(static_cast<string*>(data));
    if(str!=""){
        if(str=="abcd"){
            str="Hello";
        }
    }
    flag[0]=0;
    pthread_exit(NULL);
}

void* second(void* data){
    flag[1]=1;
    turn=0;
    while(flag[0] && turn==0){}
    string &str=*(static_cast<string*>(data));
    if(str!=""){
        if(str=="wxyz"){
            str="abcd";
        }
    }
    flag[1]=0;
    pthread_exit(NULL);
}

int main(){
    int rc=0;
    string s = "wxyz";
    pthread_t t;

    rc=pthread_create(&t,NULL,first,static_cast<void*>(&s));
    if(rc!=0){
        cout<<"error!";
        exit(rc);
    }
    rc=pthread_create(&t,NULL,second,static_cast<void*>(&s));
    if(rc!=0){
        cout<<"error!";
        exit(rc);
    }

    while(flag[0] && flag[1]!=0){}
    cout<<s;

    pthread_exit(NULL);
    return 0;
}

