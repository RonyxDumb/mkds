#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// The picture of a cup: its palette, chars and screen map pointers, the cup index and the files they are loaded from.
typedef struct CupPicture {
    /* 0000 */ Nclr *mCupPictureNclr;
    /* 0004 */ Ncgr *mCupPictureNcgr;
    /* 0008 */ Nscr *mCupPictureNscr;
    /* 000c */ s32 mCupPictureIndex;
    /* 0010 */ u8 mCupPictureNclrFile[0x228];
    /* 0238 */ u8 mCupPictureNcgrFile[0xe00];
    /* 1038 */ u8 mCupPictureNscrFile[0x824];
} CupPicture;

void ResetGlobalB4A4_from_thumb(void);
void LoadCupPictureNclr(void);
void LoadCupPictureNcgr(void);
void LoadCupPictureNscr(void);

void InitializeGlobalB4A4_from_thumb(void);

u32 GetActiveExecutionContextHeapHandle_0(void);

extern struct CupPicture *g_GlobalB4A4;
