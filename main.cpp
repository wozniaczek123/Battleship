#include <iostream>

using namespace std;
const int n = 4;
int x,y;

int plansza[n][n] = {
        {
                1,0,0,1
        },
        {
                1,0,0,0
        },
        {
                1,0,1,0
        },
        {
                0,0,1,0
        }
};
/* 0 - pudło
 * 1 - trafiony nie zatopiony
 * 2 - trafiony zatopiony
 * 9 - już tu strzelałeś
 */
int zatopiony (int ok[n][n], int x, int y){

    if(ok[x][y] == 1){
        ok[x][y] = 9;
        if(y>0 && ok[x][y-1] == 1){cout<<"y>0"; return 1;}
        else if((y<3 && ok[x][y+1] == 1)){cout<<"y<3"; return 1;}
        else if(x>0 && ok[x-1][y] == 1){cout<<"x>0"; return 1;}
        else if(x<3 && ok[x+1][y] == 1){cout<<"x<3 "; return 1;}
        else return 2;
    }
    else if(ok[x][y] == 9) return 9;
    else return 1;
}

int main(){
    while(1){
        cout<<"Podaj x: ";
        cin>>x;
        cout<<"Podaj y: ";
        cin>>y;
        int wynik = zatopiony(plansza, x, y);
        if(wynik == 1)cout<<endl<<"Trafiony nie zatopiony!"<<endl;
        else if(wynik == 2) cout<<endl<<"Trafiony zatopiony!"<<endl;
        else if(wynik == 9)cout<<endl<<"Już strzelałeś w tą część statku!"<<endl;
        else cout<<endl<<"Pudło!"<<endl;}
}