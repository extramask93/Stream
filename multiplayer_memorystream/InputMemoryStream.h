#pragma once
#include <cstdlib>
#include <cstdint>

class InputMemoryStream
{
public:
	InputMemoryStream(char *inBuffer, uint32_t byteCount) : mHead(0), mCapacity(byteCount){}
	~InputMemoryStream() {std::free(mBuffer);}
	uint32_t GetRemainingSize() const {return mCapacity - mHead;}
	void Read(void * outData, uint32_t size);
	void Read(uint32_t &outData) { Read(&outData,sizeof outData);}
	void Read(int32_t &outData) {Read(&outData, sizeof outData);}
private:
	char *mBuffer = nullptr;
	uint32_t mHead;
	uint32_t mCapacity;
};

