# cryptonote-wallet-cracker

I suggest looking into JohnTheRipper. I believe they have support for monero wallets, and they are much better than me at programming.

https://github.com/magnumripper/JohnTheRipper/issues/3144

A wallet cracker for cryptonote coins.

Needs dropping into a cryptonote core implementation. Also needs some modifications added to WalletGreen.cpp - included here in WalletGreenModifications.cpp

Won't work with monero forks without a decent amount of modification. Should be relatively trivial to add to bytecoin forks without much modification.

See https://github.com/monkeytips/monkeytipsv1/pull/3 and https://github.com/monkeytips/monkeytipsv1/pull/4 for an actual implementation of this.
