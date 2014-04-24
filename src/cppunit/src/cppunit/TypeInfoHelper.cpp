#include <string>

#include "TypeInfoHelper.h"


namespace CppUnit {

std::string 
TypeInfoHelper::getClassName( const std::type_info &info )
{
  static std::string classPrefix( "class " );

  std::string name( info.name() );
  if ( name.compare( 0, classPrefix.length(), classPrefix ) == 0 )
    return name.substr( classPrefix.length() );
  return name;
}


} //  namespace CppUnit