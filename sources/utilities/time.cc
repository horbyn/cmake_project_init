#include "time.hpp"

namespace myproj {

std::string Time::getTime() {
  auto now = std::chrono::system_clock::now();
  auto now_time = std::chrono::system_clock::to_time_t(now);
  auto now_ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;

  std::tm tm_struct = *std::localtime(&now_time);
  std::ostringstream oss;
  oss << std::put_time(&tm_struct, "%Y-%m-%d %H:%M:%S");
  oss << '.' << std::setfill('0') << std::setw(3) << now_ms.count();
  return oss.str();
}

} // namespace myproj
