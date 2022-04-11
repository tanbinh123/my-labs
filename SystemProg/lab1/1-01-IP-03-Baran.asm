    .386
    .model flat, stdcall
    option casemap :none
    include \masm32\include\masm32rt.inc

    .data
    ; buffers   
	  buff_main DB 256 DUP (?)
	  plus_A_buff DB 32 DUP (?)
	  minus_A_buff DB 32 DUP (?)
	  plus_B_buff DB 32 DUP (?)
	  minus_B_buff DB 32 DUP (?)
	  plus_C_buff DB 32 DUP (?)
	  minus_C_buff DB 32 DUP (?)
	  plus_D_buff DB 64 DUP (?)
	  minus_D_buff DB 64 DUP (?)
	  plus_E_buff DB 64 DUP (?)
	  minus_E_buff DB 64 DUP (?)
	  plus_F_buff DB 64 DUP (?)
	  minus_F_buff DB 64 DUP (?)

    ; all A
        plus_A_byte DB 12
        minus_A_byte DB -12
        plus_A_two_byte DW 12
        minus_A_two_byte DW -12
        plus_A_four_byte DD 12
        minus_A_four_byte DD -12
        plus_A_eight_byte DQ 12
        minus_A_eight_byte DQ -12
    ; all B
        plus_B_two_byte DW 1207
        minus_B_two_byte DW -1207
        plus_B_four_byte DD 1207
        minus_B_four_byte DD -1207
        plus_B_eight_byte DQ 1207
        minus_B_eight_byte DQ -1207
    ; all C
        plus_C_four_byte DD 12072003
        minus_C_four_byte DD -12072003
        plus_C_eight_byte DQ 12072003
        minus_C_eight_byte DQ -12072003
    ; all D   
        plus_D_four_byte DD 0.026
        minus_D_four_byte DD -0.026
        plus_D_eight_byte DQ 0.026
        minus_D_eight_byte DQ -0.026
    ; all E
        plus_E_eight_byte DQ 2.627
        minus_E_eight_byte DQ -2.627
    ; all F
        plus_F_eight_byte DQ 26281.055
        minus_F_eight_byte DQ -26281.055
        plus_F_ten_byte DT 26281.055
        minus_F_ten_byte DT -26281.055

        date DB "12072003", 0	
        text_title DB "Lab1", 0
        text DB "Date: %s", 10, "   A = %s", 10, "  -A = %s", 10,
		                    "   B = %s", 10, "  -B = %s", 10,
		                    "   C = %s", 10, "  -C = %s", 10,
		                    "   D = %s", 10, "  -D = %s", 10,
		                    "   E = %s", 10, "  -E = %s", 10,
		                    "   F = %s", 10, "  -F = %s", 0
        conversion DB "%d", 0	
        
    .code 
        main:
        ; conversion int
            invoke wsprintf, addr plus_A_buff, addr conversion, plus_A_four_byte
	 	invoke wsprintf, addr minus_A_buff, addr conversion, minus_A_four_byte
	 	invoke wsprintf, addr plus_B_buff, addr conversion, plus_B_four_byte
		invoke wsprintf, addr minus_B_buff, addr conversion, minus_B_four_byte
	 	invoke wsprintf, addr plus_C_buff, addr conversion, plus_C_four_byte
	 	invoke wsprintf, addr minus_C_buff, addr conversion, minus_C_four_byte
        ; conversion float
		invoke FloatToStr2, plus_D_eight_byte, addr plus_D_buff
		invoke FloatToStr2, minus_D_eight_byte, addr minus_D_buff
		invoke FloatToStr, plus_E_eight_byte, addr plus_E_buff
		invoke FloatToStr, minus_E_eight_byte, addr minus_E_buff
		invoke FloatToStr2, plus_F_eight_byte, addr plus_F_buff
		invoke FloatToStr2, minus_F_eight_byte, addr minus_F_buff
        ; add to main buffer
		invoke wsprintf, addr buff_main, addr text, addr date,		
                             addr plus_A_buff, addr minus_A_buff, 
		                 addr plus_B_buff, addr minus_B_buff,
		                 addr plus_C_buff, addr minus_C_buff,
		                 addr plus_D_buff, addr minus_D_buff,
		                 addr plus_E_buff, addr minus_E_buff,
		                 addr plus_F_buff, addr minus_F_buff

		invoke MessageBox, 0, addr buff_main, addr text_title, 0
		invoke ExitProcess, 0
        end main