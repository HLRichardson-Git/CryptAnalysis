#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int main()
{
    int numKeys = 5000000; // number of keys to generate
    const int keySize = 16; // 128 bits = 16 bytes
    unsigned char key[keySize]; // buffer to hold key data
    auto start = high_resolution_clock::now(); // start timer

    // generate keys
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 255);
    for (int i = 0; i < numKeys; i++)
    {
        for (int j = 0; j < keySize; j++)
        {
            key[j] = dis(gen);
        }
    }

    auto stop = high_resolution_clock::now(); // stop timer
    auto duration = duration_cast<milliseconds>(stop - start); // calculate duration in milliseconds
    cout << "Generated " << numKeys << " 128-bit keys in " << duration.count() << " milliseconds." << endl;
    return 0;
}
