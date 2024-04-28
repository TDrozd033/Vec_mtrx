#pragma once
#include <iostream>
#include <memory.h>
using namespace std;

class Vector
{
public: 
  // --- construction/destruction

  Vector( int nDim = 2, int nInitVal = 0 );
  Vector( const Vector& v );

  //destruktor
  virtual ~Vector();

  //=== operators
public:
  int getDim()const;

  //--assignment
  Vector& operator = ( const Vector& v ); // v = v1= v2


  // input/output
  friend istream& operator >>( istream& in, Vector& v ); // cin>> v;
  friend ostream& operator<<( ostream& out, const Vector& v ); // cout<< v;



  // -- addition
  friend const Vector operator + ( const Vector& v1, const Vector& v2 ); // v1 + v2
  friend const Vector operator + ( const Vector& v, double x ); //v1 + x
  friend const Vector operator + ( double x, const Vector& v ); //x + v1
  Vector& operator += ( const Vector& v ); //v1 += v2
  Vector& operator += ( double x );  //v1 += x
  


  // -- substraction

  friend const Vector operator - ( const Vector& v1, const Vector& v2 ); // v1 - v2
  friend const Vector operator - ( const Vector& v, double x ); //v1 - x
  
  Vector& operator -= ( const Vector& v ); //v1 -= v2
  Vector& operator -= ( double x );  //v1 -= x


  //--unary minus 

  friend const Vector operator - ( const Vector& v );

  //-- multiplication

  friend const Vector& operator * ( Vector& v, double x ); // v * x
  friend const Vector& operator * ( double x, Vector& v ); // x * v
  Vector& operator *= ( double x ); // v *= x

  // -- scalar multiplication

  friend double operator * ( const Vector& v1, const Vector& v2 ); // v1 * v2  - skalarnie


  // -- comparision 

  friend bool operator == ( const Vector& v1, const Vector& v2 ); // v1 == v2
  friend bool operator != ( const Vector& v1, const Vector& v2 ); //v1 != v2


  // indexation

  double& operator[]( int ix ); // v[2] = 3;

  const double& operator [] ( int ix ) const;// x = v[1]

  // -- cast ( rzutowanie )
  operator double* ( ) const;


private:

  void createVec( int nDim );
  void copyVec( const Vector& v );

private:
  double* m_pCoord; // vector coordinates
  int m_nDim; // vector dimension



};

//=================== INLINE FUNCTIONS

inline int Vector::getDim()const
{
  return m_nDim;

 }

// -- cast ( rzutowanie )
inline  Vector::operator double* ( ) const
{

  return m_pCoord;
 }

inline void Vector:: createVec( int nDim )
{
  if( nDim < 2 )
  {
    nDim = 2;
    cerr << "createVec invalid vector size\n";
  }
  m_nDim = nDim;
  m_pCoord = new (nothrow)double[nDim ];
  if( !m_pCoord )
  {
    cerr << " createVec: memory alocation error! \n";
  }

}

inline void Vector::copyVec( const Vector& v )
{
  //for( int i = 0; i < getDim(); i++ )
 // {                                        --- nieefektywne
 //   m_pCoord[ i ] = v.m_pCoord[ i ];
  //}

  memcpy( m_pCoord, ( double* ) v, getDim() * sizeof( double ) );

}


