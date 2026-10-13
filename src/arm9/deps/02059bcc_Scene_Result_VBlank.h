#pragma once
/* Function-specific inferred declarations. */
void Scene_Result_VBlankImpl_from_thumb(void);
void Scene_Result_VBlank(void);
#define pcRam02059bd4 (*(__typeof__(Scene_Result_VBlankImpl_from_thumb) **)(uintptr_t)0x2059bd4u)
