/* Decompiled C draft; module arm9; ROM address 0206a24c. No matching claim. */
#include "types.h"
#include "deps/0206a24c_func_0206a24c.h"

undefined4 func_0206a24c(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 + 0x4cU & 3;
  uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
  iVar3 = param_1 + iRam0206a340;
  if ((((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam0206a344) == 0) &&
     (uVar1 = param_1 + 0x48U & 3, uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
     ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000) == 0)) {
    *(undefined2 *)(iVar3 + 0xc) = 0;
    *(undefined2 *)(iVar3 + 0xe) = 600;
    *(undefined4 *)(param_1 + 0x41c) = 0x1000;
    *(undefined4 *)(param_1 + 0x420) = 0x1000;
    *(undefined4 *)(param_1 + 0x424) = 0x1000;
    *(undefined2 *)(param_1 + 0x3a4) = 0;
    uVar1 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    *(uint *)(param_1 + 0x4c) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x10000;
    uVar1 = param_1 + 0x48U & 3;
    uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 0x4000000;
    uVar1 = param_1 + 0x7cU & 3;
    uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0) {
      func_02074874(8000);
    }
    uVar2 = uRam0206a34c;
    *(undefined4 *)(param_1 + 0x394) = uRam0206a348;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    func_020eff40((uint)*(ushort *)(param_1 + 0x74) * 0x210 +
                  (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20));
    uVar1 = (*(uint *)(uRam0206a350 & 0xfffffffc) >> (uRam0206a350 & 3) * 8 |
            *(uint *)(uRam0206a350 & 0xfffffffc) << (uRam0206a350 & 3) * -8 + 0x20) + 8;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 4) {
      func_0x0218173c();
    }
    uVar1 = param_1 + 0x48U & 3;
    uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x840) == 0) {
      uVar1 = param_1 + 0x3ccU & 3;
      uVar2 = *(uint *)(param_1 + 0x3ccU & 0xfffffffc);
      StructMQRacerEntry_SomeFn_5(param_1,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
    }
    return 1;
  }
  return 0;
}

