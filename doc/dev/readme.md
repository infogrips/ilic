# ilic Developer Documentation

## Introduction
Welcome to the ilic developer documentation. ilic is an INTERLIS compiler written in c++. 
ilic was completely built from scratch, this is no c++ port of the 
[Java INTERLIS compiler](https://github.com/claeis/ili2c).

## Project Goals
+ fast INTERLIS compiler without any runtime or installation requirements (exept OS)
+ one single executable
+ standard c++ without external libraries or frameworks (except ANTLR for parse tree generation)
+ reusable ANTLR grammars without embedded c++ code
+ simple and easy to extend source code
+ documented api for developers
+ supported input formats: INTERLIS 2.3 and 2.4
+ supported output formats: INTERLIS 2.3 and 2.4, imd, xsd, gml

## How to build ilic?
Unpack the "Debug Static" libraries in \lib\antlr4\bin\win first. To compile the c++ source files 
you will need Visual Studio 2019 community edition (VS). A preconfigured project file for VS 
can be found in /build/vc2019. If you need to modify the ANTLR4 grammar files in folder 
/source/input/parser/grammar, you have to generate c++ source from ANTLR4 definition files 
first. To do this, use the batch file /build/scripts/a.bat. As ANTLR4 is a Java based utility 
a Java Runtime or JDK must be present on the development machine (java.exe has to 
work from the command line).

## Additional Information
+ [coding conventions](./codingconventions.md)
+ [output module api](./output_api.md)
