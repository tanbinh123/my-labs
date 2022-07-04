 .386
        .model flat, stdcall
        option casemap:none

        extern a_arr:qword, denomIndex:dword, n3:qword, n4:qword
        public fullDenominator

    .code 
    fullDenominator proc
        ; a / 4 - 1
        mov edi, denomIndex

        finit
        fld a_arr[edi * 8]
        fdiv n3
        fsub n4
        
        ret
    fullDenominator endp
end


























       