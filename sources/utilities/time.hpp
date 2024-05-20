#pragma once

#include <iomanip>
#include <sstream>
#include <chrono>

namespace myproj {

class Time final {
public:
  Time() = default;
  ~Time() = default;

  static std::string getTime();
};

} // namespace myproj
