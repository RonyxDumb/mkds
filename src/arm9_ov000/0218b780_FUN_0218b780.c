/* Decompiled C draft; module arm9_ov000; ROM address 0218b780. No matching claim. */
#include "types.h"
#include "deps/0218b780_FUN_0218b780.h"

void FUN_0218b780(int param_1,undefined4 param_2,int *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  
  switch(param_2) {
  case 0:
    (**(code **)(param_4 + DAT_0218b8cc))(param_4,0,param_3,*(undefined4 *)(param_4 + DAT_0218b8c8))
    ;
    bVar1 = *(byte *)(param_3 + 5);
    if (((((bVar1 & 3) == 0) || ((bVar1 & 0x40) == 0)) && ((bVar1 & 0x2c) == 0)) &&
       (*(int *)(param_4 + DAT_0218b8d0) == 0)) {
      if ((*(byte *)((int)param_3 + 0x15) & 1) == 0) {
        uVar3 = 2;
      }
      else if ((*(int *)(param_4 + 0x4c) == 0) || (*(int *)(param_4 + 0x40) == 0)) {
        uVar3 = 1;
      }
      else {
        uVar3 = 0;
      }
      FUN_0218ac54(param_4,(int)(uintptr_t)(param_3),0,uVar3);
    }
    break;
  case 1:
    if ((*(byte *)(param_3 + 5) & 0x43) == 0) {
      (**(code **)(param_4 + DAT_0218b8cc))
                (param_4,2,param_3,*(undefined4 *)(param_4 + DAT_0218b8c8));
    }
    else {
      (**(code **)(param_4 + DAT_0218b8cc))
                (param_4,1,param_3,*(undefined4 *)(param_4 + DAT_0218b8c8));
    }
    break;
  case 2:
    if ((*(byte *)(param_3 + 5) & 0x2c) != 0) {
      FUN_0218a918(param_4,(undefined4)(uintptr_t)(param_3));
    }
    (**(code **)(param_4 + DAT_0218b8cc))(param_4,3,param_3,*(undefined4 *)(param_4 + DAT_0218b8c8))
    ;
    break;
  case 3:
    if (*(int *)(param_4 + DAT_0218b8d4) != 0) {
      FUN_0218c980();
    }
    iVar2 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 4)));
    if ((iVar2 == 0) || (*(int *)(param_4 + 0x10) == 0)) {
      (**(code **)(param_4 + DAT_0218b8cc))(param_4,4,0,*(undefined4 *)(param_4 + DAT_0218b8c8));
    }
    break;
  case 5:
    (**(code **)(param_4 + DAT_0218b8cc))(param_4,5,0,*(undefined4 *)(param_4 + DAT_0218b8c8));
    break;
  case 6:
    FUN_0218acf0(param_4,*(undefined4 *)(param_4 + DAT_0218b8d8));
  }
  if (((param_3 != (int *)0x0) && (*param_3 == *(int *)(param_4 + DAT_0218b8dc))) &&
     ((short)param_3[1] == *(short *)(param_4 + DAT_0218b8e0))) {
    *(int *)(param_4 + DAT_0218b8dc) = 0;
  }
  return;
}

