/* C reconstructed from reference ARM/Thumb instructions.
 * Complete local bytes verified; full ROM and global ABI remain unverified. */
extern int Menu_EmblemOverlayQuery_021a23c8(void);
void Scene_Emblem_Update(short *p) {
 int result=Menu_EmblemOverlayQuery_021a23c8();
 if(!p) return;
 if(!result) return;
 switch(*p) { case 7: p[2]=7; return; default: p[2]=0; return; }
}
