@echo off
echo Removing ./build
del /F /S /Q build
echo Making ./build
mkdir build
echo Building module into ./build
call pip install --upgrade --prefix=build --ignore-installed .
echo entering ./doc
cd doc
echo calling make.bat html...
call make.bat clean
call make.bat html
echo done!
