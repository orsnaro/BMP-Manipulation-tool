#pragma once 
#include <bits/stdc++.h>
#include "app_enums.hpp"
#include "load_buffer.h"
#include "struct_bmp.hpp"
using namespace std;
//#include <filesytem> //in stdc++.h

           // --------------TASKS TODO SECTION -----------------
//TODO : init linikng to gui here ( my 1st cpp gui ever <3 )
//TODO : complete your checking and error handling .
//TODO : for error handling all functions must return at least pair <T,T>  => func normal return + state signal 



BMP_STRUCT bmp_import_instance; //TODO : make buffer to store latest 5 images only and 



           //--------------  PARENT CLASSES SECTION ----------------

class Init_img { //can be inhirited to load diff image formats

    public:
        //call after loading the img
        static Signals_app create_bmp_import( Load_buffer & _raw_img_obj ){//TODO : refactor create_bmp_import later to smaller funcs
            const string bfr_mp_key = _raw_img_obj.bfrd_image_name;
            vector <BYTE> tmp_vec   = _raw_img_obj.buffer_map[bfr_mp_key];
            // vector <BYTE> dumy;

            //TODO : use BGR_pxl struct also or make 4d pxl vector;
            //TODO : search for =  ( Bitwise or '|' VS '+' )
            //type  conversions used : (BYTE to WORD)  and (BYTE to DWORD)
            Fileheader *fil_hid_ptr       = &bmp_import_instance.fileheader;
            Bmpspecs   *bmp_spec_ptr      = &bmp_import_instance.bmpspecs;
            Raw_data   *pxl_arr_ptr       = &bmp_import_instance.raw_data;

            //fill Fileheader

            //stores bigger than byte in little endian
            fil_hid_ptr -> file_type_sign = (tmp_vec[0]) | (tmp_vec[1] << 8);
            fil_hid_ptr -> tot_sz         = (tmp_vec[2]) | (tmp_vec[3] << 8) | (tmp_vec[4] << 16) | (tmp_vec[5] << 24);
            fil_hid_ptr -> un_used        = (tmp_vec[6]) | (tmp_vec[7] << 8) | (tmp_vec[8] << 16) | (tmp_vec[9] << 24);
            
            //fill Bmpspecs (DIB) 
            bmp_spec_ptr -> img_width_px   = (tmp_vec[18]) | (tmp_vec[19] << 8) | (tmp_vec[20] << 16) | (tmp_vec[21] << 24); 
            bmp_spec_ptr -> img_height_px  = (tmp_vec[22]) | (tmp_vec[23] << 8) | (tmp_vec[24] << 16) | (tmp_vec[25] << 24);
            bmp_spec_ptr -> clr_planes_no  = (tmp_vec[26]) | (tmp_vec[27] << 8);
            bmp_spec_ptr -> raw_data_sz    = (tmp_vec[34]) | (tmp_vec[35] << 8) | (tmp_vec[36] << 16) | (tmp_vec[37] << 24);
            bmp_spec_ptr -> xppm           = (tmp_vec[38]) | (tmp_vec[39] << 8) | (tmp_vec[40] << 16) | (tmp_vec[41] << 24);
            bmp_spec_ptr -> yppm           = (tmp_vec[42]) | (tmp_vec[43] << 8) | (tmp_vec[44] << 16) | (tmp_vec[45] << 24);
            bmp_spec_ptr -> clrs_count     = (tmp_vec[46]) | (tmp_vec[47] << 8) | (tmp_vec[48] << 16) | (tmp_vec[49] << 24);
            bmp_spec_ptr -> important_clrs = (tmp_vec[50]) | (tmp_vec[51] << 8) | (tmp_vec[52] << 16) | (tmp_vec[53] << 24);
            


            //fill pxl array (Raw_data)
            uint32_t pxl_ar_sz = bmp_spec_ptr -> raw_data_sz; //TODO : check at loading that raw_data_sz is actually equal to actual row data section sz in file
            uint32_t pxl_ar_ofst = fil_hid_ptr -> raw_data_offset;
            uint32_t tmp_width = bmp_spec_ptr -> img_width_px;
            bool is_padded;
            int padding_no = int(tmp_width) % 4 ; 
            int first_padd_indx = tmp_width * 3; //(tmp_width * 3) is const  which equals 1st pad offset from each row begin



            (tmp_width % 4) == 0  ? is_padded = false : is_padded = true ;
            (pxl_arr_ptr -> raw_array.empty()) ? void(true) /*do nothing */ : pxl_arr_ptr -> raw_array.clear();
            for(int i = 0; i < int(pxl_ar_sz); i++){ 

                //if code to skip  bytes if it's a padding byte index
                if ( is_padded && i == first_padd_indx ) {
                    first_padd_indx += (tmp_width * 3 + padding_no) ;
                    i += (padding_no - 1); 
                    continue; 
                }
                BYTE one_pxl_ch = tmp_vec[pxl_ar_ofst + uint32_t (i)];
                pxl_arr_ptr  -> raw_array.push_back(one_pxl_ch);
            }
            

            return Signals_app::LOAD_OK; 
        }



        
        static Signals_BMPstruct check_validity(){ 

                    //TODO : continue other checks 
                    //check if size vars is actual sizes

                uint16_t bmp_magic_sign = 0x4d42; // this equals char[2] = {BM}  //if wrong switch LSB with MSB
                uint16_t *imported_magic_sign_ptr = &bmp_import_instance.fileheader.file_type_sign;

                bool is_real_bmp = (bmp_magic_sign ==  *imported_magic_sign_ptr );

                if ( !is_real_bmp ){
                    cout << "FETAL ERROR ! : this is fake bmp file \n\n ";
                    exit(EXIT_FAILURE);
                }
                cout << "BMP Created successfully!\n\n";
                return Signals_BMPstruct::OK_FILE_TYPE;
        }

