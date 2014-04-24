#include "cppunit/TestSuite.h"
#include "cppunit/TestResult.h"
#include "TypeInfoHelper.h"

namespace CppUnit {

/// Deletes all tests in the suite.
void TestSuite::deleteContents ()
{
  for (std::vector<Test *>::iterator it = m_tests.begin ();
       it != m_tests.end ();
       ++it)
    delete *it;
  m_tests.clear();
}


/// Runs the tests and collects their result in a TestResult.
void TestSuite::run (TestResult *result)
{
    for (std::vector<Test *>::iterator it = m_tests.begin ();
            it != m_tests.end ();
            ++it) {
        if (result->shouldStop ())
            break;

        Test *test = *it;
        test->run (result);
    }

}


/// Counts the number of test cases that will be run by this test.
int TestSuite::countTestCases () const
{
    int count = 0;

    for (std::vector<Test *>::const_iterator it = m_tests.begin ();
            it != m_tests.end ();
            ++it)
        count += (*it)->countTestCases ();

    return count;

}



/// Default constructor
TestSuite::TestSuite (std::string name)
  : m_name (name)
{
}

/** Constructs a test suite named after the specified type_info.
 * \param info type_info used to name the suite. The 'class' prefix
 *             is stripped from the name.
 */
TestSuite::TestSuite(const std::type_info &info ) :
  m_name( getClassName( info ) )
{
}



/// Destructor
TestSuite::~TestSuite ()
{ 
  deleteContents (); 
}


/// Adds a test to the suite. 
void 
  TestSuite::addTest (Test *test)
{ 
  m_tests.push_back (test); 
}


/// Returns a string representation of the test suite.
std::string 
  TestSuite::toString () const
{ 
  return "suite " + getName(); 
}

/// Returns the name of the test suite.
std::string 
  TestSuite::getName () const
{ 
  return m_name; 
}


/** Returns the class name of the specified type_info.
 * \param info Info which the class name is extracted from.
 * \return The string returned by type_info::name() without
 *         the "class" prefix. If the name is not prefixed
 *         by "class", it is returned as this.
 */
std::string 
  TestSuite::getClassName( const std::type_info &info )
{
  return TypeInfoHelper::getClassName( info );
}


void                
  TestSuite::getTests( std::vector<Test *> &tests ) const
{
  tests.insert( tests.end(), m_tests.begin(), m_tests.end() );
}



} // namespace CppUnit

