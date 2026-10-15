"""Hash-only archives support both relocation-bearing and unrelocated batches."""
import json
from pathlib import Path
import tempfile
import unittest
from hash_only_proof import validate_hash_only


class HashArchiveTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root=Path(self.temp.name)
        (self.root/'verification').mkdir()
        self.proof={'module':'arm7','address':'0x037fcc24','size':'12','sha256':'a'*64,'source_sha256':'b'*64}
        entry={'size':12,'sha256':'a'*64,'source_sha256':'b'*64,'audit':'audit.json'}
        (self.root/'verification/hash-only-proofs.json').write_text(json.dumps({'arm7_037fcc24':entry}))
        self.audit={'new_matches':[self.proof], 'total_functions':1,'full_rom_link_verified':False,
                    'fresh_audits':{'resolved':{'tested':0,'passed':0},'unrelocated':{'tested':1,'passed':1}}}

    def validate(self):
        (self.root/'verification/audit.json').write_text(json.dumps(self.audit))
        validate_hash_only(self.root,'arm7',0x037fcc24,12,self.proof)

    def test_unrelocated_batch(self):
        self.validate()

    def test_resolved_batch(self):
        self.audit['fresh_audits']={'resolved':{'tested':1,'passed':1},'unrelocated':{'tested':0,'passed':0}}
        self.validate()

    def test_failed_unrelocated_audit_is_rejected(self):
        self.audit['fresh_audits']['unrelocated']['tested']=2
        with self.assertRaises(AssertionError):self.validate()

    def test_empty_audit_is_rejected(self):
        self.audit['fresh_audits']['unrelocated']={'tested':0,'passed':0}
        self.audit['total_functions']=0
        with self.assertRaises(AssertionError):self.validate()

    def test_changed_source_is_rejected(self):
        self.proof={**self.proof,'source_sha256':'c'*64}
        with self.assertRaises(AssertionError):self.validate()


if __name__=='__main__':unittest.main()
