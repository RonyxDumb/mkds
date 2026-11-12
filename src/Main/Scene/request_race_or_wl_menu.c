#include "Main/Scene/request_race_or_wl_menu.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Menu/wl_menu_kind_set.h"
#include "Main/Menu/multi_simple.h"
#include "Main/Menu/menu_connection_kind.h"

#pragma thumb on
#pragma optimize_for_size on
void RequestRaceOrWLMenuScene(SceneNumbers *sceneNumbers) {
    if (sceneNumbers != NULL) {
        if (MenuGetConnectionKind() != 0 && GetMultiSimple() != 0) {
            sceneNumbers->mNextScene = 6;
            SetWLMenuKind(1);
        } else {
            sceneNumbers->mNextScene = 2;
        }
    }
}
#pragma thumb off
