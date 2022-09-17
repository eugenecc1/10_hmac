#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>

//Reference https://gist.github.com/yoshiki/812d35a32bcf175f11cb952ed9d1582a


int main()
{

	unsigned char key[] = "Jefe";
	unsigned char data[] = "what do ya want for nothing?";
	unsigned char expected[] = "5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843";
	unsigned char *result = NULL;
	int len = 32;
	static char res_hexstring[64];
	
	printf("Key = %s\n", key);
	printf("Data = %s\n", data);
	printf("Expected = %s\n", expected);
	
	result = HMAC(EVP_sha256(), key, strlen((char *)key), data, strlen((char *)data), NULL, NULL);
  
  	for (int i = 0; i < len; i++)
  	{
  		sprintf(&(res_hexstring[i * 2]), "%02x", result[i]);
  	}
 	
 	 printf("The result %s\n", res_hexstring);
  	
  	if (strcmp((char *) res_hexstring, (char *) expected) == 0) 
  		printf("The result matched with expected results\n");
  	else
    		printf("The result did not match with expected results\n");
 	
 	return 0;

}

