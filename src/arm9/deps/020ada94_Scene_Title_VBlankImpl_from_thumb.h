#pragma once
/* Function-specific inferred declarations. */
void CopyOamBuffersToMemory_from_thumb(int param_1,int param_2);
void NavigationContext_OnSceneVblank_from_thumb(void);
void Scene_Title_VBlankImpl_from_thumb(void);
#define iRam020adacc (*(int *)(uintptr_t)0x20adaccu)
#define piRam020adac8 (*(int **)(uintptr_t)0x20adac8u)
