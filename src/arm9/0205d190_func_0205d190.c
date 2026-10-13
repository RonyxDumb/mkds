/* Decompiled C draft; module arm9; ROM address 0205d190. No matching claim. */
#include "types.h"
#include "deps/0205d190_func_0205d190.h"

int func_0205d190(void)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar3 = *(uint *)(uRam0205d274 & 0xfffffffc) >> (uRam0205d274 & 3) * 8 |
          *(uint *)(uRam0205d274 & 0xfffffffc) << (uRam0205d274 & 3) * -8 + 0x20;
  uVar5 = *(uint *)(uRam0205d278 & 0xfffffffc) >> (uRam0205d278 & 3) * 8 |
          *(uint *)(uRam0205d278 & 0xfffffffc) << (uRam0205d278 & 3) * -8 + 0x20;
  uVar4 = uVar5 + 0x140;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  iVar7 = *(ushort *)(uVar3 + 0x60) - 1;
  iVar6 = iVar7 >> 0x1f;
  uVar2 = *(ushort *)
           ((uint)*(byte *)(uVar3 + 0x62) * 10 +
           (((uint)(iVar7 * 0x40000000 + iVar6) >> 0x1e | iVar6 << 2) - iVar6 & 0xff) * 0x50 + uVar5
           );
  if ((int)uVar4 < 1000) {
    if ((int)uVar4 < 700) {
      if ((int)uVar4 < 400) {
        if ((int)uVar4 < 200) {
          if ((int)uVar4 < 0) {
            iVar6 = 5;
          }
          else {
            iVar6 = 4;
          }
        }
        else {
          iVar6 = 3;
        }
      }
      else {
        iVar6 = 2;
      }
    }
    else {
      iVar6 = 1;
    }
  }
  else {
    iVar6 = 0;
  }
  if (uVar2 < 0x28) {
    if (uVar2 < 0x24) {
      if (uVar2 < 0x1e) {
        if (uVar2 < 0x14) {
          iVar7 = 4;
        }
        else {
          iVar7 = 3;
        }
      }
      else {
        iVar7 = 2;
      }
    }
    else {
      iVar7 = 1;
    }
  }
  else {
    iVar7 = 0;
  }
  uVar4 = iVar6 + iVar7;
  if (7 < uVar4) {
    uVar4 = 7;
  }
  return 7 - uVar4;
}

