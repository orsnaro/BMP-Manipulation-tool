/************************************************************************************************************
*                         		 d(Programmer): Omar Rashad salem                                     		*             
*                                  		Date: 23/12/2022                                                    *    
*            info:                                                                                          *      
*                    this is the static chroma .bmp Images project  console version (SCBMP.exe)             *
*            version :                                                                                      *
*                    Beta_console_1.5                                                                  *
*            type :                                                                                         *
*                    college solo project for 3rd year CS engineering at ksu  -> Multimedia/dr.Heba course  *
*                                 																			*
*                           	   ~All Rights Reserved 2022/2023 ©~										*
*************************************************************************************************************/
#include "main.h"
int main() {
    bool done = false;
    while(! done) done = bool(app_start());
    return 0;
}
//TODO : seperate implementation to a ".cpp" file and leave the declarations in ".hpp"
//TODO : for error handling all functions must return at least pair <T,T>  => func normal return , state signal 
//TODO : test seperatly  the background detection code on very abstract object then amp it up ( try 3 models abstract / mincraft / real photo )
//TODO : make the program flow chart ( signals between functions)
//TODO : REFACTOR REFACTOR REFACTOR , OPTIMIZE OPTIMIZE OPTIMIZE!
//TODO : check how system extends your unsigned data (it deals with most data in 2's complement thus it might extend unsigned with ones assuming it's a 2's complement -ve number which leads to UB)
//TODO : replace bits/stdc++.g library in main.h file for protability reaasons . ( some compilers and C++ versions doesnt have it)