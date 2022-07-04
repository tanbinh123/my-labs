@echo on

\masm32\bin\ml /c /coff "7-01-IP-03-Baran.asm" "7-01-IP-03-Baran-denominator.asm"
\masm32\bin\link /subsystem:windows "7-01-IP-03-Baran.obj" "7-01-IP-03-Baran-denominator.obj"