/* Decompiled C draft; module arm9_ov000; ROM address 02181854. No matching claim. */
#include "types.h"
#include "deps/02181854_FUN_02181854.h"

void FUN_02181854(void)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = func_0x02125f6c();
  if (iVar2 != 0) {
    func_0x0212ecc0(DAT_021818e4,0,0x15);
  }
  iVar2 = func_0x02125fa4();
  if ((iVar2 != 0) && (iVar2 = func_0x02128294(), iVar2 != 0)) {
    if ((*(ushort *)(DAT_021818e8 + 0x2e0) & 2) == 0) {
      bVar1 = false;
      bVar3 = false;
      if ((*(short *)(DAT_021818ec + 0x2e0) == 0) && (*(ushort *)(DAT_021818f0 + 0x2e0) < 5)) {
        bVar3 = true;
      }
      if (((!bVar3) && (*(short *)(DAT_021818f4 + 0x2e0) == 0)) &&
         (*(short *)(DAT_021818ec + 0x2e0) != 0)) {
        bVar1 = true;
      }
      if (!bVar1) {
        return;
      }
      iVar2 = func_0x02128210(*(undefined2 *)(DAT_021818f8 + 0x2e0),
                              *(undefined2 *)(DAT_021818fc + 0x2e0));
      if (iVar2 == 0) {
        return;
      }
    }
    *(undefined4 *)(*DAT_02181900 + 4) = 1;
    func_0x02128310(0);
    func_0x02125fc0();
  }
  return;
}

