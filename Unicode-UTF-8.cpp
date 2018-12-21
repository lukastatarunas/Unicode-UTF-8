#include <iostream>
#include <fstream>
#include <string>

struct UnicodeConverter
{
	int getByteCount(int input);
	std::string convertToHexadecimal(int input);
	std::string getEncodedValue(int input);
	std::string convertFromCodePage427(unsigned char character);
};

int main()
{
	int input;

	UnicodeConverter object;

	std::cout << "Enter any integer that will be converted to UTF-8 encoding:" << std::endl;
	std::cin >> input;

	std::cout << "U+" << object.convertToHexadecimal(input) << std::endl;
	std::cout << "UTF-8: " << object.getEncodedValue(input) << std::endl;

	std::basic_ifstream<unsigned char> fin("386intel.txt");
	std::ofstream fout("result.txt");

	unsigned char character;

	while (fin)
	{
		fin.get(character);

		if (character < 128)
		{
			fout << character;
		}

		else
		{
			fout << object.convertFromCodePage427(character);
		}
	}

	fin.close();
	fout.close();
}

int UnicodeConverter::getByteCount(int input)
{
	if (input < 128)
		return 1;
	if (input < 2048)
		return 2;
	if (input < 65536)
		return 3;
	if (input < 1114112)
		return 4;
}

std::string UnicodeConverter::convertToHexadecimal(int input)
{
	char hexadecimalValue[33];

	_itoa_s(input, hexadecimalValue, 16);

	return std::string(hexadecimalValue);
}

std::string UnicodeConverter::getEncodedValue(int input)
{
	std::string encodedValue;

	int byteCount = getByteCount(input);

	if (byteCount == 1)
	{
		return convertToHexadecimal(input);
	}

	char buffer[33];

	_itoa_s(input, buffer, 2);

	std::string binaryValue = buffer;

	while (binaryValue.length() < 11 + (5 * (byteCount - 2)))
	{
		binaryValue.insert(binaryValue.begin(), '0');
	}

	binaryValue.insert(binaryValue.begin(), '0');

	for (int i = 0; i < byteCount; i++)
	{
		binaryValue.insert(binaryValue.begin(), '1');
	}

	for (int i = 1; i <= byteCount--; i++)
	{
		binaryValue.insert(binaryValue.begin() + (i * 8), '0');
		binaryValue.insert(binaryValue.begin() + (i * 8), '1');
	}

	input = stoi(binaryValue, nullptr, 2);

	return convertToHexadecimal(input);
}

