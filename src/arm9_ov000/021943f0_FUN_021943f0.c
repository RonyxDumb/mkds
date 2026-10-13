/* Decompiled C draft; module arm9_ov000; ROM address 021943f0. No matching claim. */
#include "types.h"
#include "deps/021943f0_FUN_021943f0.h"

int FUN_021943f0(int *param_1,int *param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_190 [4];
  int local_18c;
  undefined1 auStack_188 [16];
  undefined1 auStack_178 [31];
  undefined1 auStack_159 [33];
  undefined1 auStack_138 [33];
  undefined1 auStack_117 [259];
  
  iVar4 = *param_1;
  if (*param_2 != 0x68) {
    func_0x0213442c(DAT_0219455c,DAT_02194560,0,0xc1);
  }
  iVar1 = FUN_021907e8((undefined4)(uintptr_t)(param_1),param_2[2],param_2 + 6,(int *)(void *)(auStack_190),&local_18c,DAT_02194564);
  if (iVar1 == 0) {
    if (local_18c != 0) {
      *param_2 = 0x6a;
      return 0;
    }
    puVar2 = (undefined1 *)func_0x02139f70(param_2[6],DAT_02194568);
    if (puVar2 != (undefined1 *)0x0) {
      *puVar2 = 0;
      iVar5 = param_2[6];
      iVar1 = func_0x0213a038(iVar5,DAT_0219456c,6);
      if (iVar1 != 0) {
        *param_2 = 0x6a;
        return 0;
      }
      iVar1 = FUN_021967b4(iVar5,(char *)(uintptr_t)(DAT_02194570),(int)(uintptr_t)(auStack_188),0x10);
      if (iVar1 == 0) {
        *param_2 = 0x6a;
        return 0;
      }
      iVar1 = func_0x0213bf90((undefined4)(uintptr_t)(auStack_188));
      iVar5 = FUN_021967b4(param_2[6],(char *)(uintptr_t)(DAT_02194574),(int)(uintptr_t)(auStack_178),0x1f);
      if (iVar5 == 0) {
        *param_2 = 0x6a;
        return 0;
      }
      iVar5 = FUN_021967b4(param_2[6],(char *)(uintptr_t)(DAT_02194578),(int)(uintptr_t)(auStack_159),0x21);
      if (iVar5 == 0) {
        *param_2 = 0x6a;
        return 0;
      }
      func_0x02135014(auStack_117,DAT_0219457c,iVar4 + DAT_02194580,
                      *(undefined4 *)(iVar4 + DAT_02194584),iVar1);
      uVar3 = func_0x0213a434(auStack_117);
      FUN_0218e0fc((undefined4)(uintptr_t)(auStack_117),uVar3,(undefined4)(uintptr_t)(auStack_138));
      iVar4 = func_0x0213a074((uint)(uintptr_t)(auStack_159),(uint)(uintptr_t)(auStack_138));
      if (iVar4 != 0) {
        FUN_02190b80((undefined4)(uintptr_t)(param_1),(undefined4)(uintptr_t)(param_2 + 10),DAT_02194588);
        FUN_02190b80((undefined4)(uintptr_t)(param_1),param_2 + 10,DAT_02194568);
        *param_2 = 0x6a;
        return 0;
      }
      FUN_02190b80(param_1,param_2 + 10,DAT_0219458c);
      FUN_02190b80(param_1,param_2 + 10,DAT_02194568);
      *param_2 = 0x69;
      param_2[3] = iVar1;
      param_2[8] = 0;
    }
    iVar1 = 0;
  }
  return iVar1;
}

