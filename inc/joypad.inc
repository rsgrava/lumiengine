include "hardware.inc"

macro jp_isPressed
    if \1 == "up"
        ld a, [jp_dir]
        ld b, P1F_2
    elif \1 == "down"
        ld a, [jp_dir]
        ld b, P1F_3
    elif \1 == "left"
        ld a, [jp_dir]
        ld b, P1F_1
    elif \1 == "right"
        ld a, [jp_dir]
        ld b, P1F_0
    elif \1 == "a"
        ld a, [jp_action]
        ld b, P1F_0
    elif \1 == "b"
        ld a, [jp_action]
        ld b, P1F_1
    elif \1 == "start"
        ld a, [jp_action]
        ld b, P1F_3
    elif \1 == "select"
        ld a, [jp_action]
        ld b, P1F_2
    else
        fail "invalid jp input"
    endc
    and a, b
endm
