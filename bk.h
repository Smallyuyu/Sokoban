#include <iostream>
#include <vector>
#include <string>
using namespace std;
#ifndef BK_H_
#define BK_H_
class bk{
    public:
        bk(vector<string>);
        void set_maps(vector<string>);
        void set_game_exit_button_on(bool);
        bool get_game_exit_button_on();
        void start();
        bool check_end();
        void print_map();
    private:
        vector<string> maps;
        vector<string> maps_of_two;
        bool game_exit_button_on;
        int two_num;
};
#endif