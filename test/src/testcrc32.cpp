//  Boost CRC example program file  ------------------------------------------//

//  Copyright 2003 Daryle Walker.  Use, modification, and distribution are
//  subject to the Boost Software License, Version 1.0.  (See accompanying file
//  LICENSE_1_0.txt or a copy at <http://www.boost.org/LICENSE_1_0.txt>.)

//  See <http://www.boost.org/libs/crc/> for the library's home page.

//  Revision History
//  17 Jun 2003  Initial version (Daryle Walker)

#include <boost/crc.hpp>  // for boost::crc_32_type

#include <cstdlib>    // for EXIT_SUCCESS, EXIT_FAILURE
#include <exception>  // for std::exception
#include <fstream>    // for std::ifstream
#include <ios>        // for std::ios_base, etc.
#include <iostream>   // for std::cerr, std::cout
#include <ostream>    // for std::endl


// Redefine this to change to processing buffer size
#ifndef PRIVATE_BUFFER_SIZE
#define PRIVATE_BUFFER_SIZE  1024
#endif

// Global objects
std::streamsize const  buffer_size = PRIVATE_BUFFER_SIZE;


// Main program
int
main
(
    int           argc,
    char const *  argv[]
)
try
{
    boost::crc_32_type  result1;
    boost::crc_32_type  result2;

//    for ( int i = 1 ; i < argc ; ++i )
//    {
        std::ifstream  ifs1( argv[1], std::ios_base::binary );
        std::ifstream  ifs2( argv[2], std::ios_base::binary );

        if ( ifs1 )
        {
            do
            {
                char  buffer1[ buffer_size ];

                ifs1.read( buffer1, buffer_size );
                result1.process_bytes( buffer1, ifs1.gcount() );
            } while ( ifs1 );
        }
        else
        {
            std::cerr << "Failed to open file '" << argv[1] << "'."
             << std::endl;
        }
        if ( ifs2 )
        {
            do
            {
                char  buffer2[ buffer_size ];

                ifs2.read( buffer2, buffer_size );
                result2.process_bytes( buffer2, ifs2.gcount() );
            } while ( ifs2 );
        }
        else
        {
            std::cerr << "Failed to open file '" << argv[2] << "'."
             << std::endl;
        }
//     }

//    std::cout << std::hex << std::uppercase << result.checksum() << std::endl;
    if (result1.checksum() == result2.checksum())
    {
	return EXIT_SUCCESS;
    }
    else
    {
	return EXIT_FAILURE;
    }
}
catch ( std::exception &e )
{
    std::cerr << "Found an exception with '" << e.what() << "'." << std::endl;
    return EXIT_FAILURE;
}
catch ( ... )
{
    std::cerr << "Found an unknown exception." << std::endl;
    return EXIT_FAILURE;
}
