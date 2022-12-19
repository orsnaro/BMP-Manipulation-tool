#include <bits/stdc++.h>
using namespace std;
#define sys filesystem 
#define pth sys::path
int main() {
// temp file : TEST ANY SNIPPITS HERE //


// //GET FILE PATH relative and make it abs .
// pth im ;
// pth crnt_dir ;
// crnt_dir = sys::current_path();
// sys::current_path();
// im = "assets/4X4rgb.bmp";
// cout << im.filename()  << "  " << im.extension() << ' ' \
//      << im.stem() << ' ' << im.relative_path() << ' ' << im.root_path() << ' ' << im.root_name();
// cout <<'\n'<<  (crnt_dir /= im) << ' ' << '\n'  ;
// system(crnt_dir.string().c_str()); //show


// READ binary save to vector
ifstream from_file;
from_file.open("assets/6x6_24bit.bmp", ios::in | ios::binary);
from_file.seekg(0 , from_file.end);
int file_length = from_file.tellg();
from_file.seekg(0 ,from_file.beg );
typedef  unsigned char BYTE;
vector <BYTE> raw(file_length);
from_file.read(  (char*) &raw[0] , file_length); //cast from unsigned char (uint8_t) to 
for ( auto & x : raw)
    cout << hex << int(x) << ' ';
cout << dec;
cout <<'\n' <<  raw.size() << endl << endl;

//WRITE BINARY FROM VECTOR 
// edit to make some of it black
    for ( int i = 67 ; i < 174 ; i++)
        raw[i] = BYTE(0);
    
ofstream to_file;
to_file.open("assets/cpy_6X6_24bit.bmp" , ios::binary | ios::out);

if( to_file.is_open() && to_file.good()  )
    to_file.write((char*) &raw[0] , raw.size() );

if(!to_file.is_open())
    from_file.close();

return 0;
}