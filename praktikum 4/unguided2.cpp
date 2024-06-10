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
