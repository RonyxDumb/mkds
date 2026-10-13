#pragma once
/* Function-specific inferred declarations. */
void GX_DisableBankForARM7(void);
void GX_DisableBankForBGExtPltt(void);
void GX_DisableBankForClearImage(void);
void GX_DisableBankForLCDC(void);
void GX_DisableBankForOBJExtPltt(void);
void GX_DisableBankForSubBG(void);
void GX_DisableBankForSubOBJ(void);
void GX_DisableBankForTexPltt(void);
void ResetSomeVram(void);
void func_02148dfc(void);
void func_02148e10(void);
void func_02148e34(void);
void func_02148e58(void);
void func_02148e6c(void);
#define DAT_02039b90 (*(uint *)(uintptr_t)0x2039b90u)
