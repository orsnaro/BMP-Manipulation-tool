//this is file path : C:\Users\OmarPc\repo_CHROMA_BMP_proj\testing
#include <bits/stdc++.h>
// #include <iostream> 
// #include <filesystem>
// #include <fstream>
using namespace std;

// seekp() is equivalant to seekg() move pointer to specific location in file
// tellg() is equivalant to tellp() requie current pointer location.
// get location is diff than tellp() pointer
int main() {
    filesystem ::path path;
    ofstream toFile;   // if file does not exist it makes new file!!
    ifstream fromFile; // if file does not exist it makes new file!!

    cout << ">> Please enter  your '.bmp' Image path ( dont forget '.bmp' !) :"
         << endl;
    cin >> path;

    bool fileExist = filesystem ::exists(path);

    if (!fileExist) {

        cout << ">>there is no image in this name  : \'" << path << "\'" << endl
             << ">>would you like to make new file with name: " << path << '?'
             << endl;
        cout << ">>print 'y' for yes and 'n' for no" << endl;
        char respond;
        cin >> respond;

        if (respond == 'y' or respond == 'Y')
            ofstream newFile(path, ios ::out | ios ::binary);
    }

    while (!fileExist) {
        cerr << ">>ERROR FINDING IMAGE!! " << endl
             << ">>please re-enter image path!:" << endl;
        cin >> path;
        fileExist = filesystem ::exists(path);
    }
    toFile.open(
        path, ios ::binary |
                  ios ::out); // if file not exist it creates it (re search it)

    cout << ">>Image : "  << path  << " is found!" << endl
         << ">>begin Importing data proccess ..." << endl;
    int x = 0xffffffff;
    // long long int *ptr = &x;

    toFile.write((char *)&x, sizeof(x));
    
    if(!toFile.fail())
        cout << "written value: \'" << hex << x << "\' successfully to " << path << endl;
    else 
        cout << "ERROR WRITING TO YOUR IMAGE TERMINATING..";
        
    if (fromFile.is_open())
        fromFile.close();
    if (toFile.is_open())
        toFile.close();
    return 0;
}

//continue from here
 /*

https://www.geeksforgeeks.org/file-handling-c-classes/


https://engineering.purdue.edu/ece264/17au/hw/HW15


https://upload.wikimedia.org/wikipedia/commons/7/75/BMPfileFormat.svg

https://en.wikipedia.org/wiki/List_of_file_signatures
https://www.geeksforgeeks.org/read-a-record-from-a-file-in-c-using-seekg-and-tellg/ 

*/