#include "gx_bgcnt.h"
#include "gx.h"
#include "registers.h"

u32 G2_GetBG0ScrPtr(void) {
    u32 control;
    u32 offset;

    control = reg_G2_BG0CNT;
    offset = (reg_GX_DISPCNT & 0x38000000) >> 27;
    control &= 0x1f00;
    offset <<= 16;
    control = (s32) control >> 8;
    return offset + 0x6000000 + (control << 11);
}

u32 G2S_GetBG0ScrPtr(void) {
    u32 control;

    control = reg_G2S_DB_BG0CNT;
    control &= 0x1f00;
    control = (s32) control >> 8;
    return (control << 11) + 0x6200000;
}

u32 G2_GetBG1ScrPtr(void) {
    u32 control;
    u32 offset;

    control = reg_G2_BG1CNT;
    offset = (reg_GX_DISPCNT & 0x38000000) >> 27;
    control &= 0x1f00;
    offset <<= 16;
    control = (s32) control >> 8;
    return offset + 0x6000000 + (control << 11);
}

u32 G2S_GetBG1ScrPtr(void) {
    u32 control;

    control = reg_G2S_DB_BG1CNT;
    control &= 0x1f00;
    control = (s32) control >> 8;
    return (control << 11) + 0x6200000;
}

u32 G2_GetBG2ScrPtr(void) {
    u32 mode;
    u32 control;
    u32 offset;
    u32 block;

    mode = reg_GX_DISPCNT & 0x7;
    control = reg_G2_BG2CNT;
    offset = ((reg_GX_DISPCNT & 0x38000000) >> 27) << 16;
    block = (control & 0x1f00) >> 8;
    switch (mode) {
        case GX_BGMODE_0:
        case GX_BGMODE_1:
        case GX_BGMODE_2:
        case GX_BGMODE_3:
        case GX_BGMODE_4:
            return offset + 0x6000000 + (block << 11);
        case GX_BGMODE_5:
            if (control & 0x80) {
                return (block << 14) + 0x6000000;
            }
            return offset + 0x6000000 + (block << 11);
        case GX_BGMODE_6:
            return 0x6000000;
    }
    return 0;
}

// Returns the sub engine BG VRAM address of the screen base block set in BG2CNT.
u32 G2S_GetBG2ScrPtr(void) {
    u32 mode;
    u32 control;
    u32 block;

    mode = reg_GXS_DB_DISPCNT & 0x7;
    control = reg_G2S_DB_BG2CNT;
    block = (control & 0x1f00) >> 8;
    switch (mode) {
        case GX_BGMODE_0:
        case GX_BGMODE_1:
        case GX_BGMODE_2:
        case GX_BGMODE_3:
        case GX_BGMODE_4:
            return (block << 11) + 0x6200000;
        case GX_BGMODE_5:
            if (control & 0x80) {
                return (block << 14) + 0x6200000;
            }
            return (block << 11) + 0x6200000;
        case GX_BGMODE_6:
            return 0;
    }
    return 0;
}

// Returns the main engine BG VRAM address of the screen base block set in BG3CNT.
u32 G2_GetBG3ScrPtr(void) {
    u32 mode;
    u32 control;
    u32 offset;
    u32 block;

    mode = reg_GX_DISPCNT & 0x7;
    control = reg_G2_BG3CNT;
    offset = ((reg_GX_DISPCNT & 0x38000000) >> 27) << 16;
    block = (control & 0x1f00) >> 8;
    switch (mode) {
        case GX_BGMODE_0:
        case GX_BGMODE_1:
        case GX_BGMODE_2:
            return offset + 0x6000000 + (block << 11);
        case GX_BGMODE_3:
        case GX_BGMODE_4:
        case GX_BGMODE_5:
            if (control & 0x80) {
                return (block << 14) + 0x6000000;
            }
            return offset + 0x6000000 + (block << 11);
        case GX_BGMODE_6:
            return 0;
    }
    return 0;
}

