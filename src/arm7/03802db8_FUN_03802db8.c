/* Decompiled C draft; module arm7; ROM address 03802db8. No matching claim. */
#include "types.h"
#include "deps/03802db8_FUN_03802db8.h"

void FUN_03802db8(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar7;
  ushort uVar8;
  ushort uVar9;
  bool bVar10;
  uint uVar6;
  
  iVar2 = DAT_03802f10;
  uVar1 = *(ushort *)(DAT_03802f10 + 0x26);
  uVar8 = *(ushort *)(DAT_03802f10 + 0x38);
  uVar4 = DAT_03802f14;
  if ((uVar1 & 4) != 4) {
    uVar4 = (uint)*(ushort *)(DAT_03802f10 + 0x3a);
  }
  iVar3 = FUN_038012f8();
  if ((iVar3 == 0) && (iVar3 = FUN_03801450(2), iVar3 != 0)) {
    if ((uVar1 & 1) == 1) {
      uVar4 = FUN_03803570();
      if ((uVar1 & 2) != 0) {
        uVar4 = uVar4 ^ 0x8000;
      }
    }
    else {
      uVar4 = FUN_03803638();
      if ((uVar1 & 2) != 0) {
        uVar4 = uVar4 ^ 0x80;
      }
    }
  }
  iVar3 = DAT_03802f18;
  uVar9 = (ushort)uVar4;
  uVar6 = iVar2 + 0x2cU & 3;
  uVar5 = *(uint *)(iVar2 + 0x2cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((uVar1 & 1) == 1) {
    uVar4 = iVar2 + 0x28U & 3;
    uVar5 = *(uint *)(iVar2 + 0x28U & 0xfffffffc);
    puVar7 = (ushort *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + uVar6);
    *puVar7 = uVar9;
    *(ushort **)(iVar3 + 0x390) = puVar7;
    *(ushort *)(iVar3 + 0x394) = uVar9;
    uVar6 = uVar6 + 2;
  }
  else {
    uVar9 = (ushort)(uVar4 & 0xff);
    if ((uVar6 & 1) == 0) {
      uVar6 = uVar6 + 1;
      uVar8 = uVar9;
    }
    else {
      uVar1 = uVar8 | (ushort)((uVar4 & 0xff) << 8);
      uVar4 = iVar2 + 0x28U & 3;
      uVar5 = *(uint *)(iVar2 + 0x28U & 0xfffffffc);
      puVar7 = (ushort *)((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + (uVar6 - 1));
      *puVar7 = uVar1;
      *(ushort **)(iVar3 + 0x390) = puVar7;
      *(ushort *)(iVar3 + 0x394) = uVar1;
      uVar6 = uVar6 + 1;
    }
  }
  *(ushort *)(iVar2 + 0x38) = uVar8;
  *(ushort *)(iVar2 + 0x3a) = uVar9;
  uVar4 = iVar2 + 0x30U & 3;
  uVar5 = *(uint *)(iVar2 + 0x30U & 0xfffffffc);
  bVar10 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) <= uVar6;
  if (bVar10) {
    uVar6 = 0;
  }
  *(uint *)(iVar2 + 0x2c) = uVar6;
  if (bVar10) {
    if ((*(ushort *)(iVar2 + 0x24) & 0x10) == 0x10) {
      FUN_0380146c(0x51,0);
    }
    else {
      iVar3 = FUN_03801320(2,0x42,0);
      if (iVar3 == 0) {
        FUN_0380146c(0x51,4);
      }
      else {
        *(undefined4 *)(iVar2 + 0x20) = 4;
        *DAT_03802f1c = *DAT_03802f1c & 0xff7f;
      }
    }
  }
  return;
}

