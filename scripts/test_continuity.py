"""Exercise continuity failures in an isolated checkout, leaving work untouched."""
import json
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]

class ContinuityTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.tmp = tempfile.TemporaryDirectory()
        cls.repo = Path(cls.tmp.name) / 'repo'
        subprocess.run(['git', 'clone', '--quiet', '--shared', str(ROOT), str(cls.repo)], check=True)
        shutil.copyfile(ROOT / 'scripts/check_continuity.py', cls.repo / 'scripts/check_continuity.py')
        cls.base = subprocess.check_output(['git', 'rev-parse', 'HEAD'], cwd=ROOT, text=True).strip()

    @classmethod
    def tearDownClass(cls):
        cls.tmp.cleanup()

    def run_guard(self):
        return subprocess.run(['python3', 'scripts/check_continuity.py', '--base', self.base], cwd=self.repo, capture_output=True, text=True)

    def test_unchanged(self):
        result = self.run_guard()
        self.assertEqual(result.returncode, 0, result.stderr)

    def test_lost_proof(self):
        path = self.repo / 'verification/local-byte-exact.tsv'
        original = path.read_bytes()
        try:
            path.write_bytes(b'\n'.join(original.split(b'\n')[:1] + original.split(b'\n')[2:]))
            result = self.run_guard()
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('Lost exact proofs', result.stderr)
        finally:
            path.write_bytes(original)

    def test_lost_fuzzy(self):
        path = self.repo / 'verification/fuzzy-candidates.json'
        original = path.read_bytes()
        try:
            value = json.loads(original)
            value['candidates'].pop()
            path.write_text(json.dumps(value))
            result = self.run_guard()
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('Lost fuzzy candidate', result.stderr)
        finally:
            path.write_bytes(original)

    def test_wrong_percentage(self):
        path = self.repo / 'PROGRESSO.json'
        original = path.read_bytes()
        try:
            value = json.loads(original)
            value['local_byte_exact_percent_by_function_body_bytes'] = 17
            path.write_text(json.dumps(value))
            result = self.run_guard()
            self.assertNotEqual(result.returncode, 0)
            self.assertIn('Progress percentage disagrees', result.stderr)
        finally:
            path.write_bytes(original)

if __name__ == '__main__':
    unittest.main()
