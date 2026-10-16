"""Reject unexplained span bytes and malformed switch tables."""
import unittest
from proof_span import validate_span,thumb_switch_bytes

class ThumbSwitchSpanTests(unittest.TestCase):
    def setUp(self):
        self.code=b''.join(x.to_bytes(2,'little') for x in [0x2801,0xd809,0x1800,0x4478,0x8900,0x0400,0x1400,0x4478,0x4700,5,5,0x4770])
    def test_bounded_table_is_excluded(self):
        self.assertEqual(thumb_switch_bytes(self.code,0x2000000),set(range(18,22)))
        validate_span(self.code,0x2000000,'thumb',20)
    def test_unexplained_bytes_rejected(self):
        with self.assertRaises(AssertionError):validate_span(self.code+b'\x00\x00',0x2000000,'thumb',20)
    def test_destination_inside_table_rejected(self):
        broken=self.code[:18]+b'\x01\x00'+self.code[20:]
        with self.assertRaises(AssertionError):validate_span(broken,0x2000000,'thumb',20)
    def test_arm_destination_rejected(self):
        broken=self.code[:18]+b'\x04\x00'+self.code[20:]
        with self.assertRaises(AssertionError):validate_span(broken,0x2000000,'thumb',20)
    def test_missing_bound_rejected(self):
        broken=b'\x00\x20'+self.code[2:]
        with self.assertRaises(AssertionError):validate_span(broken,0x2000000,'thumb',20)
    def test_truncated_table_rejected(self):
        with self.assertRaises(AssertionError):validate_span(self.code[:20],0x2000000,'thumb',16)

if __name__=='__main__':unittest.main()
