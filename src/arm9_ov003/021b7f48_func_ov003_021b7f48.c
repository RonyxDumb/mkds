/* Decompiled C draft; module arm9_ov003; ROM address 021b7f48. No matching claim. */
#include "types.h"
#include "deps/021b7f48_func_ov003_021b7f48.h"

undefined4
func_ov003_021b7f48(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  func_0x02133068(param_2,2);
  iVar1 = func_ov003_021ba178();
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  iVar2 = func_ov003_021ba178(param_2);
  if (iVar2 == 0) {
    func_ov003_021ba164(iVar1);
    return 0xffffffff;
  }
  iVar3 = 0;
  do {
    func_ov003_021b7efc(iVar3,iVar1,param_2,param_3,param_4);
    func_ov003_021b7ed0(iVar1,param_1,param_2);
    func_ov003_021b7e94(param_1,param_2,iVar2);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  func_ov003_021ba164(iVar1);
  func_ov003_021ba164(iVar2);
  return 0;
}

