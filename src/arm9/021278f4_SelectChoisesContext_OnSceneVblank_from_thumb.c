/* Decompiled C draft; module arm9; ROM address 021278f4. No matching claim. */
#include "types.h"
#include "deps/021278f4_SelectChoisesContext_OnSceneVblank_from_thumb.h"

void SelectChoisesContext_OnSceneVblank_from_thumb(void)

{
  int *piVar1;
  
  piVar1 = piRam02127984;
  if (*(int *)*piRam02127984 != 0) {
    *puRam02127988 = 0;
    if ((*(int *)(*piVar1 + 4) == 0) || (*(int *)(*piVar1 + iRam0212798c) == 0)) {
      UpdateBldcntBldalphaBldy((ushort *)(uintptr_t)(uRam02127990),0x1e,0x1f,6,10,0);
      *puRam02127994 =
           *puRam02127994 & uRam0212799c | ((*puRam02127994 & uRam02127998) >> 8 & 0xfffffffe) << 8;
      return;
    }
    UpdateBldcntBldalphaBldy((ushort *)(uintptr_t)(uRam02127990),0x1e,0x1f,6,10,0xfffffff6);
    *puRam02127994 = *puRam02127994 & uRam0212799c | ((*puRam02127994 & uRam02127998) >> 8 | 1) << 8
    ;
  }
  return;
}

