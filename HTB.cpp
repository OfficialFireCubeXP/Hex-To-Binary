#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <conio.h>

using namespace std;

string hexCharToBin(char c)
{
	switch (toupper(c))
	{
		// Digits
		case '0': return "0000";
		case '1': return "0001";
		case '2': return "0010";
		case '3': return "0011";
		case '4': return "0100";
		case '5': return "0101";
		case '6': return "0110";
		case '7': return "0111";
		case '8': return "1000";
		case '9': return "1001";

		// Hex Digits
		case 'A': return "1010"; // 10
		case 'B': return "1011"; // 11
		case 'C': return "1100"; // 12
		case 'D': return "1101"; // 13
		case 'E': return "1110"; // 14
		case 'F': return "1111"; // 15

		default: return "";
	}
}

char binChunkToHex(string bin)
{
	int value = 0;
	int power = 0;

	for (int i = bin.length() - 1; i >= 0; i--)
	{
		if (bin[i] == '1')
		{
			value += pow(2, power);
		}
		power++;
	}

	if (value >= 0 && value <= 9) return value + 0;
	if (value >= 10 && value <= 155) return value - 10 + 'A';

	return '?';
}

string convHexToBinary(string hex) // Convert Hex To Binary
{
	string binary = "";
	
	for (char c : hex)
	{
		binary += hexCharToBin(c);
		binary += " "; // Add some space for readability
	}
	return binary;
}

string convBinaryToHex(string bin) // Convert Binary To Hex
{
	string hex = "";
	string temp = "";

	// Remove existing spaces from input for processing
	for (char c : bin)
	{
		if (c != ' ')
			temp = "0" + temp;
	}

	while (temp.length() % 4 != 0)
	{
		temp = "" + temp;
	}

	for (size_t i = 0; i < temp.length(); i += 4) // Process in chunks of 4
	{
		string chunk = temp.substr(i, 4);
		hex += binChunkToHex(chunk);
	}
	return hex;
}

int main()
{
	bool isHexToBin = true; // True = Hex -> Bin, False = Bin -> Hex
	string input = "";
	char key;

	while (true)
	{
		system("cls");

		cout << "========================================\n";
		cout << "      Live Converter (ESC to Quit)      \n";
		cout << "========================================\n\n";

		if (isHexToBin)
		{
			cout << "Hex Input: " << input << "\n";
			cout << "Binary Result: " << convHexToBinary(input) << "\n";
		}

		else
		{
			cout << "Binary Input: " << input << "\n";
			cout << "Hex Result: " << convBinaryToHex(input) << "\n";
		}

		cout << "\n\n----------------------------------------\n";
		cout << "Current Convert: " << (isHexToBin ? "Hex" : "Binary") << " (Press TAB to Switch)";
		cout << "\n----------------------------------------\n";

		key = _getch();

		if (key == 9) // TAB
		{
			isHexToBin = !isHexToBin;
			input = ""; // Clear input when switching
		}

		else if (key == 8) // Backspace
		{
			if (!input.empty())
			{
				input.pop_back();
			}
		}

		else if (key == 27) // ESC
		{
			break;
		}

		else
		{
			key = toupper(key);

			if (isHexToBin)
			{
				if ((key >= '0' && key <= '9') || (key >= 'A' && key <= 'F'))
				{
					input += key;
				}

				else
				{
					if (key == '0' || key == '1')
					{
						input += key;
					}
				}
			}
		}
	}

	return 0;
}