/* Decompiled C draft; module arm9; ROM address 020871c0. No matching claim. */
#include "types.h"
#include "deps/020871c0_StructAERSubSub_Fn1_Sub2_from_thumb.h"

void StructAERSubSub_Fn1_Sub2_from_thumb(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  
  uVar3 = *puRam02087218;
  puVar2 = (undefined2 *)*puRam0208721c;
  *puVar2 = (short)uRam02087220;
  uVar1 = GetVsRacerIndicatorColor_from_thumb(param_2);
  puVar2[1] = uVar1;
  puVar2[2] = 0;
  puVar2[3] = 0x1f;
  Arm_FlushRange((uint)(uintptr_t)(puVar2),8);
  Mem_CpuFill8((uint *)(uintptr_t)(uVar3),0,*(undefined4 *)(param_1 + 4));
  func_020adddc(param_2,uVar3,1,2);
  Arm_FlushRange(uVar3,uRam02087224);
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  *(undefined2 **)(param_1 + 0x10) = puVar2;
  return;
}

