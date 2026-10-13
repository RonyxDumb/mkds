/* Decompiled C draft; module arm9; ROM address 02069068. No matching claim. */
#include "types.h"
#include "deps/02069068_StructMQRacerEntry_SomeFn_39.h"

void StructMQRacerEntry_SomeFn_39(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  iVar5 = param_1 + iRam0206912c;
  *(undefined2 *)(iVar5 + 10) = 0;
  uVar2 = uRam02069130;
  *(undefined2 *)(iVar5 + 8) = 0;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  puVar4 = (uint *)(param_1 + 0x4c);
  *(uint *)(param_1 + 0xd8) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  *(uint *)(param_1 + 0x4c) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffffbfff;
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if ((((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x2000) == 0) &&
     (*puVar4 = *(uint *)((uint)puVar4 & 0xfffffffc) >> ((uint)puVar4 & 3) * 8 |
                *(uint *)((uint)puVar4 & 0xfffffffc) << ((uint)puVar4 & 3) * -8 + 0x20 | 0x2000,
     uVar1 = param_1 + 0x4cU & 3, uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc),
     ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000000) == 0)) {
    StructMQRacerEntry_SomeFn_36();
  }
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x48000) != 0) {
    StructMQRacerEntry_SomeFn_62(param_1);
  }
  StructMQRacerEntry_SomeFn_69(param_1);
  StructMQRacerEntry_SomeFn_70(param_1);
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) == 0) {
    DriverContext_MaybeQueuePlaySfx(param_1,0xa4,0x7f,0);
  }
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x200) != 0) {
    uVar1 = param_1 + 0x514U & 3;
    uVar2 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar3 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = uVar3 + 0x2c;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *(uint *)(uVar3 + 0x2c) = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) ^ 0x40000;
  }
  return;
}

