/* Decompiled C draft; module arm9; ROM address 0210aa14. No matching claim. */
#include "types.h"
#include "deps/0210aa14_SfxStart_ForNonGhost.h"

void SfxStart_ForNonGhost(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  uVar2 = *(undefined1 *)(param_2 + 0x18);
  uVar4 = *(undefined2 *)(param_2 + 0x16);
  uVar7 = 0xffffffff;
  if ((uint)*(ushort *)(param_1 + 0x74) ==
      (int)*(char *)((*(uint *)(uRam0210ab2c & 0xfffffffc) >> (uRam0210ab2c & 3) * 8 |
                     *(uint *)(uRam0210ab2c & 0xfffffffc) << (uRam0210ab2c & 3) * -8 + 0x20) + 0x62)
     ) {
    iVar5 = func_0212d580(uVar2,uVar4);
    cVar3 = *(char *)(iVar5 + 5);
    if (cVar3 == '\x02') {
      uVar7 = 4;
    }
    else if (cVar3 == '\x03') {
      uVar7 = 5;
    }
    else if ((cVar3 == '\x06') &&
            ((iVar5 = func_0210fad4(), iVar5 != 0 || (iVar5 = func_0210fac4(), iVar5 != 0)))) {
      uVar7 = 7;
    }
  }
  if (((*(byte *)(param_2 + 0x19) & 0x20) != 0) && ((*(byte *)(param_2 + 0x19) & 0x40) != 0)) {
    iVar5 = GetDriverKartIndexMod3(*(undefined2 *)(param_1 + 0x74));
    func_0212ec04(param_2,uVar7,iVar5 + 0x2d,param_3,uVar2,uVar4);
    if (param_2 != 0) {
      uVar1 = param_1 + 0x4b8U & 3;
      uVar6 = *(uint *)(param_1 + 0x4b8U & 0xfffffffc);
      func_0212c3c8(param_2,0,
                    (int)(short)((ushort)(uVar6 >> uVar1 * 8) | (ushort)(uVar6 << uVar1 * -8 + 0x20)
                                ));
      return;
    }
    return;
  }
  func_0212ec04(param_2,uVar7,0xffffffff,param_3,uVar2,uVar4);
  return;
}

