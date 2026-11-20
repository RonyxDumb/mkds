#pragma once

#include "types.h"

typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// The picture of a course of a cup: its palette, chars and screen map pointers, mCupPictureIndex (the course id the
// picture is loaded for) and the buffers the three files are read into.
typedef struct CupPicture {
    /* 0000 */ Nclr *mCupPictureNclr;
    /* 0004 */ Ncgr *mCupPictureNcgr;
    /* 0008 */ Nscr *mCupPictureNscr;
    /* 000c */ s32 mCupPictureIndex;
    /* 0010 */ u8 mCupPictureNclrFile[0x228];
    /* 0238 */ u8 mCupPictureNcgrFile[0xe00];
    /* 1038 */ u8 mCupPictureNscrFile[0x824];
} CupPicture;

void ClearCupPicturePointer(void);
void LoadCupPictureNclr(void);
void LoadCupPictureNcgr(void);
void LoadCupPictureNscr(void);

void InitCupPicture(void);

u32 CupPictureGetCurrentHeap(void);

extern struct CupPicture *gCupPicture;
