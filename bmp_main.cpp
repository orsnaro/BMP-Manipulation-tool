#include "bmp_main.hpp"

int main() {

    filesystem ::path test_bmp_img = "test_img.bmp";
    ofstream{test_bmp_img};
    cout << test_bmp_img
         << " does exisist ? : " << (exists(test_bmp_img) == 1 ? " YES" : " NO")
         << endl;

    return 0;
}