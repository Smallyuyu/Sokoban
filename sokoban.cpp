#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include "bk.h"
#include "bk.cpp"
using namespace std;
#define chen ios::sync_with_stdio(0);cin.tie(0)
int main(){
    //chen;
    vector<string> maps;
    int op;
    bool gameing = false;
    bk game(maps);
    string ss = "RELOADING . . .";
    //運行遊戲
    while(1){
        if(gameing == false){
            //開檔
            maps.clear();
            ifstream ifs;
            int open_flag = 1;
            string txt_name;
            while(1){
                cout<<"Please Input Your file name without .txt\n";
                cout<<"Eg. mission1\n";
                cin>>txt_name;
                txt_name = txt_name + ".txt";
                cout<<txt_name<<'\n';
                ifs.open(txt_name, ifstream::in);
                if(!ifs.is_open()){
                    cout<<"Failed to open file\n";
                    cout<<"Please Input Again.\n";
                    open_flag = 0;
                }
                if(open_flag == 1) break;
            }

            //讀檔
            int n,m;
            string mp;
            ifs>>n>>m;
            for(int i = 0 ; i < n ; i++){
                ifs>>mp;
                maps.push_back(mp);
            }
            ifs.close();
            game.set_maps(maps);
            game.start(); 
        }

        //離開局遊戲
        if(game.get_game_exit_button_on() == true){
            //RELOADING
            for(int i = 0 ; i < ss.length() ; i++){
                cout<<ss[i];
                Sleep(300);
            }

            //清屏
            for(int i = 0 ; i < 50 ; i++){
                gotoxy(0,i);
                cout<<"                                                               ";
            }
            gotoxy(0,0);
            cout<<"Input 1 to Exit";
            gotoxy(0,1);
            cout<<"Input 2 to Keep Playing\n";
            cin>>op;
            if(op == 1) break; //離開總遊戲
            gameing = false;
            game.set_game_exit_button_on(false);
        }
    }
    cout<<"Exit";
    system("pause");
    return 0;
}