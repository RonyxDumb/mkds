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
    {TitleState0Nop, (void (*)(s32)) UpdateTitleState0},
    {(UnkFunc *) TitleState1ReturnArgumentWrapper, (void (*)(s32)) UpdateTitleState1},
    {(UnkFunc *) TitleState2ReturnArgumentWrapper, (void (*)(s32)) UpdateTitleState2},
    {(UnkFunc *) TitleState3ReturnArgumentWrapper, (void (*)(s32)) UpdateTitleState3},
    {(UnkFunc *) TitleState4ReturnArgumentWrapper, (void (*)(s32)) UpdateTitleState4},
    {TitleState5Nop, (void (*)(s32)) UpdateTitleState5},
    {TitleState6Nop, (void (*)(s32)) UpdateTitleState6},
};
