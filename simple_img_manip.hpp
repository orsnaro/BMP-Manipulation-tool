#pragma once
#include <bits/stdc++.h>
#include "inout_bmp.hpp"// struct objects it here temp (move later)
using namespace std;

void resize(){ 
    cout << "input NEW WIDTH in pixels:\n > ";
    uint32_t n_width ;
    cin >> n_width;
    cout << "input NEW HEIGHT in pixles:\n > ";
    uint32_t n_height;
    cin >> n_height;
    if( n_height > bmp_spec_obj.img_height_px){
        cout << "INVALID HEGIHT.. RENTER SIZE\n\n";
        resize();
    }
    if( n_width > bmp_spec_obj.img_width_px){
        cout << "INVALID WIDTH.. RENTER SIZE\n\n";
        resize();
    }

    bmp_spec_obj.img_height_px = n_height;
    bmp_spec_obj.img_width_px = n_width;
    cout << "IMAGE RESIZED!\n\n";
    //TODO : delete extra garpge data at end 

    return;
}


