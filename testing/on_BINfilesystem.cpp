#include <bits/stdc++.h>
#include <filesystem>
using namespace std;

// seekp() is equivalant to seekg()
// tellg() is equivalant to tellp()
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
