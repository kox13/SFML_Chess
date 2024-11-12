#include "Logger.h"
#include <SFML/System.hpp>
#include <iostream>
#include <cassert>

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

void Logger::LogError(const std::string& error, const char* file, unsigned int line) {
    assert(file);
    std::cerr << "\033[" << (int)Color::RED << "m";
    std::cerr << "ERROR: " << error << " in " << file << " at " << line << "\n";
    std::cerr << "\033[0m";
}

void Logger::LogWarning(const std::string& warning, const char* file, unsigned int line) {
    assert(file);
    std::cerr << "\033[" << (int)Color::YELLOW << "m";
    std::cerr << "WARNING: " << warning << " in " << file << " at " << line << "\n";
    std::cerr << "\033[0m";
}

void Logger::LogMessage(const std::string& message, Color color) {
    std::cout << "\033[" << (int)color << "m";
    std::cout << "MESSAGE: " << message << "\n";
    std::cout << "\033[0m";
}

int Logger::overflow(int c) {
    if (c != EOF) {
        std::cerr << "\033[47m"; // Only SFML errors have a background to differentiate them from normal errors
        std::cerr << "\033[" << (int)Color::RED << "m";
        std::cerr << (char)c;
        std::cerr << "\033[0m";
    }

    return c;
}