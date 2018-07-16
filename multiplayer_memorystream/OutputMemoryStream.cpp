#include "stdafx.h"
#include "OutputMemoryStream.h"
#include <algorithm>


void OutputMemoryStream::WriteBits(uint8_t data, size_t bitCount)
{
	uint32_t nextBitHead = mBitHead + static_cast<uint32_t>(bitCount);
	if(nextBitHead > mBitCapacity) {
		RealocBuffer(std::max(mBitCapacity*2,nextBitHead));
	}
	uint32_t byteOffset = mBitHead >> 3;
	uint32_t bitOffset = mBitHead & 0x7;

	uint8_t currentMask = ~(0xff << bitOffset);
	mBuffer[byteOffset] = (mBuffer[byteOffset] & currentMask) | (data<<bitOffset);

	uint32_t bitsFreeInThisByte = 8- bitOffset;

	if(bitsFreeInThisByte < bitCount) {
		mBuffer[byteOffset+1] = data>>bitsFreeInThisByte; 
	}
	mBitHead = nextBitHead;
}

void OutputMemoryStream::WriteBits(const void * data, size_t bitCount)
{
	const char* srcByte = static_cast<const char*>(data);
	while(bitCount>8) {
		WriteBits(*srcByte,8);
		++srcByte;
		bitCount -= 8;
	}
	if(bitCount) {
		WriteBits(*srcByte,bitCount);
	}
}


void OutputMemoryStream::RealocBuffer(uint32_t newSize)
{
	mBuffer = static_cast<char*>(std::realloc(mBuffer,newSize));
	mBitCapacity = newSize;
}
