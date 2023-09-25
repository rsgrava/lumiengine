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

; sets window x register
; input:
;	a: x value
macro lcd_set_wx
	ld [rWX], a
endm

; sets window y register
; input:
;	a: y value
macro lcd_set_wy
	ld [rWY], a
endm

; sets window x register
; input:
;	\1: x value
macro lcd_set_wx_const
	ld a, \1
	lcd_set_wx
endm

; sets window y register
; input:
;	\1: y value
macro lcd_set_wy_const
	ld a, \1
	lcd_set_wy
endm
