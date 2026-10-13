/* Decompiled C draft; module arm9; ROM address 020dfafc. No matching claim. */
#include "types.h"
#include "deps/020dfafc_func_020dfafc.h"

/* WARNING: Type propagation algorithm not settling */

void func_020dfafc(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int aiStack_38 [2];
  undefined1 auStack_30 [36];
  
  if (*(short *)(param_2 + 0x8e) != 0) {
    return;
  }
  aiStack_38[1] = 0x1e;
  func_01ff9048(0x14,aiStack_38 + 1,1);
  uVar3 = func_020e6cf8(param_2 + 4);
  func_01ff9048(0x19,uVar3,0xc);
  if (*(ushort *)(param_2 + 0xa8) != 0) {
    iVar5 = (int)(uint)*(ushort *)(param_2 + 0xa8) >> 4;
    MTX_RotZ33__from_thumb
              (auStack_30,(int)*(short *)(iRam020dfc3c + iVar5 * 4),
               (int)*(short *)(iRam020dfc3c + (iVar5 * 2 + 1) * 2));
    func_01ff9048(0x1a,auStack_30,9);
  }
  func_01ff9048(0x1b,param_2 + 0x1c,3);
  func_020ea7cc(*(uint *)(uRam020dfc40 & 0xfffffffc) >> (uRam020dfc40 & 3) * 8 |
                *(uint *)(uRam020dfc40 & 0xfffffffc) << (uRam020dfc40 & 3) * -8 + 0x20,param_4);
  uVar1 = param_2 + 8U & 3;
  uVar6 = *(uint *)(param_2 + 8U & 0xfffffffc);
  uVar2 = param_2 + 0xacU & 3;
  uVar4 = *(uint *)(param_2 + 0xacU & 0xfffffffc);
  iVar5 = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) -
          (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
  if (iVar5 < 0x10001) {
    iVar5 = 0xd - (0x10000 - iVar5 >> 0xd);
    aiStack_38[0] = 0x1000;
    if (iVar5 < 1) {
      iVar5 = 1;
    }
    *(short *)(param_2 + 0xe0) = (short)iVar5;
  }
  else {
    aiStack_38[0] = 0x1000 - (iVar5 + -0x10000 >> 8);
    *(undefined2 *)(param_2 + 0xe0) = 0xd;
  }
  if (0 < aiStack_38[0]) {
    func_020e53ac(param_2 + 0xb0,aiStack_38,0,param_4);
    return;
  }
  return;
}

