#pragma once
/* Function-specific inferred declarations. */
void Scene_Logo_VBlankImpl(void);
void Scene_Logo_VBlank(void);
#define pcRam02057d6c (*(__typeof__(Scene_Logo_VBlankImpl) **)(uintptr_t)0x2057d6cu)
