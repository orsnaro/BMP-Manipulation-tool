#include <bits/stdc++.h>
using namespace std;
#define sys filesystem 
#define pth sys::path

uint32_t cvt2_ltl_ind_u32(uint32_t before){

    unsigned char bytes[4] = {0,0,0,0};
    uint32_t converted_u32 = 0;

    bytes[0] = (before) & 0xff; //get lower byte
    bytes[1] = (before >> 8) & 0xff;
    bytes[2] = (before >> 16) & 0xff;
    bytes[3] = (before >> 24) & 0xff; //get higher byte

    converted_u32 = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | (bytes[3]); 

    return converted_u32;
};

int main() {

// temp file : TEST ANY SNIPPITS HERE //

// fopen is for 'C' and most of c file i/o is defined in 'stdio.h'
//  ifstream is for 'C++' and defined in 'filesystem' dont forget that 



for ( int i = 0 ; i < 10; i++){

    cout << i;
    continue;
}

uint32_t bfr = 0x11223344;
uint32_t aft =  cvt2_ltl_ind_u32(bfr);
cout << hex << bfr << ' ' << aft;
cout << ' ' << int(aft) ;

// //GET FILE PATH relative and make it abs .
// pth im ;
// pth crnt_dir ;
// crnt_dir = sys::current_path();
// sys::current_path();
// im = "assets/6x6_24bit.bmp";
// cout << im.filename()  << "  " << im.extension() << ' ' \
//      << im.stem() << ' ' << im.relative_path() << ' ' << im.root_path() << ' ' << im.root_name();
// cout <<'\n'<<  (crnt_dir /= im) << ' ' << '\n'  ;
// cout << crnt_dir.is_absolute () << im.is_absolute() << "\n\n";
// system(crnt_dir.string().c_str()); //show


// READ binary save to vector
// reading abs path "crnt_dir" opens actuall photo in imag explorer app
// ifstream from_file(crnt_dir, ios::in | ios::binary); // or use open
// from_file.seekg(0 , from_file.end);
// int file_length = from_file.tellg();
// from_file.seekg(0 ,ios::beg );//or use from_file.beg
// typedef  unsigned char BYTE;
// vector <BYTE> raw(file_length + 10);
// from_file.read(  (char*) &raw[0] , file_length); //cast from unsigned char (uint8_t) to 
// for ( auto & x : raw)
//     cout << hex << int(x) << ' ';
// cout << dec;
// cout <<'\n' <<  raw.size() << endl << endl;
// if(from_file.is_open())
//     from_file.close();

// //CHANGE WORD SIZE
// //refrence  from byte to DWORD(32bit)
// // UINT32 bigvar = (var1 << 24) + (var2 << 16) + (var3 << 8) + var4;
// int cntr = -1;
// uint16_t tst = (raw[++cntr] << 8) + raw[++cntr] ;
// cout <<"\n\n" << hex <<tst;



// //WRITE BINARY FROM VECTOR 
// // edit to make some of it black
//     for ( int i = 67 ; i < 174 ; i++)
//         raw[i] = BYTE(0);
    
// ofstream to_file;
// to_file.open("assets/cpy_6X6_24bit.bmp" , ios::binary | ios::out);

// if( to_file.is_open() && to_file.good()  )
//     to_file.write((char*) &raw[0] , raw.size() );

// if(!to_file.is_open())
//     from_file.close();

return 0;
}