/* Decompiled C draft; module arm9; ROM address 02050080. No matching claim. */
#include "types.h"
#include "deps/02050080_func_02050080.h"

void func_02050080(void)

{
  bool bVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar4 = uRam020501ac;
  uVar3 = uRam020501a8;
  bVar1 = false;
  uVar5 = *(uint *)(uRam020501a8 & 0xfffffffc) >> (uRam020501a8 & 3) * 8 |
          *(uint *)(uRam020501a8 & 0xfffffffc) << (uRam020501a8 & 3) * -8 + 0x20;
  if (uVar5 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  }
  if ((uVar7 != 0) &&
     (uVar7 = uVar5 + 4 & 3, uVar5 = *(uint *)(uVar5 + 4 & 0xfffffffc),
     (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) != 0xd)) {
    bVar1 = true;
  }
  if (!bVar1) {
    return;
  }
  uVar5 = 0;
  uVar7 = 0;
  do {
    uVar8 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
    if (((uint)*(byte *)(uVar8 + 0x15f6) & 1 << (uVar5 & 0xff)) == 0) {
      *(short *)(uVar8 + uVar5 * 8 + 0x1e52) = (short)uVar4;
    }
    else {
      *(short *)(uVar8 + uVar5 * 8 + 0x1e52) = (short)uVar7;
      *(short *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                 *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + uVar7 * 2 + 0x1e8c) =
           (short)uVar5;
      *(short *)((*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                 *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) + uVar7 * 2 + 0x1e9c) =
           (short)uVar5;
      uVar7 = uVar7 + 1 & 0xffff;
    }
    uVar8 = uRam020501a8;
    uVar5 = uVar5 + 1 & 0xffff;
  } while (uVar5 < 8);
  if (uVar7 < 8) {
    uVar2 = (undefined2)uRam020501ac;
    do {
      *(undefined2 *)
       ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + uVar7 * 2 + 0x1e8c) = uVar2;
      iVar6 = uVar7 * 2;
      uVar7 = uVar7 + 1 & 0xffff;
      *(undefined2 *)
       ((*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
        *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar6 + 0x1e9c) = uVar2;
    } while (uVar7 < 8);
  }
  iVar6 = GetCurrentSceneId();
  if (iVar6 != 2) {
    func_02043410();
    return;
  }
  func_020431e4();
  return;
}

