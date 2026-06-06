#ifndef PASSWORD_GENERATOR_H
#define PASSWORD_GENERATOR_H

#include <string>
#include <algorithm> // std::shuffle
#include <random>
#include <chrono>

std::string generatePassword(int length);

#endif