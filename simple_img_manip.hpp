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

void resize(){ //actually it crops image

    
    Bmpspecs *specs_ptr = &bmp_import_instance.bmpspecs;

    cout << "input NEW WIDTH in pixels:\n > ";
    uint32_t n_width ;
    cin >> n_width;
    cout << "input NEW HEIGHT in pixles:\n > ";
    uint32_t n_height;
    cin >> n_height;

    if( n_height > specs_ptr -> img_height_px){
        cout << "INVALID HEGIHT.. RENTER SIZE\n\n";
        resize();
    }
    if( n_width > specs_ptr -> img_height_px){
        cout << "INVALID WIDTH.. RENTER SIZE\n\n";
        resize();
    }

    specs_ptr -> img_height_px = n_height;
    specs_ptr -> img_width_px  = n_width;
    cout << "IMAGE RESIZED!\n\n";
    //TODO : delete extra garpge data at end 

    return;
}

void simple_threshold_binary(){
    vector < vector<BYTE> > thresh_arr = create_formated_arr();

    //TODO: take average of each pxl int( (B+G+R) / 3 )

    //TODO : ask user to pick thresh value 0-255

    //TODO : then loop to thresh all pxls ( put all channels to 0 or 255 depending  on thresh)

    save_formated_arr( thresh_arr );
}

void weighted_grayscale(){
  vector < vector<BYTE> > grayscale_arr = create_formated_arr();

    //fixed formuala: give each channel a weight then get average then stor avg in all channells;

    save_formated_arr( grayscale_arr );
}

