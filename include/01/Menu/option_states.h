#pragma once

#include "types.h"

// Values of OptionStates.mState, mNextState and mPrevState and of the argument of RequestOptionState. The first four
// have screen callbacks; the last three stand for the scene the option scene was entered from or leaves to (title,
// keyboard, emblem). OptionStates.mNextState is OPTION_STATE_NONE while no change is requested.
enum {
    OPTION_STATE_NONE = -1,
    OPTION_STATE_TOP_MENU,
    OPTION_STATE_SELECT_MENU,
    OPTION_STATE_HENSYU_MENU,
    OPTION_STATE_EMBREM_SELECT,
    OPTION_STATE_SCENE_TITLE,
    OPTION_STATE_SCENE_KEYBOARD,
    OPTION_STATE_SCENE_EMBLEM,
};

void RequestOptionNextScene(u16 nextScene);
int GetOptionNextScene(void);
u32 GetOptionPrevState(void);
void RequestOptionState(u32 nextState);
void SetOptionStateCallbacks(UnkFunc **callbacks);
void WriteOptionStatesRegisters(void);
void AdvanceOptionStates(void);
void ReleaseOptionStates(void);
void InitOptionStates(void *heap, s16 a);
void SetupOptionBackgrounds(void);
void LoadOptionData(void);
void ClearOptionStateCallbacks(void);
