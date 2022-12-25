#pragma once 
using namespace std;
#include <bits/stdc++.h>
#include "chroma.hpp"
#include "app_enums.hpp"
#include  "inout_bmp.hpp"
#include  "simple_img_manip.hpp"


Signals_app op_menu(){
   cout << "__Operations Menu__:\n\n 1) simple_threshold_binarize \n 2) convert to Gray scale\n "\
         << "3) crop rows\n" << " 4) Just save\n" ;
    cout << "\n\nchoose your operations please : \n > "  ;
    int op ;
    cin >> op;

    if ( op == 1)
        simple_threshold_binary();

    else if ( op == 2)
        weighted_grayscale();

    else if (op == 3 )
        resize(); 

    else if ( op == 4)
        void (true);
    else{
        cout << "INVALID OPTION ..RETRY \n\n";
        op_menu();
    }

    cout << "SAVING IMAGE...\n\n";

    //TODO: make use choose save dir

    Signals_app save_state = save_image();
    if ( int(save_state) != 0){
        cout << "SAVE ERROR TERMINATING!\n\n";
        exit(EXIT_FAILURE);
    }else 
        cout << "DONE SAVING !... \n\n";
    

    return Signals_app::APP_OK;
}

Signals_app  app_start(void){
    //TODO : move all this to menues class
    system("cls");
    cout << "\n\n___________Welcome To BMP APP (Beta  v1.5)_____________\n\n";
    Signals_app app_state = load_img_ptr -> load_img();

    if(app_state == Signals_app::APP_ERROR){
        cerr << "FETAL ERROR TERMINATING";
        exit(EXIT_FAILURE);
    }

    op_menu();
    
    cout << " Choose what to do Next: \n\n  1) to quit \n  0) to restart\n\n >  ";
    bool is_done;
    cin >> is_done;

    is_done ?  app_state = Signals_app::QUIT : app_state = Signals_app::RELOAD_APP;
    return app_state;
}

// TODO : app_start() either in cli or gui 


