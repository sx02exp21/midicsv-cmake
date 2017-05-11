REM Test release versions of Midicsv and Csvmidi with
REM an identity transform.

REM Generate test csv output
Release\Midicsv test.mid w.csv
REM Regenerate test mid file output
Release\Csvmidi w.csv w.mid

REM The following comparison should not find any differences
REM cmp not available, use comp or fc
REM cmp test.mid w.mid
REM comp test.mid w.mid
fc /b test.mid w.mid
