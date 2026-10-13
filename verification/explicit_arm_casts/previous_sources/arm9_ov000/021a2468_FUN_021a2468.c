/* Decompiled C draft; module arm9_ov000; ROM address 021a2468. No matching claim. */
#include "types.h"
#include "deps/021a2468_FUN_021a2468.h"

void FUN_021a2468(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  undefined1 auStack_44 [12];
  undefined1 auStack_38 [36];
  
  FUN_021a10b0(1,param_3,param_5,param_6);
  piVar1 = DAT_021a25c4;
  *(bool *)(*DAT_021a25c4 + DAT_021a25c8) = param_4 != 0;
  *(undefined4 *)(*piVar1 + DAT_021a25cc) = param_7;
  *(undefined4 *)(*piVar1 + DAT_021a25d0) = param_8;
  func_0x0214d1fc(param_1,*piVar1 + DAT_021a25d4,param_2);
  *(int *)(*DAT_021a25c4 + DAT_021a25d8) = param_2;
  piVar1 = DAT_021a25c4;
  if ((param_2 != 0) &&
     (((param_3 <= param_2 || (param_4 != 0)) ||
      ((pcVar3 = (char *)*DAT_021a25dc, pcVar3 != (char *)0x0 &&
       ((*pcVar3 != '\0' && ((int)((byte)pcVar3[1] - 1) <= param_2)))))))) {
    *(undefined4 *)(*DAT_021a25c4 + DAT_021a25e0) = 4;
    iVar4 = *piVar1;
    if (*(int *)(iVar4 + 0xe4) == 0) {
      uVar2 = FUN_0218b668(*(undefined4 *)(iVar4 + DAT_021a25e4),
                           *(undefined4 *)(iVar4 + DAT_021a25e4),
                           *(undefined4 *)(iVar4 + DAT_021a25ec),0,0x14,1,0,DAT_021a25e8,0);
      *(undefined4 *)(*DAT_021a25c4 + 0xe4) = uVar2;
    }
    if ((*(int *)(*DAT_021a25c4 + 0xe4) != 0) || (iVar4 = FUN_0219e594(5), iVar4 == 0)) {
      func_0x0200d9e0(auStack_44,0xc,DAT_021a25f0,param_3);
      FUN_021a363c(DAT_021a25f4,auStack_44,auStack_38,0x2f);
      uVar2 = DAT_021a25fc;
      if (param_4 != 0) {
        uVar2 = DAT_021a25f8;
      }
      FUN_021a360c(DAT_021a2600,uVar2,auStack_38,0x2f);
      func_0x0200d9e0(auStack_44,0xc,DAT_021a25f0,3);
      FUN_021a360c(DAT_021a2604,auStack_44,auStack_38,0x2f);
      FUN_0219d558(4,auStack_38,0);
      iVar4 = FUN_0219e608();
      if (iVar4 == 0) {
        FUN_0219fbec(0,1);
        iVar4 = FUN_0219fee4();
        if (iVar4 == 0) {
          if (*(int *)(*DAT_021a25c4 + 0x10) == 0) {
            FUN_021a2768(*(undefined4 *)(*DAT_021a25c4 + DAT_021a2608));
          }
          FUN_0219e8b8(0);
        }
      }
    }
    return;
  }
  FUN_021a1a38(7,0);
  return;
}

