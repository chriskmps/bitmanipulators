// Basic unsigned bitfield manipulation
// Has built in option to print output of function call
// Manipulates values by reference

#include <iostream>
#include <bitset>
#include "bitmanipulators.h"

using namespace std;

bool GetBit(int num, int pos) {
	if(OUTPUT) 
		cout << "GetBit = Bit[" << pos << "]: " << (num & (1 << pos)) << endl;
	return num & (1 << pos);
}

void SetBit(int& num, int pos) {
	if(OUTPUT) {
		int out = num;
		out = (out | (1 << pos)) ;
		std::bitset<bit_length> bitfield(out);
		cout << "SetBit = Bit[" << pos << "]: " << bitfield << endl;
	}
	num = num | (1 << pos);
}

void ClearBit(int& num, int pos) {
	if(OUTPUT) {
		int out = num;
		out = out & (~(1 << pos));
		std::bitset<bit_length> bitfield(out);
		cout << "SetBit = Bit[" << pos << "]: " << bitfield << endl;
	}
	num = num & (~(1 << pos));
}

void UpdateBit(int& num, int pos, bool val) {
	int mask = ~(1 << pos);
	if(OUTPUT) {
		int out = num;
		out = (out & mask) | (val << pos);
		std::bitset<bit_length> bitfield(out);
		cout << "SetBit = Bit[" << pos << "]: " << bitfield << endl;
	}
	num = (num & mask) | (val << pos);
}

// Clears bits from Most Significant Bit to position pos
// IE:  x = 0b11111111; ClearBitsInclusive(x, 4) will return 0b00001111
void ClearBitsInclusive(int& num, int pos) {
	int mask = (1 << pos) - 1;
	if(OUTPUT) {
		int out = num;
		out = out & mask;
		std::bitset<bit_length> bitfield(out);
		cout << "ClearBitsMSBthroughI = "<< bitfield << endl;
	}
	num = num & mask;
}

// Clears bits from position pos to position 0 (least significant bit)
// IE:  x = 0b11111111; ClearBitsExclusive(x, 4) will return 0b11110000
void ClearBitsExclusive(int& num, int pos) {
	int mask = ~((1 << pos) - 1);
	if(OUTPUT) {
		int out = num;
		out = out & mask;
		std::bitset<bit_length> bitfield(out);
		cout << "ClearBitsPosThroughZero = "<< bitfield << endl;
	}
	num = num & mask;
}