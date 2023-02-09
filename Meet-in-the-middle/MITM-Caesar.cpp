/*
TODO:
    1) write decrytption for caesar
    2) write function to check class for encrypted strings for match in e and e^-1
    3) Not necessary but sort class by string so search is faster
*/

#include <iostream>
#include <string>

#include <bits/stdc++.h>

using namespace std;

string caesarCipher(string plainText, int key);

class Table {
        string cipherText;
        int key_l;
    public:
        void putEntry(string plainText, int key);
        void getEntry();
};

int main()
{
    
    Table table[26];

    string knownPlainText = "Hello World";
    int key1 = 4; int key2 = 13;

    string cipherText = caesarCipher(knownPlainText, key1);
    cout << cipherText << endl;

    cipherText = caesarCipher(cipherText, key2);
    cout << cipherText << endl;

    for(int i = 0; i < 26; i++)
    {
        table[i].putEntry(knownPlainText, i);
    }

    for(int i = 0; i < 26; i++)
    {   
        cout << i << ": ";
        table[i].getEntry();
    }

    return 0;
}

string caesarCipher(string plainText, int key)
{

    string result = "";
 
    for (int i = 0; i < plainText.length(); i++) {

        if (plainText[i] == 32)
            result += char(plainText[i]);
        else if (isupper(plainText[i]))
            result += char(int(plainText[i] + key - 65) % 26 + 65);
        else
            result += char(int(plainText[i] + key - 97) % 26 + 97);
    }

    return result;

}

void Table::putEntry(string plainText, int key)
{

    cipherText = caesarCipher(plainText, key);
    key_l = key;

}

void Table::getEntry()
{

    cout << cipherText << endl;

}
