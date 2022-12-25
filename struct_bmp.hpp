#pragma once 
#include <bits/stdc++.h>

typedef unsigned char BYTE;

// ___ VERY IMPORTANT NOTES!! ___ //
// 1) STRUCTS instance for exporting i.e.'saving the bmp' shall follow little indian format. bmp_export_instance/s
// 2) STRUCTS instance used to image manipulation before saving shall follow big indian (easier to deal with inside the code). bmp_import_instance/s
// 3) BMP_STRUCT :: Raw_data  in imported instance will not have padding to widths that is not multiple of 4 
// 3+) (for easier manipulation) only add paddings in export instance
// 4) 24-bit main bmp struct has 3 sub structs -> Fileheader , Bmpspecs , Raw_data 


#pragma pack(1)//one byte allignmenmt in memory i.e.(disable compiler's fast mem. access optimization feature)

struct Fileheader {
    uint16_t         file_type_sign;
    uint32_t         tot_sz;
    uint32_t         un_used;
    uint32_t         raw_data_offset = 54;//offset from base i.e.(0x00000000 + 0xraw_data_offset = pixles array)

};
#pragma pack(1)
struct Bmpspecs {
    uint32_t        bmpspecs_sz = 40;//i.e.( also called 'DIB header size only')
    uint32_t        img_width_px; //originally int32_t
    uint32_t        img_height_px;//originally int32_t
    uint16_t        clr_planes_no;
    uint16_t        bpx = 24;//app currently only works on 24-bit depth bmps
    uint32_t        compression = 0; //0 for un-compressed bmps ( app currently only works on uncompressed) 
    uint32_t        raw_data_sz;
    uint32_t        xppm;// ppm =~ pixles per meter
    uint32_t        yppm;
    uint32_t        clrs_count;
    uint32_t        important_clrs;
};
struct Raw_data{ std::vector <BYTE> raw_array; }; // try char array later

struct BGR_pxl {//NOT USED FOR NOW
    //little indian of -> RGB colors
    BYTE blue_ch;
    BYTE green_ch;
    BYTE red_ch;
    // BYTE pad_byte = 0x00;
};

#pragma pack(1) 
struct BMP_STRUCT{
    Fileheader fileheader;
    Bmpspecs bmpspecs;
    Raw_data raw_data; 
};
    
