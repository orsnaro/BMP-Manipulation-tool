#pragma once 
#include <bits/stdc++.h>
#include "app_enums.hpp"
#include "load_buffer.h"
using namespace std;
//#include <filesytem> //in stdc++.h

           // --------------TASKS TODO SECTION -----------------
//TODO :load image  , do checks funcs , resize , cvrt to gray scale
//TODO : init linikng to gui here ( my 1st cpp gui ever <3 )
//TODO : for error handling all functions must return at least pair <T,T>  => func normal return + state signal 





           //--------------  PARENT CLASSES SECTION ----------------

class Init_img { //can be inhirited to load diff image formats
    public:
        //call after loading the img
        static Signals_app create_bmp( Load_buffer & _raw_img_obj ){

                //go to struct_bmp.hpp and fill sruct from _raw_img_obj

        }

        static  filesystem::path image_path;

        static Signals_app load_img(){
            cout << "\nPLease Enter image path : \n > ";
            cin >> image_path;

             if( !filesystem::exists(image_path) || image_path.extension().string() != ".bmp" ){
                cout << "fetal warning : no BMP image found at PATH:\n " \
                     << image_path << "\n PLEASE RE-Import IMAGE\n\n";

                load_img();
             }
             cout << "FOUND! \n\n LOADING IMAGE.. \n\n";

            //TODO: ask from gui or cli to enter image_path and creat obj of load_buffer

            //load raw data
            Load_buffer  raw_img_obj(image_path);
            //create the structure
            create_bmp( raw_img_obj );

        }



    //TODO : DO constructor
};


          //----------------- GLOBAL FUNCTIONS SECTION -------------


