#include <bits/stdc++.h>
using namespace std;
int choose=0;

int MaxMin(int n,bool s){
    if(n==0){
        if(s)
            return 1;
        return -1;
    }

    int a=MaxMin(n-1,!s);

    //alpha-beta pruning
    if((a==1&&s)||(a==-1 && !s)){
        choose=1;
        return a;
    }
    else if(n==1)
        return a;

    int b=MaxMin(n-2,!s);

    //alpha-beta pruning
    if((b==1&&s)||(b==-1 && !s)){
        choose=2;
        return b;
    }
    else if(n==2)
        return b;

    int c=MaxMin(n-3,!s);

    //alpha-beta pruning
    if((c==1&&s)||(c==-1 && !s)){
        choose=3;
        return c;
    }
    else{
        choose=1;
        return c;
    }

}
int main() {
    int n , x;
    bool s=true;
    int Chance_dec;
    cout << "enter the initial number of sticks in the box\n";
    cin >> n;
    Chance_dec=(rand()%2)+1;//using random function to decide which AI gets the first chance
    if(Chance_dec==1){
        cout<<"AI 1 chance first";
         while(n>0){
        x=MaxMin(n,s);
        cout<<"AI 1 chosed:"<<choose<<"\n";
        n=n-choose;
        if(n==1){
                cout<<"\nAI 1 won\n";
                break;
        }
        x=MaxMin(n,s);
        cout<<"AI 2 chosed:"<<choose<<"\n";
        n=n-choose;
        if(n==1){
            cout<<"\nAI 2 won\n";
            break;
        }
         }
    }
    else if(Chance_dec==2){
        cout<<"AI 2 chance first\n";
        while(n>0){
            x=MaxMin(n,s);
            cout<<"AI 2 chosed:"<<choose<<"\n";
            n=n-choose;
            if(n==1){
                    cout<<"\nAI 2 won\n";
                    break;
            }
            x=MaxMin(n,s);
            cout<<"AI 1 chosed:"<<choose<<"\n";
            n=n-choose;
            if(n==1){
                cout<<"\nAI 1 won\n";
                break;
            }
        }
    }
   return 0;
}