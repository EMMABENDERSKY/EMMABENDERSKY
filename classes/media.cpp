#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

media::media()
{
  title = new char[80];
  year = 0;
}

media::media(char* newTitle, int newYear)
{
  title = new char[80];
  strcpy(title, newTitle);
  year = newYear;
}

char* media::getTitle()
{
  return title;
}

int media::getYear()
{
  return year;
}

