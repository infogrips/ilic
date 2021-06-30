@echo off
set grammar_dir=..\..\..\..\source\c\ilic\input\parser\grammar
set output_dir=..\..\..\..\source\c\ilic\input\parser\generated
copy /y %grammar_dir%\*.l4 %output_dir% >nul 2>nul
copy /y %grammar_dir%\*.g4 %output_dir% >nul 2>nul

echo *** IliFileLexer ***
call antlr4 -package lexer %output_dir%\IliFileLexer.l4
echo *** IliFileParser ***
call antlr4 -package parser -visitor -no-listener %output_dir%\IliFileParser.g4
echo ***

echo *** Ili1Lexer ***
call antlr4 -package lexer %output_dir%\Ili1Lexer.l4
echo *** Ili1Parser ***
call antlr4 -package parser -visitor -no-listener %output_dir%\Ili1Parser.g4
echo ***

echo *** Ili2Lexer ***
call antlr4 -package lexer %output_dir%\Ili2Lexer.l4
echo *** Ili2Parser ***
call antlr4 -package parser -visitor -no-listener %output_dir%\Ili2Parser.g4
echo ***

del /q %output_dir%\*.l4 >nul 2>nul
del /q %output_dir%\*.g4 >nul 2>nul
