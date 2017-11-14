///////////////////////////////////////////////////////////////////////////////////////
/// Copyright © Charalambos "Charis" Poullis, charalambos@poullis.org               ///
/// http://www.poullis.org                                                          ///
/// This work is under the Creative Commons Attribution-Noncommercial-Share         ///
/// Alike 3.0 United States License:                                                ///
/// http://creativecommons.org/licenses/by-nc-sa/3.0/us/                            ///
///////////////////////////////////////////////////////////////////////////////////////


///This is a robust OBJ loader based on LEX for lexical analysis and YACC for parsing.
///I initially wrote this because of the different variations of the OBJ files available
///some in binary, others in ascii, some with different formats for the faces etc.
///This parser reads the OBJ file and puts all information in the OBJ object. You can
///convert that information to your own structures. If it fails to recognize a particular
///command it will try and recover. If it fails again it will give a syntax error. As long
///as the format conforms to the OBJ file format as set by the Alias Wavefront it will work.

///If you find any problems or make improvements please let me know by sending an email to
///charalambos@poullis.org.

///Well, I hope this is helpful to you!


///Flex compiled using:
///flex --header-file=OBJParser.lex.h -o OBJParser.lex.cpp scanner.l

///Yacc compiled using:
///bison -o OBJParser.yacc.cpp -d parser.y

#include <fstream>
#include <iostream>

#include "OBJParser.h"
#include "OBJParser.lex.h"
#include "OBJParser.yacc.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	
	std::string file_name;
    //get the filename
    std::cout << "Enter the OBJ file name: ";
    std::cin >> file_name;

    ///Read in all the contents of the file
    std::ifstream ifs(file_name);
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                         (std::istreambuf_iterator<char>()    ) );

    //If you want to debug through the code you can pass the data as a string
    //and the parser will parse the string instead of the file like below:
    //YY_BUFFER_STATE buf = OBJParser_scan_string("v 1.0 1.0 1.0\n");

    //Otherwise set the file pointer as the input stream to the parser
    //Set the stream as the input to the parser
    YY_BUFFER_STATE buf = OBJParser_scan_string(content.c_str());

    ///initialize the OBJ
    obj_model = new OBJ();

    ///If you would like to run only the scanner then uncomment the following command
//    OBJParserlex();

    ///This runs the parser
    OBJParserparse();

    ///Clean up
    OBJParser_delete_buffer(buf);
    OBJParserlex_destroy();

	//Show what you got. This is for debugging.
	printf("<------- PRINTING OUT ---------->\n");
	obj_model->Print();
	printf("<------------------------------->\n");

	//cleanup
	delete obj_model;

  	return EXIT_SUCCESS;
}
