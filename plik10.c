//autorzy: XYZ
#include <iostream>
#include <string>

using namespace std;

// Oblicza sumê podanych liczb
//----------------------------
string dodaj(string & x, string & y)
{
  string z;
  int p,w,i,j,k,n;

  i = x.length();
  j = y.length();

  n = i; if(j < i) n = j;

  p = 0;

  z = "";

  for(k = 1; k <= n; k++)
  {
    w  = (int)(x[--i]) + (int)(y[--j]) + p - 96;
    p  = w / 10;
    z = (char)((w % 10) + 48) + z;
  }

  while(i)
  {
    w  = x[--i] + p - 48;
    p  = w / 10;
    z = (char)((w % 10) + 48) + z;
  }

  while(j)
  {
    w  = y[--j] + p - 48;
    p  = w / 10;
    z = (char)((w % 10) + 48) + z;
  }

  if(p) z = (char)(p + 48) + z;

  if(z == "") z = "0";

  return z;  // zwracamy wynik dodawania
}

// Mno¿y du¿¹ liczbê a przez ma³¹ b
//---------------------------------
string mnoz_ab(string a, unsigned int b)
{
  string w;

  w = "0";           // zerujemy ³añcuch wyjœciowy

  while(true)        // wykonujemy mno¿enie
  {
    if(b & 1)   w = dodaj(w,a);
    if(b >>= 1) a = dodaj(a,a); else break;
  }

  return w;          // zwracamy wynik mno¿enia
}

// Mno¿y dwie du¿e liczby
//-----------------------
string mnoz(string & a, string & b)
{
  string c,w,z;
  int i;

  // mno¿ymy

  w = "0";

  z = "";

  for(i = b.length()-1; i >= 0; i--)
  {
    c = mnoz_ab(a,b[i]-48) + z;
    w = dodaj(w,c);
    z = z + "0";
  }

  return w;  // zwracamy wynik mno¿enia
}

//********************
//** PROGRAM G£ÓWNY **
//********************

int main()
{
  string a,w;
  unsigned int b;

  // odczytujemy dane

  cin >> a;  // du¿a liczba
  cin >> b;  // ma³a liczba

  // potêgujemy

  w = "1";

  while(true)
  {
    if(b & 1)   w = mnoz(w,a);
    if(b >>= 1) a = mnoz(a,a); else break;
  }

  // wypisujemy wynik

  cout << w << endl;

}
