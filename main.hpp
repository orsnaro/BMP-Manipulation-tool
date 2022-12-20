#pragma once 
using namespace std;
#include <bits/stdc++.h>
#include "chroma.hpp"
#include "app_enums.hpp"
#include  "init_bmp.hpp"

Signals_app  app_start(void){
    //TODO : move all this to menues class
    system("clear");
    cout << "\n\n___________Welcome To BMP APP (prealpha v0.5)_____________\n\n";

    Signals_app app_state = Init_img::load_img();
    if(app_state == Signals_app::APP_ERROR){
        cerr << "FETAL ERROR TERMINATING";
        exit(EXIT_FAILURE);
    }

    
    cout << " ENTER: \n\n '1' to quit \n'0' to restart\n\n >  ";
    bool is_done;
    cin >> is_done;

    is_done ?  app_state = Signals_app::APP_OK : app_state = Signals_app::DONT_QUIT;
    return app_state;
}

// app_start() either in cli or gui 


