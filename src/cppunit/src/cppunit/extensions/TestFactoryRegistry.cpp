#if _MSC_VER > 1000     // VC++
#pragma once
#pragma warning( disable : 4786 )   // disable warning debug symbol > 255...
#endif // _MSC_VER > 1000

#include <utility>
#include "cppunit/TestSuite.h"
#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/extensions/TestSuiteBuilder.h"
#include "../TypeInfoHelper.h"


namespace CppUnit {

TestFactoryRegistry::TestFactoryRegistry( std::string name ) :
    m_name( name )
{
}


TestFactoryRegistry::~TestFactoryRegistry()
{
}


TestFactoryRegistry &
TestFactoryRegistry::getRegistry()
{
  static TestFactoryRegistry registry;
  return registry;
}


TestFactoryRegistry &
TestFactoryRegistry::getRegistry( const std::string &name )
{
  static NamedRegistries registries;

  TestFactoryRegistryPtr &registryPointer = registries[ name ];
  if ( !registryPointer.get() )
  {
    TestFactoryRegistry *registry = new TestFactoryRegistry( name );
    registryPointer = TestFactoryRegistryPtr( registry );
  }

  return *registryPointer.get();
}


void 
TestFactoryRegistry::registerFactory( const std::string &name,
                                      AbstractTestFactory *factory )
{
  AbstractTestFactoryPtr factoryPointer( factory );
  m_factories.insert( std::make_pair( name, factoryPointer ) );
}


void 
TestFactoryRegistry::registerFactory( AbstractTestFactory *factory )
{
  std::string name = TypeInfoHelper::getClassName( typeid( *factory ) );
  registerFactory( name, factory );
}


Test *
TestFactoryRegistry::makeTest()
{
  TestSuite *suite = new TestSuite( "All Tests" );
  addTestToSuite( suite );
  return suite;
}


void 
TestFactoryRegistry::addTestToSuite( TestSuite *suite )
{
  for ( Factories::iterator it = m_factories.begin(); 
        it != m_factories.end(); 
        ++it )
  {
    AbstractTestFactory *factory = (*it).second.get();
    suite->addTest( factory->makeTest() );
  }
}


}  // namespace CppUnit
