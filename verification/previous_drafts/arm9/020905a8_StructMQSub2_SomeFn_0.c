/* Decompiled C draft; module arm9; ROM address 020905a8. No matching claim. */
#include "types.h"
#include "deps/020905a8_StructMQSub2_SomeFn_0.h"

bool StructMQSub2_SomeFn_0(int param_1)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  
  bVar5 = false;
  *(short *)(param_1 + 0x28) = *(short *)(param_1 + 0x28) + -1;
  sVar2 = *(short *)(param_1 + 0x28);
  if (sVar2 < 1) {
    *(undefined2 *)(param_1 + 0x28) = 0;
  }
  iVar3 = GetDriverEntry(*(undefined2 *)(param_1 + 0x24));
  uVar1 = iVar3 + 0x44U & 3;
  uVar4 = *(uint *)(iVar3 + 0x44U & 0xfffffffc);
  bVar6 = ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xc0) == 0;
  if (!bVar6) {
    *(undefined2 *)(param_1 + 0x28) = 5;
  }
  if (bVar6 && sVar2 < 1) {
    if (*(short *)(param_1 + 0x28) < 1) {
      *(undefined2 *)(param_1 + 0x26) = 0;
    }
  }
  else {
    *(short *)(param_1 + 0x26) = *(short *)(param_1 + 0x26) + 1;
    sVar2 = *(short *)(param_1 + 0x26);
    if (0x77 < sVar2) {
      *(undefined2 *)(param_1 + 0x26) = 0;
    }
    bVar5 = 0x77 < sVar2;
  }
  return bVar5;
}

