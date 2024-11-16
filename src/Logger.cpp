#include "Logger.h"
#include <SFML/System/Err.hpp>
#include <iostream>

static Logger* s_Instance = nullptr;
std::mutex Logger::s_Lock;

Logger::Logger() {
    sf::err().rdbuf(this);
}

void Logger::Initialize() {
    if (!s_Instance)
        s_Instance = new Logger;
}

void Logger::Shutdown() {
    delete s_Instance;
}

int Logger::overflow(int c) {
    if (c != EOF) {
        std::cerr << "\033[" << (int)Color::WHITE + 10 << "m"; // Only SFML errors have a background to differentiate them from normal errors
        std::cerr << "\033[" << (int)Color::RED << "m";
        std::cerr << (char)c;
        std::cerr << "\033[0m";
    }

    return c;
}