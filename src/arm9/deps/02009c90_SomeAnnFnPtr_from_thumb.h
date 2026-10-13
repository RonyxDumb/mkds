#pragma once
/* Function-specific inferred declarations. */
int SomeAnnFnPtr_Impl_from_thumb(void);
void SomeAnnFnPtr_from_thumb(void);
#define pcRam02009c94 (*(__typeof__(SomeAnnFnPtr_Impl_from_thumb) **)(uintptr_t)0x2009c94u)