std::string UnicodeConverter::convertFromCodePage427(unsigned char character)
{
	if (character < 128) return std::string(1, character);
	if (character == 128) return u8"\u00C7";
	if (character == 129) return u8"\u00FC";
	if (character == 130) return u8"\u00E9";
	if (character == 131) return u8"\u00E2";
	if (character == 132) return u8"\u00E4";
	if (character == 133) return u8"\u00E0";
	if (character == 134) return u8"\u00E5";
	if (character == 135) return u8"\u00E7";
	if (character == 136) return u8"\u00EA";
	if (character == 137) return u8"\u00EB";
	if (character == 138) return u8"\u00E8";
	if (character == 139) return u8"\u00EF";
	if (character == 140) return u8"\u00EE";
	if (character == 141) return u8"\u00EC";
	if (character == 142) return u8"\u00C4";
	if (character == 143) return u8"\u00C5";
	if (character == 144) return u8"\u00C9";
	if (character == 145) return u8"\u00E6";
	if (character == 146) return u8"\u00C6";
	if (character == 147) return u8"\u00F4";
	if (character == 148) return u8"\u00F6";
	if (character == 149) return u8"\u00F2";
	if (character == 150) return u8"\u00FB";
	if (character == 151) return u8"\u00F9";
	if (character == 152) return u8"\u00FF";
	if (character == 153) return u8"\u00D6";
	if (character == 154) return u8"\u00DC";
	if (character == 155) return u8"\u00A2";
	if (character == 156) return u8"\u00A3";
	if (character == 157) return u8"\u00A5";
	if (character == 158) return u8"\u20A7";
	if (character == 159) return u8"\u0192";
	if (character == 160) return u8"\u00E1";
	if (character == 161) return u8"\u00ED";
	if (character == 162) return u8"\u00F3";
	if (character == 163) return u8"\u00FA";
	if (character == 164) return u8"\u00F1";
	if (character == 165) return u8"\u00D1";
	if (character == 166) return u8"\u00AA";
	if (character == 167) return u8"\u00BA";
	if (character == 168) return u8"\u00BF";
	if (character == 169) return u8"\u2310";
	if (character == 170) return u8"\u00AC";
	if (character == 171) return u8"\u00BD";
	if (character == 172) return u8"\u00BC";
	if (character == 173) return u8"\u00A1";
	if (character == 174) return u8"\u00AB";
	if (character == 175) return u8"\u00BB";
	if (character == 176) return u8"\u2591";
	if (character == 177) return u8"\u2592";
	if (character == 178) return u8"\u2593";
	if (character == 179) return u8"\u2502";
	if (character == 180) return u8"\u2524";
	if (character == 181) return u8"\u2561";
	if (character == 182) return u8"\u2562";
	if (character == 183) return u8"\u2556";
	if (character == 184) return u8"\u2555";
	if (character == 185) return u8"\u2563";
	if (character == 186) return u8"\u2551";
	if (character == 187) return u8"\u2557";
	if (character == 188) return u8"\u255D";
	if (character == 189) return u8"\u255C";
	if (character == 190) return u8"\u255B";
	if (character == 191) return u8"\u2510";
	if (character == 192) return u8"\u2514";
	if (character == 193) return u8"\u2534";
	if (character == 194) return u8"\u252C";
	if (character == 195) return u8"\u251C";
	if (character == 196) return u8"\u2500";
	if (character == 197) return u8"\u253C";
	if (character == 198) return u8"\u255E";
	if (character == 199) return u8"\u255F";
	if (character == 200) return u8"\u255A";
	if (character == 201) return u8"\u2554";
	if (character == 202) return u8"\u2569";
	if (character == 203) return u8"\u2566";
	if (character == 204) return u8"\u2560";
	if (character == 205) return u8"\u2550";
	if (character == 206) return u8"\u256C";
	if (character == 207) return u8"\u2567";
	if (character == 208) return u8"\u2568";
	if (character == 209) return u8"\u2564";
	if (character == 210) return u8"\u2565";
	if (character == 211) return u8"\u2559";
	if (character == 212) return u8"\u2558";
	if (character == 213) return u8"\u2552";
	if (character == 214) return u8"\u2553";
	if (character == 215) return u8"\u256B";
	if (character == 216) return u8"\u256A";
	if (character == 217) return u8"\u2518";
	if (character == 218) return u8"\u250C";
	if (character == 219) return u8"\u2588";
	if (character == 220) return u8"\u2584";
	if (character == 221) return u8"\u258C";
	if (character == 222) return u8"\u2590";
	if (character == 223) return u8"\u2580";
	if (character == 224) return u8"\u03B1";
	if (character == 225) return u8"\u00DF";
	if (character == 226) return u8"\u0393";
	if (character == 227) return u8"\u03C0";
	if (character == 228) return u8"\u03A3";
	if (character == 229) return u8"\u03C3";
	if (character == 230) return u8"\u00B5";
	if (character == 231) return u8"\u03C4";
	if (character == 232) return u8"\u03A6";
	if (character == 233) return u8"\u0398";
	if (character == 234) return u8"\u03A9";
	if (character == 235) return u8"\u03B4";
	if (character == 236) return u8"\u221E";
	if (character == 237) return u8"\u03C6";
	if (character == 238) return u8"\u03B5";
	if (character == 239) return u8"\u2229";
	if (character == 240) return u8"\u2261";
	if (character == 241) return u8"\u00B1";
	if (character == 242) return u8"\u2265";
	if (character == 243) return u8"\u2264";
	if (character == 244) return u8"\u2320";
	if (character == 245) return u8"\u2321";
	if (character == 246) return u8"\u00F7";
	if (character == 247) return u8"\u2248";
	if (character == 248) return u8"\u00B0";
	if (character == 249) return u8"\u2219";
	if (character == 250) return u8"\u00B7";
	if (character == 251) return u8"\u221A";
	if (character == 252) return u8"\u207F";
	if (character == 253) return u8"\u00B2";
	if (character == 254) return u8"\u25A0";
	if (character == 255) return u8"\u00A0";
}