         static filesystem::path image_path;

         static Signals_app load_img(){
            cout << "\nPLease Enter image path : \n > ";

            if ( !image_path.empty()) // in case of another opearation without closing app    
                image_path.clear();
            cin >> image_path;

             if( !filesystem::exists(image_path) || image_path.extension().string() != ".bmp" ){
                cout << "fetal warning : no BMP image found at PATH:\n     " \
                     << image_path << "\nPLEASE RE-Import IMAGE\n" << endl;

                load_img();
             }else{
                cout << "\n FOUND! \n\n LOADING IMAGE.. \n\n";

            //TODO: ask from gui or cli to enter image_path and creat obj of load_buffer

            //load raw data
            Load_buffer  raw_img_buffer_obj(image_path);

            pair<string , vector <BYTE>> raw_pair = raw_img_buffer_obj.load_buffer_func(raw_img_buffer_obj._abs_path);

            raw_img_buffer_obj.bfrd_image_name = raw_pair.first;
            Load_buffer :: buffer_map.emplace(raw_pair.first , raw_pair.second);
            //Done buffering !

            //create the structure
            create_bmp_import( raw_img_buffer_obj );

            state_t load_state = int(check_validity());

            if (load_state != 0)
                return Signals_app::BAD_LOAD;
            else  
                return Signals_app::LOAD_OK;    
             }
             return Signals_app :: LOAD_OK;
        }



};
 Init_img init_img_obj;
 Init_img *load_img_ptr = &init_img_obj;
 filesystem :: path Init_img :: image_path;







          //----------------- GLOBAL FUNCTIONS SECTION -------------
