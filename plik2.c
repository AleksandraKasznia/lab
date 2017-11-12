#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
//pisze nowy komentarz
using namespace std;

const int N = 40; // d³ugoœæ ³añcucha s

int main()
{
  string s;
  int i,j,k,iP,iL;
  bool t;

// generujemy ³añcuch s

  srand((unsigned)time(NULL));
  s = "";
  for(i = 0; i < N; i++) s += char(65 + rand() % 4);

// wypisujemy ³añcuch s

  cout << s << endl;

// szukamy palindromów

  for(i = 0; i < N - 1; i++)
    for(j = i + 2; j <= N; j++)
    {
      iL = i; iP = j - 1; t = true;
      while(iL < iP)
        if(s[iL++] != s[iP--])
        {
          t = false; break;
        }
      if(t)
      {
        for(k = 0; k < i; k++) cout << " ";
        cout << s.substr(i,j-i) << endl;
      }
    }
  cout << endl;
  return 0;
}
