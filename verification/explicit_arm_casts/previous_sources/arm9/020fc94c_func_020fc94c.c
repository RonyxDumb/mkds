/* Decompiled C draft; module arm9; ROM address 020fc94c. No matching claim. */
#include "types.h"
#include "deps/020fc94c_func_020fc94c.h"

void func_020fc94c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  func_0210b850(param_1 + 0x300);
  *(undefined4 *)(param_1 + 0x30) = uRam020fcab4;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0xcc) = *(undefined4 *)(param_1 + 0x58);
  func_020f9c40(param_1);
  uVar3 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20 | 0x200000;
  func_020fd254(param_1);
  uVar2 = uRam020fcabc;
  uVar1 = uRam020fcab8;
  uVar6 = *(uint *)(uRam020fcab8 & 0xfffffffc) >> (uRam020fcab8 & 3) * 8 |
          *(uint *)(uRam020fcab8 & 0xfffffffc) << (uRam020fcab8 & 3) * -8 + 0x20;
  uVar3 = uVar6 + 0x4cc;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
    *(short *)(param_1 + 0x276) =
         (short)*(char *)(uVar6 + (*(ushort *)(param_1 + 0x274) & 0xff) + 0x473);
    while ((iVar4 = IsRacerFinishedRace(*(undefined2 *)(param_1 + 0x276)), iVar4 != 0 &&
           (uVar3 = uVar2 & 3, uVar5 = *(uint *)(uVar2 & 0xfffffffc),
           *(ushort *)(param_1 + 0x274) <
           (ushort)*(byte *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x3d0)))) {
      *(short *)(param_1 + 0x274) = *(short *)(param_1 + 0x274) + 1;
      *(short *)(param_1 + 0x276) =
           (short)*(char *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
                            (*(ushort *)(param_1 + 0x274) & 0xff) + 0x473);
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x274) = 1;
    *(short *)(param_1 + 0x276) =
         (short)*(char *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                          *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
                          (*(ushort *)(param_1 + 0x274) & 0xff) + 0x473);
  }
  *(undefined4 *)(param_1 + 0x260) = 0x32000;
  *(undefined4 *)(param_1 + 0x264) = 0xf000;
  *(undefined2 *)(param_1 + 0x268) = 0;
  *(undefined4 *)(param_1 + 0x27c) = 0x1a000;
  *(undefined4 *)(param_1 + 0x298) = 0;
  *(undefined4 *)(param_1 + 0x29c) = 0;
  *(undefined4 *)(param_1 + 0x2a0) = 0;
  VecFx32_Subtract(param_1 + 0x5c,param_1 + 0x298,param_1 + 0x28c);
  *(int *)(param_1 + 0xd0) = param_1 + 0xc4;
  LightInfo_SomeFn(param_1 + 0x7c,1);
  return;
}

