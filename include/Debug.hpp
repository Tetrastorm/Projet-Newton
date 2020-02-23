/*
 * Valentin Diard, 2019
 *
 * Project:     Tetra_Engine
 * License:     MIT 
`*
 * File:        Log.hpp
 * Description: Log system of Tetra Engine.
*/

#pragma once

#include <string>

#define NORMAL_COLOR "\x1B[0m"
#define RED_COLOR    "\x1B[31m"
#define YELLOW_COLOR "\x1B[33m"

enum ESeverity : unsigned char {
  Info = 0,
  Warning,
  Error,
  Critical
};

struct Debug {
public:
  static void Log(std::string const &str);
  static void Log(ESeverity const type, std::string const &str);
  static void Log(ESeverity const type, std::string const &str, const char *file_name, int line);
  static void LogError(ESeverity const type, std::string const &str, int errorCode);

private:
  static std::string GetTime(void);
  static void WriteOnLogFile(std::string const strToPrint);
};
