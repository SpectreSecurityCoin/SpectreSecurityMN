SPECTRESECURITY Core version *5.6.0* is now available from:  <https://github.com/spectresecurity-project/spectresecurity/releases>

This is a new major version release, including various bug fixes and performance improvements, as well as updated translations.

Please report bugs using the issue tracker at github: <https://github.com/spectresecurity-project/spectresecurity/issues>

Mandatory Update
==============

SPECTRESECURITY Core v5.6.0 is a mandatory update for all users. This release contains new consensus rules and improvements that are not backwards compatible with older versions. Users will need to update their clients before enforcement of this update goes into effect.

Exchange address activation is scheduled to go into effect at the following time:

```
Mainnet: block 4,281,680. ~Feb 29th 2024.
```
Masternodes will need to be restarted from the controller wallet once both the masternode daemon and the controller wallet have been upgraded.

Note: In preparation for the new address type activation, upgraded peers will start rejecting non-upgraded peers a few days before the exchange address activation block height noted above, we recommend everyone to be updated at least a week prior to this time.

How to Upgrade
==============

If you are running an older version, shut it down. Wait until it has completely shut down (which might take a few minutes for older versions), then run the installer (on Windows) or just copy over /Applications/SPECTRESECURITY-Qt (on Mac) or spectresecurityd/spectresecurity-qt (on Linux).

Notable Changes
==============

### New Exchange Address Type

A new address type has been added for use by exchanges that require additional regulatory compliance. This new "exchange address" functions similarly to a regular SPECTRESECURITY address, but with one distinct difference; transactions originating from a SHIELD address are not allowed to be sent to said exchange addresses.

Creation of these new exchange addresses is available via the new `getnewexchangeaddress` RPC command. It takes an optional `label (string)` to set a label for the address if necessary. Functionality is the same comparatively to `getnewaddress`, `getnewstakingaddress` and `getnewshieldaddress`

| Command Name | Purpose | Requires Unlocked Wallet? |
| ------------ | ------- | ------------------------- |
| `getnewexchangeaddress` | Creates a new exchange address | Yes |

Command is detailed below:

* `getnewexchangeaddress`
  ```
  Returns a new exchange address for receiving payments.
  Result:
  "address"    (string) The new exchange address.
  ```

### Use Coin Control for masternode collateral creation

It is now possible to use the GUI's Coin Control feature to manually select which inputs you would like to use when creating a new masternode. The previous functionality of automatically selecting sufficient inputs remains however.

### Generate a proposal payout address on-the-fly

Proposal creators can now choose to generate a new SPECTRESECURITY address to be used as a proposal's payout address directly within the proposal creation wizard.

### Lockable sapling notes (SHIELD UTXOs)

The ability to "lock" SHIELD UTXOs has been added to both the RPC's `lockunspent` command as well as the GUI's Coin Control interface. This brings feature parity between SHIELD and Transparent UTXOs.

### startmasternode RPC command cleanup

The `startmasternode` RPC command has had some long-time non-working options removed as part of a cleanup. Notably; the `local` and `many` options no longer exist. This is not a change in functionality, as both options have essentially done nothing for quite some time, and only led to confusion amongst users.

*5.6.0* Change log
==============

Detailed release notes follow. For convenience in locating the code changes and accompanying discussion, both the pull request and git merge commit are mentioned.

### Core Features
- #2895 `d293ad272c1c6545a54a80e60c32142fcd455564` [Core][GUI][RPC] Exchange Address (Liquid369)

### Build System
- #2758 `3e2eb99bc82b7356a6dd779c5098a5336a55e22a` [Build] Update httpserver.cpp (andi448)
- #2789 `5c5565924a747e26264430dead72d509fafcded5` [Build] Add Liquid369 gpg key (Liquid369)
- #2799 `e8cf23395ebc83f6b5dde49f497ced0e40baf5dd` [Build] Bump master to 5.5.99 (pre-6.0) (Fuzzbawls)
- #2803 `ad9ecf88ab89a775fa18b4f52fdd6b5cdf170981` [Build] Bump copyright year to 2023 (Fuzzbawls)
- #2816 `c36e8c5b51cac3eae4be6cac4e5596876bc40ae1` [Build] Fix build with configure flag --enable-mining-rpc (PeterL73)
- #2821 `523877c255915567a6d09795c3cdb51a38c6ac98` [Build] Disable libsep256k1's openssl tests (Fuzzbawls)
- #2839 `aadf4bb2c2f578712b1050d29ad4b526ebb14297` [Build] Minor fixups and simplifications for macdeploy (Fuzzbawls)
- #2868 `30ae211daf009234d9e64ef7c4a8b0f06293ca15` [Build] Add header files (Duddino)
- #2896 `ea3d1d6b3f838043a5eaf438abb9adbfba39fde7` [Build] Further security and symbol checking updates (Fuzzbawls)
- #2899 `badb446e0b5c8ade5b26d4c944f96cb64afed44e` [Build] Update copyright year to 2024 (Fuzzbawls)
- #2901 `cdda6450ba6a16c71db62e66436b98471d9c8b8d` [Build] Add duddino GPG key (Duddino)

