"""Regression checks for SDK names renamed during source import."""
import csv,hashlib,json,tempfile,unittest
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
 def game_fixture(self):
  p=self.root/'src/arm9/02002000_game.c';p.write_text('unsigned int game(void *p,int n){return n;}\n')
  (self.root/'verification/batch-source-proofs.json').write_text(json.dumps({'arm9_02002000':{}}))
  for name in ['local-byte-exact.tsv','local-linked-byte-exact.tsv']:
   with (self.root/'verification'/name).open('w') as stream:
    writer=csv.DictWriter(stream,fieldnames=['module','address','name','source_sha256'],delimiter='\t');writer.writeheader()
    if name=='local-linked-byte-exact.tsv':writer.writerow(dict(module='arm9',address='0x02002000',name='game',source_sha256=hashlib.sha256(p.read_bytes()).hexdigest()))
  return p
 def test_verified_game_source_is_used(self):
  self.game_fixture();d,b,n=recover_sdk_calls(self.root,'arm9','extern int game();','x=game(p,3);')
  self.assertEqual(n,1);self.assertIn('void *,int',d);self.assertIn('(void *)(p)',b)
 def test_changed_game_source_is_rejected(self):
  p=self.game_fixture();p.write_text(p.read_text()+'/*changed*/')
  with self.assertRaises(ValueError):recover_sdk_calls(self.root,'arm9','extern int game();','x=game(p,3);')
 def test_game_missing_arguments_are_not_invented(self):
  self.game_fixture();d='extern int game();';b='x=game(p);'
  self.assertEqual(recover_sdk_calls(self.root,'arm9',d,b),(d,b,0))
if __name__=='__main__':unittest.main()
