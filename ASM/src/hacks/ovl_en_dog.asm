; Hacks in z_en_dog for dog shuffle

.headersize(0x80B49E50 - 0x00EC5580)

; override setting scale
.org 0x80B4A3F8
; Replaces
;   jal Actor_SetScale
    jal Dog_Set_Scale
