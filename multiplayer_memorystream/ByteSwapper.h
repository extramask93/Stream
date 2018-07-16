#pragma once
#include <cstdint>

uint16_t ByteSwapper2(uint16_t from);
uint32_t ByteSwapper4(uint32_t from);
uint64_t ByteSwapper8(uint64_t from);


template < typename tFrom, typename tTo>
class TypeAliaser
{
public:
	TypeAliaser(tFrom inFromValue) : mAsFromType(inFromValue) {}
	tTo& Get() { return mAsToType; }
	union
	{
		tFrom mAsFromType;
		tTo mAsToType;
	};
};
template <typename T, size_t byteNr>
class ByteSwapper;


template<typename E>
class ByteSwapper<E, 2> {
public:
	E Swap(E from) const {
		uint16_t result = ByteSwapper2(TypeAliaser<E, uint16_t>(from).Get());
		return TypeAliaser<uint16_t, E>(result).Get();
	}
};

template<typename E>
class ByteSwapper<E, 4> {
public:
	E Swap(E from) const {
		uint16_t result = ByteSwapper4(TypeAliaser<E, uint16_t>(from).Get());
		return TypeAliaser<uint16_t, E>(result).Get();
	}
};
template<typename E>
class ByteSwapper<E, 8> {
public:
	E Swap(E from) const {
		uint16_t result = ByteSwapper8(TypeAliaser<E, uint16_t>(from).Get());
		return TypeAliaser<uint16_t, E>(result).Get();
	}
};

template<typename T>
T ByteSwap(T from) {
	return ByteSwapper<T, sizeof T>().Swap(from);
}

