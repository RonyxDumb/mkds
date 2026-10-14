"""Check detection of bytes, missing padding and appended data on a fixture."""
import hashlib
import struct
import unittest
from unittest.mock import patch
import compare_rom


class ComparisonTests(unittest.TestCase):
    def setUp(self):
        data = bytearray(1024)
        struct.pack_into('<I', data, 0x84, 512)
        struct.pack_into('<4I', data, 0x20, 512, 0x2000000, 0x2000000, 4)
        data[512:516] = b'CODE'
        self.reference = bytes(data)
        self.hash_patch = patch.object(compare_rom, 'EXPECTED_SHA1', hashlib.sha1(data).hexdigest())
        self.hash_patch.start()
        self.addCleanup(self.hash_patch.stop)

    def test_equal_does_not_assert_source_reconstruction(self):
        report = compare_rom.compare(self.reference, self.reference, 'source-build')
        self.assertTrue(report['full_file_equal'])
        self.assertFalse(report['full_source_reconstruction_verified'])
        self.assertEqual(sum(r['size'] for r in report['regions']), len(self.reference))

    def test_changed_code_and_tail_padding_are_both_detected(self):
        candidate = bytearray(self.reference)
        candidate[513] ^= 1
        candidate[-1] ^= 1
        report = compare_rom.compare(self.reference, bytes(candidate))
        self.assertEqual(report['different_or_missing_bytes'], 2)
        self.assertFalse(report['full_file_equal'])

    def test_size_changes_and_wrong_reference(self):
        self.assertEqual(compare_rom.compare(self.reference, self.reference[:-5])['different_or_missing_bytes'], 5)
        self.assertEqual(compare_rom.compare(self.reference, self.reference + b'EXTRA')['extra_candidate_bytes'], 5)
        with self.assertRaises(ValueError):
            compare_rom.compare(b'wrong', self.reference)


if __name__ == '__main__':
    unittest.main()
