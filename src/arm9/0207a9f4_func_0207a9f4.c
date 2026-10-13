/* Decompiled C draft; module arm9; ROM address 0207a9f4. No matching claim. */
#include "types.h"
#include "deps/0207a9f4_func_0207a9f4.h"

void func_0207a9f4(void)

{
  uint uVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = 0;
  puVar4 = (ushort *)GetSomeAED0DriverIdList();
  puVar3 = puRam0207aa78;
  iVar2 = iRam0207aa74;
  uVar1 = uRam0207aa70;
  uVar6 = *(char *)((*(uint *)(uRam0207aa6c & 0xfffffffc) >> (uRam0207aa6c & 3) * 8 |
                    *(uint *)(uRam0207aa6c & 0xfffffffc) << (uRam0207aa6c & 3) * -8 + 0x20) + 0x62)
          * iRam0207aa74 +
          (*(uint *)(uRam0207aa70 & 0xfffffffc) >> (uRam0207aa70 & 3) * 8 |
          *(uint *)(uRam0207aa70 & 0xfffffffc) << (uRam0207aa70 & 3) * -8 + 0x20) + 0x590;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *(undefined4 *)((uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) + 0x60) = 1;
  if (*puVar3 != 0) {
    do {
      uVar6 = uVar1 & 3;
      uVar5 = *(uint *)(uVar1 & 0xfffffffc);
      StructMQRacerEntry_SomeFn_50
                ((uint)*puVar4 * iVar2 + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20));
      iVar7 = iVar7 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar7 < (int)(uint)*puVar3);
    return;
  }
  return;
}

