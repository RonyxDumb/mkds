/* Decompiled C draft; module arm9; ROM address 0210cc3c. No matching claim. */
#include "types.h"
#include "deps/0210cc3c_func_0210cc3c.h"

void func_0210cc3c(int param_1)

{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  uVar8 = iRam0210cf14 + 0x10U & 3;
  uVar5 = *(uint *)(iRam0210cf14 + 0x10U & 0xfffffffc);
  bVar3 = false;
  if (uVar5 >> uVar8 * 8 == 0 && uVar5 << uVar8 * -8 + 0x20 == 0) {
    return;
  }
  uVar2 = *(ushort *)(param_1 + 0x34);
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) != 0) {
      func_0210c238(param_1,0);
    }
    puVar6 = (ushort *)(param_1 + 0x34);
    *(ushort *)(param_1 + 0x34) = *(ushort *)(param_1 + 0x34) & 0xfffd;
    if ((*(ushort *)(param_1 + 0x34) & 4) == 0) {
      return;
    }
    if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
      *puVar6 = *puVar6 | 1;
    }
    else {
      *puVar6 = *puVar6 & 0xfffe;
    }
    *(ushort *)(param_1 + 0x34) = *(ushort *)(param_1 + 0x34) & 0xfffb;
    return;
  }
  *(ushort *)(param_1 + 0x34) = uVar2 | 2;
  puVar6 = (ushort *)(param_1 + 0x34);
  if ((*(ushort *)(param_1 + 0x34) & 4) != 0) {
    if ((*(ushort *)(param_1 + 0x34) & 1) == 0) {
      *puVar6 = *puVar6 | 1;
    }
    else {
      *puVar6 = *puVar6 & 0xfffe;
    }
    *(ushort *)(param_1 + 0x34) = *(ushort *)(param_1 + 0x34) & 0xfffb;
  }
  uVar4 = uRam0210cf18;
  uVar8 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
  if (uVar8 != 0) {
    iVar9 = param_1 + 0xc;
    do {
      bVar1 = *(byte *)(uVar8 + 0x19);
      *(byte *)(uVar8 + 0x19) = *(byte *)(uVar8 + 0x19) & 0xf7;
      if (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 == 0 &&
          *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20 == 0) {
        if ((*(byte *)(uVar8 + 0x19) & 2) != 0) goto LAB_0210ce44;
        uVar5 = IntrusiveListWrapper_NextItem(iVar9,uVar8);
        func_0212c6f0(uVar8,0);
        *(byte *)(uVar8 + 0x19) = *(byte *)(uVar8 + 0x19) & 0xfb;
        *(byte *)(uVar8 + 0x19) = *(byte *)(uVar8 + 0x19) & 0xf7;
        *(byte *)(uVar8 + 0x19) = *(byte *)(uVar8 + 0x19) & 0xfd;
        func_0210bc54(iVar9,uVar8);
        bVar3 = true;
      }
      else {
        if ((*(byte *)(uVar8 + 0x19) & 4) == 0) {
          if (((*(byte *)(uVar8 + 0x19) & 1) != 0) &&
             (uVar5 = param_1 + 0x18U & 3, uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc),
             (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20) == 3)) {
            StructMQRacerEntry_MaybeInsertChildEntry(uVar4,param_1);
            *(undefined4 *)(param_1 + 0x18) = 1;
          }
        }
        else if ((bVar1 & 8) == 0) {
          uVar5 = IntrusiveListWrapper_NextItem(iVar9,uVar8);
          func_0212c6f0(uVar8,0);
          *(byte *)(uVar8 + 0x19) = *(byte *)(uVar8 + 0x19) & 0xfb;
          *(byte *)(uVar8 + 0x19) = *(byte *)(uVar8 + 0x19) & 0xf7;
          *(byte *)(uVar8 + 0x19) = *(byte *)(uVar8 + 0x19) & 0xfd;
          func_0210bc54(param_1 + 0xc,uVar8);
          bVar3 = true;
          goto LAB_0210ce54;
        }
LAB_0210ce44:
        uVar5 = IntrusiveListWrapper_NextItem(iVar9,uVar8);
      }
LAB_0210ce54:
      uVar8 = uVar5;
    } while (uVar5 != 0);
  }
  if (!bVar3) {
    return;
  }
  uVar8 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar8 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
  uVar5 = 3;
  if (uVar8 != 0) {
    do {
      bVar1 = *(byte *)(uVar8 + 0x19);
      if ((bVar1 & 2) != 0) {
        uVar5 = 0;
        break;
      }
      if (((bVar1 & 8) != 0) || ((bVar1 & 1) != 0)) {
        uVar5 = 1;
      }
      uVar8 = IntrusiveListWrapper_NextItem(param_1 + 0xc);
    } while (uVar8 != 0);
  }
  uVar8 = param_1 + 0x18U & 3;
  uVar7 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar8 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  if (uVar8 == uVar5) {
    return;
  }
  if (uVar8 != 3) {
    func_0210bc54(uVar8 * 0xc + iRam0210cf1c,param_1);
    *(undefined4 *)(param_1 + 0x18) = 3;
  }
  if (uVar5 == 3) {
    return;
  }
  StructMQRacerEntry_MaybeInsertChildEntry(uVar5 * 0xc + iRam0210cf1c,param_1);
  *(uint *)(param_1 + 0x18) = uVar5;
  return;
}