// Returns the sub engine BG VRAM address of the screen base block set in BG3CNT.
u32 G2S_GetBG3ScrPtr(void) {
    u32 mode;
    u32 control;
    u32 block;

    mode = reg_GXS_DB_DISPCNT & 0x7;
    control = reg_G2S_DB_BG3CNT;
    block = (control & 0x1f00) >> 8;
    switch (mode) {
        case GX_BGMODE_0:
        case GX_BGMODE_1:
        case GX_BGMODE_2:
            return (block << 11) + 0x6200000;
        case GX_BGMODE_3:
        case GX_BGMODE_4:
        case GX_BGMODE_5:
            if (control & 0x80) {
                return (block << 14) + 0x6200000;
            }
            return (block << 11) + 0x6200000;
        case GX_BGMODE_6:
            return 0;
    }
    return 0;
}

// Returns the main engine BG VRAM address of the character base block set in BG0CNT.
u32 G2_GetBG0CharPtr(void) {
    u32 control;
    u32 offset;

    control = reg_G2_BG0CNT;
    offset = (reg_GX_DISPCNT & 0x7000000) >> 24;
    control &= 0x3c;
    offset <<= 16;
    control = (s32) control >> 2;
    return offset + 0x6000000 + (control << 14);
}

u32 G2S_GetBG0CharPtr(void) {
    u32 control;

    control = reg_G2S_DB_BG0CNT;
    control &= 0x3c;
    control = (s32) control >> 2;
    return (control << 14) + 0x6200000;
}

u32 G2_GetBG1CharPtr(void) {
    u32 control;
    u32 offset;

    control = reg_G2_BG1CNT;
    offset = (reg_GX_DISPCNT & 0x7000000) >> 24;
    control &= 0x3c;
    offset <<= 16;
    control = (s32) control >> 2;
    return offset + 0x6000000 + (control << 14);
}

u32 G2S_GetBG1CharPtr(void) {
    u32 control;

    control = reg_G2S_DB_BG1CNT;
    control &= 0x3c;
    control = (s32) control >> 2;
    return (control << 14) + 0x6200000;
}

u32 G2_GetBG2CharPtr(void) {
    s32 mode;
    u32 control;

    mode = reg_GX_DISPCNT & 0x7;
    control = reg_G2_BG2CNT;
    if (mode < 5 || !(control & 0x80)) {
        return (((reg_GX_DISPCNT & 0x7000000) >> 24) << 16) + 0x6000000 + (((control & 0x3c) >> 2) << 14);
    }
    return 0;
}

// Returns the sub engine BG VRAM address of the character base block set in BG2CNT,
// or 0 in mode 5 or 6 with the 256 color bit set.
u32 G2S_GetBG2CharPtr(void) {
    s32 mode;
    u32 control;

    mode = reg_GXS_DB_DISPCNT & 0x7;
    control = reg_G2S_DB_BG2CNT;
    if (mode < 5 || !(control & 0x80)) {
        return (((control & 0x3c) >> 2) << 14) + 0x6200000;
    }
    return 0;
}

// Returns the main engine BG VRAM address of the character base block set in BG3CNT,
// or 0 when the mode is 6 or higher or in mode 3 to 5 with the 256 color bit set.
u32 G2_GetBG3CharPtr(void) {
    s32 mode;
    u32 control;

    mode = reg_GX_DISPCNT & 0x7;
    control = reg_G2_BG3CNT;
    if (mode < 3 || (mode < 6 && !(control & 0x80))) {
        return (((reg_GX_DISPCNT & 0x7000000) >> 24) << 16) + 0x6000000 + (((control & 0x3c) >> 2) << 14);
    }
    return 0;
}

// Returns the sub engine BG VRAM address of the character base block set in BG3CNT,
// or 0 when the mode is 6 or higher or in mode 3 to 5 with the 256 color bit set.
u32 G2S_GetBG3CharPtr(void) {
    s32 mode;
    u32 control;

    mode = reg_GXS_DB_DISPCNT & 0x7;
    control = reg_G2S_DB_BG3CNT;
    if (mode < 3 || (mode < 6 && !(control & 0x80))) {
        return (((control & 0x3c) >> 2) << 14) + 0x6200000;
    }
    return 0;
}
