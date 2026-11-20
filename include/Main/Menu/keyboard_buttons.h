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

// Results of CheckFriendKeyString: 0 accepts the key, 1 a key that fails the key check or equals the key made from the
// user data, 2 a key already in the friend list; the last two choose the rejection message.
#define FRIEND_KEY_CHECK_INCORRECT 1
#define FRIEND_KEY_CHECK_ALREADY_REGISTERED 2

// Rect indices the touch lookup returns on the friend code screen (the first button, the second button) and on the
// name screen (the five layout tabs come first, then the two buttons).
#define KEYBOARD_FRIEND_KEY_RECT_FIRST_BUTTON 1
#define KEYBOARD_FRIEND_KEY_RECT_SECOND_BUTTON 0
#define KEYBOARD_NAME_RECT_LAYOUT_JP 0
#define KEYBOARD_NAME_RECT_LAYOUT_ASCII 1
#define KEYBOARD_NAME_RECT_LAYOUT_EURO 2
#define KEYBOARD_NAME_RECT_LAYOUT_PICTO 3
#define KEYBOARD_NAME_RECT_LAYOUT_PICTO_SECOND 4
#define KEYBOARD_NAME_RECT_FIRST_BUTTON 5
#define KEYBOARD_NAME_RECT_SECOND_BUTTON 6

// Returns the scene number the Keyboard screen asks for (-1 = none yet); UpdateKeyboardScene copies it into
// SceneNumbers.mNextScene when it is not -1.
u32 GetKeyboardNextScene(void);
void WriteKeyboardRegisters(void);
// Advances the Keyboard screen by one step: advances the link level icons and the scene text, takes mNextState as
// mState, advances the text entry while mTextEntryEnabled is set, runs the handler of that state (one AdvanceKeyboard
// handler per KEYBOARD_STATE_* value) and then prints the text and shows and draws the screen's objects and layout
// tables.
void AdvanceKeyboard(void);
void ShowKeyboardLayoutObject(void);
void ShowKeyboardRemainingCharObjects(void);
void ShowKeyboardTextIndexObject(void);
void ShowKeyboardDisabledButtonObjects(void);
void ShowKeyboardCursorButtonObjects(void);
void PrintKeyboardTextChars(void);
void AdvanceKeyboardAskEmblem(void);
void AdvanceKeyboardWaitBackup(void);
void AdvanceKeyboardShowSaving(void);
void AdvanceKeyboardAnswerConfirm(void);
void AdvanceKeyboardSlideInConfirm(void);
void AdvanceKeyboardSlideOutName(void);
void AdvanceKeyboardEnterName(void);
void AdvanceKeyboardSlideInName(void);
void UpdateKeyboardNameButtons(void);

void AdvanceKeyboardWaitFadeName(void);
void AdvanceKeyboardShowFriendKeyError(void);
void AdvanceKeyboardSlideOutFriendKey(void);
void AdvanceKeyboardEnterFriendKey(void);
void AdvanceKeyboardSlideInFriendKey(void);
void UpdateKeyboardFriendKeyButtons(void);
void AdvanceKeyboardWaitFadeFriendKey(void);
void InitKeyboardDisplay(void);

void LoadKeyboardFiles(void);
void QueueKeyboardScreenMap(void);

void WriteKeyboardObjectOffsets(void);

// Releases the helper objects of the Keyboard screen and clears gKeyboard; the memory is freed with the scene heap.
void ReleaseKeyboard(void);

void PrintKeyboardButtonTexts(void);
void InitKeyboardCursorCorners(void);
void HideKeyboardFirstBufferObjects(void);
void SetKeyboardTextFromFriendKey(void);
void SetKeyboardTextFromName(void);
void SetKeyboardTextFromPlayerName(void);
void CopyKeyboardTextAsBytes(void);
void InitKeyboard(void *heap, s32 mode);

void SetKeyboardButtonCorners(void);

BOOL IsLocateFriendOnWithBuddyStatus4(void);
void InitKeyboardLabelCanvases(void);

extern Keyboard *gKeyboard;

extern const u8 gKeyboardKindEntryCounts[2];
extern const u8 gKeyboardKindEntryIndices[2][1];
extern const u8 gKeyboardTextLimits[2];
extern const u8 gKeyboardButtonLabelIndices[2][2];
extern const u8 gKeyboardLayoutEntryIndices[6];
extern const u8 gKeyboardRemainingEntryIndices[6];
extern const u8 gKeyboardCursorCornerEntryIndices[2][4];
extern const s16 gKeyboardTextOffsetYTarget[2][2];
extern const s16 gKeyboardTextOffsetYInitial[2][2];
extern const u8 gKeyboardTextSlotEntryIndices[10];
