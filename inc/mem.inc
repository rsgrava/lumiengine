include "hardware.inc"

; input:
;	a: bank id
macro mem_set_wram_bank
	ld [rSVBK], a
endm

; input:
;	\1: bank id
macro mem_set_wram_bank_const
	ld a, \1
	mem_set_wram_bank
endm

; input:
;	a: bank id
macro mem_set_vram_bank
	ld [rVBK], a
endm

; input:
;	\1: bank id
macro mem_set_vram_bank_const
	ld a, \1
	ld [rVBK], a
endm