#include "logger.hpp"

namespace myproj {

Logger &Logger::get_instance() noexcept {
    static Logger instance;
    return instance;
}

void Logger::set_loglevel(ELogLevel level) noexcept { loglevel_ = level; }

ELogLevel Logger::get_loglevel() const noexcept { return loglevel_; }

void Logger::set_log(const std::string &log) { log_ << log; }

std::string Logger::get_log() const { return log_.str(); }

Logger::Logger() noexcept : loglevel_{ELogLevel::INFO}, log_{} {}

Logger::~Logger() noexcept {
    try {
        std::cout << log_.rdbuf() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "[" << Time::getTime() << "] ["
                << MACRO_STR_LOGLEVEL(ELogLevel::EXCEP) << "] "
                << "log output failed" << std::endl;
    }
}

} // namespace myproj
