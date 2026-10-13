/* Decompiled C draft; module arm9; ROM address 020c1ef8. No matching claim. */
#include "types.h"
#include "deps/020c1ef8_func_020c1ef8.h"

void func_020c1ef8(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  uint uStack_48;
  int aiStack_44 [8];
  uint uVar7;
  
  uVar7 = uRam020c2108;
  uVar3 = uRam020c2104;
  uVar2 = (*(uint *)(uRam020c2100 & 0xfffffffc) >> (uRam020c2100 & 3) * 8 |
          *(uint *)(uRam020c2100 & 0xfffffffc) << (uRam020c2100 & 3) * -8 + 0x20) + 0x4cc;
  uVar6 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0) {
    return;
  }
  *(undefined4 *)
   ((*(uint *)(uRam020c2104 & 0xfffffffc) >> (uRam020c2104 & 3) * 8 |
    *(uint *)(uRam020c2104 & 0xfffffffc) << (uRam020c2104 & 3) * -8 + 0x20) + 0xa4) = 1;
  uVar1 = uRam020c2104;
  uVar2 = uVar7 & 3;
  uVar6 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
  uVar2 = uVar7 + 8;
  uVar6 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) == 2) && (*(char *)(uVar7 + 0x58) != '\0'))
  {
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0xac) = uRam020c210c;
    *(undefined4 *)
     ((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
      *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + 0xb0) = 0;
    func_020b1d90();
  }
  else {
    *(undefined4 *)
     ((*(uint *)(uRam020c2104 & 0xfffffffc) >> (uRam020c2104 & 3) * 8 |
      *(uint *)(uRam020c2104 & 0xfffffffc) << (uRam020c2104 & 3) * -8 + 0x20) + 0xac) = uRam020c2110
    ;
    uVar2 = uVar1 & 3;
    uVar6 = *(uint *)(uVar1 & 0xfffffffc);
    *(undefined4 *)((uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20) + 0xb0) = 0;
  }
  uVar2 = 0;
  if (*(char *)((*(uint *)(uRam020c2108 & 0xfffffffc) >> (uRam020c2108 & 3) * 8 |
                *(uint *)(uRam020c2108 & 0xfffffffc) << (uRam020c2108 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      *(uint *)((*(uint *)(uRam020c2104 & 0xfffffffc) >> (uRam020c2104 & 3) * 8 |
                *(uint *)(uRam020c2104 & 0xfffffffc) << (uRam020c2104 & 3) * -8 + 0x20) + uVar2 * 4
               + 0x40) = uVar2;
      uVar7 = *(uint *)(uRam020c2108 & 0xfffffffc) >> (uRam020c2108 & 3) * 8 |
              *(uint *)(uRam020c2108 & 0xfffffffc) << (uRam020c2108 & 3) * -8 + 0x20;
      uVar6 = uVar7 + 0x1c & 3;
      uVar3 = *(uint *)(uVar7 + 0x1c & 0xfffffffc);
      if (((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) == 1) ||
         (uVar6 = uVar7 + 8 & 3, uVar3 = *(uint *)(uVar7 + 8 & 0xfffffffc),
         (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) == 2)) {
        uVar6 = uVar2 * 0x30 + uVar7 + 0x70;
        uVar3 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
        bVar5 = 0;
        if ((uVar6 < 4) && ((1 << (uVar6 & 0xff) & 0xdU) != 0)) {
          bVar5 = 1;
        }
        iVar4 = GetDriverPlace(uVar2);
        aiStack_44[uVar2] = ((uint)bVar5 * 8 + 8) - iVar4;
        iVar4 = GetDriverPlace(uVar2);
        if (iVar4 == 1) {
          aiStack_44[uVar2] = aiStack_44[uVar2] + 0x20;
        }
        aiStack_44[uVar2] = -aiStack_44[uVar2];
      }
      else {
        iVar4 = GetDriverPlace(uVar2);
        aiStack_44[uVar2] = iVar4;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < *(byte *)((*(uint *)(uRam020c2108 & 0xfffffffc) >> (uRam020c2108 & 3) * 8 |
                               *(uint *)(uRam020c2108 & 0xfffffffc) <<
                               (uRam020c2108 & 3) * -8 + 0x20) + 0x3d0));
  }
  func_020ae770((*(uint *)(uRam020c2104 & 0xfffffffc) >> (uRam020c2104 & 3) * 8 |
                *(uint *)(uRam020c2104 & 0xfffffffc) << (uRam020c2104 & 3) * -8 + 0x20) + 0x40,
                aiStack_44);
  uVar2 = (*(uint *)(uRam020c2108 & 0xfffffffc) >> (uRam020c2108 & 3) * 8 |
          *(uint *)(uRam020c2108 & 0xfffffffc) << (uRam020c2108 & 3) * -8 + 0x20) + 8;
  uVar6 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  if ((uVar2 != 3) && (uVar2 != 5)) {
    return;
  }
  iVar4 = func_020617a8(&uStack_48);
  if (iVar4 == 0) {
    return;
  }
  if (uStack_48 < 0xb4) {
    return;
  }
  NNSi_MaybeSndPlayerStartSeq(uRam020c2114,0,0x46);
  return;
}

