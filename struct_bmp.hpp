#pragma once 
#include <bits/stdc++.h>
// #include <stdint.h> //in stdc++.h

typedef unsigned char BYTE;
struct Fileheader;
struct Bmpspecs;
struct Raw_data;
struct BRG_pxl;
// 24-bit bmp has 3 main structs -> Fileheader , Bmpspecs , Raw_data 



#pragma pack(1) //one byte allignmenmt
struct Fileheader {
    uint16_t         file_type_sign;
    uint32_t         tot_sz;
    uint32_t         un_used;
    const uint32_t   raw_data_offset = 54;
    //offset from base i.e.(0x00000000 + raw_data_offset = pixles array)
};

struct Bmpspecs {
   const uint32_t  Bmpspecs_sz = 40;//i.e.(DIB header size only)
   uint32_t         img_width_px;//originally uint32_t
   uint32_t         img_height_px;//originally uint32_t
   uint16_t        clr_planes_no;
   const uint16_t  bpx = 24;//app only works on 24-bit depth bmps
   const uint32_t  compression = 0;//0 for un-compressed bmps ( will only work on uncompressed) 
   uint32_t        raw_data_sz;
   uint32_t         xppm;// ppm == pixles per meter
   uint32_t         yppm;
   uint32_t        clrs_count;
   uint32_t        important_clrs;
};

#pragma pack(4)
//DWORD alignment (32bit pxl sz)
//for more safty BGR sub struct is also 4 byte size
struct Raw_data{
    std::vector <char> raw_array;
    //TODO : try this if vector didnt work as expected : 
    // char raw_data_arr[Bmpspecs.raw_data_sz] 
};

struct BGR_pxl {//NOT USED FOR NOW
    //little indian of -> RGB colors
    BYTE blue_ch;
    BYTE green_ch;
    BYTE red_ch;
    BYTE pad_byte;
    //although its 24 bit img but will make one padding byte 
};

    
