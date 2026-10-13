/* Decompiled C draft; module arm9; ROM address 02086e8c. No matching claim. */
#include "types.h"
#include "deps/02086e8c_StructAERSubSub_SomeFn_from_thumb.h"

void StructAERSubSub_SomeFn_from_thumb(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = (*(code *)*puRam02086f14)(param_1[1],0,0);
  uVar2 = uVar2 & uRam02086f18;
  *param_1 = *param_1 & uRam02086f1c;
  func_0214c6a8();
  func_0214c544(param_1[3],uVar2 * 8,param_1[1]);
  func_0214c4d4();
  *param_1 = *param_1 | uVar2 & 0x1fffffff & uRam02086f18;
  if ((short)param_1[2] != 0) {
    uVar1 = (*(code *)*puRam02086f20)((short)param_1[2],(uVar1 >> 0x1a & 7) == 2,0);
    param_1[6] = (uVar1 & uRam02086f18) << 3;
    func_0214c48c();
    SomeDmaCopy_0(param_1[4],param_1[6],(short)param_1[2]);
    func_0214c3c0();
  }
  StructAERSubSub_SomeFn_1_from_thumb(param_1);
  return;
}

