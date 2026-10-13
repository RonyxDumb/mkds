#pragma once
/* Function-specific inferred declarations. */
void Scene_WLMenu_VblankImpl_from_thumb(void);
void Scene_WLMenu_Vblank(void);
#define pcRam0204b02c (*(__typeof__(Scene_WLMenu_VblankImpl_from_thumb) **)(uintptr_t)0x204b02cu)
