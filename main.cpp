#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string caesar_encode(const string & message, int shift_value) {
    string cipher;

    for(int i = 0; i < message.length(); i++) {
        char character = message[i];
        if(isalpha(character)) {
            char base = islower(character) ? 'a' : 'A';
            char shifted = ((character - base + shift_value) % 26) + base;
            cipher += shifted;
        } else {
            cipher += character;
        }
    }

    return cipher;
}

string caesar_decode(const string & encr, int shift_value) {
    string dec;

    for(int i = 0; i < encr.length(); i++) {
        char character = encr[i];
        if(isalpha(character)) {
            char base = islower(character) ? 'a' : 'A';
            char shifted = ((character - base - shift_value + 26) % 26) + base;
            dec += shifted;
        } else {
            dec += character;
        }
    }

    return dec;
}

void encrypt_file(const string & input_filename, const string & output_filename, int shift_value) {
    ifstream in_file(input_filename);
    ofstream out_file(output_filename);

    if(!in_file) {
        cerr << "Error opening the file for encryption !! " << endl;
        return;
    }

    string line;
    while(getline(in_file, line)) {
        string ecrypted_line = caesar_encode(line, shift_value);
        out_file << ecrypted_line << endl;
    }

    in_file.close();
    out_file.close();
    cout << "File Ecrypted Successfully !! " << endl;
}

void decrypt_file(const string & input_filename, const string & output_filename, int shift_value) {
    ifstream in_file(input_filename);
    ofstream out_file(output_filename);

    if(!in_file) {
        cerr << "Unable to open file for decryption !" << endl;
        return;
    }

    string line;
    while(getline(in_file, line)) {
        string decrypted_line = caesar_decode(line, shift_value);
        out_file << decrypted_line << endl;
    }

    in_file.close();
    out_file.close();

    cout << "File decrypted successfully !! " << endl;
}

int main() {
    int shift_value;
    string input_filename, output_filename;

    cout << "Enter the input file name : ";
    cin >> input_filename;
    cout << "Enter the output file name : ";
    cin >> output_filename;
    cout << "Enter the encrypt value by which you want to encrypt/decrypt : ";
    cin >> shift_value;

    // For encryption
    // encrypt_file(input_filename, output_filename, shift_value);

    // For decryption
    decrypt_file(input_filename, output_filename, shift_value);

}