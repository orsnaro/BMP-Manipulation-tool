#pragma once
// terminal and filysystem lib will write images here as map of values :  BYTE arrays 
// keys : image name  NOTE : may be prefixed with '_' to avoid wrong naming conventions like  '1image.bmp'
#include <iostream>
#include <map>
#include <vector>
#include <filesystem>
#include "init_bmp.hpp"

using namespace std;
// #define fs filesystem;
typedef unsigned char BYTE;

class Load_buffer{

    static int obj_cnt ; // to empty the map later ( max 5 images 'last recent 5 images')
    string bfrd_image_name ; // buffer_map key
    //no size var needed you can get it from the map value.size()

    pair<string, vector<BYTE>> load_buffer_func( filesystem :: path abs_file_path ="/"){

        filesystem::path file_stem_name = abs_file_path.stem();
        //start actuall readin of image raw data
        ifstream read_img_obj(abs_file_path , ios::binary | ios::in);
        //get file size
        read_img_obj.seekg(0,ios::end);
        int file_sz = read_img_obj.tellg();
        read_img_obj.seekg(0,ios::beg);
        vector <BYTE> tmp_vec(file_sz);

        //INPUT
        read_img_obj.read( (char*) &tmp_vec[0] , file_sz); //only  c_str arrays so cast DA VECOTR!
        
        //TODO : check erros later  
        pair <string , vector<BYTE>> mp_elmnt ;
        mp_elmnt = {file_stem_name.string(),tmp_vec};

        return mp_elmnt ;
    }

    public:
        static map <string , vector <BYTE> > buffer_map;

        Load_buffer(  filesystem::path rel_file_path = "/" ) {

            filesystem :: path tmp_abs_path = filesystem::current_path();
            tmp_abs_path /= rel_file_path;

            if( !tmp_abs_path.is_absolute() || !filesystem::exists(tmp_abs_path)){
                cout << "fetal warning : not valid path or file\n " \
                     << tmp_abs_path << "\n PLEASE RE-ENTER IMAGE\n\n";
                Load_img::load_func();
            }
            
            obj_cnt ++;
            if( obj_cnt > 5 ){
                cout << "soft warning: Buffer is full . FLUSHING... \n\n";
                buffer_map.clear();
                //TODO : make the buffer dumb to file and retrive the last recent 5 files data
            }
            pair<string , vector <BYTE>> raw_pair = load_buffer_func(tmp_abs_path);
            buffer_map[raw_pair.first] = raw_pair.second;
            //Done buffering !

        }
        ~Load_buffer();
};




