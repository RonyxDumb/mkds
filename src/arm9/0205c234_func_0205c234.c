/* Decompiled C draft; module arm9; ROM address 0205c234. No matching claim. */
#include "types.h"
#include "deps/0205c234_func_0205c234.h"

void func_0205c234(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar2 = uRam0205c33c;
  uVar6 = *(uint *)(uRam0205c33c & 0xfffffffc) >> (uRam0205c33c & 3) * 8 |
          *(uint *)(uRam0205c33c & 0xfffffffc) << (uRam0205c33c & 3) * -8 + 0x20;
  iVar7 = 0;
  bVar1 = *(byte *)(uVar6 + 0x73a);
  if ((bVar1 & 1) == 0) {
    *(byte *)(uVar6 + 0x73a) = bVar1 + 1;
    return;
  }
  uVar6 = (int)(uint)bVar1 >> 1;
  uVar8 = (int)((uVar6 - 1) * 0x1000000) >> 0x18;
  if ((int)uVar8 < 0) {
    uVar8 = (int)((uVar8 + 4) * 0x1000000) >> 0x18;
  }
  while ((iVar7 < 1 && (uVar6 != uVar8))) {
    uVar3 = func_0x0219bb50();
    if ((uVar6 == uVar3) ||
       (uVar3 = uVar2 & 3, uVar5 = *(uint *)(uVar2 & 0xfffffffc),
       ((uint)*(byte *)((uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) + 0x749) & 1 << uVar6) ==
       0)) {
      uVar6 = uVar6 + 1 & 0xff;
      if (3 < uVar6) {
        uVar6 = 0;
      }
    }
    else {
      iVar4 = func_0205c340(uVar6,3,param_1);
      if (iVar4 == 0) {
        uVar6 = uVar6 + 1 & 0xff;
        if (3 < uVar6) {
          uVar6 = 0;
        }
      }
      else {
        uVar6 = uVar6 + 1 & 0xff;
        if (3 < uVar6) {
          uVar6 = 0;
        }
        iVar7 = iVar7 + 1;
      }
    }
  }
  *(char *)((*(uint *)(uRam0205c33c & 0xfffffffc) >> (uRam0205c33c & 3) * 8 |
            *(uint *)(uRam0205c33c & 0xfffffffc) << (uRam0205c33c & 3) * -8 + 0x20) + 0x73a) =
       (char)(uVar6 << 1);
  return;
}

