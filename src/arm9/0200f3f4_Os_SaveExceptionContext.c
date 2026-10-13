/* Decompiled C draft; module arm9; ROM address 0200f3f4. No matching claim. */
#include "types.h"
#include "deps/0200f3f4_Os_SaveExceptionContext.h"

int Os_SaveExceptionContext(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint unaff_r4;
  uint unaff_r5;
  uint unaff_r6;
  uint unaff_r7;
  uint unaff_r8;
  uint unaff_r9;
  uint unaff_r10;
  uint unaff_r11;
  uint in_r12;
  uint in_lr;
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  
  puVar1 = puRam0200f480;
  puRam0200f480[0x1d] =
       (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
  puVar1[0x1b] = param_1;
  puVar1[1] = *(uint *)(in_r12 & 0xfffffffc) >> (in_r12 & 3) * 8 |
              *(uint *)(in_r12 & 0xfffffffc) << (in_r12 & 3) * -8 + 0x20;
  uVar3 = in_r12 + 4 & 3;
  uVar2 = *(uint *)(in_r12 + 4 & 0xfffffffc);
  puVar1[2] = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = in_r12 + 8 & 3;
  uVar2 = *(uint *)(in_r12 + 8 & 0xfffffffc);
  puVar1[3] = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = in_r12 + 0xc & 3;
  uVar2 = *(uint *)(in_r12 + 0xc & 0xfffffffc);
  puVar1[4] = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = in_r12 + 0x10 & 3;
  uVar2 = *(uint *)(in_r12 + 0x10 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar4 = uVar3 & 0xfffffffe;
  puVar1[5] = unaff_r4;
  puVar1[6] = unaff_r5;
  puVar1[7] = unaff_r6;
  puVar1[8] = unaff_r7;
  puVar1[9] = unaff_r8;
  puVar1[10] = unaff_r9;
  puVar1[0xb] = unaff_r10;
  puVar1[0xc] = unaff_r11;
  puVar1[0x1c] = in_r12;
  puVar1[0x19] = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 2) * 8 |
                 *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 2) * -8 + 0x20;
  uVar3 = uVar4 + 4 & 3;
  uVar2 = *(uint *)(uVar4 + 4 & 0xfffffffc);
  *puVar1 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar4 + 8 & 3;
  uVar2 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  puVar1[0xd] = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar4 + 0xc & 3;
  uVar2 = *(uint *)(uVar4 + 0xc & 0xfffffffc);
  puVar1[0x10] = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  puVar1[0xe] = (uint)register0x00000054;
  puVar1[0xf] = in_lr;
  puVar1[0x1f] = 0;
  return (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b;
}

