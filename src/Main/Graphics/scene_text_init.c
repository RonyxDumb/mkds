#include "Main/Graphics/scene_text_init.h"
#include "Main/System/heap.h"

#include "Main/Graphics/back_screen.h"
#include "Main/Menu/txt_system.h"
#include "Main/Menu/select_return.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"
#include "01/Menu/option_select_menu.h"

SceneText *g_NavigationContext;

#pragma thumb on

void InitializeNavigationContext_from_thumb(void *heap, SceneTextInitParams *config) {
    TxtSystemArgs txtConfig;

    g_NavigationContext = Mem_AllocateHeap(heap, sizeof(*g_NavigationContext));
    g_NavigationContext->mSubCharOffset = SCENE_TEXT_SUB_CHAR_OFFSET;
    g_NavigationContext->mUseTxtSystem = FALSE;
    g_NavigationContext->mUseSelectChoises = FALSE;
    g_NavigationContext->mUseSelectReturn = FALSE;
    if (config->mUseTxtSystem != FALSE) {
        txtConfig.mFont = config->mTxtSystemFont;
        txtConfig.mUseCanvas1 = config->mUseCanvas1;
        txtConfig.mUseCanvas2 = config->mUseCanvas2;
        txtConfig.mUseCanvas3 = config->mUseCanvas3;
        txtConfig.mSubCharOffset = g_NavigationContext->mSubCharOffset;
        g_NavigationContext->mUseTxtSystem = TRUE;
        g_NavigationContext->mSubCharOffset = TextSystemContext_Initialize_from_thumb(heap, &txtConfig);
    }
    if (config->mUseSelectChoises != FALSE) {
        g_NavigationContext->mUseSelectChoises = TRUE;
        g_NavigationContext->mSubCharOffset = SelectChoisesContext_Initialize_from_thumb(heap, config->mSelectChoisesFont, g_NavigationContext->mSubCharOffset);
    }
    if (config->mUseSelectReturn != FALSE) {
        g_NavigationContext->mUseSelectReturn = TRUE;
        g_NavigationContext->mSubCharOffset = InitializeSelectReturn_from_thumb(heap, g_NavigationContext->mSubCharOffset);
    }
    if (config->mUseBackScreen != FALSE) {
        g_NavigationContext->mBackScreenKind = config->mBackScreenKind;
        InitBackScreenDisplay();
        g_NavigationContext->mSubCharOffset = InitializeBackScreen_from_thumb(g_NavigationContext->mSubCharOffset);
    }
}

#pragma thumb off

#pragma thumb on

void DisposeNavigationContext_from_thumb(void) {
    if (g_NavigationContext->mUseTxtSystem != FALSE) {
        TextSystemContext_Dispose_from_thumb();
    }
    if (g_NavigationContext->mUseSelectChoises != FALSE) {
        SelectChoisesContext_Dispose_from_thumb();
    }
    if (g_NavigationContext->mUseSelectReturn != FALSE) {
        SelectReturnContext_Dispose_from_thumb();
    }
    *&g_NavigationContext = NULL;
}

#pragma thumb off
