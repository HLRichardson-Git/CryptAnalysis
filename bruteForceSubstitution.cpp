
#include <iostream>
#include <string>

using namespace std;

//void iterateKey(string key, string alphabet, int i);
string createCipherAlphabet(string key, string alphabet, string cipherAlphabet);
string substitutionDecrypt(string cipherText, string cipherAlphabet, string alphabet);

int main()
{

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    cout << "Enter the cipher text: ";
    string cipherText = "";
    getline(cin, cipherText);

    string key = "";
    string cipherAlphabet = "";
    string plainText = "";

    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            key = "";
            cipherAlphabet = "";
            plainText = "";

            if (i != j)
            {
                key = key + char(alphabet[i]) + char(alphabet[j]);
                cout << key << endl;
                cipherAlphabet = createCipherAlphabet(key, alphabet, cipherAlphabet);
                plainText = substitutionDecrypt(cipherText, cipherAlphabet, alphabet);
                count++;
                cout << "Key: " << cipherAlphabet << " Decrypted: " << plainText << " Count: " << count << endl;
            }
            //cout << char(alphabet[i]) << char(alphabet[j]) << endl;
        }

    }

}

string createCipherAlphabet(string key, string alphabet, string cipherAlphabet)
{
    int keyLength = key.length();
    bool check = false;

    cipherAlphabet += key;

    for (int i = 0; i < 26; i++)
    {
        check = false;
        for (int j = 0; j < keyLength; j++)
        {
            if (key[j] == alphabet[i])
            {
                check = true;
            }
        }
        if (!check)
            cipherAlphabet += char(alphabet[i]);
    }

    return cipherAlphabet;
}

string substitutionDecrypt(string cipherText, string cipherAlphabet, string alphabet)
{
    int cipherLength = cipherText.length();
    string plainText = "";

    for (int i = 0; i < cipherLength; i++)
    {
        //plainText += char(cipherAlphabet[int(cipherText[i]) - 97]);
        for (int j = 0; j < 26; j++)
        {

            if (char(cipherText[i]) == char(cipherAlphabet[j]))
            {
                plainText += char(alphabet[j]);
                break;
            }

        }
    }
    return plainText;
}
