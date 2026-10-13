/* Decompiled C draft; module arm9; ROM address 0208e82c. No matching claim. */
#include "types.h"
#include "deps/0208e82c_func_0208e82c.h"

void func_0208e82c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_78 [36];
  uint local_54;
  uint local_50;
  uint local_4c;
  undefined1 auStack_48 [36];
  uint local_24;
  uint local_20;
  uint local_1c;
  
  uVar1 = param_2 + 8U & 3;
  uVar4 = *(uint *)(param_2 + 8U & 0xfffffffc);
  MTX_Scale43__from_thumb(auStack_78,0x1000,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,0x1000);
  uVar1 = param_3 + 8U & 3;
  uVar4 = *(uint *)(param_3 + 8U & 0xfffffffc);
  MTX_Scale43__from_thumb(auStack_48,0x1000,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,0x1000);
  uVar1 = param_2 + 0x10U & 3;
  uVar4 = *(uint *)(param_2 + 0x10U & 0xfffffffc);
  local_54 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x14U & 3;
  uVar4 = *(uint *)(param_2 + 0x14U & 0xfffffffc);
  local_50 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x18U & 3;
  uVar4 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
  local_4c = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_3 + 0x10U & 3;
  uVar4 = *(uint *)(param_3 + 0x10U & 0xfffffffc);
  local_24 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_3 + 0x14U & 3;
  uVar4 = *(uint *)(param_3 + 0x14U & 0xfffffffc);
  local_20 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_3 + 0x18U & 3;
  uVar4 = *(uint *)(param_3 + 0x18U & 0xfffffffc);
  local_1c = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  MTX_Concat43(auStack_78,param_1,auStack_78);
  MTX_Concat43(auStack_48,param_1,auStack_48);
  *puRam0208e98c = 1;
  G3_LoadMtx43(auStack_78);
  puVar2 = puRam0208e990;
  uVar1 = param_4 + 0x1cU & 3;
  uVar4 = *(uint *)(param_4 + 0x1cU & 0xfffffffc);
  *puRam0208e990 = (int)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) << 8) >> 0x10 & 0xffff;
  puVar3 = puRam0208e994;
  *puRam0208e994 = 0x10000;
  *puVar2 = 0;
  *puVar3 = 0xf0000;
  G3_LoadMtx43(auStack_48);
  puVar2 = puRam0208e990;
  uVar1 = param_4 + 0x20U & 3;
  uVar4 = *(uint *)(param_4 + 0x20U & 0xfffffffc);
  *puRam0208e990 = ((int)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) << 8) >> 0x10) << 0x10;
  puVar3 = puRam0208e994;
  *puRam0208e994 = 0xf0000;
  uVar1 = param_4 + 0x1cU & 3;
  uVar5 = *(uint *)(param_4 + 0x1cU & 0xfffffffc);
  uVar4 = param_4 + 0x20U & 3;
  uVar6 = *(uint *)(param_4 + 0x20U & 0xfffffffc);
  *puVar2 = (int)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) << 8) >> 0x10 & 0xffffU |
            ((int)((uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) << 8) >> 0x10) << 0x10;
  *puVar3 = 0x10000;
  *puRam0208e998 = 0;
  return;
}

