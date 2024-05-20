# cmake project initialization

This is an initialization project for a cmake project.

The project includes:
- Exception object, which is used to unify the exception output of the entire project
    + `throw myproj::EXCEPT(std::string{ "this is an exception" } + " hello world");`
- Logging module, which is used to unify the logging output of the entire project
    + `myproj::LOGGER(myproj::ELogLevel::EXCEP, "this is an " << "exception");`

Use case:
- When you want to test some C++ demo, this project has already provided exception and logging features, and integrated them into the cmake build system, so you can focus directly on the demo logic
