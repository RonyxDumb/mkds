/* Decompiled C draft; module arm9; ROM address 02071788. No matching claim. */
#include "types.h"
#include "deps/02071788_StructMQRacerEntry_SomeFn_85.h"

void StructMQRacerEntry_SomeFn_85(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  *(short *)(param_1 + 0x3fe) = *(short *)(param_1 + 0x3fe) + 1;
  iVar3 = iRam02071888;
  iVar2 = iRam02071880;
  uVar5 = (uint)*(ushort *)(param_1 + 0x3fe);
  if (*(ushort *)(param_1 + 0x400) <= uVar5) {
    *(undefined2 *)(param_1 + 0x3fe) = 0;
    uVar5 = param_1 + 0x4cU & 3;
    uVar4 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xfffffff7;
    return;
  }
  sVar1 = *(short *)(param_1 + 0x3fc);
  if (sVar1 == 0) {
    uVar5 = iRam0207187c + uVar5 * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x404) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar5 = iVar2 + (uint)*(ushort *)(param_1 + 0x3fe) * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x408) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0x418) = 0x1000;
    uVar5 = param_1 + 0x418U & 3;
    uVar4 = *(uint *)(param_1 + 0x418U & 0xfffffffc);
    *(uint *)(param_1 + 0x414) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    return;
  }
  if (sVar1 == 1) {
    uVar5 = iRam02071884 + uVar5 * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x404) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    uVar5 = iVar3 + (uint)*(ushort *)(param_1 + 0x3fe) * 4;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    *(uint *)(param_1 + 0x408) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0x418) = 0x1000;
    uVar5 = param_1 + 0x418U & 3;
    uVar4 = *(uint *)(param_1 + 0x418U & 0xfffffffc);
    *(uint *)(param_1 + 0x414) = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
    return;
  }
  if (sVar1 != 2) {
    return;
  }
  *(undefined4 *)(param_1 + 0x404) = 0x1000;
  iVar3 = iRam02071890;
  iVar2 = iRam0207188c;
  uVar5 = iRam02071880 + (uint)*(ushort *)(param_1 + 0x3fe) * 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x408) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = iVar2 + (uint)*(ushort *)(param_1 + 0x3fe) * 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x414) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  uVar5 = iVar3 + (uint)*(ushort *)(param_1 + 0x3fe) * 4;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x418) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  return;
}

