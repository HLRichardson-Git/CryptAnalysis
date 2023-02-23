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

int main()
{
    
    // Debug set SHOW to true to show all rounds till solution
    bool show = false;

    // Key is among or 0 12 14 13 6 shifts repeated
    int key[5] = {0,0,0,0,0};
    string cipherText = "ttsdaioyoxoibsuxvizvsajrxttsygzkrbm";
    string candidate = "";
    string plainText = "thequickbrownfoxjumpsoverthelazydog";
    int count = 0;

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                for(int l = 0; l < 26; l++)
                {
                    for(int n = 0; n < 26; n++)
                    {
                        key[0] = i;
                        key[1] = j;
                        key[2] = k;
                        key[3] = l;
                        key[4] = n;

                        candidate = decrypt(key, cipherText);

                        if(show)
                            cout << count << " | Key: " << key[0] << " " << key[1] << " " << key[2] << " " << key[3] << " " << key[4] << " | plaintext: " << candidate << endl;

                        if(plainText.compare(candidate) == 0)
                        {   
                            if (!show)
                                cout << count << " | Key: " << key[0] << " " << key[1] << " " << key[2] << " " << key[3] << " " << key[4] << " | plaintext: " << candidate << endl;

                            system("pause");
                        }

                        count++;
                    }
                }
            }   
        }
    }


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
