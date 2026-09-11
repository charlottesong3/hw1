#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr crankdat;

  crankdat.push_back("1");
  crankdat.push_front("10");
  crankdat.push_back("25");
  

  cout<< crankdat.get(0) << " " << crankdat.get(1) << " " << crankdat.get(2) <<  endl;


}
