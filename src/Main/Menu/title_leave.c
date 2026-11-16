#include "Main/Menu/title_leave.h"
#include "Main/Menu/title_select_press.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/System/result_archive_path.h"

#pragma optimize_for_size on
#pragma thumb on

void UpdateTitleLeave(SceneNumbers *sceneNumbers) {
    s16 nextScenes[5] = {SCENE_MENU_1, SCENE_WL_MENU, SCENE_WIFI_MENU, SCENE_OPTION, SCENE_RECORD};

    if (sceneNumbers != NULL) {
        switch (gTitleScene->mSelectedIndex) {
            case TITLE_ENTRY_FIRST:
            case TITLE_ENTRY_OPTION:
            case TITLE_ENTRY_RECORD:
            default:
                SetConnectionKind(CONNECTION_KIND_NONE);
                break;
            case TITLE_ENTRY_WL_MENU:
                SetConnectionKind(CONNECTION_KIND_WL_MENU);
                TitleSetWLMenuKind(0);
                break;
            case TITLE_ENTRY_WIFI_MENU:
                SetConnectionKind(CONNECTION_KIND_WIFI_MENU);
                break;
        }
        sceneNumbers->mNextScene = nextScenes[gTitleScene->mSelectedIndex];
        StopSceneSeqWithFadeSteps();
    }
}

#pragma thumb off
