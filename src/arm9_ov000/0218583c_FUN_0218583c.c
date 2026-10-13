/* Decompiled C draft; module arm9_ov000; ROM address 0218583c. No matching claim. */
#include "types.h"
#include "deps/0218583c_FUN_0218583c.h"

void FUN_0218583c(void)

{
  ushort *puVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = func_0x02036d08();
  if (iVar4 != 0) {
    *(undefined4 *)(*DAT_021858e8 + 4) = 1;
    func_0x02037288(0x1e);
    puVar1 = DAT_021858ec;
    *DAT_021858ec = *DAT_021858ec & 0x43 | (ushort)DAT_021858f0;
    *puVar1 = *puVar1 & 0xfffc;
    uVar5 = DAT_021858f8;
    puVar2 = DAT_021858f4;
    *DAT_021858f4 = *DAT_021858f4 & DAT_021858f8 | DAT_021858fc;
    puVar3 = DAT_02185900;
    *DAT_02185900 = *DAT_02185900 & uVar5 | DAT_02185904;
    uVar5 = DAT_02185908;
    *puVar2 = *puVar2 & DAT_02185908;
    *puVar3 = *puVar3 & uVar5;
    func_0x02148950(1,0,1);
    if (*(int *)(*DAT_0218590c + 0x6c) != 0) {
      uVar5 = *(uint *)(*(int *)*DAT_02185910 + 0x48);
      uVar6 = (int)((*(byte *)(*DAT_02185914 + DAT_02185918) - 1) * 0x1000000) >> 0x18;
      if (0 < (int)uVar6) {
        if (uVar5 < uVar6) {
          uVar5 = 0;
        }
        else {
          uVar5 = uVar5 - uVar6;
        }
      }
      *(uint *)(*(int *)*DAT_02185910 + 0x48) = uVar5;
      func_0x02056d40();
      func_0x02057d9c();
      if (*(int *)(*DAT_0218591c + 0xc) != 0) {
        func_0x02145d38();
      }
    }
  }
  return;
}

