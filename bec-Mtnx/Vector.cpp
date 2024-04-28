#include "Vector.h"


//// konstruktor: tworzy wektor o zadanych wymiarach (nDim) i inicjalizuje go wartoscia poczatkowa
Vector::Vector( int nDim /*= 2*/, int nInitVal /*= 0 */)
{
  createVec( nDim );
  for( int i = 0; i < nDim; i++ )
  {
    m_pCoord[ i ] = nInitVal;
  }

}


// konstruktor kopiuj¹cy: tworzy kopie istniejacego wektora
Vector::Vector( const Vector& v )
{
  m_nDim = 0;
  m_pCoord = NULL; // nukllptr
  *this = v;

}

// destruktor: zwalnia pamiec zaalokowana na przechowywanie wsp wektora
Vector::~Vector()
{
  delete[] m_pCoord; // [] !!!

}

// operator przypisania: przypisuje wart wektora v do obecnego obiektu
Vector& Vector:: operator = ( const Vector& v )// v = v1= v2
{
  if( this->getDim() != v.getDim() )
  {
    if( m_pCoord )
    {
      delete[] m_pCoord; // moze byc bez tego ifa i bedzie dzialac

    }
    createVec( v.getDim() );
  }
  copyVec( v );
  return *this;
 }

//wczytuje wsp wektora ze strumienia
istream& operator >>( istream& in, Vector& v ) // cin>> v;
{
  for( int i = 0; i < v.getDim(); i++ )
  {
    in >> v.m_pCoord[ i ];
    

  }
  /*
  double x;

  for( int i = 0; i < v.getDim(); i++ ) {
    in >> x;
    v.m_pCoord[ i ] = x;
  }*/
  return in;
}

//wypisuje wsp wektora do strumienia 
ostream& operator<<( ostream& out, const Vector& v ) // cout<< v;
{
  out << '[';
  for( int i = 0; i < v.getDim(); i++ )
  {
    out << v.m_pCoord[ i ] << ( ( i < v.getDim() - 1 ) ? "," : "" );
  }
  out << ']';
  return out;
}

// nowy wektor suma dwoch wektorow
const Vector operator + ( const Vector& v1, const Vector& v2 ) // v1 + v2
{
  Vector res( v1 );
  return res += v2;
 }

// nowy wektor ktory jest wynikiem dodawania liczby do wektora 
const Vector operator + ( const Vector& v, double x ) //v1 + x
{
  Vector res( v );
  return res += x;
 }


const Vector operator + ( double x, const Vector& v ) //x + v1
{
  return v + x; // korzystamy z operatora + ktory zdefiniowalismy wczesniej
 }


Vector& Vector:: operator += ( const Vector& v ) //v1 += v2
{
  if( this->getDim() != v.getDim() )
  {
    cerr << " +=; incompatible vector sizes\n";
    return *this;
  }
  for( int i = 0; i < getDim(); i++ )
  {
    m_pCoord[ i ] += v.m_pCoord[ i ];
  }
  return *this;
}

Vector& Vector:: operator += ( double x )  //v1 += x
{
  for( int i = 0; i < getDim(); i++ )
  {
    m_pCoord[ i ] += x;
  }
  return *this;
}

const Vector operator - ( const Vector& v1, const Vector& v2 ) // v1 - v2
{
  Vector res( v1 );
  return res -= v2;

}
const Vector operator - ( const Vector& v, double x ) //v1 - x
{
  Vector res( v );
  return res -= x;

}

Vector& Vector::operator -= ( const Vector& v ) //v1 -= v2
{
  if( this->getDim() != v.getDim() )
  {
    cerr << "-=; incompatible vector sizes\n";
    return *this;

  }

  for( int i = 0; i < getDim(); i++ )
  {
    m_pCoord[ i ] -= v.m_pCoord[ i ];
  }
  return *this;
}


Vector& Vector::operator -= ( double x )  //v1 -= x
{
  for( int i = 0; i < getDim(); i++ )
  {
    m_pCoord[ i ] -= x;
  }
  return *this;
}




const Vector& operator * ( Vector& v, double x ) // v * x
{
  Vector res( v );
  return v *= x;
}
const Vector& operator * ( double x, Vector& v ) // x * v
{
  Vector res( v );
  return v *= x;
}

Vector& Vector::operator *= ( double x ) // v *= x
{
  for( int i = 0; i < getDim(); i++ )
  {
    m_pCoord[ i ] *= x;
  }
  return *this;
}


const Vector operator - ( const Vector& v )
{
  Vector res( v );
  for( int i = 0; i < v.getDim(); i++ )
  {
    res.m_pCoord[ i ] = -v.m_pCoord[ i ];
  }
  return res;

}

double operator * ( const Vector& v1, const Vector& v2 ) // v1 * v2  - skalarnie
{
  if( v1.getDim() != v2.getDim() ) {
    std::cerr << "operator: invalid vector sizes\n";
    return 0.0;
  }
  double res = 0.0;
  for( int i = 0; i < v1.getDim(); i++ )
    res += v1.m_pCoord[ i ] * v2.m_pCoord[ i ];
  return res;
}


bool operator == ( const Vector& v1, const Vector& v2 ) // v1 == v2
{
  if( v1.getDim() != v2.getDim())
  {
    return false;
  }
  for( int i = 0; i < v1.getDim(); i++ )
  {
    if( v1.m_pCoord[ i ] != v2.m_pCoord[ i ] )
    {
      return false;
    }
  }
  return true;
}



bool operator != ( const Vector& v1, const Vector& v2 ) //v1 != v2
{
  if( v1.getDim() != v2.getDim() )
  {
    return false;
  }

  for( int i = 0; i < v1.getDim(); i++ )
  {
    if( v1.m_pCoord[ i ] != v2.m_pCoord[ i ] )
    {
      return true;
    }
  }
  return false;
}




double& Vector::operator[]( int ix ) // v[2] = 3;
{
  return m_pCoord[ ix ];
}

const double& Vector:: operator [] ( int ix ) const  // x = v[1]
{
  return m_pCoord[ ix ];
}



















