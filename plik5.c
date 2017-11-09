#include <iostream>
#include <string>

using namespace std;

int main()
{
  string s;
  int i;
  unsigned long long X,a,m,c;

// definiujemy generator LCG

  m = 3956280000ull;
  a = 1978141ull;
  c = 1309ull;

// odczytujemy klucz i wiersz znaków

  cin >> X; cin.ignore(256,'\n');
  getline(cin,s);

// szyfrujemy

  for(i = 0; i < s.length(); i++)
  {

// obliczamy kolejn¹ liczbê pseudolosow¹

    X = (a * X + c) % m;

// szyfrujemy literkê

    s[i] = toupper(s[i]);
    if((s[i] >= 'A') && (s[i] <= 'Z')) s[i] = 65 + (s[i] - 65 + X % 26) % 26;
  }

// wypisujemy zaszyfrowany tekst

  cout << s << endl << endl;
  return 0;
}
