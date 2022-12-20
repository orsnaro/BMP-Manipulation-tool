#pragma once 
#include <bits/stdc++.h>
#include "app_enums.hpp"
#include "load_buffer.h"
#include "struct_bmp.hpp"
using namespace std;
//#include <filesytem> //in stdc++.h

            Fileheader  fil_hid_obj; //TODO : later find bmp instances save technique
            Bmpspecs bmp_spec_obj; 
            Raw_data pxl_obj;

           // --------------TASKS TODO SECTION -----------------
//TODO :load image  , do checks funcs , resize , cvrt to gray scale
//TODO : init linikng to gui here ( my 1st cpp gui ever <3 )
//TODO : for error handling all functions must return at least pair <T,T>  => func normal return + state signal 





           //--------------  PARENT CLASSES SECTION ----------------

class Init_img { //can be inhirited to load diff image formats
    public:
        //call after loading the img
        static Signals_app create_bmp( Load_buffer & _raw_img_obj ){
            const string bfr_mp_key = _raw_img_obj.bfrd_image_name;
            vector <BYTE> tmp_vec = _raw_img_obj.buffer_map[bfr_mp_key];
            vector<BYTE> dumy;

            //fill file header 
                //ref : UINT32 bigvar = (var1 << 24) + (var2 << 16) + (var3 << 8) + var4;
                // BYTE to WORD 
            int cntr = -1;
            fil_hid_obj.file_type_sign = (tmp_vec[++cntr] << 8) + tmp_vec[++cntr];
            fil_hid_obj.tot_sz = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            fil_hid_obj.un_used = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            
            //fill Bmpspecs (DIB) 
            bmp_spec_obj.img_width_px = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            bmp_spec_obj.img_height_px = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            bmp_spec_obj.clr_planes_no = (tmp_vec[++cntr] << 8) + tmp_vec[++cntr];
            bmp_spec_obj.raw_data_sz = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            bmp_spec_obj.xppm = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            bmp_spec_obj.yppm = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            bmp_spec_obj.clrs_count = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            bmp_spec_obj.important_clrs = (tmp_vec[++cntr] << 24) + (tmp_vec[++cntr] << 16) + (tmp_vec[++cntr] << 8) + (tmp_vec[++cntr]);
            
            //fill pxl array 
            for(int i = fil_hid_obj.raw_data_offset ; i < tmp_vec.size(); i++)
                pxl_obj.raw_array.push_back(tmp_vec[i]);

            return Signals_app::LOAD_OK; 
        }
        static Signals_BMPstruct check_validity(){
                    //TODO : continue other checks
                int bmp_magic_sign = 0x424d;
                bool is_real_bmp = (bmp_magic_sign ==  fil_hid_obj.file_type_sign );

                if ( !is_real_bmp ){
                    cout << "FETAL ERROR ! : this is fake bmp file \n\n ";
                    exit(EXIT_FAILURE);
                }
                cout << "BMP Created successfully!\n\n";
                return Signals_BMPstruct::OK_FILE_TYPE;
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

            state_t load_state = int(check_validity());

            if (load_state != 0)
                return Signals_app::BAD_LOAD;
            else  
                return Signals_app::LOAD_OK;    
        }



    //TODO : DO constructor
};


          //----------------- GLOBAL FUNCTIONS SECTION -------------

Signals_app save_image();
//TODO: handle memory leak if user kept restarting app u must destruct those objcts


