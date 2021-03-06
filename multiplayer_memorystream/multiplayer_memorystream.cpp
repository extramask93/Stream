// multiplayer_memorystream.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <type_traits>
#include "ByteSwapper.h"
#include "OutputMemoryStream.h"
#define PLATFORM_ENDIANESS 1

template <typename T> void Write(T inData)
{
	static_assert(std::is_arithmetic<T>::value|std::is_enum<T>::value,"This function supports only basic types");
	if(STREAM_ENDIANESS == PLATFORM_ENDIANESS)
	{
		OutputMemoryStream::Write(&inData, sizeof inData);
	}
	else
	{
		T swappedData = ByteSwap(inData);
		OutputMemoryStream::Write(&swappedData,sizeof swappedData);
	}
}

int main()
{
    return 0;
}

