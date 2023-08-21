#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n,m; // n --> number of colliders, m --> number of requests
    cin>>n>>m;
    int colliders[n+1];
    for (int i = 1; i < n+1; i++)
    {
        colliders[i] = 0; // initially all the colliders have false as their success status
    }
    while(m--){
        char sign;
        int collider;
        cin>>sign>>collider;
        if(sign == '+'){
            if(colliders[collider] == 0){
                colliders[collider] = 1;
                int conflict = 0,conflict_num = 0;
                for (int i = 1; i <= n; i++)
                {
                    if(i != collider && __gcd(i,collider) != 1 && colliders[i] == 1){
                        conflict = 1;
                        conflict_num = i;
                        break;
                    }
                }
                if(conflict == 0){
                    cout<<"Success\n";
                }
                else{
                    cout<<"Conflict with "<<conflict_num<<" \n";
                    colliders[collider] = 0;
                }
                
            }
            else if(colliders[collider] == 1){
                cout<<"Already on \n";
            }
        }
        else{
            if(colliders[collider] == 1){
                colliders[collider] = 0;
                cout<<"Success \n";
            }
            else if(colliders[collider] == 0){
                cout<<"Already off \n";
            } 
        }
    }
    return 0;
}

/*

10 10
+ 6
+ 10
+ 5
- 10
- 5
- 6
+ 10
+ 3
+ 6
+ 3

*/