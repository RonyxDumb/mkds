#pragma once
/* Function-specific inferred declarations. */
void Arm_FlushRange(uint param_1,int param_2);
void CopyBgData_Bg2_Bottom(undefined4 param_1,int param_2,uint param_3);
void CopyBgData_Bg3_Bottom(undefined4 param_1,int param_2,uint param_3);
void CopyPaletteBottom(undefined4 param_1,int param_2,uint param_3);
void DC_func_0002(void);
uint ExecutionContext_GetHeapHandle(int param_1);
void GXS_EndLoadBGExtPltt(void);
void GX_SetBankForSubBGExtPltt(int param_1);
uint GetActiveExecutionContext(void);
int GetMountData7FlagBit31_from_thumb(void);
void Gfx_ReadCharGraphicsV2(int *param_1,int param_2);
void Gfx_ReadPalette(int *param_1,int param_2);
void Gfx_ReadPaletteRelative(int *param_1,int param_2);
void LoadMap2DStuff(void);
undefined4 MaybeCircuitUsesLocal3(void);
void MaybeReadCharBlock_1(int *param_1,int param_2);
void MaybeReadScreenBlock(int *param_1,int param_2);
void MaybeReadScreenBlock_0(int *param_1,int param_2);
undefined4 Mem_AllocateHeap(uint param_1,undefined4 param_2);
void SetDispcntSubBgMode(uint param_1);
void TEQSub_Fn26Impl_Fn28Impl(undefined4 param_1,int param_2,uint param_3);
void TEQSub_Fn27Impl_Fn29Impl(undefined4 param_1,int param_2,uint param_3);
void func_020b18b0(void);
void func_020b47b4(void);
void func_0214b468(undefined4 param_1,int param_2,undefined4 param_3);
void func_0214b4dc(void);
#define puRam020b0358 (*(undefined4 **)(uintptr_t)0x20b0358u)
#define puRam020b03ac (*(uint **)(uintptr_t)0x20b03acu)
#define puRam020b03b0 (*(undefined4 **)(uintptr_t)0x20b03b0u)
#define puRam020b03b4 (*(ushort **)(uintptr_t)0x20b03b4u)
#define puRam020b03b8 (*(ushort **)(uintptr_t)0x20b03b8u)
#define uRam020b0354 (*(uint *)(uintptr_t)0x20b0354u)
#define uRam020b035c (*(undefined4 *)(uintptr_t)0x20b035cu)
#define uRam020b0360 (*(undefined4 *)(uintptr_t)0x20b0360u)
#define uRam020b0364 (*(undefined4 *)(uintptr_t)0x20b0364u)
#define uRam020b0368 (*(undefined4 *)(uintptr_t)0x20b0368u)
#define uRam020b036c (*(undefined4 *)(uintptr_t)0x20b036cu)
#define uRam020b0370 (*(undefined4 *)(uintptr_t)0x20b0370u)
#define uRam020b0374 (*(undefined4 *)(uintptr_t)0x20b0374u)
#define uRam020b0378 (*(undefined4 *)(uintptr_t)0x20b0378u)
#define uRam020b037c (*(undefined4 *)(uintptr_t)0x20b037cu)
#define uRam020b0380 (*(undefined4 *)(uintptr_t)0x20b0380u)
#define uRam020b0384 (*(undefined4 *)(uintptr_t)0x20b0384u)
#define uRam020b0388 (*(undefined4 *)(uintptr_t)0x20b0388u)
#define uRam020b038c (*(undefined4 *)(uintptr_t)0x20b038cu)
#define uRam020b0390 (*(undefined4 *)(uintptr_t)0x20b0390u)
#define uRam020b0394 (*(undefined4 *)(uintptr_t)0x20b0394u)
#define uRam020b0398 (*(undefined4 *)(uintptr_t)0x20b0398u)
#define uRam020b039c (*(undefined4 *)(uintptr_t)0x20b039cu)
#define uRam020b03a0 (*(undefined4 *)(uintptr_t)0x20b03a0u)
#define uRam020b03a4 (*(undefined4 *)(uintptr_t)0x20b03a4u)
#define uRam020b03a8 (*(undefined4 *)(uintptr_t)0x20b03a8u)
