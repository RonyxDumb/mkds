// Block hash update with its round constants.
//
// Not compiled code: the routine keeps its constant words before its entry and saves ip, returns by popping
// pc and folds rotations into its operands (see below). A C file can't place them there: 1.2 puts a function's
// constant words after its code (also for `ldr rX, =value` in an asm function) and C tables in .rodata.

    .text

// Constant words of func_02150e1c: the byte-swap mask and the four round constants.
hash_swap_mask:
    .word 0x00ff00ff
hash_k1:
    .word 0x5a827999
hash_k2:
    .word 0x6ed9eba1
hash_k3:
    .word 0x8f1bbcdc
hash_k4:
    .word 0xca62c1d6

// Runs the five-word state at ctx through each 64-byte block of data (n bytes, a multiple of 64). For each block: the
// sixteen big-endian words become the start of a schedule kept in a 32-word stack area, each later word being the
// exclusive or of four earlier ones rotated left by one; four groups of 20 rounds each add one round constant (the
// words just before this function), a choice, parity or majority function of three state words, the next schedule word
// and the first state word rotated left by 5; finally the block's result is added into ctx.
// Not compiled code: it saves ip, returns by popping pc, folds rotations into its operands (`ror #27`, `ror #8`) and
// loads its constants from the words before its own start. The 1.2 compiler never saves ip, returns through `bx lr`,
// keeps rotations as two shifts and places constant words after the function (docs/compiler.md).
    .global func_02150e1c
    .type func_02150e1c, @function
func_02150e1c:
    // Load the state into r3, r9-r12; keep n at sp + 0x80.
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, ip, lr}
    ldmia r0, {r3, r9, r10, r11, ip}
    sub sp, sp, #132
    str r2, [sp, #128]
    // Next block. r8 = the first round constant, r7 = the byte-swap mask, r6 = the schedule.
hash_block:
    ldr r8, hash_k1
    ldr r7, hash_swap_mask
    mov r6, sp
    mov r5, #0
    // Rounds 0-15: byte-swap the next data word into the schedule (twice: at r6 and r6 + 0x40).
hash_round_load:
    ldr r4, [r1], #4
    add r2, r8, ip
    add r2, r2, r3, ror #27
    and lr, r4, r7
    and r4, r7, r4, ror #24
    orr r4, r4, lr, ror #8
    str r4, [r6, #64]
    str r4, [r6], #4
    add r2, r2, r4
    eor r4, r10, r11
    and r4, r4, r9
    eor r4, r4, r11
    add r2, r2, r4
    mov r9, r9, ror #2
    mov ip, r11
    mov r11, r10
    mov r10, r9
    mov r9, r3
    mov r3, r2
    add r5, r5, #4
    cmp r5, #64
    blt hash_round_load
    // Rounds 16-19: schedule word = (w[i-16] ^ w[i-14] ^ w[i-8] ^ w[i-3]) rotated left by one.
    mov r7, #0
    mov r6, sp
hash_round_mix1:
    ldr r2, [r6]
    ldr r5, [r6, #8]
    ldr r4, [r6, #32]
    ldr lr, [r6, #52]
    eor r2, r2, r5
    eor r4, r4, lr
    eor r2, r2, r4
    mov r2, r2, ror #31
    str r2, [r6, #64]
    str r2, [r6], #4
    add r2, r2, ip
    add r2, r2, r8
    add r2, r2, r3, ror #27
    eor r4, r10, r11
    and r4, r4, r9
    eor r4, r4, r11
    add r2, r2, r4
    mov r9, r9, ror #2
    mov ip, r11
    mov r11, r10
    mov r10, r9
    mov r9, r3
    mov r3, r2
    add r7, r7, #4
    cmp r7, #16
    blt hash_round_mix1
    // Rounds 20-39: second constant, parity of three state words.
    ldr r8, hash_k2
    mov r7, #0
hash_round_mix2:
    ldr r2, [r6]
    ldr r4, [r6, #8]
    ldr lr, [r6, #32]
    ldr r5, [r6, #52]
    eor r2, r2, r4
    eor lr, lr, r5
    eor r2, r2, lr
    mov r2, r2, ror #31
    str r2, [r6, #64]
    str r2, [r6], #4
    add r2, r2, ip
    add r2, r2, r8
    add r2, r2, r3, ror #27
    eor lr, r9, r10
    eor lr, lr, r11
    add r2, r2, lr
    mov r9, r9, ror #2
    mov ip, r11
    mov r11, r10
    mov r10, r9
    mov r9, r3
    mov r3, r2
    add r7, r7, #1
    cmp r7, #12
    moveq r6, sp                        // the schedule area wraps every 16 words
    cmp r7, #20
    blt hash_round_mix2
    // Rounds 40-59: third constant, majority of three state words.
    ldr r8, hash_k3
    mov r7, #0
hash_round_mix3:
    ldr r2, [r6]
    ldr lr, [r6, #8]
    ldr r5, [r6, #32]
    ldr r4, [r6, #52]
    eor r2, r2, lr
    eor r5, r5, r4
    eor r2, r2, r5
    mov r2, r2, ror #31
    str r2, [r6, #64]
    str r2, [r6], #4
    add r2, r2, ip
    add r2, r2, r8
    add r2, r2, r3, ror #27
    orr r5, r9, r10
    and r5, r5, r11
    and r4, r9, r10
    orr r5, r5, r4
    add r2, r2, r5
    mov r9, r9, ror #2
    mov ip, r11
    mov r11, r10
    mov r10, r9
    mov r9, r3
    mov r3, r2
    add r7, r7, #1
    cmp r7, #8
    moveq r6, sp
    cmp r7, #20
    blt hash_round_mix3
    // Rounds 60-79: fourth constant, parity again.
    ldr r8, hash_k4
    mov r7, #0
hash_round_mix4:
    ldr r2, [r6]
    ldr r5, [r6, #8]
    ldr r4, [r6, #32]
    ldr lr, [r6, #52]
    eor r2, r2, r5
    eor r4, r4, lr
    eor r2, r2, r4
    mov r2, r2, ror #31
    str r2, [r6, #64]
    str r2, [r6], #4
    add r2, r2, ip
    add r2, r2, r8
    add r2, r2, r3, ror #27
    eor r4, r9, r10
    eor r4, r4, r11
    add r2, r2, r4
    mov r9, r9, ror #2
    mov ip, r11
    mov r11, r10
    mov r10, r9
    mov r9, r3
    mov r3, r2
    add r7, r7, #1
    cmp r7, #4
    moveq r6, sp
    cmp r7, #20
    blt hash_round_mix4
    // Add the block's result into the state; next block while bytes remain.
    ldmia r0, {r2, r4, r6, r7, lr}
    add r3, r3, r2
    add r9, r9, r4
    add r10, r10, r6
    add r11, r11, r7
    add ip, ip, lr
    stmia r0, {r3, r9, r10, r11, ip}
    ldr lr, [sp, #128]
    subs lr, lr, #64
    str lr, [sp, #128]
    bgt hash_block
    add sp, sp, #132
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, ip, pc}
    .size func_02150e1c, . - func_02150e1c
