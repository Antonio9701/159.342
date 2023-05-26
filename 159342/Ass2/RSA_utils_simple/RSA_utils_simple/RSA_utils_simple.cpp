//////////////////////////////////////////////////////////////////////////////////////////////
// RSA test
// compiles using GCC 
//
//
// References: http://www.di-mgt.com.au/rsa_alg.html
//
// Author: Napoleon Reyes, Ph.D.
//         Massey University, Albany  
//
//////////////////////////////////////////////////////////////////////////////////////////////


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#define USE_IPV6 false

//159.334 - Networks
//single threaded server
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

//---
#include <cfenv> //for math error checking
#include <cmath>
 

#define SECRET_PASSWORD "334"

#define WSVERS MAKEWORD(2,2) /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
                             //The high-order byte specifies the minor version number; 
									  //the low-order byte specifies the major version number.

#define DEFAULT_PORT "1234" 

WSADATA wsadata; //Create a WSADATA object called wsadata. 

using namespace std;

//////////////////////////////////////////////////////////////


int repeat_square(int x,int e,int n); //integer data type only, can be upgraded to  unsigned long long


//////////////////////////////////////////////////////////////
//Note: integer data type only, can be upgraded to  unsigned long long
int repeat_square(int x,int e,int n) {
  int y=1;//initialize y to 1, very important
  while (e>0) {
    if ((e%2)==0) {
      x=(x*x)%n;
      e=e/2;
    }
    else {
      y=(x*y)%n;
      e=e-1;
    }
  }
  return y; //the result is stored in y
}


/////////////////////////////////////////////




/////////////////////////////////////////////
void testRSA_3(){
    cout << "<< RSA TEST >>" << endl;
    cout << "integer numbers." << endl;
    int e,n, z;
    int d;
    // int nonce;
    // int calculatedRandomNum;
    //p=173 and q=149
    // int p=173;
    // int q=149;

    //note: p and q must be prime numbers!
    // int p=5;
    // int q=7;

    // n=p*q;
    // z = (p-1)*(q-1);
    // e = 5;
    // d = 29;
    // int input = 12;

//------------------------
    //lecture
    int p=173;
    int q=149;

    n=25777;
    z = (p-1)*(q-1);
    e = 3;
    d = 16971;

//------------------------



    int input = 1234;

    int cipher;
    cout << "p = " << p << endl;
    cout << "q = " << q << endl; 
    cout << "n = " << n << endl;
    cout << "z = " << z << endl;
    cout << "--------------" << endl;
    cout << "(input) m = " << input << endl;
    cout << "\npublic key(e,n) = (" << e << ", " << n << ")" << endl;
    cout << "encrypting: c = m^e mod n" << endl;
    cout << "encrypting: c = " << input << "^" << e << " mod " << n << endl;
    cipher = repeat_square(input, e, n);

    cout << "cipher c = " << cipher << endl;

    
    cout << "\nprivate key(d,n) = (" << d << ", " << n << ")" <<  endl;
    cout << "decrypting: m = c^d mod n" << endl;
    cout << "decrypting: c = " << cipher << "^" << d << " mod " << n << endl;
    int number = repeat_square(cipher, d, n);
    cout << "decrypted value = " << number << endl;
    
    cout << "\n--- Analysing results ---" << endl;
    if(input == number){
       cout << "We have a match, therefore correct decryption!, " << "input = " << input << ", decrypted value = " << number << endl;    
    } else {
       cout << "Error in decryption!!" << "input = " << input << ", decrypted value = " << number << endl;    
    }

}


/////////////////////////////////////////////

int main(){

    testRSA_3(); //integer only, can be upgraded to  unsigned long long
    

  return 0;
}