// ref: https://en.wikipedia.org/wiki/MD5
// implemented by Peng Rui
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;
void run(string message) {
	unsigned i, j, var[4] = {0x67452301, 0xefcdab89, 0x98badcfe, 0x10325476}, array[(((message.length() + 8) >> 6) + 1) << 4] = {0}, K[64], s[64] = {7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};
	for (i = 0; i < 64; i++)
		K[i] = (1ULL << 32) * abs(sin(i + 1));
	for (i = 0; i < message.length(); i++)
		array[i >> 2] |= message[i] << ((i % 4) << 3);
	array[i >> 2] |= 0x80 << ((i % 4) << 3);
	array[((((message.length() + 8) >> 6) + 1) << 4) - 2] = i << 3;
	for (i = 0; i < ((message.length() + 8) >> 6) + 1; i++) {
		unsigned temp[4] = {var[0], var[1], var[2], var[3]}, dTemp, F, g, M[16];
		for (j = 0; j < 16; j++)
			M[j] = array[i * 16 + j];
		for (j = 0; j < 64; j++) {
			if (j < 16) {
				F = (temp[1] & temp[2]) | ((~temp[1]) & temp[3]);
				g = j;
			} else if (j < 32) {
				F = (temp[3] & temp[1]) | ((~temp[3]) & temp[2]);
				g = (5 * j + 1) % 16;
			} else if (j < 48) {
				F = temp[1] ^ temp[2] ^ temp[3];
				g = (3 * j + 5) % 16;
			} else {
				F = temp[2] ^ (temp[1] | (~temp[3]));
				g = (7 * j) % 16;
			}
			dTemp = temp[3];
			temp[3] = temp[2];
			temp[2] = temp[1];
			temp[1] += ((temp[0] + F + K[j] + M[g]) << s[j]) | ((temp[0] + F + K[j] + M[g]) >> (32 - s[j]));
			temp[0] = dTemp;
		}
		for (j = 0; j < 4; j++)
			var[j] += temp[j];
	}
	cout << message << ": ";
	for (i = 0; i < 4; i++)
		while (var[i]) {
			cout << setw(2) << setfill('0') << hex << var[i] % 0x100;
			var[i] /= 0x100;
		}
	cout << endl;
}
int main() {
	// modify your samples here
	run("The quick brown fox jumps over the lazy dog");
	run("The quick brown fox jumps over the lazy dog.");
	run("");
    return 0;
}

