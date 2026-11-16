#pragma once

#include "types.h"
#include "03/System/tasks.h"

typedef struct BgTextCanvas BgTextCanvas;

void DrawCanvasText(BgTextCanvas *canvas, unsigned int xPos, unsigned int yPos, unsigned int color, unsigned int flags,
                    void *text);

#include "Main/Graphics/text_canvas.h"
#include "char_canvas_text_draw.h"

// A text canvas drawn into a background: its char canvas, text canvas, chars and upload task.
typedef struct BgTextCanvas {
    /* 00 */ NNSG2dCharCanvas mCharCanvas;
    /* 20 */ TextCanvas mTextCanvas;
    /* 30 */ u8 *mChars;
    /* 34 */ TaskEntry *mUploadTask;
} BgTextCanvas;

#include "03/System/pointer_stack_create.h"

void DrawCanvasTextRect(BgTextCanvas *canvas, s32 xPos, s32 yPos, s32 width, s32 height, u32 color, u32 flags,
                        void *text);

#include "03/Graphics/obj_char_ranges.h"

// A text canvas drawn with objects: its clear function, font, character and line spacing, character range, first
// character name and area size.
typedef struct ObjTextCanvas {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mPClear)(struct ObjTextCanvas *canvas, u32 color);
    /* 1c */ u8 mUnk_1c[4];
    /* 20 */ struct ObjTextCanvas *mCharCanvas;
    /* 24 */ void *mFont;
    /* 28 */ s32 mCharSpacing;
    /* 2c */ s32 mLineSpacing;
    /* 30 */ ObjCharRange *mCharRange;
    /* 34 */ u16 mCharName;
    /* 36 */ u8 mAreaWidth;
    /* 37 */ u8 mAreaHeight;
} ObjTextCanvas;

// The text canvases: two fonts and their files, the object canvas storage, two background canvases with their upload
// flags, and the free object canvas stack.
typedef struct TextCanvases {
    /* 000 */ NNSG2dFont mFonts[2];
    /* 018 */ u8 mObjCanvasStorage[0x700];
    /* 718 */ BgTextCanvas mBgTextCanvases[2];
    /* 788 */ PointerStack *mFreeObjCanvases;
    /* 78c */ NNSG2dBinaryFileHeader *mFontFiles[2];
    /* 794 */ u8 mBgUploadPending[4];
} TextCanvases;

#include "03/Graphics/nce_oam.h"
#include "03/Menu/wifi_menu_shared.h"
#include "screen_data_unpack.h"
#include "font_glyph_layout.h"

extern const u16 gBgTextCanvasCharOffsets[2];
extern const u16 gBgTextCanvasSizes[4];
extern void *gTextCanvasNftrNames[2];

void RequestBgTextCanvasUpload(void *canvas);
void ArrangeObjTextCanvasRange(ObjTextCanvas *canvas, s32 xPos, s32 yPos, OamRange *range, s32 priority);
void ClearBgTextCanvas(BgTextCanvas *canvas, u32 color);
void DrawCharsCentered(void *canvas, s32 xPos, u32 yPos, u32 color, s32 cellWidth, u16 *text, s32 fontIndex);
void DrawCanvasChar(void *canvas, u32 xPos, u32 yPos, u32 color, u16 charCode, int fontIndex);
void ReleaseBgTextCanvasOfScreen(u32 index);
void ReleaseBgTextCanvas(BgTextCanvas *canvas);
void AdvanceBgTextCanvasUpload(TaskEntry *task, void *arg);
BgTextCanvas *InitBgTextCanvas(u32 screen, u32 fontIndex);
void DeleteObjTextCanvas(ObjTextCanvas *canvas);
ObjTextCanvas *CreateObjTextCanvas(u32 screen, u16 areaWidth, u16 areaHeight, s32 fromFront, u32 *entryCount,
                                   s32 fontIndex);
void ReleaseTextCanvases(void);
void InitTextCanvases(void);

extern TextCanvases *gTextCanvases;
