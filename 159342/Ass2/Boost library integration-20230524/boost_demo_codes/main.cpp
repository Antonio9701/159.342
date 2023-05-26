/////////////////////////////////////////////////////////////////////////////////
//
// Programming using the BOOST Library 
//
// Author: n.h.reyes@massey.ac.nz
//
// Reference: https://www.geeksforgeeks.org/advanced-c-boost-library/
//
/////////////////////////////////////////////////////////////////////////////////


#include <boost/multiprecision/cpp_int.hpp> 

using namespace boost::multiprecision; 
// using namespace boost::multiprecision::cpp_dec_float_50;  //does not work

#include <boost/multiprecision/cpp_dec_float.hpp> 
#include <boost/math/constants/constants.hpp> 

using namespace std; 
  
int128_t boost_product(long long A, long long B) 
{ 
    int128_t ans = (int128_t) A * B; 
    return ans; 
} 

/////////////////////////////////////////////////////////////
//Arbitrary precision data type: We can use any precision with the help of cpp_int data type if we are not sure about 
//how much precision is needed in future. It automatically converts the desired precision at run-time.
cpp_int boost_factorial(int num) 
{ 
    cpp_int fact = 1; 
    for (int i=num; i>1; --i)     
        fact *= i; 
    return fact; 
} 

////////////////////////////////////////////////////////////
template<typename T> 
inline T area_of_a_circle(T r) 
{   
   // pi represent predefined constant having value 
   // 3.1415926535897932384... 
   using boost::math::constants::pi; 
   return pi<T>() * r * r; 
} 


//////////////////////////////////////////////////
int main() 
{ 
    //example #1: 
    cout << "\n===========================" << endl;     
    cout << "Example #1: ";
    cout << "\n===========================" << endl;     

    long long first = 98745636214564698; 
    long long second=7459874565236544789; 
    cout << "Product of "<< first << " * "
         << second << " = \n"
         << boost_product(first,second) ; 

    //-------------------------------------------------
    //example #2: 
    cout << "\n===========================" << endl;     
    cout << "Example #2: ";
    cout << "\n===========================" << endl;     
    int num=30; 
    cout << "Factorial of " << num << " = " 
         << boost_factorial(num) ; 

    //-------------------------------------------------
    //example #3: 
    cout << "\n===========================" << endl;     
    cout << "Example #3: ";
    cout << "\n===========================" << endl;   
    float radius_f = 123.0/ 100; 
    float area_f = area_of_a_circle(radius_f); 
  
    double radius_d = 123.0 / 100; 
    double area_d = area_of_a_circle(radius_d); 
  
    cpp_dec_float_50 r_mp = 123.0 / 100; 
    cpp_dec_float_50 area_mp = area_of_a_circle(r_mp); 
  
    // numeric_limits::digits10 represent the number 
    // of decimal digits that can be held of particular 
    // data type without any loss. 
      
    // Area by using float data type 
    cout << "Float: "
         << setprecision(numeric_limits<float>::digits10) 
         << area_f << endl; 
  
    // Area by using double data type 
    cout << "Double: "
         <<setprecision(numeric_limits<double>::digits10) 
         << area_d << endl; 
  
    // Area by using Boost Multiprecision  
    cout << "Boost Multiprecision: "
         << setprecision(numeric_limits<cpp_dec_float_50>::digits10) 
         << area_mp << endl; 
/////////////////////////////////////////
// exponential increase

    int m=1;
    for(int d=1; d <= 60; d++){
        if (d % 3 == 0){
           m = m *2;  
        }
    }
    cout << "money = " << m << endl;


    return 0; 
} 