#pragma once

#include "types.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/MapObjects/data_0217b000.h"
#include "code_02022aa8.h"

void SetKeyboardButton1Rect(u32 left, u32 top, u32 right, u32 bottom);
void SetKeyboardButton0Rect(u32 left, u32 top, u32 right, u32 bottom);

typedef struct KeyboardRect KeyboardRect;

void SetKeyboardRect(KeyboardRect *rect, u32 left, u32 top, u32 right, u32 bottom);

void SetupKeyboardLayoutOther3(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount);
void SetupKeyboardLayoutOther2(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount);
void SetupKeyboardLayoutOther1(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount);
void SetupKeyboardLayoutAscii(KeyboardRect *rects, struct Ncgr *ncgr, u32 rectCount);

void SetupKeyboardLayoutHiragana(KeyboardRect *rects, Ncgr *ncgr, u32 rectCount);
void SetupKeyboardLayout(KeyboardRect *rects, Ncgr *ncgr, void (*callback)(KeyboardKeys *), s32 fixedCount,
                         u32 rectCount, u16 *charMap);
u16 LookupCharInTablePair(u16 **tablePair, u16 charCode);
KeyboardRect *FindKeyboardRectInDirection(u32 direction, KeyboardRect *rect, KeyboardRect *unused);
void RefreshKeyboardCursor(KeyboardKeys *keyboardKeys);
void AddToNonzeroNibblesInRect(u32 (*tiles)[8], s32 rowWidth, u32 addValue, s32 left, s32 top, s32 right, s32 bottom);
void AddToNonzeroNibblesOnRectEdge(u32 (*tiles)[8], s32 rowWidth, u32 addValue, s32 left, s32 top, s32 right,
                                   s32 bottom);
void AddToNonzeroNibblesInTile(u32 *tile, u32 addValue, s32 startX, s32 startRow, s32 endX, s32 endRow);
u32 IsCharInTable3(u16 charCode);
u32 IsCharInTable2(u16 charCode);
u32 IsCharInTable1(u16 charCode);
u16 CycleCharTables(u16 charCode);
u16 ConvertCharPair3(u16 charCode);
u16 ConvertCharPair2(u16 charCode);
u16 ConvertCharPair1(u16 charCode);

u32 GetKeyboardKeyValue(void);

typedef struct TPData TPData;

typedef struct KeyboardLayout KeyboardLayout;
typedef struct KeyboardKeys KeyboardKeys;

typedef struct RepeatCounter RepeatCounter;

void PollKeyboard(void);
void AdvanceKeyboardKeys(u16 keys, TPData touchPoint);
u32 IsKeyboardTouchOnStartKeyId(KeyboardKeys *keyboardKeys);
void MarkKeyboardRects(KeyboardKeys *keyboardKeys);
void DrawKeyboardGlyphs(KeyboardKeys *keyboardKeys);
KeyboardRect *FindKeyboardRectAt(KeyboardKeys *keyboardKeys, s32 pointX, s32 pointY);
u16 FindFirstCharRectIndex(KeyboardLayout *keyboardLayout);
void FillKeyboardBg2Scr(KeyboardKeys *keyboardKeys);
void CallKeyboardKeyCallback(s32 newPress);
void SetKeyboardKeyCallback(s32 (*arg0)(u32, s32));
void SetKeyboardCursorCallback(u16 (*arg0)(s32, u16));
void SetKeyboardGlyphColor(u32 color);
void SetKeyboardScreenMapTopBits(u32 topBits);
void SetupKeyboardInputMasks(u16 firstMask, u16 secondMask, u16 thirdMask);
s32 GetKeyboardValueForKeyId(u32 keyId);
s32 GetKeyboardRectValue(KeyboardRect *keyboardRect);
KeyboardRect *FindKeyboardRectByValue(u16 value);
void HiraganaKatakanaLayoutCallback(KeyboardKeys *keyboardKeys);
void AsciiLayoutCallback(KeyboardKeys *keyboardKeys);
u16 GetKeyboardKeysPressedOrRepeated(void);
u16 GetKeyboardRepeatedKeys(void);
void AdvanceKeyboardKeyRepeat(void);
void SetupKeyboardKeyRepeat(u16 keyMask);
BOOL IsRepeatCounterFiring(RepeatCounter *repeatCounter);
void ResetRepeatCounter(RepeatCounter *repeatCounter);
void AdvanceKeyboardTextEntry(void);
void InitKeyboardTextEntry(s32 screenMapWidth, s32 screenMapHeight, s32 textCapacity);
u16 KeyboardCursorCallback(s32 rectValue, u16 keys);
s32 KeyboardKeyCallback(u32 keyValue, s32 newPress);
s32 GetKeyboardLastCharIndex(void);
void SplitBytesIntoNibbles(u8 *src, u8 *dst, s32 size);

void InitKeyboardKeysAndCanvas(struct Unk02022aa8 *font, void *bg2Char, u16 *bg2Scr, s32 screenMapWidth,
                               s32 screenMapHeight, s32 screenMapTileBase);
void GetKeyboardCursorRectBounds(s32 *left, s32 *top, s32 *right, s32 *bottom);

void StoreKeyboardOffset(s32 offsetX, s32 offsetY);

void AdvanceRepeatCounter(RepeatCounter *repeatCounter);

void SetupRepeatCounter(RepeatCounter *repeatCounter, unsigned int firstFireFrame, unsigned int repeatGap);
void SetupRepeatCounterDefault(RepeatCounter *repeatCounter);

u32 IsKeyboardTouchEnabled(void);
u32 GetKeyboardLastTouchY(void);
u32 GetKeyboardLastTouchX(void);
u32 GetKeyboardTouchStatus(void);
u32 GetKeyboardTouchDown(void);
u32 GetKeyboardKeysDown(u32 mask);
u32 GetKeyboardKeysPressed(u32 mask);

void AdvanceKeyboardInput(u16 keys, volatile TPData touchPoint);

void InitKeyboardInput(void);

void ClearKeyboardInput(void);

u16 GetKeyboardTextIndex(void);

void SetKeyboardTextLimit(u16 textLimit);

u16 *GetKeyboardText(void);

void SetKeyboardText(const u16 *text);

void GetKeyboardCursorBoundsRelative(s32 *left, s32 *top, s32 *right, s32 *bottom);

u32 GetKeyboardCursorValueWrapper(void);
void MoveKeyboardCursorToValueWrapper(u16 value);

void SetKeyboardButton1Corners(u32 startX, u32 startY, u32 endX, u32 endY);
void SetKeyboardButton0Corners(u32 startX, u32 startY, u32 endX, u32 endY);

void SetKeyboardOffset(s32 offsetX, s32 offsetY);
void SelectKeyboardLayout(u32 layoutIndex);

void SetKeyboardScreenMapTopBitsWrapper(u32 topBits);

void UploadKeyboardBg2Data(void);
