/* Decompiled C draft; module arm9_ov000; ROM address 021afe84. No matching claim. */
#include "types.h"
#include "deps/021afe84_FUN_021afe84.h"

void FUN_021afe84(undefined4 param_1,undefined4 param_2,char *param_3,int param_4,int param_5,
                 int param_6)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_20;
  
  if ((((((*DAT_021affb4 != 0) && (uVar5 = *DAT_021affb8, uVar5 != 0)) &&
        (uVar3 = param_4 + param_6, 7 < uVar3)) &&
       ((uVar3 <= DAT_021affbc && (*param_3 == *DAT_021affc0)))) &&
      ((param_3[1] == DAT_021affc0[1] && ((param_3[2] == DAT_021affc0[2] && (param_3[6] == '\b')))))
      ) && ((param_3[7] == '\0' || (param_3[7] == '\x06')))) {
    uVar7 = uVar3 + 9 & 0xfffe;
    uVar4 = *DAT_021affc4;
    uVar6 = uVar4 + uVar7;
    uVar3 = *DAT_021affc8;
    if ((uVar3 <= uVar4) || (uVar6 < uVar3)) {
      if (uVar6 == uVar5) {
        local_20 = 0;
        if (uVar3 == 0) {
          return;
        }
      }
      else {
        local_20 = uVar6;
        if ((uVar5 < uVar6) && (local_20 = uVar7, uVar3 <= uVar7)) {
          return;
        }
      }
      if (uVar5 < uVar6) {
        if (1 < uVar5 - uVar4) {
          *(undefined1 *)(*DAT_021affb4 + uVar4) = 0;
          *(undefined1 *)(*DAT_021affb4 + *DAT_021affc4 + 1) = 0;
        }
        *DAT_021affc4 = 0;
      }
      puVar2 = DAT_021affc4;
      piVar1 = DAT_021affb4;
      *(char *)(*DAT_021affb4 + *DAT_021affc4) = (char)uVar7;
      *(char *)(*piVar1 + *puVar2 + 1) = (char)(uVar7 >> 8);
      func_0x0214d1fc((ushort *)(uintptr_t)(param_2),(uint *)(uintptr_t)(*piVar1 + *puVar2 + 2),6);
      func_0x0214d1fc((ushort *)(uintptr_t)(param_1),(uint *)(uintptr_t)(*DAT_021affb4 + *DAT_021affc4 + 8),6);
      func_0x0214d1fc((ushort *)(void *)(param_3 + 6),(uint *)(uintptr_t)(*DAT_021affb4 + *DAT_021affc4 + 0xe),param_4 + -6);
      if ((param_5 != 0) && (param_6 != 0)) {
        func_0x0214d1fc(param_5,*DAT_021affb4 + *DAT_021affc4 + 8 + param_4);
      }
      *DAT_021affc4 = local_20;
    }
  }
  return;
}

