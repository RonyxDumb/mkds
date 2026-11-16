#pragma once

#include "types.h"
#include "Main/Graphics/font_and_player_character.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "font_glyph_layout.h"

// Layout numbers of SelectKeyboardLayout and Keyboard.mLayout, named after the files each layout loads.
typedef enum KeyboardLayoutId {
    KEYBOARD_LAYOUT_DIGITS = 0,
    KEYBOARD_LAYOUT_KANA = 1,
    KEYBOARD_LAYOUT_ASCII = 2,
    KEYBOARD_LAYOUT_EURO = 3,
    KEYBOARD_LAYOUT_PICTOGRAMS = 4,
    KEYBOARD_LAYOUT_PICTOGRAMS_EXTRA = 5,
} KeyboardLayoutId;

// Values of the cursor and rect value functions for the two buttons below the keys.
#define KEYBOARD_VALUE_FIRST_BUTTON 1
#define KEYBOARD_VALUE_SECOND_BUTTON 2

// Key ids of the fixed keys of a layout (the first rects; the character keys follow them), as GetKeyboardValueForKeyId
// maps them: delete and space, two char map keys (hiragana and katakana in the HiraganaKatakanaLayoutCallback layout,
// shift and caps in the others) and, in the HiraganaKatakanaLayoutCallback layout only, three convert keys.
// KEYBOARD_KEY_ID_CYCLE is not a rect id: AdvanceKeyboardKeys makes it from the third input mask. Key id 2 (value 0xa)
// has no constant.
#define KEYBOARD_KEY_ID_DELETE 1
#define KEYBOARD_KEY_ID_SPACE 3
#define KEYBOARD_KEY_ID_MODE_FIRST 4
#define KEYBOARD_KEY_ID_MODE_SECOND 5
#define KEYBOARD_KEY_ID_CONVERT_FIRST 6
#define KEYBOARD_KEY_ID_CONVERT_SECOND 7
#define KEYBOARD_KEY_ID_CONVERT_THIRD 8
#define KEYBOARD_KEY_ID_CYCLE 0xffff
// Rect ids up to this are key rects, drawn with the keyboard offset; the button rects, which SetKeyboardRect gives
// KEYBOARD_RECT_ID_PLAIN, are above it.
#define KEYBOARD_KEY_ID_LAST_KEY 0xff
#define KEYBOARD_RECT_ID_PLAIN 0xff00

// Key values: what the key callback and the text entry get for a key. Values from KEYBOARD_VALUE_FIRST_CHARACTER up are
// the characters typed; the named lower ones are the other keys (the text entry acts on DELETE, the CONVERT values and
// CYCLE_CHAR_TABLES; the callback only plays sounds for the rest). Key id 2 gives the unnamed value 0xa, which the text
// entry ignores.
#define KEYBOARD_VALUE_SHIFT 4
#define KEYBOARD_VALUE_CAPS 5
#define KEYBOARD_VALUE_HIRAGANA 6
#define KEYBOARD_VALUE_KATAKANA 7
#define KEYBOARD_VALUE_DELETE 8
// Replace the last character by ConvertCharPair1, ConvertCharPair2 or ConvertCharPair3 of it, when that gives another
// character.
#define KEYBOARD_VALUE_CONVERT_FIRST 0x10
#define KEYBOARD_VALUE_CONVERT_SECOND 0x11
#define KEYBOARD_VALUE_CONVERT_THIRD 0x12
// Replace the last character by its CycleCharTables result when that differs from it.
#define KEYBOARD_VALUE_CYCLE_CHAR_TABLES 0x13
#define KEYBOARD_VALUE_SPACE 0x20
#define KEYBOARD_VALUE_FIRST_CHARACTER 0x20
#define KEYBOARD_VALUE_IDEOGRAPHIC_SPACE 0x3000

// KeyboardInput.mTouchStatus: no touch, the touch pressed this call, still pressed, released this call.
#define KEYBOARD_TOUCH_IDLE 0
#define KEYBOARD_TOUCH_BEGAN 1
#define KEYBOARD_TOUCH_HELD 2
#define KEYBOARD_TOUCH_ENDED 3

// Positions of the first and third rect of a layout: the delete key and the space key.
#define KEYBOARD_RECT_INDEX_DELETE 0
#define KEYBOARD_RECT_INDEX_SPACE 2

// Size in bytes of the BG2 character data of the keyboard.
#define KEYBOARD_BG2_CHAR_SIZE 0x4020

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
void SetKeyboardKeyCallback(s32 (*callback)(u32, s32));
void SetKeyboardCursorCallback(u16 (*callback)(s32, u16));
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

void InitKeyboardKeysAndCanvas(struct NNSG2dFont *font, void *bg2Char, u16 *bg2Scr, s32 screenMapWidth,
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

extern s32 gKeyboardOffsetX;
extern s32 gKeyboardOffsetY;
extern u16 *gCharTablePair3[2];
extern u16 *gCharTablePair1[2];
extern u16 *gCharTablePair2[2];
extern KeyboardCanvas gKeyboardCanvas;
