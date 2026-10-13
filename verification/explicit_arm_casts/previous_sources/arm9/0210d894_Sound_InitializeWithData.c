/* Decompiled C draft; module arm9; ROM address 0210d894. No matching claim. */
#include "types.h"
#include "deps/0210d894_Sound_InitializeWithData.h"

void Sound_InitializeWithData(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  Sound_EnsureInitialized();
  uVar3 = Sound_InitializeContext(param_1,param_2);
  puVar2 = puRam0210d93c;
  *puRam0210d93c = uVar3;
  uVar1 = (uint)puVar2 & 3;
  uVar4 = *(uint *)((uint)puVar2 & 0xfffffffc);
  uVar3 = Sound_Context_Allocate
                    (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,uRam0210d940,uRam0210d944,0,0);
  *puRam0210d948 = uVar3;
  if (param_3 != 0) {
    Sound_ReadSdatFromPathImpl
              (uRam0210d94c,param_3,
               *(uint *)((uint)puRam0210d93c & 0xfffffffc) >> ((uint)puRam0210d93c & 3) * 8 |
               *(uint *)((uint)puRam0210d93c & 0xfffffffc) << ((uint)puRam0210d93c & 3) * -8 + 0x20,
               0);
    uVar1 = (uint)puRam0210d93c & 3;
    uVar4 = *(uint *)((uint)puRam0210d93c & 0xfffffffc);
    *puRam0210d950 = 1;
    func_0212edac(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  }
  func_0212c6a0(uRam0210d954);
  func_0210dc60(uRam0210d958,uRam0210d95c,0);
  return;
}

