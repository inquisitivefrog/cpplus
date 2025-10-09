
sre@cpp:~/debugging/build$ gdb ./main
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "aarch64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./main...
(gdb) break main
Breakpoint 1 at 0x512c: file /home/sre/debugging/main.cpp, line 53.
(gdb) break DirectoryManager::scanDirectory
Breakpoint 2 at 0x6c08: file /home/sre/debugging/main.cpp, line 15.
(gdb) break /home/sre/debugging/main.cpp:82
Breakpoint 3 at 0x539c: file /home/sre/debugging/main.cpp, line 83.
(gdb) break /home/sre/debugging/main.cpp:75
Breakpoint 4 at 0xaaaaaaaa5378: /home/sre/debugging/main.cpp:75. (2 locations)
(gdb) run
Starting program: /home/sre/debugging/build/main 

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) y
Debuginfod has been enabled.
To make this setting permanent, add 'set debuginfod enabled on' to .gdbinit.
Downloading separate debug info for system-supplied DSO at 0xfffff7ffb000
[Thread debugging using libthread_db enabled]                                                                                                                          
Using host libthread_db library "/lib/aarch64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at /home/sre/debugging/main.cpp:53
53	int main() {
(gdb) print path
$1 = ""
(gdb) print max_files
$2 = 0
(gdb) print file_list
$3 = std::vector of length -88694, capacity 4196435 = {
  "GLIBC_2.17\000GLIBC_2.38\000GLIBC_2.25\000GLIBC_2.18\000GLIBC_2.32\000GLIBC_2.33\000GLIBC_2.36\000GLIBC_2.34\000GCC_4.2.0\000GCC_3.3\000GCC_3.0\000GCC_4.5.0\000\000\000\000\000\000\000\000\001\0005\000\001\0006\0007\0007\0008\0007\0007\0007\0009\0007\0009\0007\0007\0007\0009\0007\0007\0006\0007\0007\0007\0007\0007\000:\0007\0007\000\001\0007\0007\0007\0007\0007\0007"..., "", "", 
  "GLIBC_2.33\000GLIBC_2.36\000GLIBC_2.34\000GCC_4.2.0\000GCC_3.3\000GCC_3.0\000GCC_4.5.0\000\000\000\000\000\000\000\000\001\0005\000\001\0006\0007\0007\0008\0007\0007\0007\0009\0007\0009\0007\0007\0007\0009\0007\0007\0006\0007\0007\0007\0007\0007\000:\0007\0007\000\001\0007\0007\0007\0007\0007\0007\000;\0007\0007\0007\000\001\0007\0007\0007\0007\0007\000\001\0007\000<\0007\0007\0007\0009\0007\0007\000=\0009\0007\0007\0007\0006\0007\0007\000"..., "", "", 
  "GLIBC_2.18\000GLIBC_2.32\000GLIBC_2.33\000GLIBC_2.36\000GLIBC_2.34\000GCC_4.2.0\000GCC_3.3\000GCC_3.0\000GCC_4.5.0\000\000\000\000\000\000\000\000\001\0005\000\001\0006\0007\0007\0008\0007\0007\0007\0009\0007\0009\0007\0007\0007\0009\0007\0007\0006\0007\0007\0007\0007\0007\000:\0007\0007\000\001\0007\0007\0007\0007\0007\0007\000;\0007\0007\0007\000\001\0007\0007\0007\0007\0007\000\001\0007\000<\0007\0007\0007\000"..., "", "", "", "", "", 
  <error reading variable: Cannot create a lazy string with address 0x0, and a non-zero length.>, 
  "GCC_3.3\000GCC_3.3.1\000GCC_3.4\000GCC_3.4.2\000GCC_3.4.4\000GCC_4.0.0\000GCC_4.2.0\000GCC_4.3.0\000GCC_4.5.0\000GCC_4.7.0\000GCC_7.0.0\000GCC_11.0\000GCC_14.0\000GCC_14.0.0\000GLIBC_2.35\000GLIBC_2.34\000GLIBC_2.17\000\000\000\000\000\000\000\000\023\000\023\000\023\000\001\000\023\000\024\000\023\000\023\000\024\000\023\000\023\000\023\000\023"..., "", <error reading variable: Cannot create a lazy string with address 0x0, and a non-zero length.>, 
  "GCC_3.4.4\000GCC_4.0.0\000GCC_4.2.0\000GCC_4.3.0\000GCC_4.5.0\000GCC_4.7.0\000GCC_7.0.0\000GCC_11.0\000GCC_14.0\000GCC_14.0.0\000GLIBC_2.35\000GLIBC_2.34\000GLIBC_2.17\000\000\000\000\000\000\000\000\023\000\023\000\023\000\001\000\023\000\024\000\023\000\023\000\024\000\023\000\023\000\023\000\023\000\023\000\001\000\023\000\023\000\023\000\023\000\023\000\025\000\023\000\023\000\023\000\001\000\023\000\024\000\023\000\024\000\004\000\v"..., "", 
  <error reading variable: Cannot create a lazy string with address 0x0, and a non-zero length.>, 
  "GCC_4.5.0\000GCC_4.7.0\000GCC_7.0.0\000GCC_11.0\000GCC_14.0\000GCC_14.0.0\000GLIBC_2.35\000GLIBC_2.34\000GLIBC_2.17\000\000\000\000\000\000\000\000\023\000\023\000\023\000\001\000\023\000\024\000\023\000\023\000\024\000\023\000\023\000\023\000\023\000\023\000\001\000\023\000\023\000\023\000\023\000\023\000\025\000\023\000\023\000\023\000\001\000\023\000\024\000\023\000\024\000\004\000\v\000\004\000\004\000\f\000\r\000\004\000\020\000\f\000\022\000\004\000\004\000\003\000\005\000\a\000\004\000\004\000\t\000\a\000\a\000\004\000\004"..., "", <error reading variable: Cannot create a lazy string with address 0x0, and a non-zero length.>, 
  "GCC_14.0\000GCC_14.0.0\000GLIBC_2.35\000GLIBC_2.34\000GLIBC_2.17\000\000\000\000\000\000\000\000\023\000\023\000\023\000\001\000\023\000\024\000\023\000\023\000\024--Type <RET> for more, q to quit, c to continue without paging--q
Quit
(gdb) print scan_success
$4 = false
(gdb) next
54	    std::string path = "/tmp/test";
(gdb) next
55	    int max_files = 5;
(gdb) next
56	    std::vector<std::string> file_list;
(gdb) next
57	    bool scan_success = false;
(gdb) print path
$5 = "/tmp/test"
(gdb) print max_files
$6 = 5
(gdb) print file_list
$7 = std::vector of length 0, capacity 0
(gdb) print scan_success
$8 = false
(gdb) next
60	        boost::filesystem::path dir_path(path);
(gdb) continue
Continuing.

Breakpoint 4.1, main () at /home/sre/debugging/main.cpp:75
75	    } catch (const boost::filesystem::filesystem_error& e) {
(gdb) next
80	    DirectoryManager dir_manager(path);
(gdb) next
81	    scan_success = dir_manager.scanDirectory();
(gdb) next

Breakpoint 2, DirectoryManager::scanDirectory (this=0xffffffffef10) at /home/sre/debugging/main.cpp:15
15	    bool scanDirectory() {
(gdb) continue
Continuing.

Breakpoint 3, main () at /home/sre/debugging/main.cpp:83
83	    std::cout << "Scan success: " << (scan_success ? "true" : "false") << "\n";
(gdb) print file_name
No symbol "file_name" in current context.
(gdb) print file_list
$9 = std::vector of length 5, capacity 8 = {"/tmp/test/file0.txt", "/tmp/test/file1.txt", "/tmp/test/file2.txt", "/tmp/test/file3.txt", "/tmp/test/file4.txt"}
(gdb) print file_list[1]
$10 = "/tmp/test/file1.txt"
(gdb) print file_list[4]
$11 = "/tmp/test/file4.txt"
(gdb) continue
Continuing.
Scan success: true
Directory count: 0
File count: 5
Last error: Scan completed successfully
Files created: /tmp/test/file0.txt /tmp/test/file1.txt /tmp/test/file2.txt /tmp/test/file3.txt /tmp/test/file4.txt 
[Inferior 1 (process 184295) exited normally]
(gdb) print $7
$12 = std::vector of length 0, capacity 0
(gdb) print $6
$13 = 5
(gdb) run
Starting program: /home/sre/debugging/build/main 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/aarch64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at /home/sre/debugging/main.cpp:53
53	int main() {
(gdb) next
54	    std::string path = "/tmp/test";
(gdb) continue
Continuing.

Breakpoint 4.1, main () at /home/sre/debugging/main.cpp:75
75	    } catch (const boost::filesystem::filesystem_error& e) {
(gdb) print file_list
$20 = std::vector of length 5, capacity 8 = {"/tmp/test/file0.txt", "/tmp/test/file1.txt", "/tmp/test/file2.txt", "/tmp/test/file3.txt", "/tmp/test/file4.txt"}
(gdb) print file_list[0]
$21 = "/tmp/test/file0.txt"
(gdb) break /home/sre/debugging/main.cpp:81
Breakpoint 5 at 0xaaaaaaaa538c: file /home/sre/debugging/main.cpp, line 81.
(gdb) run
The program being debugged has been started already.
Start it from the beginning? (y or n) y
Starting program: /home/sre/debugging/build/main 
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/aarch64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at /home/sre/debugging/main.cpp:53
53	int main() {
(gdb) continue
Continuing.

Breakpoint 4.1, main () at /home/sre/debugging/main.cpp:75
75	    } catch (const boost::filesystem::filesystem_error& e) {
(gdb) continue
Continuing.

Breakpoint 5, main () at /home/sre/debugging/main.cpp:81
81	    scan_success = dir_manager.scanDirectory();
(gdb) print e.what()
Can't take address of "e" which isn't an lvalue.
(gdb) print e
$22 = {i = {0, 1127522290}, x = 5805361265115136, d = 5805361265115136}
(gdb) print e.what()
Can't take address of "e" which isn't an lvalue.
(gdb) next

Breakpoint 2, DirectoryManager::scanDirectory (this=0xffffffffef10) at /home/sre/debugging/main.cpp:15
15	    bool scanDirectory() {
(gdb) print e.what()
Can't take address of "e" which isn't an lvalue.
(gdb) next

Breakpoint 2, DirectoryManager::scanDirectory (this=0xffffffffef10) at /home/sre/debugging/main.cpp:15
15	    bool scanDirectory() {
(gdb) print e.what()
Can't take address of "e" which isn't an lvalue.
(gdb) print e
$23 = {i = {0, 1127522290}, x = 5805361265115136, d = 5805361265115136}
(gdb) exit
A debugging session is active.

	Inferior 1 [process 184307] will be killed.

Quit anyway? (y or n) y


