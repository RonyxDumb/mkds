"""Regression checks for SDK names renamed during source import."""
import json,tempfile,unittest
from pathlib import Path
from sdk_signatures import recover_sdk_calls
class SignatureTests(unittest.TestCase):
 def setUp(self):
  self.tmp=tempfile.TemporaryDirectory();self.addCleanup(self.tmp.cleanup);self.root=Path(self.tmp.name)
  (self.root/'verification').mkdir();(self.root/'src/arm9').mkdir(parents=True)
  (self.root/'verification/sdk-source-proofs.json').write_text(json.dumps({'arm9_02001000':{'donor_function':'SDK_Original','bindings':{'SDK_Original':'func_02001000'}}}))
  (self.root/'src/arm9/02001000_func_02001000.c').write_text('void *func_02001000(void *p, int n) { return p; }\n')
 def test_renamed_definition(self):
  d,b,n=recover_sdk_calls(self.root,'arm9','extern int func_02001000();','x=func_02001000(p,3);')
  self.assertEqual(n,1);self.assertIn('extern void * func_02001000(void *,int);',d);self.assertIn('(void *)(p)',b)
 def test_missing_arguments_are_not_invented(self):
  d='extern int func_02001000();';b='x=func_02001000(p);'
  self.assertEqual(recover_sdk_calls(self.root,'arm9',d,b),(d,b,0))
 def test_extra_side_effect_is_not_discarded(self):
  d='extern int func_02001000();';b='x=func_02001000(p,3,side_effect());'
  self.assertEqual(recover_sdk_calls(self.root,'arm9',d,b),(d,b,0))
 def test_other_module_is_not_reused(self):
  d='extern int func_02001000();';b='x=func_02001000(p,3);'
  self.assertEqual(recover_sdk_calls(self.root,'arm7',d,b),(d,b,0))
if __name__=='__main__':unittest.main()
