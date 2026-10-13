/* Decompiled C draft; module arm9_ov000; ROM address 021a0064. No matching claim. */
#include "types.h"
#include "deps/021a0064_FUN_021a0064.h"

undefined4 FUN_021a0064(int param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 unaff_r4;
  undefined4 uVar4;
  
  puVar3 = (undefined4 *)*DAT_021a01c0;
  cVar1 = *(char *)((int)puVar3 + 0x15);
  if (cVar1 != '\0') {
    if (cVar1 != '\x01') {
      if (cVar1 != '\x02') {
        return unaff_r4;
      }
      iVar2 = FUN_0218eb9c(*puVar3,param_1);
      if (iVar2 == 0) {
        return 0xff;
      }
      if ((param_2 != 3) ||
         (iVar2 = *DAT_021a01c0, *(char *)(iVar2 + 0x14) == *(char *)(iVar2 + 0x16))) {
        return 3;
      }
      if ((*DAT_021a01d8 == '\x01') && (DAT_021a01d8[1] == '\x01')) {
        return 0x13;
      }
      if ((*(int *)(iVar2 + DAT_021a01cc) == 10) &&
         ((*(int *)(iVar2 + 0x1c) != 0 || (*(short *)(iVar2 + 0x1a) != 0)))) {
        return 2;
      }
      return 4;
    }
    iVar2 = FUN_0218eb9c(*puVar3,param_1);
    if (iVar2 == 0) {
      return 0xff;
    }
  }
  iVar2 = *DAT_021a01c0;
  if ((((param_2 == *(byte *)(iVar2 + 0x15)) && (*(char *)(iVar2 + DAT_021a01c4) == '\0')) &&
      (*(char *)(iVar2 + 0x14) != *(char *)(iVar2 + 0x16))) &&
     ((*(char *)(iVar2 + 0x17) == '\0' || (*(int *)(iVar2 + 0x20) != *(int *)(iVar2 + DAT_021a01c8))
      ))) {
    if (((*(int *)(iVar2 + DAT_021a01cc) == 3) || (*(int *)(iVar2 + DAT_021a01cc) == 4)) &&
       ((*(int *)(iVar2 + 0x1c) != 0 || (*(short *)(iVar2 + 0x1a) != 0)))) {
      if (*(int *)(iVar2 + DAT_021a01d0) == 0) {
        uVar4 = 2;
      }
      else if (*(int *)(iVar2 + DAT_021a01d0) == param_1) {
        if ((param_3 == 0) &&
           ((param_1 <= *(int *)(iVar2 + DAT_021a01c8) ||
            (param_1 == *(int *)(iVar2 + DAT_021a01d4))))) {
          uVar4 = 0xff;
        }
        else {
          uVar4 = 2;
        }
      }
      else if ((param_3 == 0) &&
              ((param_1 <= *(int *)(iVar2 + DAT_021a01c8) || (*(int *)(iVar2 + DAT_021a01d4) != 0)))
              ) {
        uVar4 = 3;
      }
      else {
        FUN_0219fb14();
        iVar2 = FUN_0219fee4();
        if (iVar2 != 0) {
          return 0xff;
        }
        uVar4 = 2;
      }
    }
    else {
      uVar4 = 4;
    }
  }
  else {
    uVar4 = 3;
    if (((*(char *)(iVar2 + 0x15) == '\0') &&
        ((*(int *)(*(int *)(iVar2 + 0x10) + 0xb4) == 0 && (*(char *)(iVar2 + 0x17) != '\0')))) &&
       (*(int *)(*DAT_021a01c0 + 0x20) == *(int *)(*DAT_021a01c0 + DAT_021a01c8))) {
      FUN_021a4818();
    }
  }
  return uVar4;
}

