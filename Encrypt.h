#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

/* This is Encrypt class which source file name & ifstream and target filename & ofstream*/
class Encrypt{
	std::string src_filename; // Name of the source file
	std::string tar_filename; // Name of the target file
	std::ifstream src_file; // File stream for source file(read mode)
	std::fstream tar_file; // File stream for target file(writemode)
	std::size_t filesize;
	std::string password;
	
	public:
		Encrypt(const std::string &s, const std::string &t); // Encrypt constructor 
		bool checkFileStatus(); // Method to check the status of the files whether opened or not
		void encryptFile(); // Method to Encrypt the content of the source file to target file
		void decryptFile(); // Method to Decrypt the content of the target file to source file
		void setPassword();
		~Encrypt();	// Destructor to close the files
};

#endif // HEADER_H
