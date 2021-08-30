#include<iostream>
#include<string.h>
using namespace std;

void encryptProc(char msg[],int key){
	int mLen=strlen(msg),i,j,row=0,col=0;
	char rfMat[key][mLen];
	bool dirDown=false;
	//creating a railfence matrix
	for(i=0;i<key;i++){
		for(j=0;j<mLen;j++)
			rfMat[i][j]='\n';
	}
	for(i=0;i<mLen;i++){
		if(row==0 || row==key-1)
			dirDown=!dirDown;
		rfMat[row][col++]=msg[i];
		dirDown?row++:row--;
	}
	//printing
	for(i=0;i<key;i++){
		for(j=0;j<mLen;j++)
			if(rfMat[i][j]!='\n')
				cout<<rfMat[i][j];
	
	}
}
void decryptProc(char msg[],int key){
	int mLen=strlen(msg),i,j,row=0,col=0;
	char rfMat[key][mLen];
	bool dirDown;
	for(i=0;i<key;i++){
		for(j=0;j<mLen;j++)
			rfMat[i][j]='\n';
	}

	for(i=0;i<mLen;i++){
		if(row==0)
			dirDown=true;
		if(row==key-1)
			dirDown=false;
		rfMat[row][col++]='*';
		dirDown?row++:row--;
	}
	int index=0;
	for(i=0;i<key;i++)
		for(j=0;j<mLen;j++)
			if(rfMat[i][j]=='*'&&index<mLen)
				rfMat[i][j]=msg[index++];
	row=0,col=0;
	for(i=0;i<mLen;i++){
		if(row==0)
			dirDown=true;
		if(row==key-1)
			dirDown=false;
		if(rfMat[row][col]!='*')
			cout<<rfMat[row][col++];
		dirDown?row++:row--;
	}	
}

int main(){
	char msg[100],ch='y';
	int key,choice;
	cout<<"____RAIL FENCE CIPHER___\n";

	cout<<"\nENTER THE MESSAGE : ";
	cin.getline(msg,100);
	cout<<"\nENTER THE KEY : ";
	cin>>key;
	cout<<"\nSelect 1 for encryption & 2 for decryption.\n";
	cin>>choice;
	switch(choice){
		case 1: encryptProc(msg,key);
		cout<<"\n________________________\n";
		break;
		case 2:decryptProc(msg,key);
		cout<<"\n________________________\n";
		break;
		default:cout<<"Select valid option";
		cout<<"\n________________________\n";
		break;
	}
	
	return 0;
}
