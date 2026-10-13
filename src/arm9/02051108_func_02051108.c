/* Decompiled C draft; module arm9; ROM address 02051108. No matching claim. */
#include "types.h"
#include "deps/02051108_func_02051108.h"

void func_02051108(int param_1)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = uRam0205122c;
  sVar1 = *(short *)(param_1 + 2);
  if (sVar1 != 0) {
    if (sVar1 == 1) {
      uVar5 = *(uint *)(uRam0205122c & 0xfffffffc) >> (uRam0205122c & 3) * 8 |
              *(uint *)(uRam0205122c & 0xfffffffc) << (uRam0205122c & 3) * -8 + 0x20;
      uVar2 = *(ushort *)(uVar5 + 0x436);
      if ((uVar2 & 2) == 0) {
        func_020533a0();
        return;
      }
      *(ushort *)(uVar5 + 0x436) = uVar2 & 0xfffd;
      func_02053fa8();
      *(undefined4 *)
       ((*(uint *)(uRam0205122c & 0xfffffffc) >> (uRam0205122c & 3) * 8 |
        *(uint *)(uRam0205122c & 0xfffffffc) << (uRam0205122c & 3) * -8 + 0x20) + 0x10) = 0;
      return;
    }
    if (sVar1 != 7) {
      func_020533a0();
      return;
    }
  }
  *(undefined4 *)
   ((*(uint *)(uRam0205122c & 0xfffffffc) >> (uRam0205122c & 3) * 8 |
    *(uint *)(uRam0205122c & 0xfffffffc) << (uRam0205122c & 3) * -8 + 0x20) + 0x10) = 0;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar5 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
  if (uVar5 == 1) {
    uVar6 = (uint)*(ushort *)(uVar6 + *(char *)(uVar6 + 0x85) * 8 + 0x4a);
    func_02050b88(uVar6);
    uVar5 = *(uint *)(uRam0205122c & 0xfffffffc) >> (uRam0205122c & 3) * 8 |
            *(uint *)(uRam0205122c & 0xfffffffc) << (uRam0205122c & 3) * -8 + 0x20;
    if (uVar5 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    }
    if ((uVar3 == 1) &&
       (uVar3 = uVar5 + 4 & 3, uVar4 = *(uint *)(uVar5 + 4 & 0xfffffffc),
       (uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) == 9)) {
      *(byte *)(uVar5 + 0x1eac) = *(byte *)(uVar5 + 0x1eac) | (byte)(1 << (uVar6 & 0xff));
    }
    *(undefined1 *)
     ((*(uint *)(uRam0205122c & 0xfffffffc) >> (uRam0205122c & 3) * 8 |
      *(uint *)(uRam0205122c & 0xfffffffc) << (uRam0205122c & 3) * -8 + 0x20) + 0x85) = 0xff;
    return;
  }
  if (uVar5 == 2) {
    *(ushort *)(uVar6 + 0x436) = *(ushort *)(uVar6 + 0x436) & 0xfffd;
    func_02053fa8();
    return;
  }
  return;
}

