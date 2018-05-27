# Project 01

The goal of this project is to parse different structures of .xml files and capture some of it's information.

How it was solved:


Firstly, the .xml file is parsed with a lexical/syntactic analyzer (implemented in LEX/YACC and C). Then, the parsed fields are piped to another program (implemented in Java) that searches for the desired information. To finish the process, the output of the latter program is piped to another program (implemented in Python) that correlates some of the information with a .csv database and prints out the result.
