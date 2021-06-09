//ceaser cipher  
#include<bits/stdc++.h>
 
using namespace std;
//encrypting the plain text into cipher text
string encrypt(string  text,int key)
{
	string message= "";
	for(int i=0;i<text.length();i++)
	{
		if(isupper(text[i]))
		{
			message+= char((int(text[i])+key-65)%26 +65);
		}
		else if(islower(text[i]))
		{
			message+= char((int(text[i])+key-97)%26 +97);
		}
		else if(isdigit(text[i]))
		{
			message+= char((int(text[i])+key-48)%10+48);	
		}
		else if(isspace(text[i]))
		{
			message+= char(text[i]);	
		}
		
		else
		{
			message+= char(text[i]);
		}
	
	}
	return message;
}

//decryping the cipher text
	string decrypt(string  message,int key)
{
	string info= "";
	
	for(int i=0;i<message.length();i++)
	{
		if(isupper(message[i]))
		{
			info+= char((int(message[i])-key-90)%26 +90);
		}
		else if(islower(message[i]))
			info+= char((int(message[i])-key-122)%26 +122);
	
	
		else if(isdigit(message[i]))
		{
			info+= char((int(message[i])-key-57)%10 + 57);	
		}
		else if(isspace(message[i]))
		{
			info+= char(message[i]);	
		}
		
		else
		{
			info+= char(message[i]);
		}
	
	}
	return info;
	
	
}
int main()
{
	string str,cipher_text,plain_text;
	int k;
	char ch;
	cout<<"Enter the text which is to be encrypted:"<<endl;
	getline(cin,str);
	cout<<"Enter the key:"<<endl;
	cin>>k;
	cipher_text=encrypt(str,k);
	cout<<"Cipher text after encryption:"<<cipher_text<<endl;
	cout<<"----------------------------------------"<<endl;
	plain_text=decrypt(cipher_text,k);

	cout<<"plain text after decryption:"<<plain_text;
		
		
	return 0;
	
}
