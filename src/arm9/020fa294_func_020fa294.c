/* Decompiled C draft; module arm9; ROM address 020fa294. No matching claim. */
#include "types.h"
#include "deps/020fa294_func_020fa294.h"

void func_020fa294(void)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_40;
  undefined1 auStack_28 [4];
  int local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  uVar1 = *(ushort *)(*piRam020fa3b0 + 4);
  local_40 = 0;
  if (uVar1 != 0) {
    iVar7 = 0;
    uVar2 = *puRam020fa3b4;
    do {
      iVar5 = *(int *)*piRam020fa3b0 + iVar7;
      if (*(short *)(iVar5 + 0x24) == 0x6d) {
        sVar3 = *(short *)(iVar5 + 0x28);
        iVar4 = func_01ffdee4((int *)(uintptr_t)(iVar5),0,0,uRam020fa3b8,8,0xfffffffe,0,&local_20,0,0,0,0,0,(uint *)(void *)(auStack_28));
        if (iVar4 == 0) {
          local_20 = *puRam020fa3bc;
          uStack_1c = puRam020fa3bc[1];
          local_18 = puRam020fa3bc[2];
        }
        local_24 = 0;
        iVar6 = sVar3 * 0x44;
        iVar4 = *piRam020fa3c0 + iVar6;
        if (0 < *(int *)(iVar4 + 0x20) - *(int *)(iVar4 + 0x1c)) {
          func_020f1048(iVar4,1,(int)(uintptr_t)(&local_24),8,iVar5);
          iVar6 = *piRam020fa3c0 + iVar6;
          *(int *)(iVar6 + 0x1c) = *(int *)(iVar6 + 0x1c) + 1;
          func_020f0ea0(*piRam020fa3c0 + *(int *)(local_24 + 0x44) * 0x44);
          func_020f98a0(local_24,(undefined4 *)(uintptr_t)(iVar5),&local_20,0,0);
          *(ushort *)(local_24 + 0x78) = *(ushort *)(local_24 + 0x78) | uVar2;
        }
        if (local_24 != 0) {
          if ((*(uint *)(local_24 + 0x74) & uRam020fa3c8) == 0) {
            *(undefined4 *)(local_24 + iRam020fa3cc) =
                 *(undefined4 *)(*piRam020fa3c4 + *(int *)(local_24 + 0x44) * 0xa8 + 0x28);
          }
          func_020f6a6c(local_24,(undefined4)(uintptr_t)(auStack_28));
        }
      }
      iVar7 = iVar7 + 0x3c;
      local_40 = local_40 + 1;
    } while (local_40 < uVar1);
  }
  return;
}

