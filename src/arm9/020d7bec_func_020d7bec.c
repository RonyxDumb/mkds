/* Decompiled C draft; module arm9; ROM address 020d7bec. No matching claim. */
#include "types.h"
#include "deps/020d7bec_func_020d7bec.h"

void func_020d7bec(int param_1)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = param_1 + 8U & 3;
  uVar6 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar2 = param_1 + 0x20U & 3;
  uVar8 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
  uVar7 = func_02148538(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20,
                        uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20);
  puVar5 = puRam020d7c7c;
  iVar1 = (int)((uint)(((int)(((int)uVar7 >> 0x1f) * uRam020d7c74 +
                              uVar7 * iRam020d7c78 +
                              (int)((ulonglong)uRam020d7c74 * (ulonglong)uVar7 >> 0x20) + 0x800) >>
                       0xc) << 0x10) >> 0x11) >> 4;
  sVar3 = *(short *)(iRam020d7c80 + iVar1 * 4);
  sVar4 = *(short *)(iRam020d7c80 + (iVar1 * 2 + 1) * 2);
  *puRam020d7c7c = 0;
  puVar5[1] = (int)sVar3;
  puVar5[2] = 0;
  puVar5[3] = (int)sVar4;
  return;
}

