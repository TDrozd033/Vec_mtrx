#include "Matrix.h"

Matrix::Matrix( int nRow, int nCol, double nInitVal )
{
  createMatrix( nRow, nCol );
  if( nCol != 2 || nInitVal != 0 )
  {
    for( int i = 0; i < nRow; i++ )
    {
      m_pVec[ i ] = Vector( nCol, nInitVal );
    }
  }
}


Matrix::Matrix( const Matrix& m )
{
  m_pVec = NULL;
  m_nRows = 0;
  *this = m; //wywoluje operator przypisania do skopiowania zaw macierzy  

}

//destruktor
Matrix:: ~Matrix()
{
  delete[] m_pVec;
}

Matrix& Matrix:: operator = (const Matrix& m)
{
  if (this->getColNo() != m.getColNo() || this->getRowNo() != m.getRowNo())
  {
    if (this->m_pVec)
    {
      delete[] m_pVec;
    }
    createMatrix(m.getRowNo(), m.getColNo());
  }
  copyMatrix(m);
  return *this;

}



istream& operator >> ( istream& in, Matrix& m )
{
  for( int i = 0; i < m.getRowNo(); i++ )
  {
    in >> m.m_pVec[ i ];

  }

  return in;
}



ostream& operator << ( ostream& out, const Matrix& m )
{
  for( int i = 0; i < m.getRowNo(); i++ )
  {
    out << m.m_pVec[ i ] << endl; // wyswietla kazdy wiersz 
  }
  return out;
}



Vector& Matrix:: operator[]( int ix )
{
  return m_pVec[ ix ];

}
const Vector& Matrix:: operator [] ( int ix ) const
{
  return m_pVec[ ix ];
}




bool operator == ( const Matrix& m1, const Matrix& m2 ) // m1 == m2
{
  if( m1.getColNo() != m2.getColNo() || m1.getRowNo() != m2.getRowNo() )
  {
    return false;
  }
  for( int i = 0; i < m1.getRowNo(); i++ )
  {
    if( m1.m_pVec[ i ] != m2.m_pVec[ i ] )
    {
      return false;
    }
  }
  return true;
}





bool operator != ( const Matrix& m1, const Matrix& m2 ) //m1 != m2
{
  if( m1.getColNo() != m2.getColNo() || m1.getRowNo() != m2.getRowNo() )
  {
    return true;
  }
  for( int i = 0; i < m1.getRowNo(); i++ ) 
  {
    if( m1.m_pVec[ i ] != m2.m_pVec[ i ] )
    {
      return true;
    }
  }
  return false;
}


const Matrix operator * ( const Matrix& m1, const Matrix& m2 ) // m1 * m2
{
  if( m1.getColNo() != m2.getRowNo() )
  {
    cerr << "Blad: niepoprawne wymiary" << endl;
    return 0;
  }
  Matrix res( m1.getRowNo(), m2.getColNo() );
  for( int i = 0; i < m1.getRowNo(); i++ )
  {
    for( int j = 0; j < m2.getColNo(); j++ )
    {
      for( int k = 0; k < m1.getColNo(); k++ )
      {
        res[ i ][ j ] += m1[ i ][ k ] * m2[ k ][ j ];
      }
    }
  }
  return res;


}

const Vector operator * ( const Matrix& m1, const Vector& v ) // m1 * v
{
  if( m1.getColNo() != v.getDim() ) {
    cerr << "Blad: niepoprawne wymiary" << endl;
    return 0;
  }
  Vector res( m1.getRowNo() );
  for( int i = 0; i < m1.getRowNo(); i++ )
  {
    res[ i ] = m1[ i ] * v;
  }
  return res;
}





