#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// Argument of AdvanceLld.
typedef struct OamBuffer {
    /* 000 */ u8 mOams[0x400];
    /* 400 */ u16 mOamCount;
    /* 402 */ u16 field402;
} OamBuffer;

// Object behind the pointer at 0x85c of Emblem.
typedef struct Lld {
    /* 00 */ u16 mEntryCount;
    /* 02 */ u8 field2[0x2];
    /* 04 */ struct LldEntry *mEntries;
    /* 08 */ void *mCells;
    /* 0c */ void *mCellAnims;
    /* 10 */ s32 mOffsetX;
    /* 14 */ s32 mOffsetY;
} Lld;

// Object behind gEmblem, allocated by InitEmblem.
typedef struct Emblem {
    /* 0000 */ OamBuffer field0;
    /* 0404 */ OamBuffer field404;
    /* 0808 */ Nclr *mEmblemMONclr;
    /* 080c */ Nclr *mEmblemMBNclr;
    /* 0810 */ Ncgr *mEmblemMONcgr;
    /* 0814 */ Ncgr *mEmblemMBNcgr;
    /* 0818 */ Nscr *mEmblemMNscr;
    /* 081c */ Nscr *mEmblemMBgNscr;
    /* 0820 */ struct Unk02021dc8 *mEmblemMNcer;
    /* 0824 */ struct Unk02021dc8 *mEmblemMNanr;
    /* 0828 */ struct Lld *mEmblemMLld;
    /* 082c */ Nclr *mEmblemSONclr;
    /* 0830 */ Nclr *mEmblemSBNclr;
    /* 0834 */ Ncgr *mEmblemSONcgr;
    /* 0838 */ Ncgr *mEmblemSBNcgr;
    /* 083c */ Ncgr *mEmblemTemplateBNcgr;
    /* 0840 */ Nscr *mEmblemSToolNscr;
    /* 0844 */ Nscr *mEmblemSBgNscr;
    /* 0848 */ Nscr *mEmblemSTemplateFrameNscr;
    /* 084c */ Nscr *mEmblemSTemplateDarkNscr;
    /* 0850 */ struct Unk02021dc8 *mEmblemSNcer;
    /* 0854 */ struct Unk02021dc8 *mEmblemSNanr;
    /* 0858 */ struct Lld *mEmblemSLld;
    /* 085c */ Lld *mEmblemTemplateSLld;
    /* 0860 */ Ncgr *mEmblemCameraSONcgr;
    /* 0864 */ Ncgr *mEmblemCameraSBNcgr;
    /* 0868 */ Nscr *mEmblemCameraSDSNscr;
    /* 086c */ Nscr *mEmblemCameraSBgNscr;
    /* 0870 */ struct Unk02021dc8 *mEmblemCameraSNcer;
    /* 0874 */ struct Unk02021dc8 *mEmblemCameraSNanr;
    /* 0878 */ struct Lld *mEmblemCameraSLld;
    /* 087c */ u8 field87C[0x200];
    /* 0a7c */ u8 fieldA7C[0x200];
    /* 0c7c */ u8 fieldC7C[0x400];
    /* 107c */ s32 field107C;
    /* 1080 */ s32 field1080;
    /* 1084 */ s32 field1084;
    /* 1088 */ s32 field1088;
    /* 108c */ UnkFunc *field108C;
    /* 1090 */ s32 field1090;
    /* 1094 */ s32 field1094;
    /* 1098 */ s32 field1098;
    /* 109c */ s32 field109C;
    /* 10a0 */ s32 field10A0;
    /* 10a4 */ s32 field10A4;
    /* 10a8 */ s32 field10A8;
    /* 10ac */ BOOL field10AC;
    /* 10b0 */ BOOL field10B0;
    /* 10b4 */ s32 field10B4;
    /* 10b8 */ BOOL field10B8;
    /* 10bc */ s32 field10BC;
} Emblem;

extern Emblem *gEmblem;

void InitEmblem(void);
