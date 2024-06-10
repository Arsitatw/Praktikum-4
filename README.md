# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>
<p align="center">Arsita Wiwit Tiyaswening</p>
<p align="center">2311110028</p>

## Dasar Teori
Algoritma searching adalah prosedur atau metode yang digunakan untuk menemukan lokasi dari suatu elemen dalam struktur data. Elemen yang dicari dapat berupa angka, string, atau objek lain yang tersimpan dalam array, daftar, atau struktur data lainnya. Algoritma searching berperan penting dalam bidang ilmu komputer karena memungkinkan akses cepat dan efisien terhadap data yang diperlukan. Algoritma searching dapat dibagi menjadi dua yaitu :
### 1. Linear Search 
Linear Search adalah metode pencarian sederhana di mana pencarian dilakukan dengan memeriksa setiap elemen dalam struktur data satu per satu hingga elemen yang dicari ditemukan atau seluruh elemen telah diperiksa.
### 2. Binary Search
Binary Search adalah metode pencarian yang efisien, digunakan pada array yang sudah terurut. Algoritma ini bekerja dengan cara membagi dua interval pencarian pada setiap langkah, yang secara signifikan mengurangi jumlah elemen yang perlu diperiksa.
Pemilihan algoritma searching bergantung pada jenis dan ukuran data serta kebutuhan efisiensi dari aplikasi yang digunakan. Linear Search mungkin lebih tepat untuk dataset kecil atau tidak terurut, sedangkan Binary Search lebih sesuai untuk dataset besar yang sudah terurut.

## Guided
### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.
``` C++
#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    cout << "\t Program Sequential Search Sederhana\n" << endl;
    cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    
    if (ketemu) {
        cout << "\n angka " << cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }

    return 0;
}
```
### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search
```C++
#include <iostream>
#include <iomanip>

using namespace std;

int bil_data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(bil_data[j] < bil_data[min]) {
                min = j;
            }
        }
        temp = bil_data[i];
        bil_data[i] = bil_data[min];
        bil_data[min] = temp;
    }
}

void binary_search() {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(bil_data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(bil_data[tengah] < cari) {
            awal = tengah + 1;
        } else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\nData ditemukan pada index ke-" << tengah << endl;
    } else {
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {
    cout << "\tBINARY SEARCH\n";
    cout << "\nData: ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;
    cout << "\nData diurutkan: ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++) {
        cout << setw(3) << bil_data[x];
    }
    cout << endl;
    binary_search();
    return 0;
}
```
## Unguided
### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!
```C++
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
```
#### Output

#### Penjelasan
Program ini meminta pengguna untuk memasukkan sebuah kalimat dan sebuah huruf yang ingin dicari. Algoritma binary search digunakan untuk mencari huruf tersebut setelah kalimat diurutkan secara alfabetis. Fungsi binarySearch mengurutkan kalimat, kemudian melakukan pencarian biner yang membandingkan setiap elemen tengah dengan huruf yang dicari, mengabaikan perbedaan besar kecil huruf. Hasil pencarian dikembalikan sebagai true jika huruf ditemukan, atau false jika tidak ditemukan. Program kemudian menampilkan hasil pencarian kepada pengguna, menyatakan apakah huruf yang dicari ada dalam kalimat atau tidak.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!
```C++
#include <iostream>
#include <string>

using namespace std;

int countVowels(string sentence) {
    int count = 0;
    for (char ch : sentence) {
        char lowercaseCh = tolower(ch);
        if (lowercaseCh == 'a' || lowercaseCh == 'e' || lowercaseCh == 'i' || lowercaseCh == 'o' || lowercaseCh == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    string sentence;

    cout << "masukkan sebuah kalimat: ";
    getline(cin, sentence);
    int vowelCount = countVowels(sentence);

    cout << "jumlah huruf vokal dalam kalimat adalah: " << vowelCount << endl;

    return 0;
}
```
#### Output

#### Penjelasan 
Program ini meminta pengguna untuk memasukkan sebuah kalimat dan kemudian menghitung jumlah huruf vokal dalam kalimat tersebut. Fungsi countVowels digunakan untuk menghitung vokal dengan mengubah setiap karakter menjadi huruf kecil dan memeriksa apakah karakter tersebut adalah salah satu dari 'a', 'e', 'i', 'o', atau 'u'. Program kemudian menampilkan jumlah huruf vokal yang ditemukan. Penggunaan tolower memastikan perhitungan tidak terpengaruh oleh perbedaan besar kecil huruf. Hasil akhirnya adalah jumlah total vokal yang ditampilkan kepada pengguna.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!
```C++
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
```
#### Output

#### Penejelasan 
Program ini dimulai dengan menyertakan pustaka iostream untuk menggunakan fungsi-fungsi input/output standar. Selanjutnya, program menggunakan namespace std untuk menghindari penulisan berulang pada fungsi-fungsi standar dari C++. Di dalam fungsi main(), terdapat inisialisasi array data yang berisi sejumlah bilangan bulat dan sebuah variabel target yang menyimpan nilai yang ingin dicari dalam array tersebut, dalam hal ini angka 4. Selain itu, ada juga variabel count yang akan digunakan untuk menghitung jumlah kemunculan angka target. Selanjutnya, program menggunakan loop for untuk mengiterasi melalui setiap elemen dalam array data. Pada setiap iterasi, program memeriksa apakah nilai pada indeks tersebut sama dengan nilai target. Jika ya, maka variabel count akan bertambah satu. Setelah loop selesai dieksekusi, program mencetak jumlah kemunculan angka target dalam array dengan menggunakan fungsi cout. Akhirnya, program mengembalikan nilai 0 untuk menandakan bahwa program telah berjalan dengan sukses dan kemudian berakhir.
