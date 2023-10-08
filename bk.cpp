#include <iostream>
#include <string>
#include "bk.h"
#include <windows.h>
#include <conio.h>
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

bk::bk(vector<string> maps_){
    set_maps(maps_);
    set_game_exit_button_on(false);
}

void bk::set_maps(vector<string> maps_){
    maps = maps_;
}

void bk::set_game_exit_button_on(bool b_){
    game_exit_button_on = b_;
}

bool bk::get_game_exit_button_on(){
    return game_exit_button_on;
}

void bk::start(){
    //清屏
    for(int i = 0 ; i < 50 ; i++){
        gotoxy(0,i);
        cout<<"                                                               ";
    }

    string t = "x";
    for(int i = 0 ; i < maps[0].length() ; i++) t = t + 'x';
    vector<string> tmp(maps.size(),t);
    maps_of_two = tmp;
    //定義maps_of_two
    for(int i = 0 ; i < maps.size() ; i++){
        for(int j = 0 ; j < maps[i].size() ; j++){
            if(maps[i][j] == '2'){
                maps_of_two[i][j] = '2';
            }
        }
    }

    //2的數量
    int cnt = 0;
    for(int i = 0 ; i < maps.size() ; i++){
        for(int j = 0 ; j < maps[i].size() ; j++){
            if(maps_of_two[i][j] == '2'){
                cnt++;
            }
        }
    }
    two_num = cnt;

    //定義玩家初始位置
    int x,y;
    for(int i = 0 ; i < maps.size() ; i++){
        for(int j = 0 ; j < maps[i].size() ; j++){
            if(maps[i][j] == '0'){
                x = i;
                y = j;
                break;
            }
        }
    }
    int ch;
    int push_;
    print_map();
    while(1){
        push_ = 1;
        //玩家操作
        if(_kbhit()){
            ch = _getch();
            push_ = 0;
        }
        if(push_ == 0){
            if(ch == 119 || ch == 87){ //Ww 向上
                push_ = 1;
                if(maps[x - 1][y] == '-'){ //空白
                    swap(maps[x - 1][y],maps[x][y]);
                    x--;
                }
                else if(maps[x - 1][y] == '/'){ //牆壁
                    push_ = 0;
                }
                else if(maps[x - 1][y] == '1'){ //箱子
                    if(maps[x - 2][y] == '-'){
                        swap(maps[x - 1][y],maps[x - 2][y]);
                    }
                     else if(maps[x - 2][y] == '2'){
                        maps[x - 1][y] = '-';
                        maps[x - 2][y] = '1';
                    }
                    else{
                        push_ = 0;
                    }
                }
                else if(maps[x - 1][y] == '2'){
                    maps[x][y] = '-';
                    maps[x - 1][y] = '0';
                    x--;
                }
            }

            else if(ch == 97 || ch == 65){ //Aa 向左
                push_ = 1;
                if(maps[x][y - 1] == '-'){ //空白
                    swap(maps[x][y - 1],maps[x][y]);
                    y--;
                }
                else if(maps[x][y - 1] == '/'){ //牆壁
                    push_ = 0;
                }
                else if(maps[x][y - 1] == '1'){ //箱子
                    if(maps[x][y - 2] == '-'){
                        swap(maps[x][y - 1],maps[x][y - 2]);
                    }
                    else if(maps[x][y - 2] == '2'){
                        maps[x][y - 1] = '-';
                        maps[x][y - 2] = '1';
                    }
                    else{
                        push_ = 0;
                    }
                }
                else if(maps[x][y - 1] == '2'){
                    maps[x][y] = '-';
                    maps[x][y - 1] = '0';
                    y--;
                }
            }

            else if(ch == 115 || ch == 83){ //Ss 向下
                push_ = 1;
                if(maps[x + 1][y] == '-'){ //空白
                    swap(maps[x + 1][y],maps[x][y]);
                    x++;
                }
                else if(maps[x + 1][y] == '/'){ //牆壁
                    push_ = 0;
                }
                else if(maps[x + 1][y] == '1'){ //箱子
                    if(maps[x + 2][y] == '-'){
                        swap(maps[x + 1][y],maps[x + 2][y]);
                    }
                    else if(maps[x + 2][y] == '2'){
                        maps[x + 1][y] = '-';
                        maps[x + 2][y] = '1';
                    }
                    else{
                        push_ = 0;
                    }
                }
                else if(maps[x + 1][y] == '2'){
                    maps[x][y] = '-';
                    maps[x + 1][y] = '0';
                    x++;
                }
            }

            else if(ch == 100 || ch == 68){ //Dd 向右
                push_ = 1;
                if(maps[x][y + 1] == '-'){ //空白
                    swap(maps[x][y + 1],maps[x][y]);
                    y++;
                }
                else if(maps[x][y + 1] == '/'){ //牆壁
                    push_ = 0;
                }
                else if(maps[x][y + 1] == '1'){ //箱子
                    if(maps[x][y + 2] == '-'){
                        swap(maps[x][y + 1],maps[x][y + 2]);
                    }
                    else if(maps[x][y + 2] == '2'){
                        maps[x][y + 1] = '-';
                        maps[x][y + 2] = '1';
                    }
                    else{
                        push_ = 0;
                    }
                }
                else if(maps[x][y + 1] == '2'){
                    maps[x][y] = '-';
                    maps[x][y + 1] = '0';
                    y++;
                }
            }

            else if(ch == 27){ //Esc 離開
                game_exit_button_on = true;
            }
            //更新畫面
            print_map();

            //是否結束
            if(check_end() == true){
                game_exit_button_on = true;
                for(int i = 0 ; i < 50 ; i++){
                    gotoxy(0,i);
                    cout<<"                                                               ";
                }
                gotoxy(0,0);
                cout<<"YOU WIN!\n";
                break;
            }

            //是否重新遊戲
            if(game_exit_button_on == true) break;
        }
    }
    return;
}

void bk::print_map(){
    for(int i = 0 ; i < maps.size() ; i++){
        gotoxy(0,i);
        for(int j = 0 ; j < maps[i].size() ; j++){
            if(maps_of_two[i][j] == '2'){
                if(!(maps[i][j] == '0' || maps[i][j] == '1')){
                    maps[i][j] = '2';
                }
            }
            cout<<maps[i][j];
        }
    }
    return;
}

bool bk::check_end(){
    int cnt = 0;
    for(int i = 0 ; i < maps.size() ; i++){
        for(int j = 0 ; j < maps[i].size() ; j++){
            if(maps[i][j] == '1' && maps_of_two[i][j] == '2'){
                cnt++;
            }
        }
    }
    if(cnt == two_num) return true;
    return false;
}