### Depends System
- #2826 `a161b1d31a0e15116fd8968790d97ce8d1be1a01` [Depends] Bump zlib to v1.2.13 (Fuzzbawls)
- #2872 `8c4ffa642981ccff126f9fe138117177861684cb` [Depends] Bump Rust toolchain to 1.69.0 (Fuzzbawls)

### P2P Protocol and Network Code
- #2824 `cfc110e0a0750cb8903a17704f9e9c59b344cf9a` [P2P] Rate limiting rumored address processing (Liquid369)
- #2849 `39656e39125ab0eea58459e1f295aa6122203298` [P2P] Do not fully sort all nodes for addr relay (Liquid369)
- #2850 `9ea6a1bd39951b33b9ece40b30642bda00d42524` [P2P] Increase performance of Good (Liquid369)
- #2851 `f07f32c09a99542f292154051fadd13c2cdee40f` [Net] Add Liquid DNS Seeder for mainnet (Liquid369)

### GUI
- #2798 `9e2a102f3d3f19c3259e7771d8a073308f3dc8db` [GUI] Adds copy button to proposal recipient address (Liquid369)
- #2828 `89f3f9853d414ae607a4b85055ee470735ba0447` [GUI] Proposal Generate Address (Liquid369)
- #2829 `106e72e59ef4c6ac116eca55b29adcce90b4212a` [GUI] Fix bug in proposal creation (panleone)
- #2842 `744b3241943006936bf9747d87982ec7f463c6d7` [GUI] Show memo in self s->s txs (panleone)
- #2852 `aca81a13cfb6f3e1cbb4999107d065510b61473c` [GUI] Fix ban actions in peer list (Liquid369)
- #2854 `a428bc28b645d0da77de4b40d19a7cfa6ff63af1` [GUI] Don't always clear coin control (panleone)
- #2859 `fec4cfe2af5d5474de4b6a70320057d19bd913e1` [GUI] CoinControl Change (panleone)
- #2860 `62d745982e96a48ecbaed364d1b055f9ad222719` [Bug] Fix toggle lock button (panleone)
- #2862 `1f0db3868ad577d72c44171e9d4f27f9aa923fc6` [GUI] CoinControl for masternodes (panleone)
- #2863 `6c26a0eb772dbfccbdbaff0129068f1427b4f843` [Bug] [GUI] Fix focus on send transaction (panleone)
- #2865 `559e4f1dc39e1e65029462d92d42e6c7e40d5697` [GUI] Add differentiation for Shielded Memos (Liquid369)
- #2874 `d0cf09312df121894803386757ac3ef3bc9d2f2c` [GUI] Periodic make translate (Fuzzbawls)
- #2893 `012387d563647a2a1898aa381dada16eba346761` [GUI] Remove unused addressbookpage references (Fuzzbawls)

### RPC/REST
- #2833 `25bcf8600faff97bb63e60440d65193d426bb9f2` [RPC] Cleanup startmasternode command (Fuzzbawls)
- #2856 `f02ab524131e79805910c846a8569ba3beea9145` [RPC] Fix Invalidateblock (panleone)
- #2873 `05fdf6040adf0b3517b294b3a8729400522ee06e` [RPC][MN] Serialize in ADDRV2 for TorV3 in RPC's (Liquid369)

### Wallet
- #2782 `0bd96c8a188547be8ce4bb5415610e0285ec76d2` [Wallet] Fix stake split output count calculation (PeterL73)
- #2812 `ac8a74dc2a946df609c6d200a9367f1264fb638f` [Wallet] Fix AutoCombineDust and improve setautocombinethreshold (panleone)
- #2861 `326321d511e600a0d6a75350eb6cfe9832604528` [Wallet] Locked sapling notes (panleone)

### Testing Frameworks
- #2822 `0d779aa53d7e67a73e968e5c04fe4446a1021d98` [Tests] Replace hashlib.ripemd160 with native implementation (Fuzzbawls)
- #2832 `6e50e49eea89b8ea15e4bcf8def69f4b36b4116a` [Tests] Run tiertwo and sapling functional tests by default (Fuzzbawls)
- #2840 `0d2051a82c5fa5fb28c43bc9e1fa2c92ae7b4d78` [Tests] Add further RPC test coverage for cold staking (Fuzzbawls)
- #2867 `3a7ab3d715e54ef9583b436a52315ec168193977` [Core][Tests] Cleanup HTTPServer start and stop (Liquid369)
- #2877 `42643088e5052faab4fb4fa9a53f7bdc05970e52` [Tests][Scripts] Bump Python version to 3.8 and add more linting (Fuzzbawls)
- #2878 `0ab665dfef9082acff0e32d62df46b7ca859d1d1` [Lint] lint spelling (Fuzzbawls)
- #2881 `6829cfd172b410e4de169bea3f9663f4b220c949` [Tests] Fix random fee generation (panleone)

