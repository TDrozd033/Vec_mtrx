#pragma once
#include <iostream>
#include <memory.h>
#include "Vector.h"


using namespace std;
/*
Napisac klase matrix

- reprezentacja to tablica wektorow ( dynamiczna)
 - konstruktor - macierz 2 na 2 zainicjonowana zerami ( domyslnie)
 - konstruktor kopiujacy
 - operator =
 - gettery ( getColNo(), getRowNo() )
 - operatory we/wy
 - operatory indeksowania ( analogicznie do wektora )
 - operator rzutowania na wsakznik do wektora ( zwraca wskaznik do tablicy wektroro )
  - operatory == i !=
 - mnozenie macierzy
 - mnozenie macierzy przez wektor
*/

class Matrix
{
public:
  // --- construction/destruction
  Matrix( int nRow = 2, int nCol = 2, double nInitVal = 0 );
  Matrix( const Matrix& m );

  //destruktor
  virtual ~Matrix();

  //=== operators
public:
  int getColNo()const;
  int getRowNo()const;


  //--assignment
  Matrix& operator = ( const Matrix& m ); 

  
  // input/output
  friend istream& operator >> ( istream& in, Matrix& m );
  friend ostream& operator << ( ostream& out, const Matrix& m );

  // operatory indeksowania

  Vector& operator[]( int ix ); 
  const Vector& operator [] ( int ix ) const;

  // operator rzutowania na wskaznik do wektora

  operator Vector* ()const;

 // operatory == i !=

  friend bool operator == ( const Matrix& m1, const Matrix& m2 ); // m1 == m2
  friend bool operator != ( const Matrix& m1, const Matrix& m2 ); //m1 != m2

  
  //-mnozenie macierzy
  //  - mnozenie macierzy przez wektor

  friend const Matrix operator * ( const Matrix& m1, const Matrix& m2 ); // m1 * m2
  friend const Vector operator * ( const Matrix& m1, const Vector& v ); // m1 * v



private:

  void createMatrix( int nRow, int nCol );
  void copyMatrix( const Matrix& m );

private:

  int m_nRows; 
  Vector* m_pVec;

};



//=================== INLINE FUNCTIONS


inline int Matrix::getColNo()const
{
  return (m_pVec)? m_pVec[0].getDim() : 0;

}
inline int Matrix::getRowNo()const
{
  return m_nRows;

}


inline  Matrix::operator Vector* ( ) const
{

  return ( Vector* ) m_pVec;
}





inline void Matrix::createMatrix(int nRow, int nCol)
{
  if (nRow < 2 || nCol < 2)
  {
    cerr << " Zle rozmiary macierzy\n";
    m_nRows = 2;
    m_pVec = NULL;
    return;
  }

  m_nRows = nRow;
  m_pVec = new (nothrow) Vector[m_nRows]; // alokacja dla macierzy 

  if (!m_pVec)
  {
    cerr << " CreateMatrix: Blad podczas alokacji pamieci " << endl;
    m_nRows = 0;
    m_pVec = NULL;
    return;
  }
}


inline void Matrix::copyMatrix(const Matrix& m)
{
  // sprawdzamy czy wymairy macierzy sa rozne od obecnych 
  if (m_pVec->getDim() != m.getColNo() || m_nRows != m.m_nRows) {
    if (m_pVec != NULL)
      delete[] m_pVec;
    createMatrix(m.m_nRows, m.getColNo()); // tworzymy nowa macierz o dobrych wymairach - macierzy tej poczatkowaj 
  }
  for (int i = 0; i < getRowNo(); ++i) // kopiuje zawartosc macieryz poczatkowej do biezacej 
  {
    m_pVec[i] = m.m_pVec[i];
  }
}