void clear_imported_struct(){

             Fileheader *fil_hid_ptr       = &bmp_import_instance.fileheader;
             Bmpspecs   *bmp_spec_ptr      = &bmp_import_instance.bmpspecs;
             //  Raw_data   *pxl_arr_ptr       = &bmp_import_instance.raw_data;

            //clear Fileheader
            fil_hid_ptr -> file_type_sign = 0;
            fil_hid_ptr -> tot_sz         = 0;
            fil_hid_ptr -> un_used        = 0;
            
            //clear Bmpspecs (DIB) 
            bmp_spec_ptr -> img_width_px   = 0; 
            bmp_spec_ptr -> img_height_px  = 0;
            bmp_spec_ptr -> clr_planes_no  = 0;
            bmp_spec_ptr -> raw_data_sz    = 0;
            bmp_spec_ptr -> xppm           = 0;
            bmp_spec_ptr -> yppm           =0 ;
            bmp_spec_ptr -> clrs_count     = 0;
            bmp_spec_ptr -> important_clrs = 0;

            //clear raw_array()
            //is auto cleared at creat_bmp_imported()
    return;
}
void clear_exported_struct( BMP_STRUCT &exported){

             Fileheader *fil_hid_ptr       = &exported.fileheader;
             Bmpspecs   *bmp_spec_ptr      = &exported.bmpspecs;
             //  Raw_data   *pxl_arr_ptr       = &bmp_import_instance.raw_data;

            //clear Fileheader
            fil_hid_ptr -> file_type_sign = 0;
            fil_hid_ptr -> tot_sz         = 0;
            fil_hid_ptr -> un_used        = 0;
            
            //clear Bmpspecs (DIB) 
            bmp_spec_ptr -> img_width_px   = 0; 
            bmp_spec_ptr -> img_height_px  = 0;
            bmp_spec_ptr -> clr_planes_no  = 0;
            bmp_spec_ptr -> raw_data_sz    = 0;
            bmp_spec_ptr -> xppm           = 0;
            bmp_spec_ptr -> yppm           =0 ;
            bmp_spec_ptr -> clrs_count     = 0;
            bmp_spec_ptr -> important_clrs = 0;

            //clear raw_array()
            if (! exported.raw_data.raw_array.empty() )
                exported.raw_data.raw_array.clear();
    return;
}

uint16_t cvt_endians_u16(uint16_t before){//also works vice versa

    BYTE bytes[2] = {0 , 0};
    uint16_t converted_u16 = 0;

    bytes[0] = (before) & 0xff; //get lower byte 
    bytes[1] = (before >> 8) & 0xff; //get higher byte

    converted_u16 = (bytes[0] << 8) | (bytes[1]);

    return converted_u16;
};
uint32_t cvt_endians_u32(uint32_t before){ //also works vice versa

    BYTE bytes[4] = {0,0,0,0};
    uint32_t converted_u32 = 0;

    bytes[0] = (before) & 0xff; //get lower byte
    bytes[1] = (before >> 8) & 0xff;
    bytes[2] = (before >> 16) & 0xff;
    bytes[3] = (before >> 24) & 0xff; //get higher byte

    converted_u32 = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | (bytes[3]); 

    return converted_u32;
};

