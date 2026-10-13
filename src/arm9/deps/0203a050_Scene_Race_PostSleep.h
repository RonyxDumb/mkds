#pragma once
/* Function-specific inferred declarations. */
void Scene_Race_PostSleepImpl(void);
void Scene_Race_PostSleep(void);
#define pcRam0203a058 (*(__typeof__(Scene_Race_PostSleepImpl) **)(uintptr_t)0x203a058u)
