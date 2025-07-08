; Hacks in z_en_hy

.headersize(0x80AE4EE0 - 0x00E641C0)

; override text for dog lady in market day
; L254 in En_Hy.s
.org 0x80AE5254
; Replaces
;    beq     t6, $zero, lbl_80AE5268
;    nop
;    addiu   v1, $zero, 0x709B          # v1 = 0000709B
;    b       lbl_80AE5988
;    andi    v0, v1, 0xFFFF             # v0 = 0000709B
;    b       lbl_80AE5988
;    andi    v0, v1, 0xFFFF             # v0 = 0000709B
    andi    a0, t6, 0xFFFF ; a0 = t6
    jal     Get_Dog_Lady_Text
    nop
    lw      $ra, 0x0014($sp)
    addiu   $sp, $sp, 0x0020
    jr      $ra
    nop
