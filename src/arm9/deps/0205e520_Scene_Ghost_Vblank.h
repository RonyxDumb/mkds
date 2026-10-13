#pragma once
/* Function-specific inferred declarations. */
void Scene_Ghost_VblankImpl_from_thumb(void);
void Scene_Ghost_Vblank(void);
#define pcRam0205e524 (*(__typeof__(Scene_Ghost_VblankImpl_from_thumb) **)(uintptr_t)0x205e524u)
