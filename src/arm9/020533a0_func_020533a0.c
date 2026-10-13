/* Decompiled C draft; module arm9; ROM address 020533a0. No matching claim. */
#include "types.h"
#include "deps/020533a0_func_020533a0.h"

void func_020533a0(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  
  uVar4 = uRam02053654;
  uVar7 = *(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
          *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar7 + 0x454) & 0x100) != 0) {
    *(undefined4 *)(uVar7 + 0xc) = 0x26;
    bVar5 = true;
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 1;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
            *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
    bVar6 = false;
    if ((*(ushort *)(uVar4 + 0x454) & 0x40) != 0) {
      if (uVar4 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
                *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
      }
      if ((uVar4 != 1) && (*psRam02053658 != 2)) {
        bVar5 = false;
      }
      if (bVar5) {
        bVar6 = true;
      }
    }
    if (bVar6) {
      func_0204bcec();
      uVar4 = *(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
              *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20;
      *(ushort *)(uVar4 + 0x454) = *(ushort *)(uVar4 + 0x454) & 0xfeff;
    }
    *(undefined4 *)
     ((*(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
      *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  if ((*(ushort *)(uVar7 + 0x454) & 0x200) != 0) {
    func_0204eca0();
    return;
  }
  *(undefined4 *)(uVar7 + 0xc) = 2;
  uVar2 = uRam0205365c;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 1;
  iVar3 = func_02143dd0(uVar2);
  uVar2 = uRam02053660;
  uVar4 = uRam02053654;
  if (iVar3 == 2) {
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
    *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20) + 0xc) = 0x15;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0x10) = 1;
  iVar3 = func_02143d88(uVar2);
  uVar4 = uRam02053654;
  if (iVar3 == 2) {
    return;
  }
  uVar7 = *(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
          *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20;
  if ((*(ushort *)(uVar7 + 0x454) & 0x100) != 0) {
    *(undefined4 *)(uVar7 + 0xc) = 0x26;
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 1;
    iVar3 = func_020510e4();
    if ((iVar3 == 0) ||
       ((iVar3 = func_020510c8(), iVar3 != 1 && (iVar3 = func_020510ac(), iVar3 == 0)))) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (bVar5) {
      func_0204bcec();
      uVar4 = *(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
              *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20;
      *(ushort *)(uVar4 + 0x454) = *(ushort *)(uVar4 + 0x454) & 0xfeff;
    }
    *(undefined4 *)
     ((*(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
      *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20) + 0x10) = 0;
    return;
  }
  if ((*(ushort *)(uVar7 + 0x454) & 0x200) != 0) {
    func_0204eca0();
    return;
  }
  *(undefined4 *)(uVar7 + 0xc) = 2;
  uVar2 = uRam0205365c;
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 0x10) = 1;
  iVar3 = func_02143dd0(uVar2);
  uVar2 = uRam02053660;
  uVar4 = uRam02053654;
  if (iVar3 == 2) {
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
    *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20) + 0xc) = 0x15;
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0x10) = 1;
  iVar3 = func_02143d88(uVar2);
  if (iVar3 != 2) {
    uVar1 = *(ushort *)
             ((*(uint *)(uRam02053654 & 0xfffffffc) >> (uRam02053654 & 3) * 8 |
              *(uint *)(uRam02053654 & 0xfffffffc) << (uRam02053654 & 3) * -8 + 0x20) + 0x454);
    if ((uVar1 & 0x100) != 0) {
      func_02052cf4();
      return;
    }
    if ((uVar1 & 0x200) == 0) {
      func_0205108c(2);
      iVar3 = func_02143dd0(uRam0205365c);
      if (iVar3 != 2) {
        func_02050ec0();
        return;
      }
      return;
    }
    func_0204eca0();
    return;
  }
  return;
}

