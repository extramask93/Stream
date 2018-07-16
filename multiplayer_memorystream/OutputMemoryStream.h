#pragma once
#include <cstdint>
#include <cstdlib>
#define STREAM_ENDIANESS 1
class OutputMemoryStream
{
public:
	OutputMemoryStream() { RealocBuffer(256);}
	~OutputMemoryStream() { std::free(mBuffer);}
	const char * GetBuffer()	const { return mBuffer;}
	uint32_t GetBitLength() const { return mBitHead;}
	uint32_t GetByteLength()	const {return (mBitHead+7)>>3;}

	void WriteBits(uint8_t data, size_t bitCount);
	void WriteBits(const void * data, size_t bitCount);

	void WriteBytes(const void *inData,size_t inByteCount) { WriteBits(inData,inByteCount<<3);}

private:
	void RealocBuffer(uint32_t newSize);
	char * mBuffer = nullptr;
	uint32_t mBitHead;
	uint32_t mBitCapacity;
};

