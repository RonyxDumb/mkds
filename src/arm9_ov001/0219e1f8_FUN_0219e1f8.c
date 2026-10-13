/* Decompiled C draft; module arm9_ov001; ROM address 0219e1f8. No matching claim. */
#include "types.h"
#include "deps/0219e1f8_FUN_0219e1f8.h"

void FUN_0219e1f8(void)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  
  piVar4 = DAT_0219e278;
  *(int *)(*DAT_0219e278 + 8) = *(int *)(*DAT_0219e278 + 8) + 1;
  piVar4 = (int *)*piVar4;
  uVar3 = (uint)*(ushort *)(DAT_0219e27c + *piVar4 * 2);
  if ((int)uVar3 < piVar4[2]) {
    piVar4[2] = uVar3;
    piVar4 = DAT_0219e278;
    if ((*(ushort *)(DAT_0219e280 + 0x2e0) & DAT_0219e284) == 0) {
      bVar2 = false;
      bVar1 = false;
      if ((*(short *)(DAT_0219e288 + 0x2e0) == 0) && (*(ushort *)(DAT_0219e28c + 0x2e0) < 5)) {
        bVar1 = true;
      }
      if (((!bVar1) && (*(short *)(DAT_0219e290 + 0x2e0) == 0)) &&
         (*(short *)(DAT_0219e288 + 0x2e0) != 0)) {
        bVar2 = true;
      }
      if (!bVar2) {
        return;
      }
    }
    *(undefined4 *)(*DAT_0219e278 + 4) = 6;
    *(undefined4 *)(*piVar4 + 8) = 0;
    func_0x02036f10((int)*(short *)(DAT_0219e27c + 0xc));
  }
  return;
}

