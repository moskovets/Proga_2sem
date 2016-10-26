@echo off
main_prog.exe  test%1.txt out.txt %2 %3 > out_inf.txt 
fc out%1.txt out.txt
fc out_inf%1.txt out_inf.txt

pause