#include<iostream>
#include<string.h>
using namespace std;

int main(){
char msg[100];
int key,length,choice,i,j;
cout<<"Enter the message:\n";
cin.getline(msg,100);
//cout<<msg;
cout<<"Enter the key-position shift by ";
cin>>key;
cout<<"What do you wish to perform \n 1.Encryption \t \t 2.Decryption\n";
cin>>choice;
length=strlen(msg);
switch(choice)
{
	case 1:
	char ch;
	for(int i=0;msg[i] !='\0';i++){
		ch=msg[i];
		if(ch>='a' && ch<='z'){
			ch+=key;
			if(ch>'z'){
				ch=ch-'z'+'a'-1;
			}
			msg[i]=ch;
		}
		 else if (ch>='A' && ch<='Z'){
		 	ch+=key;
			if(ch>'Z'){
				ch=ch-'Z'+'A'-1;
			}
			msg[i]=ch;
		 }
	 }
	 cout<<"Encrypted message:"<<msg;
	break;
	case 2:
	char cha;
	for(int i=0;msg[i] !='\0';i++){
		cha=msg[i];
		if(cha>='a' && cha<='z'){
			cha-=key;
			if(cha<'a'){
				cha=cha+'z'-'a'+1;
			}
			msg[i]=cha;
		}
		 else if (cha>='A' && cha<='Z'){
		 	cha-=key;
			if(cha<'A'){
				cha=cha+'Z'-'A'+1;
			}
			msg[i]=cha;
		 }
	 }
	 cout<<"Decrypted message:"<<msg;
	break;
	default:
	cout<<"Choose a valid option";
	break;
}

return 0;
}

