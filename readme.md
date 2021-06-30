# ilic - INTERLIS Compiler
Checks syntactical correctness of [INTERLIS](https://www.interlis.ch) data models. 
ilic can generate output in several formats (.log, .imd, .ili, .xsd, .gml).

## License
ilic is free software. Source files and binaries can be copdied, changed, integrated in other software (commercial or non commercial) without any restrictions. On foreign libraries contained in /lib folder restrictions my apply.

## System Requirements
To run ilic a PC with Windows 7 or higher (32bit or 64bit) is required. Prebuilt Windows binaries can be
downloaded from https://www.infogrips.ch/de/support/produkt-download.

## Installation

In order to install ilic, extract the .zip file into a directory.

## Usage

Read the [help](./doc/help.txt) file for more information on ilic command line options. For information on the newest version consult the [changelog](./doc/changelog.txt).

## How to build it?

To compile the c++ source files you will need Visual Studio 2019 community edition. A preconfigured project file for VS can be found in /build/vc2019. If you need to modify the ANTLR4 grammar files in folder /source/input/parser/grammar, you have to generate c++ source from ANTLR4 files first. To do this, a batch file is included in /build/tools. As ANTLR4 is a Java based utility a Java Runtime or JDK must be installed on the development machine.
