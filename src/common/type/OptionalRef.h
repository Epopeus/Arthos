#pragma once

#include <functional>

template <typename T> using OptionalRef = std::optional<std::reference_wrapper<T>>;