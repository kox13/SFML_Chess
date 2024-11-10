#include "Logger.h"
#include <SFML/System.hpp>
#include <iostream>

static Logger* s_Instance = nullptr;

Logger::Logger() {
    sf::err().rdbuf(this);
}

Logger& Logger::Instance() {
    return *s_Instance;
}

bool Logger::Initialize() {
    if (!s_Instance) {
        s_Instance = new Logger;
        return true;
    }

    return false;
}

void Logger::Shutdown() {
    delete s_Instance;
}

int Logger::overflow(int c) {
    if (c != EOF) {
        std::cerr << "\033[32m";
        std::cerr << (char)c;
        std::cerr << "\033[0m";

        return c;
    }

    return EOF;
}
