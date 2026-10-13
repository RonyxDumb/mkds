#pragma once
/* Function-specific inferred declarations. */
int CreateDisplayConfig(undefined4 param_1,undefined4 param_2);
void DisplayConfig_SetBottomEngineObjVramModeBmp(int param_1,undefined2 param_2);
void DisplayConfig_SetSwapBufferValues(int param_1,undefined1 param_2,undefined1 param_3);
void DisplayEngineConfig_SetBg0Config(undefined2 *param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8);
void DisplayEngineConfig_SetBg1Config(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7,undefined2 param_8);
void DisplayEngineConfig_SetBg2Config(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6);
void DisplayEngineConfig_SetBg2Config2(int param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,undefined2 param_6,undefined2 param_7);
void SetGlobalDisplayConfig(int param_1);
void SetGlobalDisplayConfigForDisplayMode(undefined4 param_1);
void func_02055f68(void);
void func_02056114(undefined4 param_1);
#define DAT_0203afd8 (*(uint *)(uintptr_t)0x203afd8u)
#define DAT_0203afdc (*(int *)(uintptr_t)0x203afdcu)
#define DAT_0203afe0 (*(ushort **)(uintptr_t)0x203afe0u)
