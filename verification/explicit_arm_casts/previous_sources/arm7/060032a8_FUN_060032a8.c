/* Decompiled C draft; module arm7; ROM address 060032a8. No matching claim. */
#include "types.h"
#include "deps/060032a8_FUN_060032a8.h"

void FUN_060032a8(int param_1)

{
  int iVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_210 [516];
  uint uVar5;
  
  iVar1 = FUN_06000680();
  uVar3 = iVar1 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar5 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  thunk_FUN_037fb390(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,
                     (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                     *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xe4,0x40);
  uVar3 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  if ((1 << (*(ushort *)(uVar3 + 0x116) & 0xff) & (uint)*(ushort *)(uVar3 + 0x1f0)) == 0) {
    puVar2 = (undefined2 *)thunk_FUN_03807424();
    *puVar2 = 7;
    puVar2[1] = 6;
    thunk_FUN_038074cc();
  }
  else {
    iVar1 = FUN_06002334(auStack_210,*(undefined2 *)(uVar3 + 0xf4));
    if (*(short *)(iVar1 + 4) == 0) {
      puVar2 = (undefined2 *)thunk_FUN_03807424();
      *puVar2 = 7;
      puVar2[1] = 0;
      thunk_FUN_038074cc();
    }
    else {
      FUN_0600326c(DAT_06003358);
    }
  }
  return;
}

