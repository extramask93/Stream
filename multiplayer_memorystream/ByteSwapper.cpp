#include "stdafx.h"
#include "ByteSwapper.h"

uint16_t ByteSwapper2(uint16_t from) {
	return ((from >> 8) & 0x00ff) | ((from << 8) & 0xff00);
}
uint32_t ByteSwapper4(uint32_t from) {
	return ((from >> 24) & 0x000000ff) | ((from >> 8) & 0x0000ff00) | ((from << 8) & 0x00ff0000) |
		((from << 24) & 0xff000000);
}
uint64_t ByteSwapper8(uint64_t from) {
	return ((from >> 56) & 0x00000000000000ff) |
		((from >> 40) & 0x000000000000ff00) |
		((from >> 24) & 0x0000000000ff0000) |
		((from >> 8) & 0x000000000ff00000) |
		((from << 8) & 0x0000000ff0000000) |
		((from << 24) & 0x0000ff0000000000) |
		((from << 40) & 0x00ff000000000000) |
		((from << 56) & 0xff00000000000000);
}