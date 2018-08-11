// Basic unsigned bitfield manipulation
// Has built in option to print output of function call
// Manipulates values by reference

#include <iostream>
#include <bitset>

using namespace std;

const bool OUTPUT = false;
enum BITSIZE { U04 = 4, U08 = 8, U16 = 16, U32 = 32, U64 = 64, U128 = 128, U256 = 256};
const int bit_length = U08;

bool GetBit(int num, int pos);

void SetBit(int& num, int pos);

void ClearBit(int& num, int pos);

void UpdateBit(int& num, int pos, bool val);

// Clears bits from Most Significant Bit to position pos
// IE:  x = 0b11111111; ClearBitsInclusive(x, 4) will return 0b00001111
void ClearBitsInclusive(int& num, int pos);

// Clears bits from position pos to position 0 (least significant bit)
// IE:  x = 0b11111111; ClearBitsExclusive(x, 4) will return 0b11110000
void ClearBitsExclusive(int& num, int pos);