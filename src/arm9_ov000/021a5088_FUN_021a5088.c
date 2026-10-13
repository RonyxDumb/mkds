/* Decompiled C draft; module arm9_ov000; ROM address 021a5088. No matching claim. */
#include "types.h"
#include "deps/021a5088_FUN_021a5088.h"

void FUN_021a5088(int param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = DAT_021a5218;
  switch(*(undefined2 *)(param_1 + 2)) {
  case 0:
    switch(*(undefined2 *)(param_1 + 8)) {
    default:
      FUN_021a57fc(0xb);
      FUN_021a58a4(7,*DAT_021a5218 + DAT_021a5238,*(undefined2 *)(param_1 + 8),DAT_021a5240);
      return;
    case 6:
      break;
    case 7:
      if (*(int *)(*DAT_021a5218 + DAT_021a521c) == 0xc) {
        FUN_021a57fc(8);
        FUN_021a574c();
        return;
      }
      uVar1 = *(ushort *)(param_1 + 10);
      if ((uVar1 == 0) || (DAT_021a5228 < uVar1)) {
        FUN_021a574c();
        return;
      }
      *(ushort *)(*DAT_021a5218 + DAT_021a5220) = uVar1;
      iVar3 = func_0x02144514(DAT_021a522c,*piVar2 + DAT_021a5230,DAT_021a5234);
      if (iVar3 != 2) {
        if ((iVar3 != 3) && (iVar3 == 8)) {
          FUN_021a57fc(0xc);
          FUN_021a58a4(1,*DAT_021a5218 + DAT_021a5238,0,DAT_021a5228);
          return;
        }
        FUN_021a57fc(0xb);
        FUN_021a58a4(7,*DAT_021a5218 + DAT_021a5238,0,DAT_021a523c);
        return;
      }
      break;
    case 8:
    case 9:
      iVar3 = *DAT_021a5218;
      switch(*(undefined4 *)(iVar3 + DAT_021a521c)) {
      case 9:
        *(undefined2 *)(iVar3 + DAT_021a5220) = 0;
        *(undefined2 *)(*piVar2 + DAT_021a5224) = 6;
      case 0xc:
        FUN_021a574c();
        return;
      case 10:
        *(undefined2 *)(iVar3 + DAT_021a5220) = 0;
      case 8:
        FUN_021a57fc(0xc);
        return;
      }
    }
    break;
  case 1:
    *(undefined2 *)(*DAT_021a5218 + DAT_021a5244) = *(undefined2 *)(param_1 + 0xe);
  case 6:
  case 0xb:
  case 0xc:
    FUN_021a57fc(8);
    FUN_021a574c();
    return;
  default:
    FUN_021a57fc(0xb);
    FUN_021a58a4(7,*DAT_021a5218 + DAT_021a5238,0,DAT_021a5248);
  }
  return;
}

