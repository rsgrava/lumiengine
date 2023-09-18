include "hardware.inc"

; input:
;	a: bank id
macro mem_set_wram_bank
	ld [rSVBK], a
endm

macro mem_set_wram_bank_const
	ld a, \1
	mem_set_wram_bank
endm