/* Decompiled C draft; module arm9; ROM address 020b3b58. No matching claim. */
#include "types.h"
#include "deps/020b3b58_func_020b3b58.h"

void func_020b3b58(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  ushort uVar8;
  
  uVar5 = *(uint *)(uRam020b3cd0 & 0xfffffffc) >> (uRam020b3cd0 & 3) * 8 |
          *(uint *)(uRam020b3cd0 & 0xfffffffc) << (uRam020b3cd0 & 3) * -8 + 0x20;
  if (*(char *)(uVar5 + 0x58) == '\0') {
    return;
  }
  uVar6 = uVar5 + 0x1c & 3;
  uVar2 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
  if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) == 1) ||
     (uVar6 = uVar5 + 8 & 3, uVar5 = *(uint *)(uVar5 + 8 & 0xfffffffc),
     (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 2)) {
    iVar3 = GetSomeLUMaxIndex();
    uVar8 = (ushort)*(byte *)((*(uint *)(uRam020b3cd4 & 0xfffffffc) >> (uRam020b3cd4 & 3) * 8 |
                              *(uint *)(uRam020b3cd4 & 0xfffffffc) << (uRam020b3cd4 & 3) * -8 + 0x20
                              ) + iVar3 * 8 + 0x146);
  }
  else {
    iVar3 = GetSomeLUMaxIndex();
    uVar8 = *(ushort *)
             ((*(uint *)(uRam020b3cd4 & 0xfffffffc) >> (uRam020b3cd4 & 3) * 8 |
              *(uint *)(uRam020b3cd4 & 0xfffffffc) << (uRam020b3cd4 & 3) * -8 + 0x20) + 0x144 +
             iVar3 * 8);
  }
  bVar7 = true;
  uVar6 = *(uint *)(uRam020b3cd0 & 0xfffffffc) >> (uRam020b3cd0 & 3) * 8 |
          *(uint *)(uRam020b3cd0 & 0xfffffffc) << (uRam020b3cd0 & 3) * -8 + 0x20;
  uVar5 = uVar6 + 0x1c;
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) != 1) &&
     (uVar6 = uVar6 + 8, uVar5 = uVar6 & 3, uVar6 = *(uint *)(uVar6 & 0xfffffffc),
     (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) != 2)) {
    bVar7 = false;
  }
  if (bVar7) {
    iVar3 = GetSomeLUMaxIndex();
    uVar1 = (ushort)*(byte *)((*(uint *)(uRam020b3cd4 & 0xfffffffc) >> (uRam020b3cd4 & 3) * 8 |
                              *(uint *)(uRam020b3cd4 & 0xfffffffc) << (uRam020b3cd4 & 3) * -8 + 0x20
                              ) + iVar3 * 8 + 0x14a);
  }
  else {
    iVar3 = GetSomeLUMaxIndex();
    uVar1 = *(ushort *)
             ((*(uint *)(uRam020b3cd4 & 0xfffffffc) >> (uRam020b3cd4 & 3) * 8 |
              *(uint *)(uRam020b3cd4 & 0xfffffffc) << (uRam020b3cd4 & 3) * -8 + 0x20) + iVar3 * 8 +
             0x148);
  }
  uVar5 = uRam020b3cd0;
  if (uVar1 < uVar8) {
    func_0205d6d0(0);
    return;
  }
  if (uVar8 < uVar1) {
    func_0205d6d0(1);
    return;
  }
  uVar6 = 0;
  if (*(char *)((*(uint *)(uRam020b3cd0 & 0xfffffffc) >> (uRam020b3cd0 & 3) * 8 |
                *(uint *)(uRam020b3cd0 & 0xfffffffc) << (uRam020b3cd0 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      iVar3 = GetDriverPlace(uVar6);
      if (iVar3 == 1) break;
      uVar2 = uVar5 & 3;
      uVar4 = *(uint *)(uVar5 & 0xfffffffc);
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < *(byte *)((uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) + 0x3d0));
  }
  uVar5 = uVar6 * 0x30 +
          (*(uint *)(uRam020b3cd0 & 0xfffffffc) >> (uRam020b3cd0 & 3) * 8 |
          *(uint *)(uRam020b3cd0 & 0xfffffffc) << (uRam020b3cd0 & 3) * -8 + 0x20) + 0x74;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  func_0205d6d0(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
  return;
}

