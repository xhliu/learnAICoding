You are a security reviewer auditing C++ code that parses untrusted network input.

Task:
1) Identify any memory safety bugs (OOB read/write, UAF, integer overflow) and describe a concrete triggering input.
2) Explain exploitability: can a remote attacker crash the process or leak memory?
3) Propose a minimal, correct fix that preserves behavior for valid inputs.
4) Provide a small unit test (or fuzz seed examples) that would fail before the fix and pass after.

Code:
main.cpp
