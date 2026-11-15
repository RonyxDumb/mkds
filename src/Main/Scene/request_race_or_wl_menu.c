#include "Main/Scene/request_race_or_wl_menu.h"
#include "Main/Menu/wl_menu_kind.h"
#include "Main/System/scene_numbers.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Menu/wl_menu_kind_set.h"
#include "Main/Menu/multi_simple.h"
#include "Main/Menu/menu_connection_kind.h"

#pragma thumb on
#pragma optimize_for_size on
void RequestRaceOrWLMenuScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        if (MenuGetConnectionKind() != CONNECTION_KIND_NONE && GetMultiSimple() != 0) {
            sceneNumbers->mNextScene = SCENE_WL_MENU;
            SetWLMenuKind(WL_MENU_KIND_TO_RACE);
        } else {
            sceneNumbers->mNextScene = SCENE_RACE;
        }
    }
}
#pragma thumb off
