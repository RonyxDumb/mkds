#include "Main/Menu/title_state_handlers.h"
#include "Main/Menu/title_blend_in.h"
#include "Main/Menu/title_slide_in.h"
#include "Main/Menu/title_menu_input.h"
#include "Main/Menu/title_slide_out.h"
#include "Main/Menu/title_select_press.h"
#include "Main/Menu/title_leave.h"
#include "Main/Menu/title_request_nickname_scene.h"
#include "Main/Menu/title_input.h"
#include "Main/Menu/title_table_draw.h"

TitleStateHandlers g_HUFunctionList[7] = {
    {TitleBlendInNop, (void (*)(s32)) UpdateTitleBlendIn},
    {(void (*)(void)) TitleSlideInReturnArgumentWrapper, (void (*)(s32)) UpdateTitleSlideIn},
    {(void (*)(void)) TitleMenuInputReturnArgumentWrapper, (void (*)(s32)) UpdateTitleMenuInput},
    {(void (*)(void)) TitleSlideOutReturnArgumentWrapper, (void (*)(s32)) UpdateTitleSlideOut},
    {(void (*)(void)) TitleSelectPressReturnArgumentWrapper, (void (*)(s32)) UpdateTitleSelectPress},
    {TitleLeaveNop, (void (*)(s32)) UpdateTitleLeave},
    {TitleRequestNicknameSceneNop, (void (*)(s32)) UpdateTitleRequestNicknameScene},
};
