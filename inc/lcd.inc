include "hardware.inc"

; sets scroll x register
; input:
;	a: new scx value
macro lcd_set_scx
	ld [rSCX], a
endm

; sets scroll y register
; input:
;	a: new scy value
macro lcd_set_scy
	ld [rSCY], a
endm

; applies offset to scroll x register
; input:
;	b: offset
macro lcd_offset_scx
	ld a, [rSCX]
	add a, b
	ld [rSCX], a
endm

; applies offset to scroll y register
; input:
;	b: offset
macro lcd_offset_scy
	ld a, [rSCY]
	add a, b
	ld [rSCY], a
endm