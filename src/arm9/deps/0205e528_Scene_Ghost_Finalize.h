#pragma once
/* Function-specific inferred declarations. */
void Scene_Ghost_FinalizeImpl_from_thumb(void);
void Scene_Ghost_Finalize(void);
#define pcRam0205e52c (*(__typeof__(Scene_Ghost_FinalizeImpl_from_thumb) **)(uintptr_t)0x205e52cu)
