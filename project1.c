#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

// Utility function to print a formatted timestamp
std::string currentTime() {
    auto now = std::chrono::system_clock::now();
    auto t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S"); // YYYY-MM-DD HH:MM:SS
    return oss.str();
}

// ANSI escape codes for colors
const std::string RESET = "\033[0m";
const std::string CYAN = "\033[36m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

int main() {
    // Greeting banner
    std::cout << CYAN << "=============================\n";
    std::cout << "   🚀 Advanced Hello World   \n";
    std::cout << "=============================" << RESET << "\n\n";

    // Print message
    std::string message = "Hello, World!";
    std::cout << GREEN << message << RESET << std::endl;

    // Show timestamp
    std::cout << YELLOW << "\nProgram executed at: " 
              << currentTime() << RESET << std::endl;

    // Exit gracefully
    std::cout << CYAN << "✨ Program finished successfully ✨" 
              << RESET << std::endl;

    return 0;
}
