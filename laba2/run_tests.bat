@echo off
cls
call test_bat.bat 1 3 5
call test_bat.bat 2 
call test_bat.bat 3 5 3
call test_bat.bat 4 3 5
call test_bat.bat 5 3 5
call test_bat.bat 6 3 5
call test_bat.bat 7 3 5
call test_bat.bat 8 3 10
call test_bat.bat 9 3 6
call test_bat.bat 10 3 6
call test_bat.bat 11 5 6
call test_bat.bat 12 5 6
call test_bat.bat 13 5 6



:for %%i in (1) do call test_bat.bat %%i
