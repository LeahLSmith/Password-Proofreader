# Password-Proofreader
Module written in C++ and inline Microsoft assembly that checks whether a password meets user specifications.

# A password has 4 components:
* Character Count
* Letters allowed/required
* Numbers allowed/required
* Symbols allowed/required

# Pseudocode
1. Ask for specifications for character counts.
2. Get user password and scan input (inline MASM).
3. Show errors (if any).
4. Repeat steps 2 and 3 until password is accepted.
5. Store in database.
