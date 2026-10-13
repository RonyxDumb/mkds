/* Decompiled C draft; module arm7; ROM address 0600808c. No matching claim. */
#include "types.h"
#include "deps/0600808c_FUN_0600808c.h"

undefined4 FUN_0600808c(undefined2 *param_1,undefined2 *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_218 [516];
  uint uVar6;
  
  iVar3 = FUN_06000680();
  uVar6 = iVar3 + 0x154cU & 3;
  uVar5 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  iVar3 = FUN_060020e0((undefined4)(uintptr_t)(auStack_218));
  if (*(short *)(iVar3 + 4) == 0) {
    iVar3 = FUN_0600210c((undefined4)(uintptr_t)(auStack_218));
    if (*(short *)(iVar3 + 4) == 0) {
      FUN_06008054();
      iVar3 = FUN_06002150((undefined4)(uintptr_t)(auStack_218));
      if (*(short *)(iVar3 + 4) == 0) {
        uVar1 = *(ushort *)(iVar3 + 6);
        *(ushort *)
         ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1f0) = uVar1;
        uVar2 = thunk_FUN_038072f8(((uint)uVar1 << 0xf) >> 0x10);
        *(undefined2 *)
         ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1f2) = uVar2;
        FUN_06002394((undefined2 *)(void *)(auStack_218),DAT_06008298,0x28,5);
        uVar5 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
        *(undefined4 *)(uVar5 + 0x7b4) = DAT_0600829c;
        *(undefined4 *)(uVar5 + 0x7b8) = 0;
        *(undefined2 *)
         ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1e8) = 2;
        *(undefined2 *)
         ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x1ea) = 1;
        iVar3 = FUN_060020b0((undefined4)(uintptr_t)(auStack_218));
        if (*(short *)(iVar3 + 4) == 0) {
          thunk_FUN_037fb230(iVar3 + 6,
                             (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                             *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20,8);
          *(undefined2 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x28) =
               *(undefined2 *)(iVar3 + 0xe);
          *(undefined2 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x2c) =
               *(undefined2 *)(iVar3 + 0x10);
          *(undefined2 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x2e) =
               *(undefined2 *)(iVar3 + 0x12);
          *(undefined2 *)
           ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
            *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x2a) =
               *(undefined2 *)(iVar3 + 0x14);
          iVar3 = FUN_06002168((undefined4)(uintptr_t)(auStack_218));
          if (*(short *)(iVar3 + 4) == 0) {
            thunk_FUN_037fb390(iVar3 + 6,
                               (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                               *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0xdc,6);
            iVar3 = FUN_060022d4((undefined2 *)(void *)(auStack_218),1);
            if (*(short *)(iVar3 + 4) == 0) {
              uVar4 = 1;
            }
            else {
              *param_1 = (short)DAT_060082a8;
              *param_2 = *(undefined2 *)(iVar3 + 4);
              uVar4 = 0;
            }
          }
          else {
            *param_1 = (short)DAT_060082a4;
            *param_2 = *(undefined2 *)(iVar3 + 4);
            uVar4 = 0;
          }
        }
        else {
          *param_1 = (short)DAT_060082a0;
          *param_2 = *(undefined2 *)(iVar3 + 4);
          uVar4 = 0;
        }
      }
      else {
        *param_1 = (short)DAT_06008294;
        *param_2 = *(undefined2 *)(iVar3 + 4);
        uVar4 = 0;
      }
    }
    else {
      *param_1 = (short)DAT_06008290;
      *param_2 = *(undefined2 *)(iVar3 + 4);
      uVar4 = 0;
    }
  }
  else {
    *param_1 = 0x304;
    *param_2 = *(undefined2 *)(iVar3 + 4);
    uVar4 = 0;
  }
  return uVar4;
}

