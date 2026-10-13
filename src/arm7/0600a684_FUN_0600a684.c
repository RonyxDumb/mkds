/* Decompiled C draft; module arm7; ROM address 0600a684. No matching claim. */
#include "types.h"
#include "deps/0600a684_FUN_0600a684.h"

void FUN_0600a684(void)

{
  uint uVar1;
  ushort uVar2;
  ushort *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar3 = DAT_0600a884;
  iVar4 = (*(uint *)(DAT_0600a87c & 0xfffffffc) >> (DAT_0600a87c & 3) * 8 |
          *(uint *)(DAT_0600a87c & 0xfffffffc) << (DAT_0600a87c & 3) * -8 + 0x20) + DAT_0600a880;
  uVar1 = iVar4 + 0x50U & 3;
  uVar5 = *(uint *)(iVar4 + 0x50U & 0xfffffffc);
  *(uint *)(iVar4 + 0x50) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (*DAT_0600a884 & 0xff);
  uVar2 = puVar3[1];
  uVar1 = iVar4 + 0x4cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x4cU & 0xfffffffc);
  *(uint *)(iVar4 + 0x4c) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar1 = iVar4 + 0x5cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x5cU & 0xfffffffc);
  *(uint *)(iVar4 + 0x5c) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar2 = puVar3[2];
  uVar1 = iVar4 + 0x58U & 3;
  uVar5 = *(uint *)(iVar4 + 0x58U & 0xfffffffc);
  *(uint *)(iVar4 + 0x58) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar1 = iVar4 + 0x54U & 3;
  uVar5 = *(uint *)(iVar4 + 0x54U & 0xfffffffc);
  *(uint *)(iVar4 + 0x54) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar2 = puVar3[3];
  uVar1 = iVar4 + 0x60U & 3;
  uVar5 = *(uint *)(iVar4 + 0x60U & 0xfffffffc);
  *(uint *)(iVar4 + 0x60) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar1 = iVar4 + 0x38U & 3;
  uVar5 = *(uint *)(iVar4 + 0x38U & 0xfffffffc);
  *(uint *)(iVar4 + 0x38) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0x48U & 3;
  uVar5 = *(uint *)(iVar4 + 0x48U & 0xfffffffc);
  *(uint *)(iVar4 + 0x48) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (puVar3[4] & 0xff);
  uVar1 = iVar4 + 0x20U & 3;
  uVar5 = *(uint *)(iVar4 + 0x20U & 0xfffffffc);
  *(uint *)(iVar4 + 0x20) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (puVar3[5] & 0xff);
  uVar2 = puVar3[6];
  uVar1 = iVar4 + 0x30U & 3;
  uVar5 = *(uint *)(iVar4 + 0x30U & 0xfffffffc);
  *(uint *)(iVar4 + 0x30) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar1 = iVar4 + 0x44U & 3;
  uVar5 = *(uint *)(iVar4 + 0x44U & 0xfffffffc);
  *(uint *)(iVar4 + 0x44) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar2 = puVar3[7];
  uVar1 = iVar4 + 0x3cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x3cU & 0xfffffffc);
  *(uint *)(iVar4 + 0x3c) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0x40U & 3;
  uVar5 = *(uint *)(iVar4 + 0x40U & 0xfffffffc);
  *(uint *)(iVar4 + 0x40) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar1 = iVar4 + 0xcU & 3;
  uVar5 = *(uint *)(iVar4 + 0xcU & 0xfffffffc);
  *(uint *)(iVar4 + 0xc) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (puVar3[8] & 0xff);
  uVar1 = iVar4 + 0x78U & 3;
  uVar5 = *(uint *)(iVar4 + 0x78U & 0xfffffffc);
  *(uint *)(iVar4 + 0x78) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)puVar3[0x10] >> 8);
  uVar2 = puVar3[0x11];
  uVar1 = iVar4 + 0x7cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x7cU & 0xfffffffc);
  *(uint *)(iVar4 + 0x7c) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0x80U & 3;
  uVar5 = *(uint *)(iVar4 + 0x80U & 0xfffffffc);
  *(uint *)(iVar4 + 0x80) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar2 = puVar3[0x12];
  uVar1 = iVar4 + 0x84U & 3;
  uVar5 = *(uint *)(iVar4 + 0x84U & 0xfffffffc);
  *(uint *)(iVar4 + 0x84) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0x88U & 3;
  uVar5 = *(uint *)(iVar4 + 0x88U & 0xfffffffc);
  *(uint *)(iVar4 + 0x88) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar2 = puVar3[0x13];
  uVar1 = iVar4 + 0x8cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x8cU & 0xfffffffc);
  *(uint *)(iVar4 + 0x8c) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0x90U & 3;
  uVar5 = *(uint *)(iVar4 + 0x90U & 0xfffffffc);
  *(uint *)(iVar4 + 0x90) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar2 = puVar3[0x14];
  uVar1 = iVar4 + 0x94U & 3;
  uVar5 = *(uint *)(iVar4 + 0x94U & 0xfffffffc);
  *(uint *)(iVar4 + 0x94) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0x98U & 3;
  uVar5 = *(uint *)(iVar4 + 0x98U & 0xfffffffc);
  *(uint *)(iVar4 + 0x98) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar2 = puVar3[0x15];
  uVar1 = iVar4 + 0x9cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x9cU & 0xfffffffc);
  *(uint *)(iVar4 + 0x9c) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0xa0U & 3;
  uVar5 = *(uint *)(iVar4 + 0xa0U & 0xfffffffc);
  *(uint *)(iVar4 + 0xa0) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar2 = puVar3[0x16];
  uVar1 = iVar4 + 0xa4U & 3;
  uVar5 = *(uint *)(iVar4 + 0xa4U & 0xfffffffc);
  *(uint *)(iVar4 + 0xa4) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0xa8U & 3;
  uVar5 = *(uint *)(iVar4 + 0xa8U & 0xfffffffc);
  *(uint *)(iVar4 + 0xa8) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  uVar2 = puVar3[0x17];
  uVar1 = iVar4 + 0xacU & 3;
  uVar5 = *(uint *)(iVar4 + 0xacU & 0xfffffffc);
  *(uint *)(iVar4 + 0xac) = (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + (uVar2 & 0xff);
  uVar1 = iVar4 + 0xb0U & 3;
  uVar5 = *(uint *)(iVar4 + 0xb0U & 0xfffffffc);
  *(uint *)(iVar4 + 0xb0) =
       (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + ((int)(uint)uVar2 >> 8);
  return;
}

