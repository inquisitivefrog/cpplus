
sre@cpp:~/debugging/multi-file/build$ time ./main
Cleared /tmp/test directories
Created directory: "/tmp/test0"
Created file: "/tmp/test0/file0.txt"
Created file: "/tmp/test0/file1.txt"
Created file: "/tmp/test0/file2.txt"
Created directory: "/tmp/test99"
Created file: "/tmp/test99/file0.txt"
Created file: "/tmp/test99/file1.txt"
Created file: "/tmp/test99/file2.txt"
Directory creation completed. Starting threads...
Thread-251975092269408: Scanning path: /tmp/test0
Thread-251975092269408: Found file: "/tmp/test0/file0.txt"
Thread-251975092269408: Found file: "/tmp/test0/file1.txt"
Thread-251975092269408: Found file: "/tmp/test0/file2.txt"
Thread-251975092269408: Scanned /tmp/test0, dirs: 0, files: 3, total dirs: 0, total files: 6
Thread-251975083815264: Scanning path: /tmp/test99
Thread-251975083815264: Found file: "/tmp/test99/file0.txt"
Thread-251975083815264: Found file: "/tmp/test99/file1.txt"
Thread-251975083815264: Found file: "/tmp/test99/file2.txt"
Thread-251975083815264: Scanned /tmp/test99, dirs: 0, files: 3, total dirs: 0, total files: 300
Main completed. Total dirs: 0, Total files: 300

real	0m0.029s
user	0m0.007s
sys	0m0.022s

