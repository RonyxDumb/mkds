#include "Main/Menu/title_state_handlers.h"
#include "Main/Menu/title_state0.h"
#include "Main/Menu/title_state1.h"
#include "Main/Menu/title_state2.h"
#include "Main/Menu/title_state3.h"
#include "Main/Menu/title_state4.h"
#include "Main/Menu/title_state5.h"
#include "Main/Menu/title_state6.h"
#include "Main/Menu/title_input.h"
#include "Main/Menu/title_table_draw.h"

TitleStateHandlers gTitleStateHandlers[7] = {
    {TitleBlendInNop, (void (*)(s32)) UpdateTitleBlendIn},
    {(void (*)(void)) TitleSlideInReturnArgumentWrapper, (void (*)(s32)) UpdateTitleSlideIn},
    {(void (*)(void)) TitleMenuInputReturnArgumentWrapper, (void (*)(s32)) UpdateTitleMenuInput},
    {(void (*)(void)) TitleSlideOutReturnArgumentWrapper, (void (*)(s32)) UpdateTitleSlideOut},
    {(void (*)(void)) TitleSelectPressReturnArgumentWrapper, (void (*)(s32)) UpdateTitleSelectPress},
    {TitleLeaveNop, (void (*)(s32)) UpdateTitleLeave},
    {TitleRequestNicknameSceneNop, (void (*)(s32)) UpdateTitleRequestNicknameScene},
};
