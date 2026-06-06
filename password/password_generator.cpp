// This code generate a password randomly

#include "password_generator.hpp"

std::string generatePassword(int length) {
	// define the character set for the password
	const std::string charset =
        "abcdefghijklmnopqrstuvwxyz"  // lowercase character
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"  // uppercase character
        "0123456789"                  // numbers
        "!@#$%^&*()-_=+[]{}|;:,.<>?"; // special character

    // seed the random number engine using a high-resolution clock
    // this provides a good source of entropy for seeding
    std::mt19937 generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());

    // create a uniform integer distribution for the character set indices
    // the range is from 0 to charset.size() - 1
    std::uniform_int_distribution<> distribution(0, charset.size() - 1);

    std::string password = "";
    password.reserve(length); // pre-allocate memory for efficiency

    // generate each character of the password
    for (int i = 0; i < length; ++i) {
    	// get a random index from the distribution and append the corresponding character
    	password += charset[distribution(generator)];
    }
    return password;    
}
