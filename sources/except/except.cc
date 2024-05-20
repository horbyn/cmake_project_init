#include "except.hpp"

namespace myproj {

Except::~Except() {}

Except::Except(const std::string& file, int line, const std::string& msg)
                     : msg_{}, code_{} {
    code_ = errno;
    std::string extra{};

#ifdef DEBUG
    extra = std::string("[") + file + ":" + std::to_string(line) + "] ";
#else
    (void)file;
    (void)line;
#endif

    msg_ += extra + msg;
    if (code_ != 0)
        msg_ += " (" + std::to_string(code_) + ": " + std::string(std::strerror(errno)) + ")";
}

const char *Except::what() const noexcept {
    return msg_.c_str();
}

} // namespace myproj
