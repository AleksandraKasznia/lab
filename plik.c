//autorzy: XYZ
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;
//dodany komentarz
int main()
{
  const int M = 20; // d�ugo�� �a�cucha s
  string s;
  int i,j,n;

// generujemy �a�cuch s

  srand((unsigned)time(NULL));
  s = "";
  for(i = 0; i < M; i++)
    s += char(65 + rand() % 2);

// wypisujemy �a�cuch s

  cout << s << endl;

// szukamy s��w podw�jnych

  for(i = 0; i < M - 1; i++)
    for(n = 2; i + n <= M; n += 2)
    {
      j = i + n / 2;
      if(s.substr(i,j-i) == s.substr(j,j-i))
      {
        for(j = 0; j < i; j++) cout << " ";
        cout << s.substr(i,n) << endl;
      }
    }
  cout << endl;
  return 0;
}