Signals_app create_bmp_export( BMP_STRUCT &final_img , BMP_STRUCT &manip_img){//TODO : refactor create_bmp_export later to smaller funcs
            //this function converts all to little indian before writing to memory using save_image()
            //this function also adds padding to img widths that  aren't multiples of 4
            

             Fileheader *fil_hid_ptr   = &final_img.fileheader;
             Bmpspecs   *bmp_spec_ptr  = &final_img.bmpspecs;
             Raw_data   *pxl_arr_ptr2   = &final_img.raw_data;


            //fill Fileheader
            fil_hid_ptr -> file_type_sign  =  manip_img.fileheader.file_type_sign ;
            fil_hid_ptr -> tot_sz          =  manip_img.fileheader.tot_sz;
            fil_hid_ptr -> un_used         =  manip_img.fileheader.un_used;
            fil_hid_ptr -> raw_data_offset =  manip_img.fileheader.raw_data_offset;
            
            //fill Bmpspecs (DIB) 
            bmp_spec_ptr -> bmpspecs_sz    =  manip_img.bmpspecs.bmpspecs_sz;
            bmp_spec_ptr -> img_width_px   =  manip_img.bmpspecs.img_width_px;
            bmp_spec_ptr -> img_height_px  =  manip_img.bmpspecs.img_height_px;
            bmp_spec_ptr -> clr_planes_no  =  manip_img.bmpspecs.clr_planes_no;
            bmp_spec_ptr -> bpx            =  manip_img.bmpspecs.bpx;
            bmp_spec_ptr -> compression    =  manip_img.bmpspecs.compression;
            bmp_spec_ptr -> raw_data_sz    =  manip_img.bmpspecs.raw_data_sz;
            bmp_spec_ptr -> xppm           =  manip_img.bmpspecs.xppm;
            bmp_spec_ptr -> yppm           =  manip_img.bmpspecs.yppm;
            bmp_spec_ptr -> clrs_count     =  manip_img.bmpspecs.clrs_count;
            bmp_spec_ptr -> important_clrs =  manip_img.bmpspecs.important_clrs;
            // LATER : search for =  ( Bitwise or '|' VS '+' ) (done)
            
            //fill pxl array 
            //take  vars from created : BMP_improt_instance struct cuz in the export struct it's in little indian 
            int pxl_ar_sz      = manip_img.bmpspecs.raw_data_sz; //TODO : check at loading that raw_data_sz is actually equal to actual row data section sz in file
            int pxl_ar_ofst    = manip_img.fileheader.raw_data_offset;
            uint32_t tmp_width = manip_img.bmpspecs.img_width_px;
            int padding_no     = int(tmp_width) % 4; 
            int padd_indx      = tmp_width * 3; //(tmp_width * 3) is const  which equals 1st pad offset from each row begin
            bool is_padded;

            (tmp_width % 4) == 0  ? is_padded = false : is_padded = true ;
            (pxl_arr_ptr2 -> raw_array.empty()) ? void(true)/*do nothing */ : pxl_arr_ptr2 -> raw_array.clear();


            int cntr = 0;
            pxl_arr_ptr2 ->raw_array = manip_img.raw_data.raw_array;
            
            for(int i = 0, j = 0 ; i < pxl_ar_sz; i++){

                if ( is_padded && i == padd_indx){
                    auto begin = pxl_arr_ptr2 -> raw_array.begin();
                    pxl_arr_ptr2 -> raw_array.insert(begin + padd_indx , 2 , BYTE(0x00) );
                    padd_indx += (tmp_width * 3 + padding_no) ;
                }
                
            }


            return Signals_app::LOAD_OK; 
        }

Signals_app save_image(){

    BMP_STRUCT bmp_export_instance;
    clear_exported_struct(bmp_export_instance);

    create_bmp_export( bmp_export_instance , bmp_import_instance );

    filesystem :: path new_img_pth = "edited_image.bmp";

    if (filesystem:: exists ( new_img_pth ) )//ACTUALLY NEEDED ONLY WHEN IOS::APP
        filesystem::remove(new_img_pth);

    ofstream new_img_obj("edited_image.bmp" , ios::binary); //may use ios::trunc and delete prev if
      
    if( new_img_obj.is_open() && new_img_obj.good() ){
        new_img_obj.write( (char*) &bmp_export_instance.fileheader , sizeof(bmp_export_instance.fileheader) );
        new_img_obj.write( (char*) &bmp_export_instance.bmpspecs   , sizeof(bmp_export_instance.bmpspecs) );
        new_img_obj.write( (char*) &bmp_export_instance.raw_data.raw_array[0] , bmp_export_instance.raw_data.raw_array.size() );
    }else{
        cout << "ERROR SAVING!\n\n";
        return Signals_app::SAVE_ERROR;
    }

    if(new_img_obj.is_open())
        new_img_obj.close();

    filesystem::path abs_path = filesystem::current_path();
    abs_path /= new_img_pth;

    system(abs_path.string().c_str()); //to open edited image

    //since its declared globally so if uesr loaded new image old data in the instance may cause UB
    clear_imported_struct();

    return Signals_app::APP_OK;
}
