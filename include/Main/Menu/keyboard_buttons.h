#pragma once

#include "types.h"
#include "Main/Graphics/scene_text_init.h"
#include "Main/Menu/menu_screens_work.h"

// Entries of common.bmg that the Keyboard screen shows, named after their text.
typedef enum KeyboardMessage {
    KEYBOARD_MESSAGE_YES = 0,
    KEYBOARD_MESSAGE_NO = 1,
    KEYBOARD_MESSAGE_OK = 4,
    KEYBOARD_MESSAGE_CANCEL = 5,
    KEYBOARD_MESSAGE_ENTER_FRIEND_CODE = 7,
    KEYBOARD_MESSAGE_ENTER_TEMPORARY_NAME = 8,
    KEYBOARD_MESSAGE_FRIEND_CODE_REGISTERED = 9,
    KEYBOARD_MESSAGE_FRIEND_CODE_INCORRECT = 0xa,
    KEYBOARD_MESSAGE_FRIEND_CODE_ALREADY_REGISTERED = 0xb,
    KEYBOARD_MESSAGE_CONFIRM_NAME = 0xe,
    KEYBOARD_MESSAGE_ENTER_NICKNAME = 0xf,
    KEYBOARD_MESSAGE_NICKNAME_REGISTERED = 0x10,
    KEYBOARD_MESSAGE_CONFIRM_FRIEND_CODE = 0x11,
    KEYBOARD_MESSAGE_CREATE_EMBLEM = 0x13,
    KEYBOARD_MESSAGE_SAVING = 0x81,
} KeyboardMessage;

// Results of CheckFriendCode: the message of the friend code screen that goes with a rejected key.
#define FRIEND_KEY_CHECK_INCORRECT 1
#define FRIEND_KEY_CHECK_ALREADY_REGISTERED 2

// Rect indices the touch lookup returns on the friend code screen (the first button, the second button) and on the
// name screen (the five layout tabs come first, then the two buttons).
#define KEYBOARD_FRIEND_KEY_RECT_FIRST_BUTTON 1
#define KEYBOARD_FRIEND_KEY_RECT_SECOND_BUTTON 0
#define KEYBOARD_NAME_RECT_TAB_KANA 0
#define KEYBOARD_NAME_RECT_TAB_ASCII 1
#define KEYBOARD_NAME_RECT_TAB_EURO 2
#define KEYBOARD_NAME_RECT_TAB_PICTOGRAMS 3
#define KEYBOARD_NAME_RECT_TAB_PICTOGRAMS_EXTRA 4
#define KEYBOARD_NAME_RECT_FIRST_BUTTON 5
#define KEYBOARD_NAME_RECT_SECOND_BUTTON 6

// Returns the scene number the Keyboard screen asks for (-1 = none yet); Scene_Keyboard_Update_from_thumb copies it into
// SceneNumbers.mNextScene when it is not -1.
u32 GetKeyboardContextNextSceneId_from_thumb(void);
void WriteKeyboardRegisters(void);
// Advances the Keyboard screen by one step: takes mNextState as mState, runs the handler of that state
// (one AdvanceKeyboard handler per KEYBOARD_STATE_* value) and then runs the cell and drawing helpers of the screen.
void AdvanceKeyboard(void);
void ShowKeyboardLayoutObject(void);
void ShowKeyboardRemainingCharObjects(void);
void ShowKeyboardTextIndexObject(void);
void ShowKeyboardDisabledButtonObjects(void);
void ShowKeyboardCursorButtonObjects(void);
void PrintKeyboardTextChars(void);
// Handler of KEYBOARD_STATE_ASK_EMBLEM.
void Keyboard_SwitchFn13_from_thumb(void);
// Handler of KEYBOARD_STATE_WAIT_BACKUP.
void Keyboard_SwitchFn12_from_thumb(void);
// Handler of KEYBOARD_STATE_SHOW_SAVING.
void Keyboard_SwitchFn11_from_thumb(void);
// Handler of KEYBOARD_STATE_ANSWER_CONFIRM.
void Keyboard_SwitchFn10_from_thumb(void);
// Handler of KEYBOARD_STATE_SLIDE_IN_CONFIRM.
void Keyboard_SwitchFn9_from_thumb(void);
// Handler of KEYBOARD_STATE_SLIDE_OUT_NAME.
void Keyboard_SwitchFn8_from_thumb(void);
// Handler of KEYBOARD_STATE_ENTER_NAME.
void Keyboard_SwitchFn7_from_thumb(void);
// Handler of KEYBOARD_STATE_SLIDE_IN_NAME.
void Keyboard_SwitchFn6_from_thumb(void);
void UpdateKeyboardNameButtons(void);

// Handler of KEYBOARD_STATE_WAIT_FADE_NAME.
void Keyboard_SwitchFn5_from_thumb(void);
// Handler of KEYBOARD_STATE_SHOW_FRIEND_KEY_ERROR.
void Keyboard_SwitchFn4_from_thumb(void);
// Handler of KEYBOARD_STATE_SLIDE_OUT_FRIEND_KEY.
void Keyboard_SwitchFn3_from_thumb(void);
// Handler of KEYBOARD_STATE_ENTER_FRIEND_KEY.
void Keyboard_SwitchFn2_from_thumb(void);
// Handler of KEYBOARD_STATE_SLIDE_IN_FRIEND_KEY.
void Keyboard_SwitchFn1_from_thumb(void);
void UpdateKeyboardFriendKeyButtons(void);
// Handler of KEYBOARD_STATE_WAIT_FADE_FRIEND_KEY.
void Keyboard_SwitchFn0_from_thumb(void);
void InitKeyboardDisplay(void);

void LoadKeyboardFiles(void);
void QueueKeyboardScreenMap(void);

void WriteKeyboardObjectOffsets(void);

// Releases the helper objects of the Keyboard screen and clears g_KeyboardContext; the memory is freed with the scene heap.
void ReleaseKeyboard(void);

void PrintKeyboardButtonTexts(void);
void InitKeyboardCursorCorners(void);
void HideKeyboardFirstBufferObjects(void);
void SetKeyboardTextFromFriendKey(void);
void SetKeyboardTextFromName(void);
void SetKeyboardTextFromPlayerName(void);
void CopyKeyboardTextAsBytes(void);
void InitializeKeyboardContext_from_thumb(void *heap, s32 mode);

void SetKeyboardButtonCorners(void);

BOOL IsLocateFriendOnWithBuddyStatus4(void);
void InitKeyboardLabelCanvases(void);

extern Keyboard *g_KeyboardContext;

extern const u8 gKeyboardKindEntryCounts[2];
extern const u8 gKeyboardKindEntryIndices[2][1];
extern const u8 g_KeyboardMaxSizeArray[2];
extern const u8 gKeyboardButtonLabelIndices[2][2];
extern const u8 gKeyboardLayoutEntryIndices[6];
extern const u8 gKeyboardRemainingEntryIndices[6];
extern const u8 gKeyboardCursorCornerEntryIndices[2][4];
extern const s16 gKeyboardTextOffsetYTarget[2][2];
extern const s16 gKeyboardTextOffsetYInitial[2][2];
extern const u8 gKeyboardTextSlotEntryIndices[10];
