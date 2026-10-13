/* Decompiled C draft; module arm9_ov000; ROM address 0218aa14. No matching claim. */
#include "types.h"
#include "deps/0218aa14_FUN_0218aa14.h"

void FUN_0218aa14(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_828;
  undefined1 auStack_824 [2];
  short local_822;
  int local_820;
  undefined4 local_81c;
  undefined1 auStack_818 [2052];
  
  local_81c = 8;
  if (param_2 == 0) {
    local_828 = param_1[8];
  }
  else {
    local_828 = param_1[9];
  }
  iVar1 = FUN_0218e668(local_828);
  do {
    if ((iVar1 == 0) ||
       (iVar1 = FUN_0218e438(local_828,auStack_818,DAT_0218ab10,0,auStack_824,&local_81c),
       iVar1 == -1)) {
      return;
    }
    auStack_818[iVar1] = 0;
    for (piVar3 = (int *)param_1[2]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[8]) {
      if (((((param_2 != 0) && ((*(byte *)((int)piVar3 + 0x15) & 8) != 0)) &&
           (piVar3[4] == local_820)) ||
          ((*piVar3 == local_820 && (((short)piVar3[1] == local_822 || (param_2 != 0)))))) ||
         ((*piVar3 == param_1[10] &&
          ((((*(byte *)((int)piVar3 + 0x15) & 2) != 0 && (piVar3[2] == local_820)) &&
           ((short)piVar3[3] == local_822)))))) {
        if (param_2 == 0) {
          if (*param_1 == 1) {
            FUN_0218ab90((int)(uintptr_t)(param_1),(int)(uintptr_t)(piVar3),auStack_818,iVar1);
          }
          else {
            FUN_0218ab18(param_1,piVar3,auStack_818,iVar1);
          }
          break;
        }
        iVar2 = FUN_0218ab14(param_1,piVar3,auStack_818,iVar1);
        if (iVar2 != 0) break;
      }
    }
    iVar1 = FUN_0218e668(local_828);
  } while( true );
}

