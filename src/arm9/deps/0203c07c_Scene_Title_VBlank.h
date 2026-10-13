#pragma once
/* Function-specific inferred declarations. */
void Scene_Title_VBlankImpl_from_thumb(void);
void Scene_Title_VBlank(void);
#define pcRam0203c084 (*(__typeof__(Scene_Title_VBlankImpl_from_thumb) **)(uintptr_t)0x203c084u)
