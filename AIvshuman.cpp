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
    int n , x, match;
    bool s=true;
    int Chance_dec;//used to deide whom to give the chance first 
    cout << "enter the initial number of sticks in the box\n";
    cin >> n;
    Chance_dec=(rand()%2)+1;//this is to decide who gets the first chance with the help of generating a no. randomly
    if(Chance_dec==1){
        cout<<"Your chance first";
         while(n>0){
            cout<<"\n Enter value: ";//Human enters the value 
            cin>>match;
            if(match>=1 && match<=3){
                n=n-match;
                if(n==1){
                        cout<<"\nYou won\n";
                        break;
                }
                x=MaxMin(n,s);
                cout<<"opponent chose:"<<choose;
                n=n-choose;
                if(n==1){
                    cout<<"\nAI won\n";
                    break;
                }
            }
            else 
                cout<<"ERROR input is not valid\n";
        }
    }
    else{
        cout<<"AI's chance first";
        while(n>0){
            x=MaxMin(n,s);
            cout<<"\n Opponent chose:"<<choose;
            n=n-choose;
            if(n==1){
                cout<<"\nAI won\n";
                break;
            }
            cout<<"\nEnter value: ";
            cin>>match;
            n=n-match;
            if(n==1){
                    cout<<"\nYou won\n";
                    break;
            }
        }
    }
   return 0;
}