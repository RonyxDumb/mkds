/* Decompiled C draft; module arm9_ov000; ROM address 021836f4. No matching claim. */
#include "types.h"
#include "deps/021836f4_FUN_021836f4.h"

void FUN_021836f4(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  iVar3 = func_0x02125f88();
  if (iVar3 != 0) {
    uVar4 = func_0x020b3f7c(*(undefined4 *)(*DAT_02183798 + DAT_0218379c),0xd);
    func_0x02126638(uVar4,0,0,1,0,0,0);
  }
  iVar3 = func_0x02125fa4();
  if (iVar3 != 0) {
    if ((*(ushort *)(DAT_021837a0 + 0x2e0) & 2) == 0) {
      bVar1 = false;
      bVar5 = false;
      if ((*(short *)(DAT_021837a4 + 0x2e0) == 0) && (*(ushort *)(DAT_021837a8 + 0x2e0) < 5)) {
        bVar5 = true;
      }
      if (((!bVar5) && (*(short *)(DAT_021837ac + 0x2e0) == 0)) &&
         (*(short *)(DAT_021837a4 + 0x2e0) != 0)) {
        bVar1 = true;
      }
      if (!bVar1) {
        return;
      }
      iVar3 = func_0x02128210(*(undefined2 *)(DAT_021837b0 + 0x2e0),
                              *(undefined2 *)(DAT_021837b4 + 0x2e0));
      if (iVar3 == 0) {
        return;
      }
    }
    piVar2 = DAT_02183798;
    *(undefined4 *)(*DAT_02183798 + 4) = 10;
    *(undefined4 *)(*piVar2 + 0x20) = 2;
    func_0x02128310(0);
    func_0x02125fc0();
  }
  return;
}

