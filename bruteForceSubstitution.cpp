#include <iostream>
#include <string>

using namespace std;

string createCipherAlphabet(string key, string alphabet, string cipherAlphabet);
string substitutionDecrypt(string cipherText, string cipherAlphabet, string alphabet);

int main()
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string cipherText = "tdaqueogirmwkbmxfujpsmvartdahlzynmc";

    string key = "";
    string cipherAlphabet = "";
    string plainText = "";

    int count = 0;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                for (int l = 0; l < 26; l++)
                {
                    key = "";
                    cipherAlphabet = "";
                    plainText = "";

                    if (i != j && i != k && i != l && j != k && j != l && k != l)
                    {
                        key = key + char(alphabet[i]) + char(alphabet[j]) + char(alphabet[k]) + char(alphabet[l]);
                        cipherAlphabet = createCipherAlphabet(key, alphabet, cipherAlphabet);
                        plainText = substitutionDecrypt(cipherText, cipherAlphabet, alphabet);
                        count++;
                        if (plainText == "thequickbrownfoxjumpsoverthelazydog")
                        {
                            cout << "Key        | " << key << endl;
                            cout << "Alphabet   | " << cipherAlphabet << endl;
                            cout << "Decrypted  | " << plainText << endl;
                            cout << "Count      | " << count << endl;
                        }
                    }
                }
            }
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
