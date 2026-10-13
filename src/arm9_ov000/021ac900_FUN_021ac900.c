/* Decompiled C draft; module arm9_ov000; ROM address 021ac900. No matching claim. */
#include "types.h"
#include "deps/021ac900_FUN_021ac900.h"

void FUN_021ac900(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  undefined2 *puVar6;
  int local_38;
  int local_34;
  uint local_30;
  
  puVar1 = (undefined2 *)(param_6 + param_5 * 2);
  puVar6 = puVar1 + param_5;
  func_0x0214d168((uint *)(void *)(puVar1),0,param_5 << 2);
  iVar2 = thunk_FUN_021acecc(param_2,param_5);
  iVar3 = thunk_FUN_021acecc(param_3,param_5);
  if ((0 < iVar2) && (0 < iVar3)) {
    local_38 = iVar3 + (param_5 - iVar2) + -1;
    if (local_38 < param_5) {
      func_0x0214d1fc((ushort *)(uintptr_t)(param_2),(uint *)(void *)(puVar1 + local_38),iVar2 << 1);
      if (iVar3 < 3) {
        if (iVar3 < 2) {
          local_30 = (uint)*(ushort *)(param_3 + iVar3 * 2 + -2);
          local_34 = 0;
        }
        else {
          iVar2 = param_3 + iVar3 * 2;
          local_30 = (uint)*(ushort *)(iVar2 + -2);
          local_34 = (uint)*(ushort *)(iVar2 + -4) * 0x10000;
        }
      }
      else {
        iVar2 = param_3 + iVar3 * 2;
        uVar5 = (uint)*(ushort *)(iVar2 + -4) * 0x10000;
        local_34 = *(ushort *)(iVar2 + -6) + uVar5;
        local_30 = (uint)*(ushort *)(iVar2 + -2) + (uint)CARRY4((uint)*(ushort *)(iVar2 + -6),uVar5)
        ;
      }
      if (local_38 < param_5) {
        puVar4 = puVar6 + iVar3;
        do {
          func_0x02134df8((uint *)(void *)(puVar1 + 1),(uint *)(void *)(puVar1),(param_5 * 2 + -1) * 2);
          uVar5 = func_0x02132e40((uint)puVar4[-3] + (uint)puVar4[-2] * 0x10000,
                                  (uint)*puVar4 * 0x10000 + (uint)puVar4[-1] +
                                  (uint)CARRY4((uint)puVar4[-3],(uint)puVar4[-2] * 0x10000),local_34
                                  ,local_30);
          if (DAT_021acaac < uVar5) {
            uVar5 = DAT_021acaac;
          }
          while( true ) {
            FUN_021acb98((undefined2 *)(uintptr_t)(param_6),(ushort *)(uintptr_t)(param_3),uVar5 & 0xffff,param_5);
            iVar2 = FUN_021acc8c((int)(uintptr_t)(puVar6),param_6,param_5);
            if (-1 < iVar2) break;
            uVar5 = uVar5 - 1;
          }
          FUN_021acd24(puVar6,puVar6,(ushort *)(uintptr_t)(param_6),param_5);
          *puVar1 = (short)uVar5;
          local_38 = local_38 + 1;
        } while (local_38 < param_5);
      }
    }
    else {
      func_0x0214d1fc((ushort *)(uintptr_t)(param_2),(uint *)(void *)(puVar6),param_5 << 1);
    }
  }
  if (param_1 != 0) {
    func_0x0214d1fc(puVar1,(uint *)(uintptr_t)(param_1),param_5 << 1);
  }
  if (param_4 != 0) {
    func_0x0214d1fc(puVar6,(uint *)(uintptr_t)(param_4),param_5 << 1);
  }
  return;
}

