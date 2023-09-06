include "hardware.inc"

; interrupts that are enabled at startup
def ENABLED_INTERRUPTS EQU IEF_VBLANK

; write id of the last interrupt in memory
; called in handler to identify which interrupt was the last to happen
macro set_last_interrupt
	ld a, \1				; loading id of last interrupt
	ld [last_interrupt], a	; writing id in memory
endm

; check whether the last interrupt was of a specified id
; zero flag will be set if it was
macro check_last_interrupt
	ld a, [last_interrupt]
	cp a, \1
endm
