/* C reconstructed from reference ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
extern int GetDisplayMode_0(void), IsRaceEnded(void), GetRaceMode(void), func_020b2d54(void), func_020c3db4(void);
int GetCurrentOptionMenuKind_from_thumb(void) {
 if(GetDisplayMode_0()==2 && !IsRaceEnded()) return 3;
 if(IsRaceEnded()) {
  if(GetRaceMode()==4) { switch(func_020b2d54()) { case 0: return 2; default: return 1; } }
  if(func_020c3db4()) return 2;
  return 1;
 }
 return 0;
}
