// C++Weekly.cpp : Defines the entry point for the console application.
//

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <typeinfo>
#include <exception>
#include <cxxabi.h>
#include <experimental/any>

////////////////
// C++ Weekly #9
// /////////////
struct MyClass
{
  std::vector< std::list< std::pair< std::string, std::string > > > m_data;
};

std::string demangle( const char* mangled_name )
{
  int status;
  char* demangled_name = abi::__cxa_demangle( mangled_name, nullptr, 0, &status );
  if( status == 0 )
  {
    std::string retval( demangled_name );
    free( demangled_name );
    std::cout << "Retval = " << retval << "\n";
    return retval;
  }
  else
  {
     throw std::runtime_error("Demangling error");
  }
}


int main(int argc, char *argv[])
{
  std::cout << demangle( typeid( &MyClass::m_data ).name() ) << "\n";
}

