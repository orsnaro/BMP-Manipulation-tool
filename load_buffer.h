#pragma once
// Load_buffer  and filysystem lib will write images here as map :  
// KEYS : image name  VALUES :  vector <byte> vec

#include <bits/stdc++.h>
#include "inout_bmp.hpp"

using namespace std;
typedef unsigned char BYTE;


class Load_buffer{

     static int obj_cnt ; // to empty the map later ( max 5 images 'last recent 5 images')
    //no size var needed you can get it from the map value.size()

    public:
    
        //TODO :those two var may be private and use func to get them
        string bfrd_image_name ; // buffer_map key better be const string 
        filesystem :: path _abs_path;

        pair<string, vector<BYTE>> load_buffer_func( filesystem :: path abs_file_path ="/"){

            filesystem::path file_stem_name = abs_file_path.stem();

            //start actuall reading of image raw data
            ifstream read_img_obj(abs_file_path , ios::binary | ios::in);

            //get file size
            read_img_obj.seekg(0, read_img_obj.end);
            int file_sz = read_img_obj.tellg();
            read_img_obj.seekg(0,read_img_obj.beg);
            vector <BYTE> tmp_vec2(file_sz + 1);

            //INPUT
            read_img_obj.read( (char*) &tmp_vec2[0] , file_sz); //only  c_str arrays so cast DA VECOTR!
            if( read_img_obj.is_open() ) read_img_obj.close();

            
            
            //TODO : check erros later  
            pair <string , vector<BYTE>> mp_elmnt ;
            mp_elmnt = {file_stem_name.string(),tmp_vec2};

            return mp_elmnt ;
        }

        static map <string , vector <BYTE> > buffer_map;

        

        Load_buffer(  filesystem::path rel_file_path = "/" ) {
            _abs_path = filesystem::current_path();
            _abs_path /= rel_file_path;

            if( !_abs_path.is_absolute()){
                cout << "fetal warning : not valid path\n " \
                     << _abs_path << "\n PLEASE RE-Import IMAGE\n\n";
                     exit(EXIT_FAILURE);
            }
            
            obj_cnt ++;
            if( obj_cnt > 5 ){
                cout << "soft warning: Buffer is full . FLUSHING... \n\n";
                buffer_map.clear();
                //TODO : make the buffer dumb to file and retrive the last recent 5 files data
            }
        }

} load_buffer_obj1;

 Load_buffer *load_bfr_ptr = &load_buffer_obj1;
 map <string , vector <BYTE> > Load_buffer :: buffer_map;
 int Load_buffer :: obj_cnt ;
