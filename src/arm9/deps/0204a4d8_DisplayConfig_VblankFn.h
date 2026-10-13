#pragma once
/* Function-specific inferred declarations. */
void DisplayConfig_VblankFnImpl(void);
void DisplayConfig_VblankFn(void);
#define pcRam0204a4e0 (*(__typeof__(DisplayConfig_VblankFnImpl) **)(uintptr_t)0x204a4e0u)
