/*
 * Valentin DIARD, 2019
 *
 * Project:     Tetra_Engine
 * License:     MIT
`*
 * File:        Debug.hpp
 * Description: Log system source of the engine.
*/

#include "Debug.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <fstream>
#include <experimental/filesystem>

void Debug::Log(std::string const &str)
{
    Debug::Log(ESeverity::Info, str);
}

void Debug::Log(ESeverity const type, std::string const &str)
{
    std::string strToPrint;

    switch (type) {
        case ESeverity::Info:
            strToPrint = Debug::GetTime() + str;
            std::cout << strToPrint << std::endl;
            break;
        case ESeverity::Warning:
            strToPrint = Debug::GetTime() + "WARNING\t" + str;
            std::cout << YELLOW_COLOR << strToPrint << NORMAL_COLOR << std::endl;
            break;
        case ESeverity::Error:
            strToPrint = Debug::GetTime() + "ERROR\t" + str;
            std::cerr << RED_COLOR << strToPrint << NORMAL_COLOR << std::endl;
            break;
        default:
            strToPrint = Debug::GetTime() + "CRITICAL ERROR\t" + str;
            std::cerr << RED_COLOR << strToPrint << NORMAL_COLOR << std::endl;
    }
    WriteOnLogFile(strToPrint);
}

void Debug::Log(ESeverity const type, std::string const &str, const char *file_name, int line)
{
    std::string strToPrint;

    switch (type) {
        case ESeverity::Info:
            strToPrint = Debug::GetTime() + "(" + std::string(file_name) + ":" + std::to_string(line) +")\t" + str;
            std::cout << strToPrint << std::endl;
            break;
        case ESeverity::Warning:
            strToPrint = Debug::GetTime() + "WARNING\t" + "(" + std::string(file_name) + ":" + std::to_string(line) +")\t" + str;
            std::cout << YELLOW_COLOR << strToPrint << NORMAL_COLOR << std::endl;
            break;
        case ESeverity::Error:
            strToPrint = Debug::GetTime() + "ERROR\t" + "(" + std::string(file_name) + ":" + std::to_string(line) +")\t" + str;
            std::cerr << RED_COLOR << strToPrint << NORMAL_COLOR << std::endl;
            break;
        default:
            strToPrint = Debug::GetTime() + "CRITICAL ERROR\t" + "(" + std::string(file_name) + ":" + std::to_string(line) +")\t" + str;
            std::cerr << RED_COLOR << strToPrint << NORMAL_COLOR << std::endl;
    }
    WriteOnLogFile(strToPrint);
}

void Debug::LogError(ESeverity const type, std::string const &str, int errorCode)
{
    std::string strToPrint;

    switch (type) {
        case ESeverity::Error:
            strToPrint = Debug::GetTime() + "ERROR\t[" + std::to_string(errorCode) + "]\t" + str;
            std::cerr << RED_COLOR << strToPrint << NORMAL_COLOR << std::endl;
            break;
        case ESeverity::Critical:
            strToPrint = Debug::GetTime() + "CRITICAL ERROR\t[" + std::to_string(errorCode) + "]\t" + str;
            std::cerr << RED_COLOR << strToPrint << NORMAL_COLOR << std::endl;
            break;
        default:
            Debug::Log(ESeverity::Warning, "void Debug::Log(ESeverity const type, std::string const &str, int errorCode)\tyou want be use in case of error.");
            Debug::Log(type, str);
    }
    WriteOnLogFile(strToPrint);
}

std::string Debug::GetTime(void)
{
    char buffer[29];
    std::string output;
    timeval currentTime;
    std::string milli_str;

    gettimeofday(&currentTime, nullptr);
    //%d-%m-%Y
    strftime(buffer, sizeof(buffer), "<%T:", localtime(&currentTime.tv_sec));
    milli_str = std::to_string(currentTime.tv_usec / 1000);
    if (milli_str.length() < 3) {
        while (milli_str.length() < 3) {
            milli_str += "0";
        }
    }
    output = buffer + milli_str + ">\t";
    return (output);
}

void Debug::WriteOnLogFile(std::string const strToPrint)
{
    static bool once = false;
    std::string fileName = "Saved/TetraEngine.log";

    std::experimental::filesystem::v1::create_directory("Saved");
    static std::ofstream logFile = std::ofstream(fileName, std::ios::trunc);

    if (!logFile) {
        exit(EXIT_FAILURE);
    }
    logFile << strToPrint << std::endl;
    if (!once) {
        logFile = std::ofstream(fileName, std::ios::app);
        once = !once;
    }
}
