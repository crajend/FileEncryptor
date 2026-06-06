#include "Encrypt.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Encrypt obj("linuxFeatures.txt","encrypted.txt");
	
	if(obj.checkFileStatus()) {
		
		obj.setPassword();
		std::cout<<"Encrypting the file...!"<<std::endl;
		obj.encryptFile();
		std::cout<<"Decrypting the file...!"<<std::endl;
		obj.decryptFile();
	}
	
	return 0;
}
