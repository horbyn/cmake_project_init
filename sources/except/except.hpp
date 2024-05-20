#pragma once

#include <sstream>
#include <exception>
#include <cstring>

namespace myproj {

class Except final : public std::exception {
public:
    Except() = delete;
    ~Except();

    Except(const std::string &file, int line, const std::string &msg);
    const char *what() const noexcept override;

private:
    std::string msg_;
    int code_;
};

#define EXCEPT(msg)     (myproj::Except((__FILE__), (__LINE__), (msg)))

} // namespace myproj
