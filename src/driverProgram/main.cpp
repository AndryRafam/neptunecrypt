/* THIS PART OF THE PROGRAM WILL BE MODIFIED WITH V2 VERSION */

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <termios.h>
#include <unistd.h>

#include "../simpleCipher/xchacha20Cipher.hpp"
#include "../password/password_generator.hpp"
#include "../password/set_echo.hpp"

#define yellow "\x1B[33m"
#define reset "\x1B[0m"

// main function
int main(/*int argc, char **argv*/) {
		
	std::ios::sync_with_stdio(false);
	
	system("clear"); // clear the screen
	
	std::ifstream infile;
	std::string line;
	infile.open("about.txt");
	while(std::getline(infile, line)) {
		std::cout << "\e[1m" << line << "\e[0m" << std::endl;
	}
	infile.close();
	
	// encryption or decryption
	std::cout << std::endl;
	std::cout << "encrypt/decrypt (e/d) ? >: ";
	std::string mode;
	std::cin >> mode;
	std::cin.ignore();
	
	// encryption
	if (mode=="e" || mode=="encrypt") {
	
		std::cout << "\e[1m" << "Encryption mode" << "\e[0m" << std::endl;
		
		label_1_file_path:
			std::cout << "File absolute path >: ";
			std::string filePath;
			std::getline(std::cin, filePath);
			
		// if file exist
		// proceed for encryption
		if(std::filesystem::exists(filePath)) {
			
			/*This portion of the code generate the password
			length randomly using mersen twister*/
			std::random_device rd; // seed the random number generator
			std::mt19937 gen(rd()); // initialize the mersene twister

			// define the distribution range between 16 to 64 include [16,64]
			// this define the password length
			std::uniform_int_distribution<int> distrib(16,64);
			
			int passLen = distrib(gen);

			std::string password_xchacha20 = generatePassword(passLen);
			std::cout << "Generated Password >: " << password_xchacha20 << std::endl;
			if(xchacha20filefolder(mode, filePath, password_xchacha20)) {
				std::cout << "\e[1m" << yellow << "Encrypted" << "\e[0m" << reset << "\n\n";
			}
		}
		// if file doesn't exist repeat the process
		else {
			std::cout << "\e[1m" << yellow << "File doesn't exist" << "\e[0m" << reset << std::endl;
			goto label_1_file_path; // repeat the process until a valid is input
		}
	}
	// decryption
	else if(mode=="d" || mode=="decrypt") {
		std::cout << "\e[1m" << "Decryption mode" << "\e[0m" << std::endl;
		
		label_2_file_path:
			std::cout << "File absolute path >: ";
			std::string filePath;
			std::getline(std::cin, filePath);
			
		// if file exist,
		// proceed for decryption
		if(std::filesystem::exists(filePath)) {
			std::string password_xchacha20;
			std::cout << "Enter your password >: ";
			setEcho(false); // disable mirroring input to the screen
			std::getline(std::cin, password_xchacha20); // password will not be outputed for security reason
			setEcho(true); //
			std::cout << std::endl;
			if(xchacha20filefolder(mode, filePath, password_xchacha20)) {
				std::cout << "\e[1m" << yellow << "Decrypted" << "\e[0m" << reset << "\n\n";
			}

		}
			// if file doesn't exist repeat the process
		else {
			std::cout << "\e[1m" << yellow << "File doesn't exist" << "\e[0m" << reset << std::endl;
			goto label_2_file_path; // repeat the process until a valid is input
		}
	}
	// default
	else {
		std::cout << "\e[1m" << "Invalid choice. Program terminated." << "\e[0m" << std::endl;
		return 0;
	}
	return 0;		
}
	
