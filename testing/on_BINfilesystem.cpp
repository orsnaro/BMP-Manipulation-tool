#include <bits/stdc++.h>
using namespace std;


int main (){
    ofstream toFile;
    ifstream fromFile;
    string path = {};
    cout << ">> Please enter you '.bmp' Image path ( dont forget '.bmp' !) :" << endl;
    cin >> path ;

    
    fromFile.open(path, ios::binary | ios::in);
    while(fromFile.fail()){
        cerr << "ERROR FINDING IMAGE!! " << endl <<  "please re-enter image path!:" << endl;
        cin >> path;
    } 
    cout << "Image" << path << " is found!" <<endl 
    <<"begin Importing data proccess ..."<< endl;

    toFile.write()

    if ( fromFile.is_open() ) fromFile.close();
    if (toFile.is_open()) toFile.close();
    return 0 ;
}
