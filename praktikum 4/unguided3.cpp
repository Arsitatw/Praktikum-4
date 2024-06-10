#include <iostream>

using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int target = 4; 
    int count = 0; 

    for (int i = 0; i < 10; i++) {
        if (data[i] == target) {
            count++;
        }
    }

    cout << "jumlah kemunculan angka 4 dalam data adalah: " << count << endl;

    return 0;
}
