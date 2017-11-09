#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s1,s2,s3;
  int p,w,i,j,k,n;

  // odczytujemy liczby do dodawania

  cin >> s1 >> s2;

  // obliczamy d�ugo�ci ka�dego z �a�cuch�w

  i = s1.length();
  j = s2.length();

  // w n wyznaczamy d�ugo�� najkr�tszego �a�cucha

  n = i; if(j < i) n = j;

  // zerujemy przeniesienie oraz �a�cuch wynikowy

  p = 0;

  s3 = "";

  // sumujemy kolejne od ko�ca cyfry obu �a�cuch�w

  for(k = 1; k <= n; k++)
  {
    w  = (int)(s1[--i]) + (int)(s2[--j]) + p - 96;
    p  = w / 10;
    s3 = (char)((w % 10) + 48) + s3;
  }

  // je�li �a�cuch s1 ma jeszcze cyfry, to dodajemy do nich
  // przeniesienia i umieszczamy w �a�cuchu wynikowym

  while(i)
  {
    w  = s1[--i] + p - 48;
    p  = w / 10;
    s3 = (char)((w % 10) + 48) + s3;
  }

  // je�li �a�cuch s2 ma jeszcze cyfry, to dodajemy do nich
  // przeniesienia i umieszczamy w �a�cuchu wynikowym

  while(j)
  {
    w  = s2[--j] + p - 48;
    p  = w / 10;
    s3 = (char)((w % 10) + 48) + s3;
  }

  // je�li pozosta�o przeniesienie, to do��czamy je do cyfr
  // w �a�cuchu wynikowym

  if(p) s3 = (char)(p + 48) + s3;

  // je�li w s3 nie ma cyfr, to wpisujemy tam 0

  if(s3 == "") s3 = "0";

  // wy�wietlamy wynik

  cout << s3 << endl;

}
