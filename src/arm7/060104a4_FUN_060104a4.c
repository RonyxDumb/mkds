/* Decompiled C draft; module arm7; ROM address 060104a4. No matching claim. */
#include "types.h"
#include "deps/060104a4_FUN_060104a4.h"

undefined4 FUN_060104a4(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  uVar1 = DAT_06010584;
  puVar4 = (undefined2 *)
           ((*(uint *)(DAT_06010584 & 0xfffffffc) >> (DAT_06010584 & 3) * 8 |
            *(uint *)(DAT_06010584 & 0xfffffffc) << (DAT_06010584 & 3) * -8 + 0x20) + DAT_06010588);
  *(undefined2 *)(param_2 + 2) = 0x12;
  uVar5 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if (*(short *)((uVar1 >> uVar5 * 8 | uVar1 << uVar5 * -8 + 0x20) + 0x34c) == 0x20) {
    if (*(ushort *)(param_1 + 0x12) < 4) {
      if (*(ushort *)(param_1 + 0x14) < 0x40) {
        if (*(ushort *)(param_1 + 0x16) == 0) {
          uVar2 = 5;
        }
        else if (*(ushort *)(param_1 + 0x16) < 0x3e9) {
          uVar5 = 0;
          while ((uVar5 < 0x10 && (iVar3 = FUN_060096c4((ushort *)(uintptr_t)(param_1 + 0x18 + uVar5)), iVar3 != 0))) {
            iVar3 = FUN_0600a558();
            if (iVar3 == 0) {
              return 5;
            }
            uVar5 = uVar5 + 1;
          }
          if (uVar5 == 0) {
            uVar2 = 5;
          }
          else {
            *(int *)(puVar4 + 0xc) = param_1;
            *(int *)(puVar4 + 0xe) = param_2;
            *puVar4 = 0x80;
            *(undefined2 *)(param_2 + 4) = 0x80;
            FUN_0600fba4();
            uVar2 = 0x80;
          }
        }
        else {
          uVar2 = 5;
        }
      }
      else {
        uVar2 = 5;
      }
    }
    else {
      uVar2 = 5;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

