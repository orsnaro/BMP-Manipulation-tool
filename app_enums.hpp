#pragma once
#include <iostream>
typedef short int state_t;

          // --------------- ENUMS SECTION ----------------

enum class Signals_BMPstruct : state_t {
    
    //all valid states = 0 
    OK_FILE_TYPE, 
    VALID_OFFSET  = 0, 
    VALID_DIB_SZ = 0, 
    OK_IMAGES_SIZE = 0,
    VALID_COMPRESSION = 0, 
    VALID_BIT_DEPTH = 0 ,
    VALID_PADDING = 0, 

    //all invalid states != 0 and unique 
    INVALID_FILE_TYPE,
    INVALID_OFFSET,
    INVALID_DIB_SZ,
    BAD_IMAGES_SIZE,
    INVALID_COMPRESSION,
    INVALID_BIT_DEPTH,
    INVALID_PADDING //if read wrong or paddings  not 0x00 valued
}signals_bmpstruct;

enum class Signals_app : state_t {
    //all valid states = 0
    APP_OK = 0,
    LOAD_OK= 0,
    SAVE_OK= 0,
    RELOAD_APP = 0,


    // all invalid states != 0 and unique
    QUIT = 1,
    APP_ERROR,
    BAD_LOAD, 
    SAVE_ERROR

}signals_app;

