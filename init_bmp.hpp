#pragma once 
#include <bits/stdc++.h>
#include <sys

//load image  , do checks funcs , resize , cvrt to gray scale
//TODO : init linikng to gui here ( my 1st cpp gui ever <3 )

typedef short int state_t;

enum class Signals : state_t {
    ACCEPTED_FILE_TYPE,INVALID_FILE_TYPE,
    VALID_OFFSET , INVALID_OFFSET,
    VALID_DIB_SZ ,INVALID_DIB_SZ,

    IMAGES_SIZE_BAD , IMAGES_SIZE_OK
    
};
