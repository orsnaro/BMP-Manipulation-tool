#pragma once
// termianl and filysystem lib will write images here as map of values :  BYTE arrays 
// keys : image name  prefixed with '_' to avoid wrong naming conventions like  '1image.bmp'
#include <iostream>
#include <map>
#include <vector>
#include <filesystem>

using namespace std;
typedef unsigned char BYTE;

class Load_buffer{
    static int obj_cnt ; // to empty the map later ( max 5 images 'last recent 5 images')
    string bfrd_image_name ;

    public:
        static map <string , vector <BYTE> > buffer_map;
        Load_buffer( string file_abs_path , ) 
        // buffer_map load_buffer()
}




