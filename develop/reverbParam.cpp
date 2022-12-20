#include <iostream>
using namespace std;

int main() {
    while (true) {
        int frame = 0;
        cin >> frame;
        cout << "frame: " << frame << endl;
        cout << "ms: " << (double)frame / 44100 * 1000 << endl;
    }
}