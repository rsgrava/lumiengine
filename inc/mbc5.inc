include "hardware.inc"

macro mbc5_enable_ram
	ld a, CART_SRAM_ENABLE
	ld [rRAMG], a
endm

macro mbc5_disable_ram
	ld a, CART_SRAM_DISABLE
	ld [rRAMG], a
endm

; input:
;	e: lower byte of bank id
;	a: upper byte of bank id
macro mbc5_set_rom_bank
	ld [rROMB1], a
	ld a, e
	ld [rROMB0], a
endm

; input:
;	a: bank id
macro mbc5_set_ram_bank
	ld [rRAMB], a
endm

macro mbc5_set_ram_bank_const
	ld a, \1
	ld [rRAMB], a
endm