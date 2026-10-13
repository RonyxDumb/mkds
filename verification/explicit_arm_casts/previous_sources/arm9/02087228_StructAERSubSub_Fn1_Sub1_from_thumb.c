/* Decompiled C draft; module arm9; ROM address 02087228. No matching claim. */
#include "types.h"
#include "deps/02087228_StructAERSubSub_Fn1_Sub1_from_thumb.h"

void StructAERSubSub_Fn1_Sub1_from_thumb(int param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  
  puVar3 = (undefined2 *)*puRam02087288;
  iVar2 = *piRam0208728c + param_2 * 4;
  uVar4 = *(undefined4 *)(iVar2 + iRam02087290);
  Mem_CpuCopy8(*(undefined4 *)(iVar2 + iRam02087294),puVar3,*(undefined2 *)(param_1 + 8));
  uVar1 = (undefined2)uRam02087298;
  if (*(char *)(*piRam0208729c + 0x58) != '\0') {
    uVar1 = *(undefined2 *)(iRam020872a0 + *(int *)(*piRam0208729c + param_2 * 0x30 + 0x74) * 2);
  }
  *puVar3 = uVar1;
  Arm_FlushRange(puVar3,*(undefined2 *)(param_1 + 8));
  Arm_FlushRange(uVar4,*(undefined4 *)(param_1 + 4));
  *(undefined2 **)(param_1 + 0x10) = puVar3;
  *(undefined4 *)(param_1 + 0xc) = uVar4;
  return;
}

