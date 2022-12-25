#pragma once
#include <bits/stdc++.h>
#include "inout_bmp.hpp"// struct objects it here temp (move later)
using namespace std;


int row_sz = bmp_import_instance.bmpspecs.img_width_px * 4;    

vector < vector<BYTE> > create_formated_arr(){

    vector < vector<BYTE> > formated_pxl_ar ; // for easier image process its a vector each elemnt it one row of image

    //TODO : loop to push data row by row to formated_pxl_ar

    return formated_pxl_ar;
}

void save_formated_arr( vector < vector<BYTE> > _to_save_arr){
    vector<BYTE> *unformated_arr_ptr = &bmp_import_instance.raw_data.raw_array;

    //access pxls bytes like this:  *unformated_arr_ptr[2] 
    //TODO: loop to save the formatted again to imported struct to ready to export to final struct later
}

void resize(){ //actually it crops image rows now only

    
    Bmpspecs *specs_ptr = &bmp_import_instance.bmpspecs;

    cout << "\n\n ##Original Image shape(width , height) : " ;
    cout << specs_ptr ->img_width_px <<','<<  specs_ptr -> img_height_px << " ##" << endl << endl;

    cout << "input NEW WIDTH in pixels:\n > ";
    uint32_t n_width ;
    cin >> n_width;
    cout << "input NEW HEIGHT in pixles:\n > ";
    uint32_t n_height;
    cin >> n_height;

    if( n_height > (specs_ptr -> img_height_px) or n_height == 0){
        cout << "INVALID HEGIHT.. RENTER SIZE\n\n";
        resize();
    }else if( n_width > (specs_ptr -> img_width_px) or n_width == 0){
        cout << "INVALID WIDTH.. RENTER SIZE\n\n";
        resize();
    }else if ( n_width <= (specs_ptr -> img_width_px) && n_height <= (specs_ptr -> img_height_px) ){
        specs_ptr -> img_height_px = n_height;
        specs_ptr -> img_width_px  = n_width;
        cout << "IMAGE RESIZED!\n\n";
    }

    //TODO : delete extra garpge data at end 

    return;
}

void simple_threshold_binary(){
    // vector < vector<BYTE> > thresh_arr = create_formated_arr();
     Raw_data *_thresh_ptr = &bmp_import_instance.raw_data;
     Bmpspecs *specs_ptr = &bmp_import_instance.bmpspecs;

     
    for(int i = 0; i < specs_ptr -> raw_data_sz; i+=3){
        if ( i >= specs_ptr -> raw_data_sz )
            break;

        float avg =( (_thresh_ptr -> raw_array[i] ) + (_thresh_ptr -> raw_array[i + 1] ) + (_thresh_ptr -> raw_array[i + 2]) ) / 3;
        if ( avg > 127){
            _thresh_ptr ->raw_array[i] = 255;
            _thresh_ptr ->raw_array[i + 1] = 255;
            _thresh_ptr ->raw_array[i + 2] = 255;
        }else{
            _thresh_ptr ->raw_array[i] = 0;
            _thresh_ptr ->raw_array[i + 1] = 0;
            _thresh_ptr ->raw_array[i + 2] = 0;
        }
    }
    //TODO: take average of each pxl int( (B+G+R) / 3 )

    //TODO : ask user to pick thresh value 0-255

    //TODO : then loop to thresh all pxls ( put all channels to 0 or 255 depending  on thresh)

    // save_formated_arr( thresh_arr );
    return;
}

void weighted_grayscale(){

//   vector < vector<BYTE> > grayscale_arr = create_formated_arr(); 
     Raw_data *_grayscale_ptr = &bmp_import_instance.raw_data;
     Bmpspecs *specs_ptr = &bmp_import_instance.bmpspecs;

    cout << " NOTE : this currently works for images with width that is mutliple of 4 only\n\n";

    cout << "\n\n ##Original Image shape(width , height) : " ;
    cout << specs_ptr ->img_width_px <<','<<  specs_ptr -> img_height_px << " ##" << endl << endl;

    if ( (specs_ptr -> img_width_px) % 4 != 0){
        cout << "soft warning! : the image width is not multiple of four !! can't do it for now !\n\n";
        return;
    }else{
        for(int i = 0; i < specs_ptr -> raw_data_sz; i+=3){
            if ( i >= specs_ptr -> raw_data_sz )
                break;

            float avg =( (_grayscale_ptr -> raw_array[i] * 0.11) + (_grayscale_ptr -> raw_array[i + 1] * 0.59) + (_grayscale_ptr -> raw_array[i +2] * 0.3)) / 3;
            _grayscale_ptr ->raw_array[i] = avg;
            _grayscale_ptr ->raw_array[i + 1] = avg;
            _grayscale_ptr ->raw_array[i + 2] = avg;
        }

    //TODO : use a formated array and enable for unpadded images 

    } 

    //fixed formuala: give each channel a weight then get average then stor avg in all channells;
    // save_formated_arr( grayscale_arr );

    return;
}

