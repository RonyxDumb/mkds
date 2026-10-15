"""Regression checks for cache invalidation and real MWCC acceptance boundaries."""
import concurrent.futures
import time
from dataclasses import replace
import io
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch
from batch_matching import Candidate, Search, MatchingContext, ROOT


class BatchTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        self.compiler, self.wibo = self.root/'compiler', self.root/'wibo'
        self.compiler.write_bytes(b'compiler-one')
        self.wibo.write_bytes(b'runner-one')
        self.context = MatchingContext.__new__(MatchingContext)
        self.context.local = {'arm9': {'f': (0x02000000, False)}}
        self.context.allsyms = {'f': {(0x02000000, False)}}
        self.context.inventory = {('arm9',0x02000000): ('f','arm',8)}
        self.candidate = Candidate('arm9','f','arm',0x02000000,8,'test',
                                   'unsigned f(unsigned x) { return x+1; }\n', bytes.fromhex('010080e21eff2fe1'))
        self.search = self.make_search()

    def make_search(self):
        return Search(self.context,self.compiler,self.wibo,self.root/'cache',['-O4,p'])

    def failure(self, code=1, message=b'#   Error: undefined identifier'):
        return subprocess.CompletedProcess([],code,b'',message)

    def test_negative_cache_avoids_repeating_source_error(self):
        with patch('batch_matching.subprocess.run',return_value=self.failure()) as run:
            first=self.search.compile(self.candidate,'-O4,p')
            second=self.search.compile(self.candidate,'-O4,p')
        self.assertEqual(run.call_count,1)
        self.assertEqual(first['outcome'],'compile_error')
        self.assertTrue(second['cache_hit'])

    def test_concurrent_same_key_compiles_once(self):
        def failure(*args, **kwargs):
            time.sleep(0.01)
            return self.failure()
        with patch('batch_matching.subprocess.run',side_effect=failure) as run:
            with concurrent.futures.ThreadPoolExecutor(max_workers=4) as executor:
                results=list(executor.map(lambda _:self.search.compile(self.candidate,'-O4,p'),range(4)))
        self.assertEqual(run.call_count,1)
        self.assertEqual(sum(r['cache_hit'] for r in results),3)

    def test_frontend_error_stops_optimization_retries(self):
        self.search.optimizations=['-O4,p','-O2','-O0']
        with patch('batch_matching.subprocess.run',return_value=self.failure()) as run:
            _,results=self.search.run(self.candidate)
        self.assertEqual(run.call_count,1)
        self.assertEqual(results[-1]['skipped_optimizations'],2)

    def test_unknown_compiler_error_still_tries_optimizations(self):
        self.search.optimizations=['-O4,p','-O2','-O0']
        with patch('batch_matching.subprocess.run',return_value=self.failure(message=b'#   Error: instruction selection failed')) as run:
            self.search.run(self.candidate)
        self.assertEqual(run.call_count,3)

    def test_flags_invalidate_negative_cache(self):
        with patch('batch_matching.subprocess.run',return_value=self.failure()) as run:
            self.search.compile(self.candidate,'-O4,p')
            self.search.compile(self.candidate,'-O1')
        self.assertEqual(run.call_count,2)

    def test_source_change_invalidates(self):
        self.assertNotEqual(self.search.key(self.candidate,[]),self.search.key(replace(self.candidate,source='changed'),[]))

    def test_original_bytes_change_invalidates(self):
        self.assertNotEqual(self.search.key(self.candidate,[]),self.search.key(replace(self.candidate,original=b'changed!'),[]))

    def test_address_and_mode_invalidate(self):
        old=self.search.key(self.candidate,[])
        self.assertNotEqual(old,self.search.key(replace(self.candidate,address=0x2000100),[]))
        self.assertNotEqual(old,self.search.key(replace(self.candidate,mode='thumb'),[]))

    def test_toolchain_change_invalidates(self):
        self.compiler.write_bytes(b'compiler-two')
        self.assertNotEqual(self.search.fingerprint,self.make_search().fingerprint)

    def test_symbols_invalidate(self):
        self.context.local['arm9']['f']=(0x2000100,False)
        self.assertNotEqual(self.search.fingerprint,self.make_search().fingerprint)

    def test_timeout_is_not_a_negative_hit(self):
        with patch('batch_matching.subprocess.run',side_effect=subprocess.TimeoutExpired('test',30)) as run:
            self.search.compile(self.candidate,'-O4,p')
            self.search.compile(self.candidate,'-O4,p')
        self.assertEqual(run.call_count,2)

    def test_signal_and_environment_failures_are_retried(self):
        for failure in [self.failure(-9),self.failure(1,b'license server unavailable')]:
            with self.subTest(code=failure.returncode),patch('batch_matching.subprocess.run',return_value=failure) as run:
                self.search.compile(self.candidate,'-O4,p')
                self.search.compile(self.candidate,'-O4,p')
            self.assertEqual(run.call_count,2)

    def test_corrupt_cache_is_rebuilt(self):
        with patch('batch_matching.subprocess.run',return_value=self.failure()) as run:
            self.search.compile(self.candidate,'-O4,p')
            next((self.root/'cache').glob('*/*/result.json')).write_text('{broken')
            self.search.compile(self.candidate,'-O4,p')
        self.assertEqual(run.call_count,2)

    def test_ambiguous_global_is_rejected(self):
        self.context.allsyms['ambiguous']={(0x2000100,False),(0x2000200,False)}
        with self.assertRaisesRegex(ValueError,'ambiguous'):
            self.context.resolve('arm9','ambiguous')

    @unittest.skipUnless((ROOT/'tools/mwccarm/1.2/sp2p3/mwccarm.exe').exists() and (ROOT/'tools/wibo').exists(),'private MW toolchain unavailable')
    def test_real_exact_cache_relinks_and_rejects_corrupt_object(self):
        search=Search(self.context,ROOT/'tools/mwccarm/1.2/sp2p3/mwccarm.exe',ROOT/'tools/wibo',self.root/'real-cache',['-O4,p'])
        first=search.compile(self.candidate,'-O4,p')
        self.assertEqual(first['outcome'],'exact')
        self.assertTrue(search.compile(self.candidate,'-O4,p')['cache_hit'])
        Path(first['object']).write_bytes(b'corrupt')
        rebuilt=search.compile(self.candidate,'-O4,p')
        self.assertEqual(rebuilt['outcome'],'exact')
        self.assertFalse(rebuilt['cache_hit'])
        different=search.compile(replace(self.candidate,original=b'\0'*8),'-O4,p')
        self.assertEqual(different['outcome'],'mismatch')


if __name__=='__main__':
    unittest.main()
