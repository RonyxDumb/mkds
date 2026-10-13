/* Decompiled C draft; module arm9; ROM address 01fff524. No matching claim. */
#include "types.h"
#include "deps/01fff524_func_01fff524.h"

void func_01fff524(int param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar2 = uRam01fff684;
  *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) & 0xff00;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 8;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) == 5) {
    uVar3 = param_1 + 0x30U & 3;
    uVar2 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if ((uVar3 == 0x13) ||
       (uVar2 = param_1 + 0x58U & 3, uVar4 = *(uint *)(param_1 + 0x58U & 0xfffffffc),
       (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) != 0xf)) {
      bVar1 = false;
    }
    else {
      uVar3 = uVar3 * 0x1c +
              (*(uint *)(uRam01fff688 & 0xfffffffc) >> (uRam01fff688 & 3) * 8 |
              *(uint *)(uRam01fff688 & 0xfffffffc) << (uRam01fff688 & 3) * -8 + 0x20) + 0x14;
      uVar2 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if ((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) - 1 < 2) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    if (bVar1) {
      if (((*(ushort *)(param_1 + 0x1ec) & 0x4000) != 0) &&
         (iVar5 = func_020f0154(param_1), iVar5 != 0)) {
        *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam01fff68c;
      }
      goto LAB_01fff610;
    }
  }
  if (((*(ushort *)(param_1 + 0x1ec) & 0x2000) != 0) && (iVar5 = func_020f0154(param_1), iVar5 != 0)
     ) {
    *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam01fff68c;
  }
LAB_01fff610:
  uVar3 = uRam01fff684;
  if ((*(ushort *)(param_1 + 0x1ec) & 0x100) == 0) {
    return;
  }
  *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) & 0xfeff;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) + 8;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if (((uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) != 5) &&
     ((*(ushort *)(param_1 + 0x1ec) & 0x1000) != 0)) {
    return;
  }
  iVar5 = func_020f0154(param_1);
  if (iVar5 != 0) {
    *(ushort *)(param_1 + 0x1ec) = *(ushort *)(param_1 + 0x1ec) | *puRam01fff690;
    return;
  }
  return;
}

