#include "cppunit/TestRegistry.h"
#include "cppunit/TextTestResult.h"
#include "cppunit/TestSuite.h"
#include "cppunit/Test.h"

#include "BoardGame.h"
#include "Chess.h"

#include "BoardGameTest.h"
#include "ChessTest.h"


#include <vector>
#include <iostream>

BoardGameTest<BoardGame> bgt("BoardGameTest<BoardGame>");
ChessTest<Chess> ct("ChessTest<Chess>");


int 
main(int argc, char** argv)
{
  CppUnit::TestSuite suite;
  bgt.registerTests(&suite);
  ct.registerTests(&suite);

  CppUnit::TextTestResult res;
  suite.run( &res );

  std::cout << res << std::endl;
  
  return 0;
}
