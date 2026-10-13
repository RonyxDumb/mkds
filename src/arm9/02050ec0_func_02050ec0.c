/* Decompiled C draft; module arm9; ROM address 02050ec0. No matching claim. */
#include "types.h"
#include "deps/02050ec0_func_02050ec0.h"

void func_02050ec0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = uRam02051084;
  uVar6 = uRam02051080;
  *(undefined4 *)
   ((*(uint *)(uRam02051080 & 0xfffffffc) >> (uRam02051080 & 3) * 8 |
    *(uint *)(uRam02051080 & 0xfffffffc) << (uRam02051080 & 3) * -8 + 0x20) + 0xc) = 0x15;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(undefined4 *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x10) = 1;
  iVar4 = func_02143d88(uVar2);
  uVar5 = uRam02051080;
  if (iVar4 == 2) {
    return;
  }
  uVar6 = *(uint *)(uRam02051080 & 0xfffffffc) >> (uRam02051080 & 3) * 8 |
          *(uint *)(uRam02051080 & 0xfffffffc) << (uRam02051080 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar6 + 0x454) & 0x100) != 0) {
    *(undefined4 *)(uVar6 + 0xc) = 0x26;
    *(undefined4 *)
     ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
      *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x10) = 1;
    iVar4 = func_020510e4();
    if ((iVar4 == 0) ||
       ((iVar4 = func_020510c8(), iVar4 != 1 && (iVar4 = func_020510ac(), iVar4 == 0)))) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (bVar3) {
      func_0204bcec();
      uVar5 = *(uint *)(uRam02051080 & 0xfffffffc) >> (uRam02051080 & 3) * 8 |
              *(uint *)(uRam02051080 & 0xfffffffc) << (uRam02051080 & 3) * -8 + 0x20;
      *(ushort *)(uVar5 + 0x454) = *(ushort *)(uVar5 + 0x454) & 0xfeff;
    }
    *(undefined4 *)
     ((*(uint *)(uRam02051080 & 0xfffffffc) >> (uRam02051080 & 3) * 8 |
      *(uint *)(uRam02051080 & 0xfffffffc) << (uRam02051080 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  if ((*(ushort *)(uVar6 + 0x454) & 0x200) != 0) {
    func_0204eca0();
    return;
  }
  *(undefined4 *)(uVar6 + 0xc) = 2;
  uVar2 = uRam02051088;
  *(undefined4 *)
   ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
    *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x10) = 1;
  iVar4 = func_02143dd0(uVar2);
  uVar2 = uRam02051084;
  uVar5 = uRam02051080;
  if (iVar4 == 2) {
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam02051080 & 0xfffffffc) >> (uRam02051080 & 3) * 8 |
    *(uint *)(uRam02051080 & 0xfffffffc) << (uRam02051080 & 3) * -8 + 0x20) + 0xc) = 0x15;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(undefined4 *)((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x10) = 1;
  iVar4 = func_02143d88(uVar2);
  if (iVar4 == 2) {
    return;
  }
  uVar1 = *(ushort *)
           ((*(uint *)(uRam02051080 & 0xfffffffc) >> (uRam02051080 & 3) * 8 |
            *(uint *)(uRam02051080 & 0xfffffffc) << (uRam02051080 & 3) * -8 + 0x20) + 0x454);
  if ((uVar1 & 0x100) != 0) {
    func_02052cf4();
    return;
  }
  if ((uVar1 & 0x200) != 0) {
    func_0204eca0();
    return;
  }
  func_0205108c(2);
  iVar4 = func_02143dd0(uRam02051088);
  if (iVar4 != 2) {
    func_02050ec0();
    return;
  }
  return;
}

