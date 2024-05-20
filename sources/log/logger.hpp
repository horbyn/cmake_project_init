#pragma once

#include <iostream>
#include <sstream>
#include <exception>
#include "utilities/time.hpp"

namespace myproj {

enum class ELogLevel {
    RESERVED = 0,
    DBG,
    INFO,
    EXCEP
};
#define MACRO_STR_LOGLEVEL(e) \
    ((e == ELogLevel::RESERVED) ? "RESERVED" : \
     (e == ELogLevel::DBG) ?      "DBG" : \
     (e == ELogLevel::INFO) ?     "INFO" : \
     (e == ELogLevel::EXCEP) ?    "EXCEP" : "UNKNOWN")

class Logger final {
public:
    static Logger &get_instance() noexcept;

    void set_loglevel(ELogLevel level = ELogLevel::INFO) noexcept;
    ELogLevel get_loglevel() const noexcept;
    void set_log(const std::string &log);
    std::string get_log() const;

private:
    Logger() noexcept;
    ~Logger() noexcept;

    ELogLevel loglevel_;
    std::stringstream log_;
};

#define LOGGER(loglevel, mess) do \
    { \
        using namespace myproj; \
        auto &ins = Logger::get_instance(); \
        auto level = ins.get_loglevel(); \
        if ((int)loglevel >= (int)level) { \
            std::ostringstream ss{}; \
            ss << "[" << Time::getTime() << "] [" \
                << MACRO_STR_LOGLEVEL(loglevel) << "] " << mess << "\n"; \
            ins.set_log(ss.str()); \
        } \
    } while (0)

} // namespace myproj
