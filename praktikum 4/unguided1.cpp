#include <iostream>
#include <algorithm>

using namespace std;

bool binarySearch(string sentence, char letter) {
    sort(sentence.begin(), sentence.end()); 
    int left = 0, right = sentence.length() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (tolower(sentence[mid]) == tolower(letter)) { 
            return true;
        } else if (tolower(sentence[mid]) < tolower(letter)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    string sentence;
    char letter;

    cout << "masukkan sebuah kalimat: ";
    getline(cin, sentence);

    cout << "masukkan huruf yang ingin Anda cari: ";
    cin >> letter;

    if (binarySearch(sentence, letter)) {
        cout << "huruf '" << letter << "' ditemukan dalam kalimat" << endl;
    } else {
        cout << "huruf '" << letter << "' tidak ditemukan dalam kalimat" << endl;
    }

    return 0;
}
