#pragma once
/* Function-specific inferred declarations. */
void Scene_Menu_VBlankImpl_from_thumb(void);
void Scene_Menu_VBlank(void);
#define pcRam02039f58 (*(__typeof__(Scene_Menu_VBlankImpl_from_thumb) **)(uintptr_t)0x2039f58u)
