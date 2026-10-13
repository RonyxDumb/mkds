/* Decompiled C draft; module arm9; ROM address 02043410. No matching claim. */
#include "types.h"
#include "deps/02043410_func_02043410.h"

void func_02043410(void)

{
  undefined2 uVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = uRam02043534;
  iVar3 = iRam02043530;
  uVar8 = 0;
  uVar1 = (undefined2)uRam02043538;
  do {
    iVar7 = uVar8 * 0x5c + iVar3;
    StructCY_SomeFn((undefined2 *)(uintptr_t)(iVar7));
    StructCY_SomeFn_0(iVar7,uVar4,0x1e,10);
    *(undefined4 *)(iVar7 + 0x3c) = 0;
    *(undefined2 *)(iVar7 + 0x40) = 0;
    *(undefined4 *)(iVar7 + 0x44) = 0;
    *(undefined2 *)(iVar7 + 0x42) = uVar1;
    StructCYB_SomeFn(iVar7 + 0x28);
    StructCYA_SomeFn((undefined2 *)(uintptr_t)(iVar7 + 0x48));
    iVar7 = iRam02043530;
    uVar8 = uVar8 + 1 & 0xffff;
  } while (uVar8 < 8);
  bVar2 = false;
  uVar8 = *(uint *)(uRam0204353c & 0xfffffffc) >> (uRam0204353c & 3) * 8 |
          *(uint *)(uRam0204353c & 0xfffffffc) << (uRam0204353c & 3) * -8 + 0x20;
  if (uVar8 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
            *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
  }
  if ((uVar5 != 0) &&
     (uVar5 = uVar8 + 4 & 3, uVar6 = *(uint *)(uVar8 + 4 & 0xfffffffc),
     (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) != 0xd)) {
    bVar2 = true;
  }
  if (bVar2) {
    uVar5 = 0;
    do {
      if (((uint)*(byte *)(uVar8 + 0x15f6) & 1 << (*(ushort *)(uVar8 + uVar5 * 2 + 0x1e8c) & 0xff))
          != 0) {
        *(undefined4 *)(uVar5 * 0x5c + iVar7 + 0x3c) = 4;
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 8);
  }
  uVar5 = uRam02043540;
  *(undefined4 *)
   ((*(uint *)(uRam02043540 & 0xfffffffc) >> (uRam02043540 & 3) * 8 |
    *(uint *)(uRam02043540 & 0xfffffffc) << (uRam02043540 & 3) * -8 + 0x20) + 8) = 0;
  uVar8 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(undefined4 *)((uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) + 0xc) = 0;
  return;
}

