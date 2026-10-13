/* Decompiled C draft; module arm9_ov000; ROM address 02185418. No matching claim. */
#include "types.h"
#include "deps/02185418_FUN_02185418.h"

void FUN_02185418(void)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  
  if ((*(ushort *)(DAT_0218548c + 0x2e0) & 2) == 0) {
    bVar2 = false;
    bVar1 = false;
    if ((*(short *)(DAT_02185490 + 0x2e0) == 0) && (*(ushort *)(DAT_02185494 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_02185498 + 0x2e0) == 0)) &&
       (*(short *)(DAT_02185490 + 0x2e0) != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      return;
    }
    iVar4 = func_0x02128210(*(undefined2 *)(DAT_0218549c + 0x2e0),
                            *(undefined2 *)(DAT_021854a0 + 0x2e0));
    if (iVar4 == 0) {
      return;
    }
  }
  piVar3 = DAT_021854a4;
  *(undefined4 *)(*DAT_021854a4 + 4) = 2;
  *(undefined4 *)(*piVar3 + 0x28) = 8;
  func_0x02128310(0);
  func_0x02125fc0();
  return;
}

