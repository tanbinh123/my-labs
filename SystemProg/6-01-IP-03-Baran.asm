 .386
        include \masm32\include\masm32rt.inc
        includelib \masm32\lib\user32.lib 
    .data
        a_arr DQ 8.25, -31.16, 7.9, -24.2356, 4.0
        b_arr DQ 3.8, 391.2, -6.66, 13.13, 8.88
        c_arr DQ 0.75, -38.3, 1.23, -36.51, 0.5
        d_arr DQ 9.456, 1.532, 11.7, -6.2, 7.77

; Buffers
	  buff_main  DB 1024 DUP (?)
        buff_tail  DB 256 DUP (?)

        buff_numer DQ 64 DUP (?)
        buff_denom DQ 64 DUP (?)
        buff_res   DQ 64 DUP (?)
        buff_a     DQ 64 DUP (?)
        buff_b     DQ 64 DUP (?)
        buff_c     DQ 64 DUP (?)
        buff_d     DQ 64 DUP (?)
        
; Numbers for exspression
        n1 DQ 2.0
        n2 DQ 23.0
        n3 DQ 4.0
        n4 DQ 1.0

; Variables
        number      DD 1
        
        numerator   DQ 0
        denominator DQ 0
        res         DQ 0

        text_title     DB "6-01-IP-03-Baran", 0
	  text_formating DB "%d.", 13, "(2 * %s - %s + sqrt(23 * %s))/(%s / 4 - 1)%s", 0
        text_normal    DB " =", 13, " %s/%s = %s", 0
        text_zeroErr   DB " = %s/%s", 13, "0 in the denominator is invalid", 0
        text_sqrtErr   DB 13, "square root must be more then 0", 0
    .code 
Start: 
    mov edi, 0

@calculation:
; Numerator:
; 2 * c - d
    finit
    fld c_arr[edi * 8]
    fmul n1
    fsub d_arr[edi * 8]
    
; sqrt(23 * b)
    fld b_arr[edi * 8]
    fmul n2
    fsqrt 

; Check is sqrt root larger 0
    fcom st(1)			
    fstsw ax
    sahf
    jb @sqrtErr
    fadd ; if square root more then 0 - calc numerator
    fst numerator 

; Denominator:
    finit
    fld a_arr[edi * 8]
    fdiv n3
    fsub n4
    fst denominator

; Check is denominator equal 0
    ftst
    fstsw ax 
    sahf
    je @zeroErr

; Result
    fld numerator
    fdiv denominator
    fstp res
    jmp @normal

@zeroErr:
    invoke FloatToStr, numerator, addr buff_numer
    invoke FloatToStr, denominator, addr buff_denom

    invoke wsprintfA, addr buff_tail, addr text_zeroErr, addr buff_numer, addr buff_denom
    jmp @formating

@sqrtErr:
    invoke wsprintfA, addr buff_tail, addr text_sqrtErr
    jmp @formating

@normal:
    invoke FloatToStr, numerator, addr buff_numer
    invoke FloatToStr, denominator, addr buff_denom
    invoke FloatToStr, res, addr buff_res
    invoke wsprintfA, addr buff_tail, addr text_normal, addr buff_numer, 
                                                addr buff_denom, addr buff_res

@formating:                                                      
    invoke FloatToStr, a_arr[edi * 8], addr buff_a
    invoke FloatToStr, b_arr[edi * 8], addr buff_b
    invoke FloatToStr, c_arr[edi * 8], addr buff_c
    invoke FloatToStr, d_arr[edi * 8], addr buff_d
    invoke wsprintfA, addr buff_main, addr text_formating, number, 
                                           addr buff_c, addr buff_d, addr buff_b,
                                           addr buff_a, addr buff_tail                                   
                                      
    invoke MessageBoxA, NULL, addr buff_main, addr text_title, MB_OK
            
    add edi, 1
    add number, 1

    cmp edi, 5
    jne @calculation
end Start
                                             