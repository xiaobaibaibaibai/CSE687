Rem the path of browser 
set browserPath="c:/Program Files (x86)/Google/Chrome/Application/chrome.exe" 

Rem the path of directory of loaded files 
set loadedFileLocation=../unconvertedPages

Rem this patterns are only used to search hearders and cpp file.
set basicPattern= *.cpp *.h

cd .\Debug\
start Executive.exe %browserPath% %loadedFileLocation% %basicPattern%
cd ..