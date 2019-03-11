#pragma once
#include <string>
#ifdef _WIN32
const std::string RESOURCE_PATH = "resources\\";
#else
const std::string RESOURCE_PATH = "./resources/"
#endif // UNIX