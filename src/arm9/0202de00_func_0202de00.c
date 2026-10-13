/* Decompiled C draft; module arm9; ROM address 0202de00. No matching claim. */
#include "types.h"
#include "deps/0202de00_func_0202de00.h"

void func_0202de00(int param_1,short *param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined2 *param_7)

{
  undefined4 uVar1;
  undefined1 auStack_44 [20];
  undefined1 auStack_30 [20];
  undefined2 local_1c;
  
  uVar1 = GetBmgIndexFromCircuitIndex_from_thumb(param_6);
  uVar1 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(param_1 + 0x58),uVar1);
  func_0212426c(0,(int)*param_2,*(undefined4 *)(param_1 + 0x14),uVar1,*(undefined4 *)(param_1 + 0xc)
                ,*(undefined4 *)(param_1 + 0x18));
  func_02025cd0((short *)(void *)(auStack_44),*(undefined1 *)(param_7 + 1),*(undefined1 *)((int)param_7 + 3),*param_7);
  func_02124224(0,(int)param_2[4],*(undefined4 *)(param_1 + 0x14),auStack_44,
                *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18),7);
  CopyMemory16(param_3,(int)(uintptr_t)(auStack_30),0x14);
  local_1c = 0;
  func_0212426c(0,(int)param_2[8],*(undefined4 *)(param_1 + 0x14),auStack_30,
                *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x18));
  func_0212463c(param_4,*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x38),
                *(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x44),0,(int)param_2[3],
                *(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  uVar1 = func_02124a68((int)param_2[7],*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc))
  ;
  func_021171a0(param_5,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),(int)param_2[7],
                uVar1,0);
  return;
}

