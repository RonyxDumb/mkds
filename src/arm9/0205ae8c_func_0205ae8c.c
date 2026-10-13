/* Decompiled C draft; module arm9; ROM address 0205ae8c. No matching claim. */
#include "types.h"
#include "deps/0205ae8c_func_0205ae8c.h"

void func_0205ae8c(uint param_1)

{
  sbyte sVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  uVar5 = *(uint *)(uRam0205af80 & 0xfffffffc) >> (uRam0205af80 & 3) * 8 |
          *(uint *)(uRam0205af80 & 0xfffffffc) << (uRam0205af80 & 3) * -8 + 0x20;
  iVar3 = (int)*(char *)(uVar5 + (param_1 & 0xff));
  uVar4 = *(uint *)(uRam0205af84 & 0xfffffffc) >> (uRam0205af84 & 3) * 8 |
          *(uint *)(uRam0205af84 & 0xfffffffc) << (uRam0205af84 & 3) * -8 + 0x20;
  iVar8 = iVar3 * 0x88;
  uVar6 = ((uint)*(byte *)(uVar4 + iVar8 + 0x18a) << 0x18) >> 0x19;
  if (iVar3 < 0) {
    return;
  }
  uVar7 = 0;
  uVar9 = *(uint *)(uRam0205af88 & 0xfffffffc) >> (uRam0205af88 & 3) * 8 |
          *(uint *)(uRam0205af88 & 0xfffffffc) << (uRam0205af88 & 3) * -8 + 0x20;
  if (*(char *)(uVar9 + 0x3d0) != '\0') {
    do {
      if (uVar7 != param_1) {
        sVar1 = *(sbyte *)(uVar5 + uVar7);
        if ((-1 < sVar1) &&
           (((uint)*(byte *)(sVar1 * 0x88 + uVar4 + 0x18a) << 0x18) >> 0x19 < uVar6)) {
          bVar2 = false;
          if ((((uint)*(byte *)(uVar4 + 0xfc) & 1 << sVar1) != 0) &&
             (((uint)*(byte *)(uVar4 + 0x749) & 1 << sVar1) == 0)) {
            bVar2 = true;
          }
          if (bVar2) {
            uVar6 = uVar6 - 1 & 0xff;
          }
        }
      }
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < *(byte *)(uVar9 + 0x3d0));
  }
  *(byte *)(uVar4 + iRam0205af8c + iVar8) =
       *(byte *)(uVar4 + iRam0205af8c + iVar8) & 1 | (byte)((uVar6 & 0x7f) << 1);
  return;
}

