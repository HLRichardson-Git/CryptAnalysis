#pragma once

class DES
{
public:

	static std::string decimalToBinary(int decimal);
	static int binaryToDecimal(std::string binary);
	static std::string Xor(std::string a, std::string b);

	static std::string algorithm(bool isEncryption, std::string block, std::string keyRounds[16]);

};
