#pragma once

#include <functional>

template<class T>
using VoidCallback = std::function<void(T)>;