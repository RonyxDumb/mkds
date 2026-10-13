/* Decompiled C draft; module arm9_ov001; ROM address 021829ac. No matching claim. */
#include "types.h"
#include "deps/021829ac_FUN_021829ac.h"

void FUN_021829ac(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  piVar1 = (int *)func_0x02100138(0x68);
  func_0x0207a974((short)*(char *)(*DAT_02182a34 + 0x62));
  if (piVar1 != (int *)0x0) {
    iVar4 = 0;
    for (iVar3 = 0;
        (iVar4 < (int)(uint)*(ushort *)(piVar1 + 1) &&
        (iVar2 = *(int *)(*piVar1 + iVar3), iVar2 != 0)); iVar3 = iVar3 + 4) {
      if (*(int *)(iVar2 + 0xf8) == 7) {
        if (*(int *)(iVar2 + 0xe8) != 0) {
          *(undefined4 *)(iVar2 + 0xe8) = 0;
        }
        iVar5 = iVar5 + 1;
        if (iVar5 <= param_1) {
          if ((*(ushort *)(iVar2 + 2) & DAT_02182a38) == 0) {
            func_0x020d2398();
          }
          if (*(int *)(*DAT_02182a34 + 8) == 4) {
            func_ov001_0218155c(1);
          }
        }
      }
      iVar4 = iVar4 + 1;
    }
  }
  return;
}

