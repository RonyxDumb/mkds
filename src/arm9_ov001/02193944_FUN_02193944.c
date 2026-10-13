/* Decompiled C draft; module arm9_ov001; ROM address 02193944. No matching claim. */
#include "types.h"
#include "deps/02193944_FUN_02193944.h"

void FUN_02193944(void)

{
  short sVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar3 = DAT_021939f4;
  *(int *)(*DAT_021939f4 + 0xc) = *(int *)(*DAT_021939f4 + 0xc) + 1;
  sVar1 = func_0x020ae4c0(1,0xfa,0,*(undefined4 *)(*piVar3 + 0xc),10);
  iVar6 = 0;
  piVar3 = DAT_021939fc;
  iVar4 = DAT_021939f8;
  do {
    iVar5 = 0;
    if (0 < *piVar3) {
      do {
        if (iVar6 == 1) {
          *(short *)(*(int *)(*DAT_021939f4 + 0x20) + (uint)*(byte *)(iVar4 + iVar5) * 0x40 + 4) =
               sVar1;
        }
        else {
          *(short *)(*(int *)(*DAT_021939f4 + 0x20) + (uint)*(byte *)(iVar4 + iVar5) * 0x40 + 4) =
               -sVar1;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < *piVar3);
    }
    iVar4 = iVar4 + 4;
    piVar3 = piVar3 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 3);
  iVar4 = FUN_02192e94();
  if ((iVar4 == 1) && (*(int *)(*DAT_021939f4 + 8) != 2)) {
    uVar2 = func_0x020ae4c0(1,0x32,0,*(undefined4 *)(*DAT_021939f4 + 0xc),10);
    *(undefined4 *)(*DAT_021939f4 + 0x18) = uVar2;
  }
  piVar3 = DAT_021939f4;
  if (9 < *(int *)(*DAT_021939f4 + 0xc)) {
    *(undefined4 *)(*DAT_021939f4 + 4) = 2;
    *(undefined4 *)(*piVar3 + 0xc) = 0;
    func_0x02128374();
  }
  return;
}

