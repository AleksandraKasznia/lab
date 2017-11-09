#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s1,s2,s3;
  int p,w,i,j,k,n;

  // odczytujemy liczby do dodawania

  cin >> s1 >> s2;

  // obliczamy d³ugoœci ka¿dego z ³añcuchów

  i = s1.length();
  j = s2.length();

  // w n wyznaczamy d³ugoœæ najkrótszego ³añcucha

  n = i; if(j < i) n = j;

  // zerujemy przeniesienie oraz ³añcuch wynikowy

  p = 0;

  s3 = "";

  // sumujemy kolejne od koñca cyfry obu ³añcuchów

  for(k = 1; k <= n; k++)
  {
    w  = (int)(s1[--i]) + (int)(s2[--j]) + p - 96;
    p  = w / 10;
    s3 = (char)((w % 10) + 48) + s3;
  }

  // jeœli ³añcuch s1 ma jeszcze cyfry, to dodajemy do nich
  // przeniesienia i umieszczamy w ³añcuchu wynikowym

  while(i)
  {
    w  = s1[--i] + p - 48;
    p  = w / 10;
    s3 = (char)((w % 10) + 48) + s3;
  }

  // jeœli ³añcuch s2 ma jeszcze cyfry, to dodajemy do nich
  // przeniesienia i umieszczamy w ³añcuchu wynikowym

  while(j)
  {
    w  = s2[--j] + p - 48;
    p  = w / 10;
    s3 = (char)((w % 10) + 48) + s3;
  }

  // jeœli pozosta³o przeniesienie, to do³¹czamy je do cyfr
  // w ³añcuchu wynikowym

  if(p) s3 = (char)(p + 48) + s3;

  // jeœli w s3 nie ma cyfr, to wpisujemy tam 0

  if(s3 == "") s3 = "0";

  // wyœwietlamy wynik

  cout << s3 << endl;

}
