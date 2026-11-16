#pragma once

#include "types.h"

typedef struct Unk0217aa14_104 Unk0217aa14_104;

// 0x24 bytes from 0x04 of Unk0205b504, followed by four 8-byte values.
typedef struct Unk0205b504_04 {
    /* 00 */ union {
        u16 field0;
        s16 mUnk_00_s;
        u8 mUnk_00_b[4];
        struct {
            u32 field0_0 : 24;
        };
    };
    /* 04 */ u64 field4[4];
} Unk0205b504_04;

// Message of 0x28 bytes from 0x04.
typedef struct Unk0205b504 {
    /* 00 */ union {
        u8 field0;
        struct {
            u8 field0_0 : 2;
            u8 field0_2 : 2;
            u8 field0_4 : 4;
        };
    };
    /* 01 */ u8 field1;
    /* 02 */ union {
        u8 field2;
        struct {
            u8 field2_0 : 4;
        };
    };
    /* 03 */ u8 field3;
    /* 04 */ Unk0205b504_04 field4;
} Unk0205b504;

void sub_205B0F4(void);
void sub_205B32C(void);
void func_0205b504(u32 a, Unk0205b504 *packet, u32 c, u32 d);
void sub_205B6BC(u32 a, Unk0205b504 *packet, u32 c);
void sub_205B778(u32 a, Unk0205b504 *packet, u32 c);
void sub_205B824(const u64 *ticks, s32 participant);
s32 sub_205B954(s32 participant);
Unk0217aa14_104 *sub_205B978(s32 participant, u32 b);
void E7FnList4_Fn11(void);
void sub_205BA60(void);
u32 sub_205BBA8(void);
u32 E7FnList4_Fn10(void);
void E7FnList4_Fn9(void);
void sub_205BE0C(void);
void sub_205C234(s32 dataSize);
int sub_205C340(u8 participant, u32 b, int dataSize);
void E7FnList4_Fn8(void);
void E7FnList4_Fn7(void);
void func_0205c610(u32 participant);
void E7FnList4_Fn6(void);
void E7FnList4_Fn5(void);
void func_0205c7a0(u32 participant);
void sub_205C800(u16 a, void (*callback)(u32));
void E7FnList4_Fn4(void);
void E7FnList4_Fn3(void);
void E7FnList4_Fn2(void);
void sub_205CCEC(void);
void InitializeGlobalAA(void *heap);
void SetParticipantKartMapFromMask(u32 participantMask);
void ResetParticipantKartMap(void);
