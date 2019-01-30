Rem the path of directory of loaded files 
set loadedFileLocation=../inputFile 

Rem this patterns are only used to search hearders and cpp file.
set basicPattern= *.cpp *.h

cd .\Debug\
start Executive.exe %loadedFileLocation% %basicPattern%
cd ..