### Scripts and Tools
- #2806 `e4634a5d53d24502056f22f95379b22c69275579` [Tools] Sanitize existing clang-format rules (Fuzzbawls)
- #2827 `38df19c2672b60c90ec315fd781dde3183bb81d1` [Tools] Fix case typo in .clang-format (Fuzzbawls)
- #2855 `616cc4823f6a04cdcf8790ab5d7766189064eaf3` [Scripts] Delete redundant util/fetch-params.sh (Liquid369)
- #2892 `658f2fe46e27b7db1b2b7df31725383cfcd13fa1` [Scripts][GUI] Overhaul translation ingestion script and update translations from Transifex (Fuzzbawls)

### Continuous Integration
- #2787 `286c318db2fc451bfdea2605ff11aabf68fb0298` [GA] Update depreciated actions (Fuzzbawls)
- #2817 `9240e153f3074cb0537e72c887e1715449e7b7a1` [GA] Bump GA linux workers to Ubuntu 20.04 (Fuzzbawls)
- #2825 `e1e376e494fab2fac33d85bb3477ef8f776e378e` [GA] Reorganize and optimize GA runner flow (Fuzzbawls)
- #2857 `05e73a0ef50c2886c48faf1d330d810f7112584b` [GA] Overhaul GA caches (Fuzzbawls)
- #2891 `028a1eaa1d8cdc1ff3ebe8463182189007092094` [GA] Fix macOS runs (Fuzzbawls)
- #2897 `c53095a9ed8b672c15d22f3ef21a15cbc427d3be` [GA] Update actions to node20 versions (Fuzzbawls)
- #2903 `03f038b82fa724978b112def30192abdfb279904` [GA] Link Boost 1.76 regardless of pre-existing version (Fuzzbawls)

### Internal Libraries
- #2753 `aa9be76d1313a86db0c8411c85ee518ef3f2a526` [Libs] Re-introduce immer header-only library as a git subtree (Fuzzbawls)
- #2807 `59e4c1acb092abc46b825fd461a86fef0e80bd71` [Libs] Update chiabls subtree library (Fuzzbawls)
- #2853 `5d71589ab8043772fe87df982a6f3d6d7effb608` [Libs] Bump chiabls subtree (Fuzzbawls)
- #2870 `7488a2721da8a4defc08d145dadd3c3065e2735d` [Libs] Update librustzcash (Duddino)

### Documentation
- #2788 `d3acaa09f5fd9d5ef4a95ca7cd2b1a674e7851ce` [Doc] Don't include dependency paths in Doxygen or Coverage (Fuzzbawls)
- #2846 `28c9eaba5d89b7dd77d128bd88d2465b4d883e3c` [Doc] Remove bitness from spectresecurity-qt help message and manpage (Fuzzbawls)
- #2894 `3c1f32fb1258aa80f9683e0a84f466a8535fea98` [Doc] Update Ubuntu ppa source for db4.8 (Fuzzbawls)
- #2898 `a949c658b815bc2e817c238aab00ed4711844939` [Doc] Update gpg keyserver URL (Fuzzbawls)

### Miscellaneous
- #2266 `8b983704a31eddd16d036e7ccadccdad8d304c11` [Cleanup] Use C++11 nullptr instead of NULL (Fuzzbawls)
- #2793 `e9c73031615b9263019102721b4e3e077fc556b2` [Consensus] Set v5.5.0 superblock checkpoint block hash. (Fuzzbawls)
- #2841 `14d859ccb593a684013e2c1526ef2b19ec4b6a5b` [Core] Remove unused PoW block signing code (panleone)
- #2845 `83dd4542659aad2eaeb1ca2f84ff3388a06fa71b` [Core] Unify binary exit codes (Fuzzbawls)
- #2847 `05f0662f73a78261e0d8d55a4053afdd2e4aee18` [ZMQ] Call va_end() on va_start()ed args. (Fuzzbawls)
- #2848 `b33843bfdba8e5935bcaa0bfd37de2c892329922` [Misc] Cleanup whitespace and guard RPC tables from clang-format (Fuzzbawls)
- #2900 `9a60dd86d7d17f4aa922c69831950a3a997cb2a1` [Core] Bump Protocol Version to 70927 (Liquid369)

## Credits

Thanks to everyone who directly contributed to this release:
- Duddino
- Fuzzbawls
- Liquid369
- PeterL73
- andi448
- panleone

As well as everyone that helped translating on [Transifex](https://www.transifex.com/projects/p/spectresecurity-project-translations/), the QA team during Testing and the Node hosts supporting our Testnet.
