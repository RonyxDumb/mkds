/* Decompiled C draft; module arm9; ROM address 0203e550. No matching claim. */
#include "types.h"
#include "deps/0203e550_func_0203e550.h"

void func_0203e550(uint param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar6;
  bool bVar7;
  uint uVar5;
  
  uVar5 = param_1 + 0x24 & 3;
  uVar4 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if ((int)uVar5 < 0x7fffffff) {
    *(uint *)(param_1 + 0x24) = uVar5 + 1;
  }
  *(undefined2 *)(param_1 + 0x36) = 0xffff;
  *(undefined2 *)(param_1 + 0x34) = 0xffff;
  uVar5 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  bVar7 = false;
  if (((uVar5 == 1) || (uVar5 == 2)) || (uVar5 == 3)) {
    bVar7 = true;
  }
  if (bVar7) {
    return;
  }
  uVar5 = param_1 + 0x24 & 3;
  uVar4 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  if ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) <=
      (int)(uint)*(ushort *)(param_1 + 0x3a)) {
    return;
  }
  if ((*(ushort *)(param_1 + 0x30) & 1) != 0) {
    func_02106ab8();
  }
  iVar3 = GetCurrentLapCount();
  uVar5 = param_1 + 0x24 & 3;
  uVar4 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  func_0203f334(param_1,iVar3 < (int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20));
  uVar5 = param_1 + 0x24 & 3;
  uVar4 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  *(ushort *)(param_1 + 0x3a) = (ushort)(uVar4 >> uVar5 * 8) | (ushort)(uVar4 << uVar5 * -8 + 0x20);
  if ((*(ushort *)(param_1 + 0x30) & 1) != 0) {
    func_020b1a34();
  }
  uVar6 = *(uint *)(uRam0203e748 & 0xfffffffc) >> (uRam0203e748 & 3) * 8 |
          *(uint *)(uRam0203e748 & 0xfffffffc) << (uRam0203e748 & 3) * -8 + 0x20;
  uVar5 = uVar6 + 8;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  bVar7 = (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 4;
  if ((!bVar7) &&
     (((cVar1 = *(char *)(uVar6 + 0x2f), cVar1 == '\x02' || (cVar1 == '\x04')) || (cVar1 == '\x06'))
     )) {
    bVar7 = true;
  }
  if (!bVar7) {
    return;
  }
  uVar5 = GetCurrentLapCount();
  if (*(ushort *)(param_1 + 0x3a) <= uVar5) {
    return;
  }
  uVar2 = GetCurrentLapCount();
  uVar4 = uRam0203e748;
  *(undefined2 *)(param_1 + 0x3a) = uVar2;
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  uVar5 = uVar4 + 8 & 3;
  uVar6 = *(uint *)(uVar4 + 8 & 0xfffffffc);
  uVar5 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  if (uVar5 != 4) {
    if (((*(ushort *)(param_1 + 0x30) & 1) == 0) && (uVar5 == 5)) {
      return;
    }
    *(ushort *)(param_1 + 0x30) = *(ushort *)(param_1 + 0x30) | 0x40;
    return;
  }
  bVar7 = true;
  iVar3 = GetGlobalRK();
  if (*(char *)(uVar4 + 0x2f) == '\x04') {
    uVar5 = iVar3 + 4U & 3;
    uVar6 = *(uint *)(iVar3 + 4U & 0xfffffffc);
    bVar7 = (uint)*(byte *)(uVar4 + 0x37) <= (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  }
  else if ((*(char *)(uVar4 + 0x2f) == '\x06') && ((*(ushort *)(param_1 + 0x3c) & 0xf) != 1)) {
    bVar7 = false;
  }
  if (bVar7) {
    uVar5 = (*(uint *)(uRam0203e748 & 0xfffffffc) >> (uRam0203e748 & 3) * 8 |
            *(uint *)(uRam0203e748 & 0xfffffffc) << (uRam0203e748 & 3) * -8 + 0x20) + 8;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) != 4) {
      return;
    }
    func_0203e788(((uint)*(ushort *)(param_1 + 0x3c) << 0x18) >> 0x1c,0);
    return;
  }
  func_0203e788(((uint)*(ushort *)(param_1 + 0x3c) << 0x18) >> 0x1c,4);
  return;
}

