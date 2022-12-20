/************************************************************************************************************
*                         		 d(Programmer): Omar Rashad salem                                     		*             
*                                  		Date: 18/12/2022                                                    *    
*            info:                                                                                          *      
*                    this is the static chroma .bmp Images project  console version (SCBMP.exe)             *
*            version :                                                                                      *
*                    pre_alpha_console_0.5                                                                  *
*            type :                                                                                         *
*                    college solo project for 3rd year CS engineering at ksu  -> Multimedia/dr.Heba course  *
*                                 																			*
*                           	   ~All Rights Reserved 2022/2023 ©~										*
*************************************************************************************************************/
#include "main.hpp"
int main() {

    bool not_done = 1;
    while(not_done){
        not_done = bool(app_start());
    }

    return 0;
}
//TODO : seperate implementation to a ".cpp" file and leave the declarations in ".hpp"
//TODO : for error handling all functions must return at least pair <T,T>  => func normal return , state signal 
//TODO : see whats exactly sets photo dimensions ( the header or actual pixels matrix )
//TODO : try read and write from actual photo and see how it behaves with classes
//TODO : check manually your whitsh range on pics in test channel on telegram and in file
//TODO : test seperatly  the background detection code on versy abstract object then amp it up ( try 3 models abstract / mincraft / real photo )
//TODO : REFACTOR REFACTOR REFACTOR , OPTIMIZE OPTIMIZE OPTIMIZE!