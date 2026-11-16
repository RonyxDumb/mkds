#include "Main/Graphics/scene_text_wrapper.h"
#include "Main/Graphics/scene_text.h"
#include "Main/Graphics/scene_text_init.h"

#pragma thumb on
void j_DisposeNavigationContext_from_thumb(void) {
    u32 unused;
    DisposeNavigationContext_from_thumb();
}
#pragma thumb off

#pragma thumb on
void j_NavigationContext_OnSceneVblank_from_thumb(void) {
    u32 unused;
    NavigationContext_OnSceneVblank_from_thumb();
}
#pragma thumb off
