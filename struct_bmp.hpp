#pragma once 
#include <bits/stdc++.h>
// #include <stdint.h>

typedef unsigned char BYTE;
struct Fileheader;
struct Bmpspecs;
struct Raw_data;
// 24 bit bmp has 3 main structs -> Fileheader , Bmpspecs , Raw_data 

}

#pragma pack(1) //one byte allignmenmt
struct Fileheader {
    uint16_t        file_type_sign;
    uint32_t         tot_sz;
    uint32_t         un_used;
    const uint32_t   raw_data_offset = 54;
    //offset from base i.e.(0x00000000 + raw_data_offset = pixles array)
};

struct Bmpspecs {
   const uint32_t   Bmpspecs_sz = 40;//i.e.(DIB header size only)
   int32_t         img_width_px;
   int32_t         img_height_px;
   uint16_t        clr_planes_no;
   const uint16_t  bpx = 24;//app only works on 24-bits bmps
   const uint32_t  compression = 0;//0 for un-compressed bmps ( will only work on uncompressed) 
   uint32_t        raw_data_sz;
   int32_t         xppm;// ppm == pixles per meter
   int32_t         yppm;
   unint32_t       clrs_count;
   unint32_t       important_clrs;
};

#pragma pack(4)
struct BGR_pxl {//little indian of -> RGB colors
    //although its 24 bit img but will make one padding byte 
    BYTE blue_ch;
    BYTE green_ch;
    BYTE red_ch;
    BYTE pad_byte;
};

//DWORD alignment (32bit pxl sz) 
//for more safty BGR sub struct is also 4 byte size

struct Raw_data{
//TODO : try this if vector didnt work : 
    // char raw_data_arr[Bmpspecs.raw_data_sz] 
    vector<char> raw_array;
};

    
