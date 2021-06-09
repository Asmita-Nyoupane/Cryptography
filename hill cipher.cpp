#include<iostream>
#include<string>
#include<regex>

using namespace std;
int i,j;

//converting the string into matrix form
void getkey(string key, int keymatrix[][2])
{
    int k=0;
    for(i=0;i<2;i++)
    {

        for(j=0;j<2;j++)
        {
            //converting  each character of key into uppercase
            key[k]=toupper(key[k]);

            keymatrix[i][j]=key[k]%65;
            k++;

        }

    }
}

 string encryption(int keymatrix[2][2],string message)
 {
     int count=0,itr1=0,itr2=0;

     int messagevector[2][message.length()/2];
     for(i=0;i<message.length();i++)
     { //converting message into uppercase
          message[i]=toupper(message[i]);
         if(i%2==0)
         {
             messagevector[0][itr1]=message[i]%65;

             itr1++;
         }
         else{
            messagevector[1][itr2]=message[i]%65;

            itr2++;
         }



     }

     if(message.length()%2!=0)

     {
         count =1;
         message+="0";
     }
     else
        count=0;


     string encrypttext="";
     int len=message.length()/2;
     if(count==0)
     {
          for(i=0;i<len;i++)
     {
            int temp1= messagevector[0][i]*keymatrix[0][0]+messagevector[1][i]*keymatrix[0][1];
			encrypttext+=char((temp1%26)+65);

			int temp2=messagevector[0][i]*keymatrix[1][0]+messagevector[1][i]*keymatrix[1][1];
			encrypttext+=char((temp2%26)+65);



     }
     }
     else{

          for(i=0;i<len-1;i++)
          {

            int temp1= messagevector[0][i]*keymatrix[0][0]+messagevector[1][i]*keymatrix[0][1];
			encrypttext+=char((temp1%26)+65);
			int temp2=messagevector[0][i]*keymatrix[1][0]+messagevector[1][i]*keymatrix[1][1];
			encrypttext+=char((temp2%26)+65);
          }

     }
    return encrypttext;

 }
 int modulo(int a, int b )
 { int rem=a%b;
     if(rem<0)
        rem+=b;
        return rem;
 }
 void inverse( int keymatrix[2][2])
 {
     int deter= keymatrix[0][0]*keymatrix[1][1]-keymatrix[1][0]*keymatrix[0][1];
     if(deter==0)
     {

         cout<<"Wrong Entry!!"<<endl;
     }
      deter =modulo(deter,26);


     int matrix_inverse=-1;
     for(i=0;i<26;i++)
     {
            int deter_inverse=deter*i;

           if(modulo(deter_inverse,26)==1)
           {
               matrix_inverse=i;
               break;
           }
           else
           continue;
     }
     //finding adjoint matrix
     swap(keymatrix[0][0],keymatrix[1][1]);
     keymatrix[0][1]=(-1)*keymatrix[0][1];
      keymatrix[1][0]=(-1)*keymatrix[1][0];
       for(i=0;i<2;i++)
       {

           for(j=0;j<2;j++)
           {
               keymatrix[i][j]=modulo(keymatrix[i][j],26);
           }
       }
       //determining the inverse of matrix
       if( matrix_inverse==-1)
       {
           cout<<"Can't proceed the process"<<endl;
           exit(1);
       }
       else{

          for(i=0;i<2;i++)
       {

           for(j=0;j<2;j++)
           {
               keymatrix[i][j]=matrix_inverse*keymatrix[i][j];
           }
       }
       }



 }
 //Decryption process
 void  decryption(int keymatrix[][2],string ciphertext)
 {
     inverse(keymatrix);
      int count=0,itr1=0,itr2=0;

     int ciphervector[2][ciphertext.length()/2];
     for(i=0;i<ciphertext.length();i++)
     {
         if(i%2==0)
         {
            ciphervector[0][itr1]=ciphertext[i]%65;

             itr1++;
         }
         else{
            ciphervector[1][itr2]=ciphertext[i]%65;

            itr2++;
         }



     }

     if(ciphertext.length()%2!=0)

     {
         count =1;
        ciphertext+="0";
     }
     else
        count=0;

    string decrypttext="";
    int len=ciphertext.length()/2;
     if(count==0)
     {
          for(i=0;i<len;i++)
     {
            int temp1=ciphervector[0][i]*keymatrix[0][0]+ ciphervector[1][i]*keymatrix[0][1];
			decrypttext+=char((temp1%26)+65);

			int temp2=ciphervector[0][i]*keymatrix[1][0]+ciphervector[1][i]*keymatrix[1][1];
			decrypttext+=char((temp2%26)+65);
     }
     }
     else{

          for(i=0;i<len-1;i++)
          {

            int temp1= ciphervector[0][i]*keymatrix[0][0]+ciphervector[1][i]*keymatrix[0][1];
			decrypttext+=char((temp1%26)+65);
			int temp2=ciphervector[0][i]*keymatrix[1][0]+ciphervector[1][i]*keymatrix[1][1];
			decrypttext+=char((temp2%26)+65);
          }

     }
     cout<<"After Decryption text becomes:"<<decrypttext<<endl;

 }

int main()
{
    string message,key;
    int choice ,keymatrix[2][2];
    cout<<"Enter the message:"<<endl;
    getline(cin,message);
    //removing the white space from message
    message = regex_replace(message, regex("\\s+"), "");
    cout<<"Enter the key:"<<endl;
    getline(cin,key);
    //removing the white space from key
    key = regex_replace(key, regex("\\s+"), "");

    getkey(key, keymatrix);
while(1)
{     cout<<"Enter your choice:"<<endl;
     cout<<"1 for Encryption"<<endl<<"2 for Decryption "<<endl<<"3 for  Exit"<<endl;
    cin>>choice;
    switch(choice)
    {

    case 1:
        {
            cout<<"Encryption process start:"<<endl;
            cout<<"------------------------------------------------------"<<endl;
            string encrypttext =encryption(keymatrix,message);
             cout<<"After encryption text becomes:"<<encrypttext<<endl;
            break;
        }

    case 2:
        {
            cout<<"Decryption process start:"<<endl;
             string ciphertext=encryption(keymatrix,message);
             cout<<"------------------------------------------------------"<<endl;
            decryption(keymatrix,ciphertext);
            break;
        }
    case 3:
        exit(1);

    default:
        cout<<"Only 1 and 2 are valid entry"<<endl;
    }

}


    return 0;

}
