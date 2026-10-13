#pragma once
/* Function-specific inferred declarations. */
void ConfigureDispcntDisplay(ushort param_1,uint param_2,int param_3);
void G3X_Initialize(void);
void G3X_InitializeMatrixStack(void);
void G3X_InitializeTable(void);
void G3X_SetClearColor(uint param_1,int param_2,undefined2 param_3,int param_4,int param_5);
void G3X_SetHOffset(undefined4 param_1);
void GX_SetBankForLCDC(ushort param_1);
void GX_SetBankForOBJExtPltt(int param_1);
void GX_SetBankForSubBGExtPltt(int param_1);
void GX_SetBankForSubOBJExtPltt(int param_1);
void MaybePrepareVram(void);
void Mem_CpuFastMemorySet(undefined4 param_1,undefined4 *param_2,uint param_3);
void SetDispcntSubBgMode(uint param_1);
void SetGlobalDisplayConfig(int param_1);
void SetGlobalDisplayConfig_Bg2(uint param_1,int param_2);
void SetGlobalDisplayConfig_Bg3(uint param_1,int param_2);
void func_02039b94(void);
void func_021491b0(int param_1);
void func_0214922c(int param_1);
void func_021493b0(undefined4 param_1);
void func_021494f0(int param_1);
void func_021495e4(int param_1);
void func_021498a0(int param_1);
void func_021499b4(int param_1);
void func_02149b20(int param_1);
#define _DAT_04000000 (*(uint *)(uintptr_t)0x4000000u)
#define piRam020380b4 (*(int **)(uintptr_t)0x20380b4u)
#define puRam020380c4 (*(uint **)(uintptr_t)0x20380c4u)
#define puRam020380c8 (*(ushort **)(uintptr_t)0x20380c8u)
#define puRam020380d0 (*(undefined2 **)(uintptr_t)0x20380d0u)
#define puRam020380d4 (*(undefined2 **)(uintptr_t)0x20380d4u)
#define puRam020380d8 (*(uint **)(uintptr_t)0x20380d8u)
#define puRam020380e0 (*(ushort **)(uintptr_t)0x20380e0u)
#define puRam020380e4 (*(undefined4 **)(uintptr_t)0x20380e4u)
#define puRam020380e8 (*(undefined4 **)(uintptr_t)0x20380e8u)
#define puRam020380ec (*(ushort **)(uintptr_t)0x20380ecu)
#define puRam020380f0 (*(undefined4 **)(uintptr_t)0x20380f0u)
#define puRam020380f4 (*(ushort **)(uintptr_t)0x20380f4u)
#define puRam020380f8 (*(undefined4 **)(uintptr_t)0x20380f8u)
#define puRam020380fc (*(ushort **)(uintptr_t)0x20380fcu)
#define puRam02038108 (*(ushort **)(uintptr_t)0x2038108u)
#define uRam020380b8 (*(undefined4 *)(uintptr_t)0x20380b8u)
#define uRam020380bc (*(undefined4 *)(uintptr_t)0x20380bcu)
#define uRam020380c0 (*(uint *)(uintptr_t)0x20380c0u)
#define uRam020380cc (*(undefined4 *)(uintptr_t)0x20380ccu)
#define uRam020380dc (*(uint *)(uintptr_t)0x20380dcu)
#define uRam02038100 (*(uint *)(uintptr_t)0x2038100u)
#define uRam02038104 (*(uint *)(uintptr_t)0x2038104u)
