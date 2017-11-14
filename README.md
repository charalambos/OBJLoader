# OBJParser

A robust OBJParser using a Lexical Analyzer and Parser
Charalambos Poullis

This is a robust OBJ loader based on LEX for lexical analysis and YACC for parsing. I
initially wrote this because of the different variations of the OBJ files available some in
binary, others in ascii, some with different formats for the faces etc. This parser reads the
OBJ file and puts all information in the OBJ object. You can convert that information to
your own structures. If it fails to recognize a particular command it will try and recover. If
it fails again it will give a syntax error. As long as the format conforms to the OBJ file
format as set forth by Alias Wavefront the OBJParser will work as expected.


IMPORTANT: If you use this software, YOU MUST CITE the following in any
resulting publication/software:

@article{2017_POULLIS_OBJPARSER,
  title={A robust OBJParser using Customized Lexical Analyzer and Parser},
  author={Poullis, Charalambos},
  journal={Immersive and Creative Technologies Lab, Technical Report 02, 2017 -
  ICT-TR-2017-02},
  year={2017}
}

Dependencies:
-Eigen3
-Flex (lexical analyzer)
-Bison (parser)
