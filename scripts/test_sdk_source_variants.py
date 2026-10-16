"""Check that source hypotheses never insert assembly placeholders."""
import unittest
from sdk_source_variants import externalize_asm_functions,source_variant
class VariantTests(unittest.TestCase):
 def test_externalizes_only_assembly_sibling(self):
  text='asm unsigned int Primitive(unsigned int x) { mov r0, r0\n bx lr\n}\nint Helper(int x) { return Primitive(x)+1; }\n'
  result=externalize_asm_functions(text)
  self.assertIn('extern unsigned int Primitive(unsigned int x);',result)
  self.assertIn('int Helper(int x) { return Primitive(x)+1; }',result)
  self.assertNotIn('mov r0',result)
 def test_comments_and_inline_asm_are_not_rewritten(self):
  text='/* asm int fake(void) { bx lr } */\nint real(void) { asm { mov r0,r0 } return 0; }'
  self.assertEqual(externalize_asm_functions(text),text)
 def test_unclosed_assembly_is_rejected(self):
  with self.assertRaises(ValueError):externalize_asm_functions('asm void f(void) { mov r0,r0')
 def test_cleanup_hypothesis_requires_three_known_blocks(self):
  with self.assertRaises(ValueError):source_variant('int f(void){return 0;}',['g3d_unconditional_setup_cleanup'])
if __name__=='__main__':unittest.main()
