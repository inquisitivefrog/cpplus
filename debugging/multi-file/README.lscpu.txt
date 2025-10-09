
sre@cpp:~/debugging/multi-file/build$ lscpu
Architecture:             aarch64
  CPU op-mode(s):         64-bit
  Byte Order:             Little Endian
CPU(s):                   2
  On-line CPU(s) list:    0,1
Vendor ID:                Apple
  Model name:             -
    Model:                0
    Thread(s) per core:   1
    Core(s) per socket:   2
    Socket(s):            1
    Stepping:             0x0
    BogoMIPS:             48.00
    Flags:                fp asimd evtstrm aes pmull sha1 sha2 crc32 atomics fphp asimdhp cpuid asimdrdm jscvt fcma lrcpc dcpop sha3 asimddp sha512 asimdfhm dit usc
                          at ilrcpc flagm sb paca pacg dcpodp flagm2 frint bf16 afp
NUMA:                     
  NUMA node(s):           1
  NUMA node0 CPU(s):      0,1
Vulnerabilities:          
  Gather data sampling:   Not affected
  Itlb multihit:          Not affected
  L1tf:                   Not affected
  Mds:                    Not affected
  Meltdown:               Not affected
  Mmio stale data:        Not affected
  Reg file data sampling: Not affected
  Retbleed:               Not affected
  Spec rstack overflow:   Not affected
  Spec store bypass:      Vulnerable
  Spectre v1:             Mitigation; __user pointer sanitization
  Spectre v2:             Not affected
  Srbds:                  Not affected
  Tsx async abort:        Not affected

sre@cpp:~/debugging/multi-file/build$ lscpu --caches
NAME ONE-SIZE ALL-SIZE WAYS TYPE        LEVEL SETS PHY-LINE COHERENCY-SIZE
L1d                         Data            1               
L1i                         Instruction     1               
L2                          Unified         2               

sre@cpp:~/debugging/multi-file/build$ lscpu --all --extended
CPU NODE SOCKET CORE L1d:L1i:L2 ONLINE
  0    0      0    0 0:0:0         yes
  1    0      0    1 0:0:0         yes

