/*

    Written by: Hunter Richardson
    Last updated: February 23rd, 2023

    Brute force attack to the Vignere Cipher, to find a solution you need
    to know the size of the key |k| = 5, the cipher text and plain text pair.

*/

#include <iostream>
#include <string.h>

using namespace std;

string decrypt(int key[5], string cipherText);
void bruteforce(int key[5], int index, string cipherText, string plainText);

int main()
{
    int key[5] = {0, 0, 0, 0, 0};
    string cipherText = "ttsdaioyoxoibsuxvizvsajrxttsygzkrbm";
    string plainText = "thequickbrownfoxjumpsoverthelazydog";

    bruteforce(key, 0, cipherText, plainText);

    return 0;
}


string decrypt(int key[4], string cipherText)
{

    int cipherLength = cipherText.length();
    string plainText = "";

    for (int i = 0; i < cipherLength; i++)
    {

        if (cipherText[i] == 32)
            plainText += cipherText[i];
        else
            plainText += ((cipherText[i] - 97 - key[i % 5] + 26) % 26) + 97;

    }

    return plainText;
}

void bruteforce(int key[5], int index, string cipherText, string plainText)
{
    if (index == 5)
    {
        string candidate = decrypt(key, cipherText);
        if (candidate == plainText)
        {
            cout << "Key | ";
            for (int i = 0; i < 5; i++)
                cout << key[i] << " ";
            cout << "| plaintext: " << candidate << endl;
            return;
        }
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            key[index] = i;
            bruteforce(key, index + 1, cipherText, plainText);
        }
    }
}
