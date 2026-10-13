/* Decompiled C draft; module arm7; ROM address 06015e68. No matching claim. */
#include "types.h"
#include "deps/06015e68_FUN_06015e68.h"

void FUN_06015e68(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar4;
  
  uVar9 = *(uint *)(DAT_060161ac & 0xfffffffc) >> (DAT_060161ac & 3) * 8 |
          *(uint *)(DAT_060161ac & 0xfffffffc) << (DAT_060161ac & 3) * -8 + 0x20;
  iVar11 = uVar9 + DAT_060161b0;
  sVar1 = *(short *)(uVar9 + 0x350);
  uVar4 = uVar9 + 0x1dc & 3;
  uVar3 = *(uint *)(uVar9 + 0x1dc & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if (uVar4 == 0xffffffff) {
    return;
  }
  iVar10 = uVar4 + 0x10;
  if ((*(ushort *)(uVar4 + 0x28) & 1) == 0) {
    uVar3 = iVar11 + 0x28U & 3;
    uVar5 = *(uint *)(iVar11 + 0x28U & 0xfffffffc);
    *(uint *)(iVar11 + 0x28) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 1;
  }
  else {
    uVar3 = iVar11 + 0x2cU & 3;
    uVar5 = *(uint *)(iVar11 + 0x2cU & 0xfffffffc);
    *(uint *)(iVar11 + 0x2c) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 1;
  }
  iVar6 = thunk_FUN_03806b2c(*(ushort *)(uVar4 + 0x18) & 0xf0,0x10);
  uVar3 = iVar11 + 0x24U & 3;
  uVar5 = *(uint *)(iVar11 + 0x24U & 0xfffffffc);
  *(uint *)(iVar11 + 0x24) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + iVar6 + -1;
  uVar5 = (uint)*(ushort *)(uVar4 + 0x24);
  uVar3 = (uVar5 << 0x1c) >> 0x1e;
  uVar5 = (uVar5 << 0x18) >> 0x1c;
  uVar7 = FUN_0600ede8(uVar4 + 0x2e);
  *(short *)(uVar4 + 0x12) = (short)uVar7;
  if (uVar7 == 0xff) {
    *(undefined2 *)(uVar4 + 0x12) = 0;
    if ((sVar1 == 1) && (uVar3 == 0)) {
      if (uVar5 == 0) {
        FUN_06017404(iVar10);
      }
      else if (uVar5 == 4) {
        FUN_06016f4c(iVar10);
      }
      else if (uVar5 == 0xb) {
        FUN_0601661c(iVar10);
      }
    }
  }
  else {
    FUN_0600ea58();
    FUN_0600eba4(uVar7 & 0xffff,*(ushort *)(uVar4 + 0x22) & 0xff);
    if (uVar3 == 0) {
      uVar2 = *(ushort *)(uVar4 + 0x3a);
      uVar8 = FUN_0600e884(uVar7);
      if (uVar2 == uVar8) {
        uVar3 = iVar11 + 0x3cU & 3;
        uVar5 = *(uint *)(iVar11 + 0x3cU & 0xfffffffc);
        *(uint *)(iVar11 + 0x3c) = (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 1;
        goto switchD_060160c8_default;
      }
      FUN_0600ea94(uVar7);
    }
    if (sVar1 == 1) {
      FUN_0600eb40(uVar7 & 0xffff,((uint)*(ushort *)(uVar4 + 0x24) << 0x13) >> 0x1f);
      if (uVar3 == 0) {
                    /* WARNING: Could not recover jumptable at 0x06016000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        if (uVar5 < 0xd) {
          (*(code *)(uVar5 * 4 + 0x6016008))();
          return;
        }
      }
      else if ((uVar3 == 1) && (uVar5 == 10)) {
        FUN_060164f8(iVar10);
      }
    }
    else if ((sVar1 == 2) || (sVar1 == 3)) {
      if (uVar3 == 0) {
                    /* WARNING: Could not recover jumptable at 0x060160c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        if (uVar5 < 0xd) {
          (*(code *)(uVar5 * 4 + 0x60160d0))();
          return;
        }
      }
      else if ((uVar3 == 1) && ((uVar5 == 0xe || (uVar5 == 0xf)))) {
        FUN_060164f4(iVar10);
      }
    }
  }
switchD_060160c8_default:
  FUN_060090b4(uVar9 + 0x1dc,uVar4);
  if (*(short *)(uVar9 + 0x1e4) != 0) {
    FUN_06008a8c(1,7);
  }
  return;
}

