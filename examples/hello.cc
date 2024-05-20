#include "except/except.hpp"
#include "log/logger.hpp"

int
main(int argc, char **argv) {

    try {
        LOGGER(myproj::ELogLevel::INFO, "hello example");
        throw EXCEPT("hello failed");
        LOGGER(myproj::ELogLevel::INFO, "hello succeeded");
    } catch (const myproj::Except &e) {
        LOGGER(myproj::ELogLevel::EXCEP, e.what());
    } catch (const std::exception &e) {
        LOGGER(myproj::ELogLevel::EXCEP, e.what());
    }

    return 0;
}
