#include "Encrypt.h"

/*Encrypt constructor which initialize source file and target file parameters*/
Encrypt::Encrypt(const std::string &s, const std::string &t) : src_filename(s), tar_filename(t), filesize(0) {

	src_file.open(s.c_str());
	tar_file.open(t.c_str(), std::ios::out );	
}

/*Checking the status of the both files*/
bool Encrypt::checkFileStatus() {
	
	//Check whether the source file opened or not
	if(src_file.is_open())
		std::cout<<src_filename << " opened Successfully...!"<<std::endl;
	else {
		std::cout<<"Failed to open "<<src_filename<<std::endl;
		return false;
	}
	
	//Check whether the target file opened or not	
	if(tar_file.is_open())
		std::cout<<tar_filename<<" opened Successfully...!"<<std::endl;
	else {
		std::cout<<"Failed to open "<<tar_filename<<std::endl;
		return false;
	}
	
	return true;
}

void Encrypt::setPassword() {
	std::cout << "Enter the password : ";
	std::cin >> password;	
}

void Encrypt::decryptFile(){
	
	char ch;
	std::fstream out_file("decrypt_file.txt", std::ios::out);
	std::ifstream en_file("encrypted.txt");
	
	int pwdLen=password.size();
	int pwdIdx=0;
	int i=0;
		
	std::cout<<"File Size:"<<filesize<<std::endl;
	while(en_file.get(ch)){
		//if(i>=filesize)
			//break;
		i++;
		char d=(char)(ch ^ password[pwdIdx]);
		std::cout<<d;
		out_file.put(d);
		pwdIdx = (pwdIdx+1) % pwdLen;
	}
	
	en_file.close();
	out_file.close();
}

void Encrypt::encryptFile() {

	char ch;
	
	int pwdLen=password.size();
	int pwdIdx=0;
	
	//Read file character by character and encrypt by doing X-OR with password
	while(src_file.get(ch)) {
		std::cout<<ch;
		filesize++;
		char e=(char)(ch ^ password[pwdIdx]);
		tar_file.put(e);
		pwdIdx = (pwdIdx+1) % pwdLen;
	}
	
	src_file.close();
	tar_file.close();
}


Encrypt::~Encrypt() {
	src_file.close();
	std::cout<<src_filename << " closed Successfully...!"<<std::endl;
	
	tar_file.close();
	std::cout<<tar_filename<<" closed Successfully...!"<<std::endl;
}

