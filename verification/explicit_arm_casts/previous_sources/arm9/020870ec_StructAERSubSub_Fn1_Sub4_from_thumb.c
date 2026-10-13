/* Decompiled C draft; module arm9; ROM address 020870ec. No matching claim. */
#include "types.h"
#include "deps/020870ec_StructAERSubSub_Fn1_Sub4_from_thumb.h"

void StructAERSubSub_Fn1_Sub4_from_thumb(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  cVar1 = *(char *)(*piRam0208719c + param_2 * 0x30 + 0x96);
  if (cVar1 == '\0') {
    *(undefined4 *)(param_1 + 0xc) = 0;
    return;
  }
  iVar2 = *piRam020871a0;
  iVar3 = 7;
  if (cVar1 == '\x02') {
    iVar3 = 4;
  }
  else if (cVar1 == '\x03') {
    iVar3 = -1;
  }
  Mem_CpuCopy8(*(undefined4 *)(param_1 + 0xc),iVar2,*(undefined4 *)(param_1 + 4));
  if ((0 < iVar3) && (uVar7 = 0, *(int *)(param_1 + 4) != 0)) {
    do {
      uVar5 = (uint)*(byte *)(iVar2 + uVar7);
      uVar6 = uVar5;
      if ((int)(uVar5 & 0xf) < iVar3) {
        uVar6 = uVar5 & 0xf0;
      }
      bVar4 = (byte)uVar6;
      if ((int)(((uVar5 & 0xf0) << 0x14) >> 0x18) < iVar3) {
        bVar4 = bVar4 & 0xf;
      }
      *(byte *)(iVar2 + uVar7) = bVar4;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 4));
  }
  Arm_FlushRange(iVar2,*(undefined4 *)(param_1 + 4));
  *(int *)(param_1 + 0xc) = iVar2;
  return;
}

