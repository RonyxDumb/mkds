/* Decompiled C draft; module arm9; ROM address 02066ac0. No matching claim. */
#include "types.h"
#include "deps/02066ac0_StructMQRacerEntry_SomeFn_78.h"

void StructMQRacerEntry_SomeFn_78(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  
  uVar2 = param_1 + 0x514U & 3;
  uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar11 = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20;
  bVar1 = false;
  uVar2 = func_0205b954(*(undefined1 *)
                         ((*(uint *)(uRam02066ddc & 0xfffffffc) >> (uRam02066ddc & 3) * 8 |
                          *(uint *)(uRam02066ddc & 0xfffffffc) << (uRam02066ddc & 3) * -8 + 0x20) +
                         (*(ushort *)(param_1 + 0x74) & 0xff)));
  iVar3 = IsAwardOrStaffRoll();
  iVar5 = iRam02066de0;
  if (iVar3 != 1) {
    iVar5 = 0;
  }
  *(int *)(uVar11 + 0x24) = iVar5;
  uVar6 = uVar11 + 0x20 & 3;
  uVar4 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
  if ((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) < uVar2) {
    iVar5 = func_0205b978(*(undefined1 *)
                           ((*(uint *)(uRam02066ddc & 0xfffffffc) >> (uRam02066ddc & 3) * 8 |
                            *(uint *)(uRam02066ddc & 0xfffffffc) << (uRam02066ddc & 3) * -8 + 0x20)
                           + (*(ushort *)(param_1 + 0x74) & 0xff)),uVar2);
    if (iVar5 == 0) {
      puVar12 = (undefined4 *)0x0;
    }
    else {
      puVar12 = (undefined4 *)(iVar5 + 8);
    }
    if (puVar12 != (undefined4 *)0x0) {
      uVar6 = (*(uint *)(uRam02066de4 & 0xfffffffc) >> (uRam02066de4 & 3) * 8 |
              *(uint *)(uRam02066de4 & 0xfffffffc) << (uRam02066de4 & 3) * -8 + 0x20) + 0x728;
      uVar4 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      iVar5 = (uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) - uVar2;
      if (iVar5 < 0) {
        iVar3 = IntrusiveListWrapper_GetAtIndex(uVar11 + 0x8c,0);
        if (iVar3 != 0) {
          IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(uVar11 + 0x8c),iVar3);
          uVar8 = puVar12[1];
          uVar9 = puVar12[2];
          uVar10 = puVar12[3];
          *(undefined4 *)(iVar3 + 0xc) = *puVar12;
          *(undefined4 *)(iVar3 + 0x10) = uVar8;
          *(undefined4 *)(iVar3 + 0x14) = uVar9;
          *(undefined4 *)(iVar3 + 0x18) = uVar10;
          uVar8 = puVar12[5];
          *(undefined4 *)(iVar3 + 0x1c) = puVar12[4];
          *(undefined4 *)(iVar3 + 0x20) = uVar8;
          *(short *)(iVar3 + 8) = (short)((uint)(iVar5 * -0x10000) >> 0x10) + 1;
          IntrusiveListWrapper_InsertLast(uVar11 + 0x80,iVar3);
        }
        uVar6 = param_1 + 0x514U & 3;
        uVar4 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
        uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
        *(short *)(uVar6 + 0x5c) =
             *(short *)(uVar6 + 0x5c) +
             (short)(iRam02066de0 * ((int)*(short *)(uVar6 + 0x40) - (int)*(short *)(uVar6 + 0x5c))
                     + 0x800U >> 0xc);
        *(undefined2 *)(param_1 + 0x388) = *(undefined2 *)(uVar6 + 0x5c);
      }
      else {
        if (0x19 < iVar5) {
          iVar5 = 0x19;
        }
        StructMQRacerEntry_SomeFn_19(param_1,(short *)(void *)(puVar12),iVar5);
        bVar1 = true;
      }
    }
    *(uint *)(uVar11 + 0x20) = uVar2;
  }
  else {
    uVar2 = param_1 + 0x514U & 3;
    uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
    uVar2 = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20;
    *(short *)(uVar2 + 0x5c) =
         *(short *)(uVar2 + 0x5c) +
         (short)(iRam02066de0 * ((int)*(short *)(uVar2 + 0x40) - (int)*(short *)(uVar2 + 0x5c)) +
                 0x800U >> 0xc);
    *(undefined2 *)(param_1 + 0x388) = *(undefined2 *)(uVar2 + 0x5c);
  }
  uVar2 = param_1 + 0x514U & 3;
  uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar2 = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20;
  iVar5 = IntrusiveListWrapper_NextItem(uVar2 + 0x80,0);
  if (iVar5 != 0) {
    iVar3 = uVar2 + 0x80;
    do {
      iVar7 = IntrusiveListWrapper_NextItem(iVar3,iVar5);
      *(short *)(iVar5 + 8) = *(short *)(iVar5 + 8) + -1;
      if (*(short *)(iVar5 + 8) < 1) {
        if (!bVar1) {
          StructMQRacerEntry_SomeFn_19(param_1,(short *)(uintptr_t)(iVar5 + 0xc),0);
        }
        IntrusiveListWrapper_RemoveItem((uint *)(uintptr_t)(iVar3),iVar5);
        IntrusiveListWrapper_InsertLast(uVar2 + 0x8c,iVar5);
        iVar5 = iVar7;
        if (iVar7 == 0) break;
      }
      iVar5 = IntrusiveListWrapper_NextItem(iVar3,iVar5);
    } while (iVar5 != 0);
  }
  uVar2 = param_1 + 0x514U & 3;
  uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar2 = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + 0x44;
  uVar11 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) & 2) != 0) {
    uVar2 = param_1 + 0x78U & 3;
    uVar11 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    func_0204360c(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20,1);
  }
  uVar2 = param_1 + 0x514U & 3;
  uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar2 = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + 0x44;
  uVar11 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) & 4) != 0) {
    uVar2 = param_1 + 0x78U & 3;
    uVar11 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    func_0204360c(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20,2);
  }
  uVar2 = param_1 + 0x514U & 3;
  uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar2 = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + 0x44;
  uVar11 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) & 8) != 0) {
    uVar2 = param_1 + 0x78U & 3;
    uVar11 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    func_0204360c(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20,0x20);
  }
  uVar2 = param_1 + 0x514U & 3;
  uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar2 = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + 0x44;
  uVar11 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) & 0x10) != 0) {
    uVar2 = param_1 + 0x78U & 3;
    uVar11 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    func_0204360c(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20,0x10);
  }
  uVar2 = param_1 + 0x514U & 3;
  uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar2 = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + 0x44;
  uVar11 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) & 1) != 0) {
    uVar2 = param_1 + 0x44U & 3;
    uVar11 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x44) = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20 | 0x10;
  }
  uVar2 = param_1 + 0x514U & 3;
  uVar11 = *(uint *)(param_1 + 0x514U & 0xfffffffc);
  uVar2 = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + 0x44;
  uVar11 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (((uVar2 >> uVar11 * 8 | uVar2 << uVar11 * -8 + 0x20) & 0x20) != 0) {
    *(undefined2 *)(param_1 + 0x238) = 3;
    uVar2 = param_1 + 0x48U & 3;
    uVar11 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20 | 0x20;
    return;
  }
  *(undefined2 *)(param_1 + 0x238) = 0;
  uVar2 = param_1 + 0x48U & 3;
  uVar11 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) & 0xffffffdf;
  return;
}

