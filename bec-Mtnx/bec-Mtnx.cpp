
#include <iostream>
using namespace std;

#include "Vector.h"
#include "Matrix.h"
int main()
{
  Vector v1; // domyslny 
  Vector v2( 4, 1 );
  Vector v3( 4, 2 );
  Vector v4( v3 );
  Vector v5;
  Vector v6( 4,3);
  v5 = v2 + v3 + 4;
  

  cout << "v1 = " << v1 << endl;
  cout << "Podaj dwie wspolrzedne wektora : ";
    cin >> v1; 


  cout << "v1 = " << v1 << endl;
  cout << "v2 = " << v2 << endl;
  cout << "v3 = " << v3 << endl;
  cout << "v4 = " << v4 << endl;
  cout << "v5 = " << v5 << endl;
  cout << "v6 = " << v6 << endl;
  // v1 + v2
  cout << "v2 + v3" << v2 + v3 << endl;

  //x + v1
  cout << "-4 + v2 = " << -4 + v2 << endl;

  //v1 + x
  cout << "v2 + 5 = " << v2 + 5 << endl;

  //v1 += v2
  
  v3 += v4;
  cout << "v3 += v4 = " << v3 << endl;

  //v1 += x
  v6 += 2;
  cout << " v6 += 2 = " << v6 << endl;

  // v1 - v2
  cout << "v4 - v3 = " << v4 - v3 << endl;


  //v1 - x
  cout << "v1 - 1 = " << v1 - 1 << endl;

  //v1 -= v2
  v6 -= v3;
  cout << " v6 -= v3 = " << v6 << endl;

  //v1 -= x
  v4 -= 3;
  cout << "  v4 -= 2 = " << v4 << endl;

  // v * x
  cout << "  v2 * 5 = " << v2 * 5 << endl;
  

  // x * v
  cout << "  -3 * v6 = " << -3 * v6 << endl;

  // v *= x
  v4 *= 2;
  cout << " v4 *= 2  = " << v4 << endl;

  // v = -v
  v4 = -v4;
  cout << " v4 = -v4  = " << v4 << endl;

  // v1 * v2  - skalarnie
  cout << "Iloczyn skalarny v3 * v2 = " << v3 * v2 << endl;

  // v1 == v2
  if( v4 == v3 )
    cout << " v4 == v3 " << endl;
  else
    cout << " v4 != v3 " << endl;

  //v1 != v2
  if( v4 != v3 )
    cout << " v4 != v3 " << endl;
  else
    cout << " v4 == v3 " << endl;


  // x = v[1]
  double x = v3[ 1 ];
  cout << "x = v3[ 1 ] x = " << x << endl;

  // v[2] = 3;
  
  v2[ 0 ] += 4;
  cout << "v2[ 0 ] += 4 v2=" << v2 << endl;


  v5[ 1 ] = 2;
  cout << "v5[ 1 ] = 2 v5 = " << v5 << endl;
  
  v4[ 1 ] = v2[ 2 ] + v3[ 1 ];
  cout << "v4[ 1 ] = v2[ 2 ] + v3[ 1 ]  v4 = " << v4 << endl;

  // -----------------------------MATRIX----------------------------

  Matrix m1;
  Matrix m2( 3, 3, 1 );
  Matrix m3( 3, 3, 2 );
  cout << "m1 = \n " << m1 << endl;
  cout << "m2 = \n " << m2 << endl;
  cout << "m3 = \n " << m3 << endl;
  Vector* pVec = ( Vector* ) m3;
  cout << "pVec[1] = " << pVec[ 1 ] << endl;
  m1 = m2;
  cout << "m1 = m2 = \n " << m1 << endl;
  cout << "m1 == m2 :" << ( ( m1 == m2 ) ? 1 : 0 ) << endl;
 
  m3[ 0 ][ 1 ] = -2; m3[ 1 ][ 1 ] = -2; m3[ 2 ][ 1 ] = -2;
  cout << "m3 = \n " << m3 << endl;
  Vector w5( 3, 4 );
  cout << "m1 * w5 \n" << m1 * w5 << endl;
  m1 = m1 * m3;
  cout << " m1 * m3 \n" << m1 << endl;
  
  return 0;
}


