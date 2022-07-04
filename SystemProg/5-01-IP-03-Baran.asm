 .386
        include \masm32\include\masm32rt.inc
        includelib \masm32\lib\user32.lib 
    .data
        a_arr DD -2, 3, 4, 6, 5
        c_arr DD 5, -36, 13, -30, -50
        d_arr DD 20, 28, -32, 6, 64
        
	  buff_main  DB 1024 DUP (?)

        number      DD 0
        numerator   DD 0
        denominator DD 0
        res         DD 0
        mod_res     DD 0

        text_title     DB "5-01-IP-03-Baran", 0
	  text_formating DB "%d.", 13, "(%d - %d/2 + 33)/(2 * %d * %d - 1) = %d/%d = %d", 13, 
                          "Final result = %d", 13, 0
    .code 
Start:
    mov edi, 0
    mov number, 1
   
@calculation:
; d/2
    mov eax, d_arr[edi * 4]
    mov ebx, 2
    cdq
    idiv ebx
    mov numerator, eax

; Numerator: c - d/2 + 33 
    mov ebx, c_arr[edi * 4]
    mov numerator, ebx
    sub numerator, eax
    add numerator, 33

; Denominator: 2 * a * a - 1 
    mov ebx, a_arr[edi * 4]
    imul ebx, ebx
    imul ebx, 2
    sub ebx, 1
    mov denominator, ebx

; Result
    mov eax, numerator
    mov ebx, denominator
    cdq
    idiv ebx
    mov res, eax

; Parity check
    test eax, 1
    jnz @odd
    
@pair:
    mov esi, 2
    cdq
    idiv esi
    mov mod_res, eax
    jmp @formating

@odd:
    imul eax, 5
    mov mod_res, eax

@formating:
    invoke wsprintfA, addr buff_main, addr text_formating, number, c_arr[edi * 4], 
                                                        d_arr[edi * 4], a_arr[edi * 4], 
                                                        a_arr[edi * 4], numerator, 
                                                        denominator, res, mod_res                                                      

    invoke MessageBoxA, NULL, addr buff_main, addr text_title, MB_OK

    add edi, 1
    add number, 1

    cmp edi, 5
    jne @calculation
end Start