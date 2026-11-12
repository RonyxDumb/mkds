#pragma once

#include "types.h"
#include "Main/Graphics/scene_text_init.h"

// Returns the scene number the Keyboard screen asks for (-1 = none yet); UpdateKeyboardScene copies it into
// SceneNumbers.mNextScene when it is not -1.
u32 GetKeyboardNextScene(void);
void WriteKeyboardRegisters(void);
// Advances the Keyboard screen by one step: takes mNextState as mState, runs the handler of that state
// (AdvanceKeyboardState0 to AdvanceKeyboardState13) and then runs the cell and drawing helpers of the screen.
void AdvanceKeyboard(void);
void ShowKeyboardLayoutObject(void);
void ShowKeyboardRemainingCharObjects(void);
void ShowKeyboardTextIndexObject(void);
void ShowKeyboardDisabledButtonObjects(void);
void ShowKeyboardCursorButtonObjects(void);
void PrintKeyboardTextChars(void);
// Handler of state 13 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState13(void);
// Handler of state 12 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState12(void);
// Handler of state 11 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState11(void);
// Handler of state 10 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState10(void);
// Handler of state 9 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState9(void);
// Handler of state 8 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState8(void);
// Handler of state 7 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState7(void);
// Handler of state 6 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState6(void);
void UpdateKeyboardNameButtons(void);

// Handler of state 5 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState5(void);
// Handler of state 4 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState4(void);
// Handler of state 3 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState3(void);
// Handler of state 2 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState2(void);
// Handler of state 1 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState1(void);
void UpdateKeyboardFriendKeyButtons(void);
// Handler of state 0 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState0(void);
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
