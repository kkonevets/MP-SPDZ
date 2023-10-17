#pragma once

#include <cstdint>

template <class T>
void serialize(const T&, uint8_t*);

template <class T>
T deserialize(uint8_t*);
