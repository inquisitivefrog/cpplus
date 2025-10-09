
COLLECTION
----------
sre@cpp:~/debugging/multi-file/build$ valgrind --tool=cachegrind --cache-sim=yes --I1=131072,8,64 --D1=65536,8,64 --LL=4194304,8,64 --cachegrind-out-file=cachegrind.out.packed ./main
==196634== Cachegrind, a high-precision tracing profiler
==196634== Copyright (C) 2002-2017, and GNU GPL'd, by Nicholas Nethercote et al.
==196634== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==196634== Command: ./main
==196634== 
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
Thread-89915744: Scanning path: /tmp/test0
Thread-89915744: Found file: "/tmp/test0/file0.txt"
Thread-89915744: Found file: "/tmp/test0/file1.txt"
Thread-89915744: Found file: "/tmp/test0/file2.txt"
Thread-89915744: Scanned /tmp/test0, dirs: 0, files: 3, total dirs: 0, total files: 3
Thread-98369888: Scanning path: /tmp/test99
Thread-98369888: Found file: "/tmp/test99/file0.txt"
Thread-98369888: Found file: "/tmp/test99/file1.txt"
Thread-98369888: Found file: "/tmp/test99/file2.txt"
Thread-98369888: Scanned /tmp/test99, dirs: 0, files: 3, total dirs: 0, total files: 300
Main completed. Total dirs: 0, Total files: 300
==196634== 
==196634== I refs:        5,889,253
==196634== I1  misses:        2,829
==196634== LLi misses:        2,784
==196634== I1  miss rate:      0.05%
==196634== LLi miss rate:      0.05%
==196634== 
==196634== D refs:        2,662,483  (1,611,904 rd   + 1,050,579 wr)
==196634== D1  misses:       15,581  (   12,796 rd   +     2,785 wr)
==196634== LLd misses:       10,048  (    8,019 rd   +     2,029 wr)
==196634== D1  miss rate:       0.6% (      0.8%     +       0.3%  )
==196634== LLd miss rate:       0.4% (      0.5%     +       0.2%  )
==196634== 
==196634== LL refs:          18,410  (   15,625 rd   +     2,785 wr)
==196634== LL misses:        12,832  (   10,803 rd   +     2,029 wr)
==196634== LL miss rate:        0.2% (      0.1%     +       0.2%  )

ANALYSIS
--------
sre@cpp:~/debugging/multi-file/build$ cg_annotate cachegrind.out.packed --auto=yes --show=Ir,D1mr,ILmr
--------------------------------------------------------------------------------
-- Metadata
--------------------------------------------------------------------------------
Invocation:       /usr/bin/cg_annotate cachegrind.out.packed --auto=yes --show=Ir,D1mr,ILmr
I1 cache:         131072 B, 64 B, 8-way associative
D1 cache:         65536 B, 64 B, 8-way associative
LL cache:         4194304 B, 64 B, 8-way associative
Command:          ./main
Events recorded:  Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Events shown:     Ir D1mr ILmr
Event sort order: Ir I1mr ILmr Dr D1mr DLmr Dw D1mw DLmw
Threshold:        0.1%
Annotation:       on

--------------------------------------------------------------------------------
-- Summary
--------------------------------------------------------------------------------
Ir________________ D1mr___________ ILmr__________ 

5,889,253 (100.0%) 12,796 (100.0%) 2,784 (100.0%)  PROGRAM TOTALS

--------------------------------------------------------------------------------
-- File:function summary
--------------------------------------------------------------------------------
  Ir______________________ D1mr________________ ILmr______________  file:function

< 2,355,478 (40.0%, 40.0%)   340  (2.7%,  2.7%) 921 (33.1%, 33.1%)  ???:
    781,036 (13.3%)          183  (1.4%)        334 (12.0%)           ???
    219,854  (3.7%)            0                 15  (0.5%)           std::filesystem::__cxx11::path::_M_split_cmpts()
    133,981  (2.3%)            0                  3  (0.1%)           std::filesystem::__cxx11::path::_List::_Impl_deleter::operator()(std::filesystem::__cxx11::path::_List::_Impl*) const
     91,800  (1.6%)            0                  3  (0.1%)           std::filesystem::__cxx11::path::_List::_List(std::filesystem::__cxx11::path::_List const&)
     66,000  (1.1%)            1  (0.0%)         18  (0.6%)           std::filesystem::__cxx11::path::_M_append(std::basic_string_view<char, std::char_traits<char> >)
     44,600  (0.8%)            0                  5  (0.2%)           std::filesystem::status(std::filesystem::__cxx11::path const&, std::error_code&)
     42,029  (0.7%)            0                  1  (0.0%)           operator new(unsigned long)
     39,312  (0.7%)           15  (0.1%)          2  (0.1%)           std::locale::id::_M_id() const
     38,490  (0.7%)            0                  4  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_append(char const*, unsigned long)
     38,412  (0.7%)            0                  3  (0.1%)           std::locale::locale()
     33,900  (0.6%)            0                  8  (0.3%)           std::basic_filebuf<char, std::char_traits<char> >::overflow(int)
     32,200  (0.5%)            3  (0.0%)          3  (0.1%)           std::ios_base::_M_init()
     30,228  (0.5%)            1  (0.0%)          3  (0.1%)           std::basic_ios<char, std::char_traits<char> >::_M_cache_locale(std::locale const&)
     29,748  (0.5%)            0                  5  (0.2%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::__sv_wrapper, std::allocator<char> const&)
     29,318  (0.5%)            1  (0.0%)          5  (0.2%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long)
     28,800  (0.5%)            0                  2  (0.1%)           std::filesystem::status(std::filesystem::__cxx11::path const&)
     28,100  (0.5%)            1  (0.0%)          4  (0.1%)           std::basic_streambuf<char, std::char_traits<char> >::xsputn(char const*, long)
     25,980  (0.4%)            0                  2  (0.1%)           std::locale::~locale()
     25,800  (0.4%)            0                  4  (0.1%)           std::basic_filebuf<char, std::char_traits<char> >::close()
     23,796  (0.4%)            0                  6  (0.2%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_mutate(unsigned long, unsigned long, char const*, unsigned long)
     23,100  (0.4%)            0                  2  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&&)
     22,080  (0.4%)            0                  4  (0.1%)           std::locale::operator=(std::locale const&)
     18,630  (0.3%)            1  (0.0%)          2  (0.1%)           std::ios_base::ios_base()
     18,320  (0.3%)            0                  2  (0.1%)           std::basic_ios<char, std::char_traits<char> >::init(std::basic_streambuf<char, std::char_traits<char> >*)
     17,040  (0.3%)            0                  2  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_create(unsigned long&, unsigned long)
     16,500  (0.3%)            1  (0.0%)          4  (0.1%)           std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::_Ios_Openmode)
     16,300  (0.3%)            1  (0.0%)         14  (0.5%)           std::filesystem::__cxx11::directory_iterator::directory_iterator(std::filesystem::__cxx11::path const&, std::filesystem::directory_options, std::error_code*)
     15,300  (0.3%)            1  (0.0%)          4  (0.1%)           std::ostream::write(char const*, long)
     14,947  (0.3%)            4  (0.0%)          2  (0.1%)           std::ostream::sentry::sentry(std::ostream&)
     14,496  (0.2%)           14  (0.1%)          1  (0.0%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string()
     14,100  (0.2%)            0                  4  (0.1%)           std::basic_filebuf<char, std::char_traits<char> >::basic_filebuf()
     14,100  (0.2%)            0                  3  (0.1%)           std::basic_filebuf<char, std::char_traits<char> >::_M_terminate_output()
     13,500  (0.2%)            0                  4  (0.1%)           std::basic_filebuf<char, std::char_traits<char> >::_M_convert_to_external(char*, long)
     13,224  (0.2%)            0                  1  (0.0%)           std::filesystem::__cxx11::path::_List::_List()
     13,200  (0.2%)            1  (0.0%)          5  (0.2%)           std::filesystem::__cxx11::directory_iterator::operator++()
     12,958  (0.2%)            0                  4  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::reserve(unsigned long)
     12,144  (0.2%)            2  (0.0%)          7  (0.3%)           std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long)
     11,700  (0.2%)            0                  4  (0.1%)           std::basic_filebuf<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode)
     11,700  (0.2%)            1  (0.0%)          3  (0.1%)           std::basic_filebuf<char, std::char_traits<char> >::xsputn(char const*, long)
     11,208  (0.2%)            0                  1  (0.0%)           std::_V2::system_category()
     10,800  (0.2%)            0                  3  (0.1%)           std::basic_ofstream<char, std::char_traits<char> >::~basic_ofstream()
     10,688  (0.2%)            0                  8  (0.3%)           std::locale::_Impl::_M_install_facet(std::locale::id const*, std::locale::facet const*)
     10,500  (0.2%)            0                  0                   std::__basic_file<char>::is_open() const
     10,000  (0.2%)            2  (0.0%)          5  (0.2%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_assign(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
      9,380  (0.2%)            0                  4  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct(unsigned long, char)
      9,000  (0.2%)            0                  2  (0.1%)           std::__basic_file<char>::close()
      8,932  (0.2%)            0                  2  (0.1%)           std::ios_base::~ios_base()
      8,544  (0.1%)            6  (0.0%)          2  (0.1%)           __aarch64_cas4_acq
      8,500  (0.1%)            0                  7  (0.3%)           std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<unsigned long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, unsigned long) const
      8,100  (0.1%)            0                  3  (0.1%)           std::__basic_file<char>::open(char const*, std::_Ios_Openmode, int)
      8,100  (0.1%)            0                  2  (0.1%)           std::filesystem::__cxx11::path::has_filename() const
      7,500  (0.1%)            1  (0.0%)          6  (0.2%)           std::ostream& std::ostream::_M_insert<unsigned long>(unsigned long)
      7,448  (0.1%)            0                 10  (0.4%)           std::__cxx11::basic_stringbuf<char, std::char_traits<char>, std::allocator<char> >::overflow(int)
      7,350  (0.1%)            0                  1  (0.0%)           __aarch64_swp4_rel
      7,346  (0.1%)            0                  6  (0.2%)           std::ostream::put(char)
      7,200  (0.1%)            0                  3  (0.1%)           std::__basic_file<char>::xsputn(char const*, long)
      6,700  (0.1%)            2  (0.0%)          5  (0.2%)           std::__cxx11::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::basic_stringstream()
      6,466  (0.1%)            0                  1  (0.0%)           operator delete(void*)
      6,000  (0.1%)            0                  2  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::append(char const*)
      6,000  (0.1%)            0                  1  (0.0%)           std::basic_filebuf<char, std::char_traits<char> >::_M_destroy_internal_buffer()

<   708,971 (12.0%, 52.0%) 3,532 (27.6%, 30.3%)  48  (1.7%, 34.8%)  ./elf/./elf/dl-lookup.c:
    446,679  (7.6%)        2,942 (23.0%)         32  (1.1%)           do_lookup_x
    163,708  (2.8%)           15  (0.1%)         11  (0.4%)           _dl_lookup_symbol_x
     98,584  (1.7%)          575  (4.5%)          5  (0.2%)           check_match

<   625,422 (10.6%, 62.7%)    14  (0.1%, 30.4%) 107  (3.8%, 38.6%)  ./malloc/./malloc/malloc.c:
    213,754  (3.6%)            4  (0.0%)         10  (0.4%)           _int_free
    198,371  (3.4%)            3  (0.0%)          9  (0.3%)           malloc
    124,646  (2.1%)            1  (0.0%)          5  (0.2%)           free
     53,297  (0.9%)            3  (0.0%)         23  (0.8%)           _int_malloc
     18,869  (0.3%)            1  (0.0%)          5  (0.2%)           _int_free_merge_chunk
      9,999  (0.2%)            0                  3  (0.1%)           _int_free_create_chunk

<   359,466  (6.1%, 68.8%) 2,033 (15.9%, 46.3%)   1  (0.0%, 38.7%)  ./elf/../sysdeps/generic/dl-new-hash.h:_dl_lookup_symbol_x

<   147,507  (2.5%, 71.3%)     6  (0.0%, 46.3%)   7  (0.3%, 38.9%)  ./string/../sysdeps/aarch64/multiarch/../memcpy.S:
    143,165  (2.4%)            3  (0.0%)          3  (0.1%)           __GI_memcpy

<   138,547  (2.4%, 73.6%) 1,872 (14.6%, 60.9%)  18  (0.6%, 39.6%)  ./elf/../sysdeps/aarch64/dl-machine.h:
    138,214  (2.3%)        1,857 (14.5%)         17  (0.6%)           _dl_relocate_object

<   113,096  (1.9%, 75.5%)   334  (2.6%, 63.5%)   5  (0.2%, 39.8%)  ./string/../sysdeps/aarch64/strcmp.S:strcmp

<   111,560  (1.9%, 77.4%) 1,808 (14.1%, 77.7%)  30  (1.1%, 40.8%)  ./elf/./elf/dl-reloc.c:
    111,399  (1.9%)        1,807 (14.1%)         27  (1.0%)           _dl_relocate_object

<   103,428  (1.8%, 79.2%)     0  (0.0%, 77.7%)   8  (0.3%, 41.1%)  ./string/../sysdeps/aarch64/nptl/../memset.S:
    102,594  (1.7%)            0                  4  (0.1%)           __GI_memset

<   102,446  (1.7%, 80.9%)     0  (0.0%, 77.7%)  25  (0.9%, 42.0%)  /usr/include/c++/13/bits/basic_string.h:
     22,000  (0.4%)            0                  4  (0.1%)           std::__cxx11::to_string(int)
     20,434  (0.3%)            0                  3  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string<std::basic_string_view<char, std::char_traits<char> >, void>(std::basic_string_view<char, std::char_traits<char> > const&, std::allocator<char> const&)
     17,400  (0.3%)            0                  5  (0.2%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::__str_concat<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::value_type const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::size_type, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::value_type const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::size_type, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::allocator_type const&)
     14,400  (0.2%)            0                  4  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::operator+<char, std::char_traits<char>, std::allocator<char> >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*)
     12,480  (0.2%)            0                  4  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::operator+<char, std::char_traits<char>, std::allocator<char> >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&&)
      8,800  (0.1%)            0                  2  (0.1%)           std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string<std::allocator<char> >(unsigned long, char, std::allocator<char> const&)

<    87,407  (1.5%, 82.4%)     8  (0.1%, 77.7%)  66  (2.4%, 44.4%)  ./libio/./libio/genops.c:
     29,700  (0.5%)            2  (0.0%)          8  (0.3%)           _IO_link_in
     24,600  (0.4%)            0                 10  (0.4%)           __GI__IO_un_link.part.0
      7,500  (0.1%)            0                  2  (0.1%)           _IO_old_init
      6,900  (0.1%)            0                  2  (0.1%)           _IO_no_init
      6,321  (0.1%)            0                  2  (0.1%)           _IO_setb

<    77,883  (1.3%, 83.7%) 1,689 (13.2%, 90.9%)  11  (0.4%, 44.8%)  ./elf/./elf/do-rel.h:
     77,749  (1.3%)        1,688 (13.2%)          9  (0.3%)           _dl_relocate_object

<    68,091  (1.2%, 84.9%)     3  (0.0%, 91.0%)  52  (1.9%, 46.7%)  ./libio/./libio/fileops.c:
     21,300  (0.4%)            1  (0.0%)          8  (0.3%)           _IO_file_fopen@@GLIBC_2.17
     15,600  (0.3%)            0                  5  (0.2%)           _IO_file_close_it@@GLIBC_2.17
      9,600  (0.2%)            0                  4  (0.1%)           _IO_file_open
      8,477  (0.1%)            2  (0.0%)          7  (0.3%)           _IO_file_xsputn@@GLIBC_2.17

<    44,177  (0.8%, 85.6%)     0  (0.0%, 91.0%)  24  (0.9%, 47.5%)  /usr/include/c++/13/bits/fs_path.h:
     21,000  (0.4%)            0                  3  (0.1%)           std::filesystem::__cxx11::path::path<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::filesystem::__cxx11::path>(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::filesystem::__cxx11::path::format)
      6,611  (0.1%)            0                  1  (0.0%)           std::filesystem::__cxx11::path::~path()

<    41,353  (0.7%, 86.3%)     2  (0.0%, 91.0%)  34  (1.2%, 48.7%)  /home/sre/debugging/multi-file/main.cpp:
     34,333  (0.6%)            2  (0.0%)         26  (0.9%)           main
      7,000  (0.1%)            0                  6  (0.2%)           scanDirectories(DirectoryManager&)

<    40,834  (0.7%, 87.0%)     0  (0.0%, 91.0%)   4  (0.1%, 48.9%)  ./string/../sysdeps/aarch64/multiarch/../memchr.S:__GI_memchr

<    35,072  (0.6%, 87.6%)     0  (0.0%, 91.0%)   6  (0.2%, 49.1%)  /usr/include/c++/13/bits/fs_dir.h:
     10,200  (0.2%)            0                  0                   std::filesystem::file_status::type() const
      7,400  (0.1%)            0                  1  (0.0%)           std::filesystem::__cxx11::operator==(std::filesystem::__cxx11::directory_iterator const&, std::filesystem::__cxx11::directory_iterator const&)

<    33,440  (0.6%, 88.2%)     5  (0.0%, 91.0%)   8  (0.3%, 49.4%)  /usr/include/c++/13/bits/charconv.h:
     22,990  (0.4%)            5  (0.0%)          5  (0.2%)           void std::__detail::__to_chars_10_impl<unsigned int>(char*, unsigned int, unsigned int)
     10,450  (0.2%)            0                  3  (0.1%)           unsigned int std::__detail::__to_chars_len<unsigned int>(unsigned int, int)

<    31,000  (0.5%, 88.7%)     0  (0.0%, 91.0%)   5  (0.2%, 49.6%)  /usr/include/c++/13/bits/shared_ptr_base.h:
     14,500  (0.2%)            0                  2  (0.1%)           std::__shared_count<(__gnu_cxx::_Lock_policy)2>::_M_less(std::__shared_count<(__gnu_cxx::_Lock_policy)2> const&) const
      7,000  (0.1%)            0                  2  (0.1%)           bool std::__shared_ptr<std::filesystem::__cxx11::_Dir, (__gnu_cxx::_Lock_policy)2>::owner_before<std::filesystem::__cxx11::_Dir>(std::__shared_ptr<std::filesystem::__cxx11::_Dir, (__gnu_cxx::_Lock_policy)2> const&) const

<    28,409  (0.5%, 89.2%)    10  (0.1%, 91.1%)   4  (0.1%, 49.7%)  ./string/../sysdeps/aarch64/multiarch/strlen_asimd.S:__strlen_asimd

<    28,359  (0.5%, 89.7%)     0  (0.0%, 91.1%)  10  (0.4%, 50.1%)  /usr/include/c++/13/bits/unique_ptr.h:
     15,626  (0.3%)            0                  3  (0.1%)           std::unique_ptr<std::filesystem::__cxx11::path::_List::_Impl, std::filesystem::__cxx11::path::_List::_Impl_deleter>::~unique_ptr()

<    26,982  (0.5%, 90.1%)     2  (0.0%, 91.1%)  40  (1.4%, 51.5%)  ./malloc/./malloc/arena.c:
     24,346  (0.4%)            0                  1  (0.0%)           free

<    25,675  (0.4%, 90.6%)     0  (0.0%, 91.1%)  26  (0.9%, 52.4%)  /home/sre/debugging/multi-file/DirectoryManager.cpp:
     25,622  (0.4%)            0                 20  (0.7%)           DirectoryManager::scanDirectory(std::basic_string_view<char, std::char_traits<char> >, std::basic_string_view<char, std::char_traits<char> >)

<    25,495  (0.4%, 91.0%)     0  (0.0%, 91.1%)   5  (0.2%, 52.6%)  ./elf/../sysdeps/generic/ldsodefs.h:
     12,677  (0.2%)            0                  1  (0.0%)           do_lookup_x
     12,499  (0.2%)            0                  2  (0.1%)           _dl_relocate_object

<    22,900  (0.4%, 91.4%)     6  (0.0%, 91.2%)   5  (0.2%, 52.8%)  ./dirent/../sysdeps/unix/sysv/linux/readdir64.c:readdir

<    21,670  (0.4%, 91.8%)     0  (0.0%, 91.2%)   4  (0.1%, 52.9%)  ./nptl/./nptl/libc-cleanup.c:
     11,438  (0.2%)            0                  2  (0.1%)           __libc_cleanup_push_defer
     10,232  (0.2%)            0                  2  (0.1%)           __libc_cleanup_pop_restore

<    21,000  (0.4%, 92.1%)     0  (0.0%, 91.2%)   4  (0.1%, 53.1%)  /usr/include/c++/13/bits/fs_ops.h:
      9,000  (0.2%)            0                  1  (0.0%)           std::filesystem::exists(std::filesystem::file_status)

<    14,100  (0.2%, 92.4%)     0  (0.0%, 91.2%)   4  (0.1%, 53.2%)  ./io/../sysdeps/unix/sysv/linux/open64.c:open

<    13,500  (0.2%, 92.6%)     0  (0.0%, 91.2%)   5  (0.2%, 53.4%)  ./libio/./libio/iofopen.c:
     12,000  (0.2%)            0                  4  (0.1%)           __fopen_internal

<    13,257  (0.2%, 92.8%)   425  (3.3%, 94.5%)   9  (0.3%, 53.7%)  ./elf/./elf/dl-runtime.c:_dl_fixup

<    13,200  (0.2%, 93.0%)     0  (0.0%, 94.5%)   8  (0.3%, 54.0%)  ./libio/./libio/iofclose.c:fclose@@GLIBC_2.17

<    12,402  (0.2%, 93.3%)     0  (0.0%, 94.5%)  17  (0.6%, 54.6%)  /usr/include/c++/13/bits/new_allocator.h:
      8,040  (0.1%)            0                  1  (0.0%)           std::__new_allocator<char>::~__new_allocator()

<    12,087  (0.2%, 93.5%)     2  (0.0%, 94.5%)   9  (0.3%, 55.0%)  ./libio/./libio/libioP.h:
      8,400  (0.1%)            2  (0.0%)          1  (0.0%)           fclose@@GLIBC_2.17

<    11,965  (0.2%, 93.7%)    86  (0.7%, 95.2%)  14  (0.5%, 55.5%)  ./elf/./elf/dl-tunables.c:
     11,285  (0.2%)           44  (0.3%)          5  (0.2%)           __GI___tunables_init

<    11,011  (0.2%, 93.9%)     0  (0.0%, 95.2%)   2  (0.1%, 55.5%)  ./io/../sysdeps/unix/sysv/linux/fstatat64.c:fstatat

<    10,500  (0.2%, 94.0%)     1  (0.0%, 95.2%)   4  (0.1%, 55.7%)  ./string/./string/strstr.c:strstr

<    10,130  (0.2%, 94.2%)    77  (0.6%, 95.8%)  18  (0.6%, 56.3%)  ./elf/./elf/dl-version.c:
     10,038  (0.2%)           77  (0.6%)         16  (0.6%)           _dl_check_map_versions

<     9,728  (0.2%, 94.4%)     4  (0.0%, 95.8%)   5  (0.2%, 56.5%)  ./wcsmbs/./wcsmbs/btowc.c:btowc

<     8,513  (0.1%, 94.5%)     0  (0.0%, 95.8%)   5  (0.2%, 56.7%)  /usr/include/c++/13/bits/char_traits.h:
      6,513  (0.1%)            0                  2  (0.1%)           std::char_traits<char>::length(char const*)

<     8,500  (0.1%, 94.7%)     0  (0.0%, 95.8%)   2  (0.1%, 56.8%)  /usr/include/c++/13/bits/stl_function.h:std::less<std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>*>::operator()(std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>*, std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>*) const

<     8,436  (0.1%, 94.8%)     0  (0.0%, 95.8%)   7  (0.3%, 57.0%)  ./nptl/./nptl/pthread_mutex_unlock.c:
      7,361  (0.1%)            0                  5  (0.2%)           __pthread_mutex_unlock_usercnt

<     8,206  (0.1%, 94.9%)     3  (0.0%, 95.8%)   7  (0.3%, 57.3%)  ./nptl/./nptl/pthread_mutex_lock.c:pthread_mutex_lock@@GLIBC_2.17

<     8,008  (0.1%, 95.1%)     0  (0.0%, 95.8%)   1  (0.0%, 57.3%)  ./io/../sysdeps/unix/sysv/linux/stat64.c:stat

<     6,600  (0.1%, 95.2%)     0  (0.0%, 95.8%)   3  (0.1%, 57.4%)  ./io/../sysdeps/unix/sysv/linux/fcntl_nocancel.c:__fcntl64_nocancel

<     6,200  (0.1%, 95.3%)     5  (0.0%, 95.9%)   5  (0.2%, 57.6%)  ./string/../sysdeps/aarch64/strchr.S:index

<     6,090  (0.1%, 95.4%)     0  (0.0%, 95.9%)   1  (0.0%, 57.6%)  ./elf/../sysdeps/generic/dl-protected.h:do_lookup_x

--------------------------------------------------------------------------------
-- Function:file summary
--------------------------------------------------------------------------------
  Ir____________________ D1mr________________ ILmr______________  function:file

> 781,036 (13.3%, 13.3%)   183  (1.4%,  1.4%) 334 (12.0%, 12.0%)  ???:???

> 523,174  (8.9%, 22.1%) 2,048 (16.0%, 17.4%)  12  (0.4%, 12.4%)  _dl_lookup_symbol_x:
  359,466  (6.1%)        2,033 (15.9%)          1  (0.0%)           ./elf/../sysdeps/generic/dl-new-hash.h
  163,708  (2.8%)           15  (0.1%)         11  (0.4%)           ./elf/./elf/dl-lookup.c

> 465,467  (7.9%, 30.0%) 2,944 (23.0%, 40.4%)  34  (1.2%, 13.6%)  do_lookup_x:
  446,679  (7.6%)        2,942 (23.0%)         32  (1.1%)           ./elf/./elf/dl-lookup.c
   12,677  (0.2%)            0                  1  (0.0%)           ./elf/../sysdeps/generic/ldsodefs.h
    6,090  (0.1%)            0                  1  (0.0%)           ./elf/../sysdeps/generic/dl-protected.h

> 339,955  (5.8%, 35.8%) 5,353 (41.8%, 82.3%)  58  (2.1%, 15.7%)  _dl_relocate_object:
  138,214  (2.3%)        1,857 (14.5%)         17  (0.6%)           ./elf/../sysdeps/aarch64/dl-machine.h
  111,399  (1.9%)        1,807 (14.1%)         27  (1.0%)           ./elf/./elf/dl-reloc.c
   77,749  (1.3%)        1,688 (13.2%)          9  (0.3%)           ./elf/./elf/do-rel.h
   12,499  (0.2%)            0                  2  (0.1%)           ./elf/../sysdeps/generic/ldsodefs.h

> 219,854  (3.7%, 39.6%)     0  (0.0%, 82.3%)  15  (0.5%, 16.3%)  std::filesystem::__cxx11::path::_M_split_cmpts():???

> 213,754  (3.6%, 43.2%)     4  (0.0%, 82.3%)  10  (0.4%, 16.6%)  _int_free:./malloc/./malloc/malloc.c

> 200,226  (3.4%, 46.6%)     3  (0.0%, 82.3%)  11  (0.4%, 17.0%)  malloc:
  198,371  (3.4%)            3  (0.0%)          9  (0.3%)           ./malloc/./malloc/malloc.c

> 148,992  (2.5%, 49.1%)     1  (0.0%, 82.3%)   6  (0.2%, 17.2%)  free:
  124,646  (2.1%)            1  (0.0%)          5  (0.2%)           ./malloc/./malloc/malloc.c
   24,346  (0.4%)            0                  1  (0.0%)           ./malloc/./malloc/arena.c

> 143,165  (2.4%, 51.5%)     3  (0.0%, 82.4%)   3  (0.1%, 17.3%)  __GI_memcpy:./string/../sysdeps/aarch64/multiarch/../memcpy.S

> 133,981  (2.3%, 53.8%)     0  (0.0%, 82.4%)   3  (0.1%, 17.5%)  std::filesystem::__cxx11::path::_List::_Impl_deleter::operator()(std::filesystem::__cxx11::path::_List::_Impl*) const:???

> 113,096  (1.9%, 55.7%)   334  (2.6%, 85.0%)   5  (0.2%, 17.6%)  strcmp:./string/../sysdeps/aarch64/strcmp.S

> 102,594  (1.7%, 57.5%)     0  (0.0%, 85.0%)   4  (0.1%, 17.8%)  __GI_memset:./string/../sysdeps/aarch64/nptl/../memset.S

>  98,737  (1.7%, 59.2%)   579  (4.5%, 89.5%)   9  (0.3%, 18.1%)  check_match:
   98,584  (1.7%)          575  (4.5%)          5  (0.2%)           ./elf/./elf/dl-lookup.c

>  91,800  (1.6%, 60.7%)     0  (0.0%, 89.5%)   3  (0.1%, 18.2%)  std::filesystem::__cxx11::path::_List::_List(std::filesystem::__cxx11::path::_List const&):???

>  66,000  (1.1%, 61.8%)     1  (0.0%, 89.5%)  18  (0.6%, 18.9%)  std::filesystem::__cxx11::path::_M_append(std::basic_string_view<char, std::char_traits<char> >):???

>  53,297  (0.9%, 62.7%)     3  (0.0%, 89.5%)  23  (0.8%, 19.7%)  _int_malloc:./malloc/./malloc/malloc.c

>  44,600  (0.8%, 63.5%)     0  (0.0%, 89.5%)   5  (0.2%, 19.9%)  std::filesystem::status(std::filesystem::__cxx11::path const&, std::error_code&):???

>  42,029  (0.7%, 64.2%)     0  (0.0%, 89.5%)   1  (0.0%, 19.9%)  operator new(unsigned long):???

>  40,834  (0.7%, 64.9%)     0  (0.0%, 89.5%)   4  (0.1%, 20.0%)  __GI_memchr:./string/../sysdeps/aarch64/multiarch/../memchr.S

>  39,312  (0.7%, 65.6%)    15  (0.1%, 89.6%)   2  (0.1%, 20.1%)  std::locale::id::_M_id() const:???

>  38,490  (0.7%, 66.2%)     0  (0.0%, 89.6%)   4  (0.1%, 20.3%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_append(char const*, unsigned long):???

>  38,412  (0.7%, 66.9%)     0  (0.0%, 89.6%)   3  (0.1%, 20.4%)  std::locale::locale():???

>  34,338  (0.6%, 67.5%)     2  (0.0%, 89.7%)  26  (0.9%, 21.3%)  main:
   34,333  (0.6%)            2  (0.0%)         26  (0.9%)           /home/sre/debugging/multi-file/main.cpp

>  33,900  (0.6%, 68.0%)     0  (0.0%, 89.7%)   8  (0.3%, 21.6%)  std::basic_filebuf<char, std::char_traits<char> >::overflow(int):???

>  32,200  (0.5%, 68.6%)     3  (0.0%, 89.7%)   3  (0.1%, 21.7%)  std::ios_base::_M_init():???

>  30,228  (0.5%, 69.1%)     1  (0.0%, 89.7%)   3  (0.1%, 21.8%)  std::basic_ios<char, std::char_traits<char> >::_M_cache_locale(std::locale const&):???

>  29,748  (0.5%, 69.6%)     0  (0.0%, 89.7%)   5  (0.2%, 22.0%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::__sv_wrapper, std::allocator<char> const&):???

>  29,700  (0.5%, 70.1%)     2  (0.0%, 89.7%)   8  (0.3%, 22.3%)  _IO_link_in:./libio/./libio/genops.c

>  29,318  (0.5%, 70.6%)     1  (0.0%, 89.7%)   5  (0.2%, 22.4%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_replace(unsigned long, unsigned long, char const*, unsigned long):???

>  28,800  (0.5%, 71.1%)     0  (0.0%, 89.7%)   2  (0.1%, 22.5%)  std::filesystem::status(std::filesystem::__cxx11::path const&):???

>  28,409  (0.5%, 71.6%)    10  (0.1%, 89.8%)   4  (0.1%, 22.7%)  __strlen_asimd:./string/../sysdeps/aarch64/multiarch/strlen_asimd.S

>  28,100  (0.5%, 72.1%)     1  (0.0%, 89.8%)   4  (0.1%, 22.8%)  std::basic_streambuf<char, std::char_traits<char> >::xsputn(char const*, long):???

>  25,980  (0.4%, 72.5%)     0  (0.0%, 89.8%)   2  (0.1%, 22.9%)  std::locale::~locale():???

>  25,800  (0.4%, 72.9%)     0  (0.0%, 89.8%)   4  (0.1%, 23.0%)  std::basic_filebuf<char, std::char_traits<char> >::close():???

>  25,622  (0.4%, 73.4%)     0  (0.0%, 89.8%)  20  (0.7%, 23.7%)  DirectoryManager::scanDirectory(std::basic_string_view<char, std::char_traits<char> >, std::basic_string_view<char, std::char_traits<char> >):/home/sre/debugging/multi-file/DirectoryManager.cpp

>  24,600  (0.4%, 73.8%)     0  (0.0%, 89.8%)  10  (0.4%, 24.1%)  __GI__IO_un_link.part.0:./libio/./libio/genops.c

>  24,000  (0.4%, 74.2%)     0  (0.0%, 89.8%)   4  (0.1%, 24.2%)  std::__cxx11::to_string(int):
   22,000  (0.4%)            0                  4  (0.1%)           /usr/include/c++/13/bits/basic_string.h

>  23,796  (0.4%, 74.6%)     0  (0.0%, 89.8%)   6  (0.2%, 24.5%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_mutate(unsigned long, unsigned long, char const*, unsigned long):???

>  23,500  (0.4%, 75.0%)     0  (0.0%, 89.8%)   3  (0.1%, 24.6%)  std::filesystem::__cxx11::path::path<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::filesystem::__cxx11::path>(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::filesystem::__cxx11::path::format):
   21,000  (0.4%)            0                  3  (0.1%)           /usr/include/c++/13/bits/fs_path.h

>  23,100  (0.4%, 75.4%)     0  (0.0%, 89.8%)   2  (0.1%, 24.6%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&&):???

>  22,990  (0.4%, 75.8%)     5  (0.0%, 89.8%)   5  (0.2%, 24.8%)  void std::__detail::__to_chars_10_impl<unsigned int>(char*, unsigned int, unsigned int):/usr/include/c++/13/bits/charconv.h

>  22,900  (0.4%, 76.2%)     6  (0.0%, 89.9%)   5  (0.2%, 25.0%)  readdir:./dirent/../sysdeps/unix/sysv/linux/readdir64.c

>  22,080  (0.4%, 76.5%)     0  (0.0%, 89.9%)   4  (0.1%, 25.1%)  std::locale::operator=(std::locale const&):???

>  21,600  (0.4%, 76.9%)     2  (0.0%, 89.9%)   9  (0.3%, 25.5%)  fclose@@GLIBC_2.17:
   13,200  (0.2%)            0                  8  (0.3%)           ./libio/./libio/iofclose.c
    8,400  (0.1%)            2  (0.0%)          1  (0.0%)           ./libio/./libio/libioP.h

>  21,300  (0.4%, 77.3%)     1  (0.0%, 89.9%)   8  (0.3%, 25.8%)  _IO_file_fopen@@GLIBC_2.17:./libio/./libio/fileops.c

>  20,434  (0.3%, 77.6%)     0  (0.0%, 89.9%)   3  (0.1%, 25.9%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string<std::basic_string_view<char, std::char_traits<char> >, void>(std::basic_string_view<char, std::char_traits<char> > const&, std::allocator<char> const&):/usr/include/c++/13/bits/basic_string.h

>  19,500  (0.3%, 78.0%)     0  (0.0%, 89.9%)   5  (0.2%, 26.0%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::__str_concat<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::value_type const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::size_type, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::value_type const*, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::size_type, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::allocator_type const&):
   17,400  (0.3%)            0                  5  (0.2%)           /usr/include/c++/13/bits/basic_string.h

>  18,869  (0.3%, 78.3%)     1  (0.0%, 89.9%)   5  (0.2%, 26.2%)  _int_free_merge_chunk:./malloc/./malloc/malloc.c

>  18,630  (0.3%, 78.6%)     1  (0.0%, 89.9%)   2  (0.1%, 26.3%)  std::ios_base::ios_base():???

>  18,320  (0.3%, 78.9%)     0  (0.0%, 89.9%)   2  (0.1%, 26.4%)  std::basic_ios<char, std::char_traits<char> >::init(std::basic_streambuf<char, std::char_traits<char> >*):???

>  17,100  (0.3%, 79.2%)     0  (0.0%, 89.9%)   6  (0.2%, 26.6%)  _IO_file_close_it@@GLIBC_2.17:
   15,600  (0.3%)            0                  5  (0.2%)           ./libio/./libio/fileops.c

>  17,040  (0.3%, 79.5%)     0  (0.0%, 89.9%)   2  (0.1%, 26.7%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_create(unsigned long&, unsigned long):???

>  16,500  (0.3%, 79.8%)     1  (0.0%, 89.9%)   4  (0.1%, 26.8%)  std::basic_ofstream<char, std::char_traits<char> >::basic_ofstream(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, std::_Ios_Openmode):???

>  16,300  (0.3%, 80.0%)     1  (0.0%, 89.9%)  14  (0.5%, 27.3%)  std::filesystem::__cxx11::directory_iterator::directory_iterator(std::filesystem::__cxx11::path const&, std::filesystem::directory_options, std::error_code*):???

>  15,626  (0.3%, 80.3%)     0  (0.0%, 89.9%)   3  (0.1%, 27.4%)  std::unique_ptr<std::filesystem::__cxx11::path::_List::_Impl, std::filesystem::__cxx11::path::_List::_Impl_deleter>::~unique_ptr():/usr/include/c++/13/bits/unique_ptr.h

>  15,300  (0.3%, 80.6%)     1  (0.0%, 89.9%)   4  (0.1%, 27.6%)  std::ostream::write(char const*, long):???

>  15,300  (0.3%, 80.8%)     0  (0.0%, 89.9%)   4  (0.1%, 27.7%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::operator+<char, std::char_traits<char>, std::allocator<char> >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, char const*):
   14,400  (0.2%)            0                  4  (0.1%)           /usr/include/c++/13/bits/basic_string.h

>  14,947  (0.3%, 81.1%)     4  (0.0%, 90.0%)   2  (0.1%, 27.8%)  std::ostream::sentry::sentry(std::ostream&):???

>  14,500  (0.2%, 81.3%)     0  (0.0%, 90.0%)   2  (0.1%, 27.8%)  std::__shared_count<(__gnu_cxx::_Lock_policy)2>::_M_less(std::__shared_count<(__gnu_cxx::_Lock_policy)2> const&) const:/usr/include/c++/13/bits/shared_ptr_base.h

>  14,496  (0.2%, 81.6%)    14  (0.1%, 90.1%)   1  (0.0%, 27.9%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string():???

>  14,100  (0.2%, 81.8%)     0  (0.0%, 90.1%)   4  (0.1%, 28.0%)  open:./io/../sysdeps/unix/sysv/linux/open64.c

>  14,100  (0.2%, 82.0%)     0  (0.0%, 90.1%)   4  (0.1%, 28.2%)  std::basic_filebuf<char, std::char_traits<char> >::basic_filebuf():???

>  14,100  (0.2%, 82.3%)     0  (0.0%, 90.1%)   3  (0.1%, 28.3%)  std::basic_filebuf<char, std::char_traits<char> >::_M_terminate_output():???

>  13,734  (0.2%, 82.5%)   426  (3.3%, 93.4%)  10  (0.4%, 28.6%)  _dl_fixup:
   13,257  (0.2%)          425  (3.3%)          9  (0.3%)           ./elf/./elf/dl-runtime.c

>  13,500  (0.2%, 82.7%)     0  (0.0%, 93.4%)   4  (0.1%, 28.8%)  std::basic_filebuf<char, std::char_traits<char> >::_M_convert_to_external(char*, long):???

>  13,224  (0.2%, 83.0%)     0  (0.0%, 93.4%)   1  (0.0%, 28.8%)  std::filesystem::__cxx11::path::_List::_List():???

>  13,200  (0.2%, 83.2%)     1  (0.0%, 93.4%)   5  (0.2%, 29.0%)  std::filesystem::__cxx11::directory_iterator::operator++():???

>  12,972  (0.2%, 83.4%)    45  (0.4%, 93.8%)   6  (0.2%, 29.2%)  __GI___tunables_init:
   11,285  (0.2%)           44  (0.3%)          5  (0.2%)           ./elf/./elf/dl-tunables.c

>  12,958  (0.2%, 83.6%)     0  (0.0%, 93.8%)   4  (0.1%, 29.3%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::reserve(unsigned long):???

>  12,480  (0.2%, 83.8%)     0  (0.0%, 93.8%)   4  (0.1%, 29.5%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > std::operator+<char, std::char_traits<char>, std::allocator<char> >(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&&, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >&&):/usr/include/c++/13/bits/basic_string.h

>  12,144  (0.2%, 84.1%)     2  (0.0%, 93.8%)   7  (0.3%, 29.7%)  std::basic_ostream<char, std::char_traits<char> >& std::__ostream_insert<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&, char const*, long):???

>  12,000  (0.2%, 84.3%)     0  (0.0%, 93.8%)   4  (0.1%, 29.9%)  __fopen_internal:./libio/./libio/iofopen.c

>  11,700  (0.2%, 84.5%)     0  (0.0%, 93.8%)   4  (0.1%, 30.0%)  std::basic_filebuf<char, std::char_traits<char> >::open(char const*, std::_Ios_Openmode):???

>  11,700  (0.2%, 84.7%)     1  (0.0%, 93.8%)   3  (0.1%, 30.1%)  std::basic_filebuf<char, std::char_traits<char> >::xsputn(char const*, long):???

>  11,438  (0.2%, 84.8%)     0  (0.0%, 93.8%)   2  (0.1%, 30.2%)  __libc_cleanup_push_defer:./nptl/./nptl/libc-cleanup.c

>  11,208  (0.2%, 85.0%)     0  (0.0%, 93.8%)   1  (0.0%, 30.2%)  std::_V2::system_category():???

>  11,011  (0.2%, 85.2%)     0  (0.0%, 93.8%)   2  (0.1%, 30.3%)  fstatat:./io/../sysdeps/unix/sysv/linux/fstatat64.c

>  10,800  (0.2%, 85.4%)     0  (0.0%, 93.8%)   3  (0.1%, 30.4%)  std::basic_ofstream<char, std::char_traits<char> >::~basic_ofstream():???

>  10,688  (0.2%, 85.6%)     0  (0.0%, 93.8%)   8  (0.3%, 30.7%)  std::locale::_Impl::_M_install_facet(std::locale::id const*, std::locale::facet const*):???

>  10,500  (0.2%, 85.8%)     1  (0.0%, 93.8%)   4  (0.1%, 30.9%)  strstr:./string/./string/strstr.c

>  10,500  (0.2%, 85.9%)     0  (0.0%, 93.8%)   0  (0.0%, 30.9%)  std::__basic_file<char>::is_open() const:???

>  10,450  (0.2%, 86.1%)     0  (0.0%, 93.8%)   3  (0.1%, 31.0%)  unsigned int std::__detail::__to_chars_len<unsigned int>(unsigned int, int):/usr/include/c++/13/bits/charconv.h

>  10,240  (0.2%, 86.3%)     5  (0.0%, 93.8%)   5  (0.2%, 31.1%)  btowc:
    9,728  (0.2%)            4  (0.0%)          5  (0.2%)           ./wcsmbs/./wcsmbs/btowc.c

>  10,232  (0.2%, 86.5%)     0  (0.0%, 93.8%)   2  (0.1%, 31.2%)  __libc_cleanup_pop_restore:./nptl/./nptl/libc-cleanup.c

>  10,200  (0.2%, 86.6%)    77  (0.6%, 94.5%)  19  (0.7%, 31.9%)  _dl_check_map_versions:
   10,038  (0.2%)           77  (0.6%)         16  (0.6%)           ./elf/./elf/dl-version.c

>  10,200  (0.2%, 86.8%)     0  (0.0%, 94.5%)   0  (0.0%, 31.9%)  std::filesystem::file_status::type() const:/usr/include/c++/13/bits/fs_dir.h

>  10,000  (0.2%, 87.0%)     2  (0.0%, 94.5%)   5  (0.2%, 32.1%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_assign(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&):???

>   9,999  (0.2%, 87.2%)     0  (0.0%, 94.5%)   3  (0.1%, 32.2%)  _int_free_create_chunk:./malloc/./malloc/malloc.c

>   9,600  (0.2%, 87.3%)     0  (0.0%, 94.5%)   4  (0.1%, 32.3%)  _IO_file_open:./libio/./libio/fileops.c

>   9,380  (0.2%, 87.5%)     0  (0.0%, 94.5%)   4  (0.1%, 32.5%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct(unsigned long, char):???

>   9,000  (0.2%, 87.6%)     0  (0.0%, 94.5%)   2  (0.1%, 32.5%)  std::__basic_file<char>::close():???

>   9,000  (0.2%, 87.8%)     0  (0.0%, 94.5%)   1  (0.0%, 32.6%)  std::filesystem::exists(std::filesystem::file_status):/usr/include/c++/13/bits/fs_ops.h

>   8,932  (0.2%, 87.9%)     0  (0.0%, 94.5%)   2  (0.1%, 32.7%)  std::ios_base::~ios_base():???

>   8,800  (0.1%, 88.1%)     0  (0.0%, 94.5%)   2  (0.1%, 32.7%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string<std::allocator<char> >(unsigned long, char, std::allocator<char> const&):/usr/include/c++/13/bits/basic_string.h

>   8,544  (0.1%, 88.2%)     6  (0.0%, 94.5%)   2  (0.1%, 32.8%)  __aarch64_cas4_acq:???

>   8,532  (0.1%, 88.4%)     2  (0.0%, 94.5%)   8  (0.3%, 33.1%)  _IO_file_xsputn@@GLIBC_2.17:
    8,477  (0.1%)            2  (0.0%)          7  (0.3%)           ./libio/./libio/fileops.c

>   8,500  (0.1%, 88.5%)     0  (0.0%, 94.5%)   7  (0.3%, 33.3%)  std::ostreambuf_iterator<char, std::char_traits<char> > std::num_put<char, std::ostreambuf_iterator<char, std::char_traits<char> > >::_M_insert_int<unsigned long>(std::ostreambuf_iterator<char, std::char_traits<char> >, std::ios_base&, char, unsigned long) const:???

>   8,500  (0.1%, 88.7%)     0  (0.0%, 94.5%)   2  (0.1%, 33.4%)  std::less<std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>*>::operator()(std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>*, std::_Sp_counted_base<(__gnu_cxx::_Lock_policy)2>*) const:/usr/include/c++/13/bits/stl_function.h

>   8,206  (0.1%, 88.8%)     3  (0.0%, 94.6%)   7  (0.3%, 33.7%)  pthread_mutex_lock@@GLIBC_2.17:./nptl/./nptl/pthread_mutex_lock.c

>   8,100  (0.1%, 88.9%)     0  (0.0%, 94.6%)   3  (0.1%, 33.8%)  std::__basic_file<char>::open(char const*, std::_Ios_Openmode, int):???

>   8,100  (0.1%, 89.1%)     0  (0.0%, 94.6%)   2  (0.1%, 33.8%)  std::filesystem::__cxx11::path::has_filename() const:???

>   8,040  (0.1%, 89.2%)     0  (0.0%, 94.6%)   1  (0.0%, 33.9%)  std::__new_allocator<char>::~__new_allocator():/usr/include/c++/13/bits/new_allocator.h

>   8,008  (0.1%, 89.4%)     0  (0.0%, 94.6%)   1  (0.0%, 33.9%)  stat:./io/../sysdeps/unix/sysv/linux/stat64.c

>   7,500  (0.1%, 89.5%)     1  (0.0%, 94.6%)   6  (0.2%, 34.1%)  std::ostream& std::ostream::_M_insert<unsigned long>(unsigned long):???

>   7,500  (0.1%, 89.6%)     0  (0.0%, 94.6%)   2  (0.1%, 34.2%)  _IO_old_init:./libio/./libio/genops.c

>   7,448  (0.1%, 89.7%)     0  (0.0%, 94.6%)  10  (0.4%, 34.6%)  std::__cxx11::basic_stringbuf<char, std::char_traits<char>, std::allocator<char> >::overflow(int):???

>   7,400  (0.1%, 89.9%)     0  (0.0%, 94.6%)   1  (0.0%, 34.6%)  std::filesystem::__cxx11::operator==(std::filesystem::__cxx11::directory_iterator const&, std::filesystem::__cxx11::directory_iterator const&):/usr/include/c++/13/bits/fs_dir.h

>   7,361  (0.1%, 90.0%)     0  (0.0%, 94.6%)   5  (0.2%, 34.8%)  __pthread_mutex_unlock_usercnt:./nptl/./nptl/pthread_mutex_unlock.c

>   7,350  (0.1%, 90.1%)     0  (0.0%, 94.6%)   1  (0.0%, 34.8%)  __aarch64_swp4_rel:???

>   7,346  (0.1%, 90.2%)     0  (0.0%, 94.6%)   6  (0.2%, 35.0%)  std::ostream::put(char):???

>   7,200  (0.1%, 90.4%)     0  (0.0%, 94.6%)   3  (0.1%, 35.1%)  std::__basic_file<char>::xsputn(char const*, long):???

>   7,000  (0.1%, 90.5%)     0  (0.0%, 94.6%)   6  (0.2%, 35.3%)  scanDirectories(DirectoryManager&):/home/sre/debugging/multi-file/main.cpp

>   7,000  (0.1%, 90.6%)     0  (0.0%, 94.6%)   2  (0.1%, 35.4%)  bool std::__shared_ptr<std::filesystem::__cxx11::_Dir, (__gnu_cxx::_Lock_policy)2>::owner_before<std::filesystem::__cxx11::_Dir>(std::__shared_ptr<std::filesystem::__cxx11::_Dir, (__gnu_cxx::_Lock_policy)2> const&) const:/usr/include/c++/13/bits/shared_ptr_base.h

>   6,900  (0.1%, 90.7%)     0  (0.0%, 94.6%)   2  (0.1%, 35.5%)  _IO_no_init:./libio/./libio/genops.c

>   6,700  (0.1%, 90.8%)     2  (0.0%, 94.6%)   5  (0.2%, 35.7%)  std::__cxx11::basic_stringstream<char, std::char_traits<char>, std::allocator<char> >::basic_stringstream():???

>   6,611  (0.1%, 90.9%)     0  (0.0%, 94.6%)   1  (0.0%, 35.7%)  std::filesystem::__cxx11::path::~path():/usr/include/c++/13/bits/fs_path.h

>   6,600  (0.1%, 91.1%)     0  (0.0%, 94.6%)   3  (0.1%, 35.8%)  __fcntl64_nocancel:./io/../sysdeps/unix/sysv/linux/fcntl_nocancel.c

>   6,513  (0.1%, 91.2%)     0  (0.0%, 94.6%)   2  (0.1%, 35.9%)  std::char_traits<char>::length(char const*):/usr/include/c++/13/bits/char_traits.h

>   6,466  (0.1%, 91.3%)     0  (0.0%, 94.6%)   1  (0.0%, 35.9%)  operator delete(void*):???

>   6,321  (0.1%, 91.4%)     0  (0.0%, 94.6%)   2  (0.1%, 36.0%)  _IO_setb:./libio/./libio/genops.c

>   6,200  (0.1%, 91.5%)     5  (0.0%, 94.6%)   5  (0.2%, 36.2%)  index:./string/../sysdeps/aarch64/strchr.S

>   6,000  (0.1%, 91.6%)     0  (0.0%, 94.6%)   2  (0.1%, 36.2%)  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::append(char const*):???

>   6,000  (0.1%, 91.7%)     0  (0.0%, 94.6%)   1  (0.0%, 36.3%)  std::basic_filebuf<char, std::char_traits<char> >::_M_destroy_internal_buffer():???

--------------------------------------------------------------------------------
-- Annotated source file: ./dirent/../sysdeps/unix/sysv/linux/readdir64.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./dirent/../sysdeps/unix/sysv/linux/readdir64.c

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/../sysdeps/aarch64/dl-machine.h
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/../sysdeps/aarch64/dl-machine.h

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/../sysdeps/generic/dl-new-hash.h
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/../sysdeps/generic/dl-new-hash.h

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/../sysdeps/generic/dl-protected.h
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/../sysdeps/generic/dl-protected.h

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/../sysdeps/generic/ldsodefs.h
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/../sysdeps/generic/ldsodefs.h

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/./elf/dl-lookup.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/./elf/dl-lookup.c

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/./elf/dl-reloc.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/./elf/dl-reloc.c

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/./elf/dl-runtime.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/./elf/dl-runtime.c

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/./elf/dl-tunables.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/./elf/dl-tunables.c

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/./elf/dl-version.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/./elf/dl-version.c

--------------------------------------------------------------------------------
-- Annotated source file: ./elf/./elf/do-rel.h
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./elf/./elf/do-rel.h

--------------------------------------------------------------------------------
-- Annotated source file: ./io/../sysdeps/unix/sysv/linux/fcntl_nocancel.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./io/../sysdeps/unix/sysv/linux/fcntl_nocancel.c

--------------------------------------------------------------------------------
-- Annotated source file: ./io/../sysdeps/unix/sysv/linux/fstatat64.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./io/../sysdeps/unix/sysv/linux/fstatat64.c

--------------------------------------------------------------------------------
-- Annotated source file: ./io/../sysdeps/unix/sysv/linux/open64.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./io/../sysdeps/unix/sysv/linux/open64.c

--------------------------------------------------------------------------------
-- Annotated source file: ./io/../sysdeps/unix/sysv/linux/stat64.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./io/../sysdeps/unix/sysv/linux/stat64.c

--------------------------------------------------------------------------------
-- Annotated source file: ./libio/./libio/fileops.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./libio/./libio/fileops.c

--------------------------------------------------------------------------------
-- Annotated source file: ./libio/./libio/genops.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./libio/./libio/genops.c

--------------------------------------------------------------------------------
-- Annotated source file: ./libio/./libio/iofclose.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./libio/./libio/iofclose.c

--------------------------------------------------------------------------------
-- Annotated source file: ./libio/./libio/iofopen.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./libio/./libio/iofopen.c

--------------------------------------------------------------------------------
-- Annotated source file: ./libio/./libio/libioP.h
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./libio/./libio/libioP.h

--------------------------------------------------------------------------------
-- Annotated source file: ./malloc/./malloc/arena.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./malloc/./malloc/arena.c

--------------------------------------------------------------------------------
-- Annotated source file: ./malloc/./malloc/malloc.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./malloc/./malloc/malloc.c

--------------------------------------------------------------------------------
-- Annotated source file: ./nptl/./nptl/libc-cleanup.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./nptl/./nptl/libc-cleanup.c

--------------------------------------------------------------------------------
-- Annotated source file: ./nptl/./nptl/pthread_mutex_lock.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./nptl/./nptl/pthread_mutex_lock.c

--------------------------------------------------------------------------------
-- Annotated source file: ./nptl/./nptl/pthread_mutex_unlock.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./nptl/./nptl/pthread_mutex_unlock.c

--------------------------------------------------------------------------------
-- Annotated source file: ./string/../sysdeps/aarch64/multiarch/../memchr.S
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./string/../sysdeps/aarch64/multiarch/../memchr.S

--------------------------------------------------------------------------------
-- Annotated source file: ./string/../sysdeps/aarch64/multiarch/../memcpy.S
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./string/../sysdeps/aarch64/multiarch/../memcpy.S

--------------------------------------------------------------------------------
-- Annotated source file: ./string/../sysdeps/aarch64/multiarch/strlen_asimd.S
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./string/../sysdeps/aarch64/multiarch/strlen_asimd.S

--------------------------------------------------------------------------------
-- Annotated source file: ./string/../sysdeps/aarch64/nptl/../memset.S
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./string/../sysdeps/aarch64/nptl/../memset.S

--------------------------------------------------------------------------------
-- Annotated source file: ./string/../sysdeps/aarch64/strchr.S
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./string/../sysdeps/aarch64/strchr.S

--------------------------------------------------------------------------------
-- Annotated source file: ./string/../sysdeps/aarch64/strcmp.S
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./string/../sysdeps/aarch64/strcmp.S

--------------------------------------------------------------------------------
-- Annotated source file: ./string/./string/strstr.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./string/./string/strstr.c

--------------------------------------------------------------------------------
-- Annotated source file: ./wcsmbs/./wcsmbs/btowc.c
--------------------------------------------------------------------------------
Unannotated because one or more of these original files are unreadable:
- ./wcsmbs/./wcsmbs/btowc.c

--------------------------------------------------------------------------------
-- Annotated source file: /home/sre/debugging/multi-file/DirectoryManager.cpp
--------------------------------------------------------------------------------
Ir__________ D1mr ILmr____ 

-- line 3 ----------------------------------------
    .           . .         #include <fstream>
    .           . .         #include <iostream>
    .           . .         #include <mutex>
    .           . .         #include <sstream>
    .           . .         #include "DirectoryManager.hpp"
    .           . .         
    .           . .         std::mutex cout_mutex;
    .           . .         
   14 (0.0%)    0 2 (0.1%)  DirectoryManager::DirectoryManager(const std::string& base_path) {
   14 (0.0%)    0 1 (0.0%)      if (base_path.empty() || base_path.size() > sizeof(base_path_) - 1) {
    .           . .                 throw std::invalid_argument("Invalid path: " + base_path);
    .           . .             }
    7 (0.0%)    0 1 (0.0%)      strncpy(base_path_, base_path.c_str(), sizeof(base_path_) - 1);
    2 (0.0%)    0 1 (0.0%)      base_path_[sizeof(base_path_) - 1] = '\0';
    2 (0.0%)    0 0             dir_count_ = 0;
    2 (0.0%)    0 0             file_count_ = 0;
   12 (0.0%)    0 1 (0.0%)  }
    .           . .         
1,200 (0.0%)    0 1 (0.0%)  void DirectoryManager::scanDirectory(std::string_view path, std::string_view thread_name) {
    .           . .             try {
  400 (0.0%)    0 0                 std::filesystem::path p(path);
2,590 (0.0%)    0 2 (0.1%)          bool verbose = (path == "/tmp/test0" || path == "/tmp/test99");
  400 (0.0%)    0 0                 if (verbose) {
   10 (0.0%)    0 0                     std::lock_guard<std::mutex> lock(cout_mutex);
   32 (0.0%)    0 1 (0.0%)              std::cout << thread_name << ": Scanning path: " << path << "\n";
    4 (0.0%)    0 0                 }
  800 (0.0%)    0 1 (0.0%)          if (!std::filesystem::exists(p)) {
    .           . .                     std::lock_guard<std::mutex> lock(cout_mutex);
    .           . .                     std::cerr << thread_name << ": Directory does not exist: " << path << "\n";
    .           . .                     return;
    .           . .                 }
  800 (0.0%)    0 2 (0.1%)          if (!std::filesystem::is_directory(p)) {
    .           . .                     std::lock_guard<std::mutex> lock(cout_mutex);
    .           . .                     std::cerr << thread_name << ": Path is not a directory: " << path << "\n";
    .           . .                     return;
    .           . .                 }
  200 (0.0%)    0 2 (0.1%)          int local_dir_count = 0, local_file_count = 0;
6,200 (0.1%)    0 2 (0.1%)          for (auto it = std::filesystem::directory_iterator(p); it != std::filesystem::directory_iterator(); ++it) {
1,200 (0.0%)    0 0                     auto status = it->status();
2,700 (0.0%)    0 1 (0.0%)              if (status.type() == std::filesystem::file_type::directory) {
    .           . .                         local_dir_count++;
2,700 (0.0%)    0 0                     } else if (status.type() == std::filesystem::file_type::regular) {
  900 (0.0%)    0 1 (0.0%)                  local_file_count++;
1,200 (0.0%)    0 0                         if (verbose) {
   30 (0.0%)    0 0                             std::lock_guard<std::mutex> lock(cout_mutex);
  126 (0.0%)    0 1 (0.0%)                      std::cout << thread_name << ": Found file: " << it->path() << "\n";
   12 (0.0%)    0 0                         }
    .           . .                     }
  200 (0.0%)    0 0                 }
    .           . .                 {
  400 (0.0%)    0 0                     std::lock_guard<std::mutex> lock(count_mutex_);
  600 (0.0%)    0 0                     dir_count_ += local_dir_count;
  600 (0.0%)    0 1 (0.0%)              file_count_ += local_file_count;
  400 (0.0%)    0 0                     if (verbose) {
   10 (0.0%)    0 0                         std::lock_guard<std::mutex> cout_lock(cout_mutex);
   32 (0.0%)    0 1 (0.0%)                  std::cout << thread_name << ": Scanned " << path << ", dirs: " << local_dir_count
   30 (0.0%)    0 1 (0.0%)                            << ", files: " << local_file_count << ", total dirs: " << dir_count_
   42 (0.0%)    0 1 (0.0%)                            << ", total files: " << file_count_ << "\n";
    4 (0.0%)    0 1 (0.0%)              }
  200 (0.0%)    0 0                 }
  400 (0.0%)    0 0             } catch (const std::filesystem::filesystem_error& e) {
    .           . .                 std::lock_guard<std::mutex> lock(cout_mutex);
    .           . .                 std::ofstream log("/tmp/errors.log", std::ios::app);
    .           . .                 log << thread_name << ": Filesystem error: " << e.what() << "\n";
    .           . .                 log.close();
    .           . .                 std::cerr << thread_name << ": Filesystem error: " << e.what() << "\n";
    .           . .         
    .           . .             } catch (const std::exception& e) {
    .           . .                 std::lock_guard<std::mutex> lock(cout_mutex);
    .           . .                 std::ofstream log("/tmp/errors.log", std::ios::app);
    .           . .                 log << thread_name << ": Exception: " << e.what() << "\n";
    .           . .                 log.close();
    .           . .                 std::cerr << thread_name << ": Exception: " << e.what() << "\n";
    .           . .             }
1,200 (0.0%)    0 1 (0.0%)  }

--------------------------------------------------------------------------------
-- Annotated source file: /home/sre/debugging/multi-file/main.cpp
--------------------------------------------------------------------------------
Ir__________ D1mr____ ILmr____ 

-- line 6 ----------------------------------------
    .        .        .         #include <mutex>
    .        .        .         #include <queue>
    .        .        .         #include <sstream>
    .        .        .         #include <string>
    .        .        .         #include <thread>
    .        .        .         #include <vector>
    .        .        .         #include "DirectoryManager.hpp"
    .        .        .         
   10 (0.0%) 0        0         std::queue<std::string> paths;
    .        .        .         std::mutex mutex;
    .        .        .         
   22 (0.0%) 0        1 (0.0%)  void scanDirectories(DirectoryManager& manager) {
    .        .        .             while (true) {
  204 (0.0%) 0        0                 std::string path;
    .        .        .                 {
  510 (0.0%) 0        0                     std::lock_guard<std::mutex> lock(mutex);
  718 (0.0%) 0        1 (0.0%)              if (paths.empty()) break;
  600 (0.0%) 0        0                     path = paths.front();
  300 (0.0%) 0        0                     paths.pop();
  608 (0.0%) 0        1 (0.0%)          }
  304 (0.0%) 0        0                 std::stringstream thread_name;
1,100 (0.0%) 0        1 (0.0%)          thread_name << "Thread-" << std::this_thread::get_id();
1,800 (0.0%) 0        1 (0.0%)          manager.scanDirectory(path, thread_name.str());
  808 (0.0%) 0        0             }
   26 (0.0%) 0        1 (0.0%)  }
    .        .        .         
    9 (0.0%) 0        1 (0.0%)  int main() {
   10 (0.0%) 0        1 (0.0%)      std::filesystem::remove_all("/tmp/test");
    8 (0.0%) 0        0             std::cout << "Cleared /tmp/test directories" << std::endl;
    .        .        .         
    2 (0.0%) 0        1 (0.0%)      std::vector<std::string> directories;
    3 (0.0%) 0        0             directories.reserve(100);
  605 (0.0%) 0        1 (0.0%)      for (int i = 0; i < 100; ++i) {
1,300 (0.0%) 0        1 (0.0%)          std::string path = "/tmp/test" + std::to_string(i);
    .        .        .                 try {
  800 (0.0%) 0        0                     std::filesystem::create_directory(path);
1,400 (0.0%) 0        1 (0.0%)              if (!std::filesystem::exists(path)) {
    .        .        .                         std::cerr << "Failed to create directory " << path << std::endl;
    .        .        .                         continue;
    .        .        .                     }
  597 (0.0%) 0        1 (0.0%)              if (i == 0 || i == 99) {
   36 (0.0%) 0        1 (0.0%)                  std::cout << "Created directory: \"" << path << "\"" << std::endl;
    .        .        .                     }
2,300 (0.0%) 1 (0.0%) 2 (0.1%)              for (int j = 0; j < 3; ++j) {
8,700 (0.1%) 0        1 (0.0%)                  std::string file_path = path + "/file" + std::to_string(j) + ".txt";
2,100 (0.0%) 0        1 (0.0%)                  std::ofstream file(file_path, std::ios::out | std::ios::binary);
2,100 (0.0%) 0        0                         if (!file) {
    .        .        .                             std::cerr << "Failed to open " << file_path << ": " << strerror(errno) << std::endl;
    .        .        .                             continue;
    .        .        .                         }
1,800 (0.0%) 0        1 (0.0%)                  file.write("Test content", 12); 
  600 (0.0%) 0        0                         file.close();
4,200 (0.1%) 0        1 (0.0%)                  if (!std::filesystem::exists(file_path)) {
    .        .        .                             std::cerr << "Failed to create " << file_path << ": " << strerror(errno) << std::endl;
1,791 (0.0%) 0        1 (0.0%)                  } else if (i == 0 || i == 99) {
  108 (0.0%) 0        1 (0.0%)                      std::cout << "Created file: \"" << file_path << "\"" << std::endl;
    .        .        .                         }
3,000 (0.1%) 0        0                     }
    .        .        .                 } catch (const std::filesystem::filesystem_error& e) {
    .        .        .                     std::cerr << "Error creating directory " << path << ": " << e.what() << std::endl;
    .        .        .                 }
  500 (0.0%) 0        0                 directories.emplace_back(std::move(path));
  400 (0.0%) 0        0             }
    8 (0.0%) 0        1 (0.0%)      std::cout << "Directory creation completed. Starting threads..." << std::endl;
    .        .        .         
1,218 (0.0%) 0        2 (0.1%)      for (auto& p : directories) {
  600 (0.0%) 0        0                 paths.push(std::move(p));
    .        .        .             }
    .        .        .         
   12 (0.0%) 0        1 (0.0%)      DirectoryManager manager("/tmp");
    2 (0.0%) 0        0             std::vector<std::thread> workers;
   17 (0.0%) 0        1 (0.0%)      for (int i = 0; i < 2; ++i) {
   20 (0.0%) 0        0                 workers.emplace_back(scanDirectories, std::ref(manager));
    .        .        .             }
   40 (0.0%) 0        2 (0.1%)      for (auto& w : workers) {
    4 (0.0%) 0        0                 w.join();
    .        .        .             }
    6 (0.0%) 0        0             std::cout << "Main completed. Total dirs: " << manager.getDirCount()
   19 (0.0%) 0        1 (0.0%)                << ", Total files: " << manager.getFileCount() << std::endl;
    1 (0.0%) 0        0             return 0;
   27 (0.0%) 1 (0.0%) 4 (0.1%)  }

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/basic_string.h
--------------------------------------------------------------------------------
Ir___________ D1mr ILmr____ 

-- line 347 ----------------------------------------
     .           . .               void
     .           . .               _M_init_local_buf() _GLIBCXX_NOEXCEPT
     .           . .               {
     .           . .         #if __cpp_lib_is_constant_evaluated
     .           . .         	if (std::is_constant_evaluated())
     .           . .         	  for (size_type __i = 0; __i <= _S_local_capacity; ++__i)
     .           . .         	    _M_local_buf[__i] = _CharT();
     .           . .         #endif
     1 (0.0%)    0 0               }
     .           . .         
     .           . .               __attribute__((__always_inline__))
     .           . .               _GLIBCXX14_CONSTEXPR
     .           . .               pointer
     .           . .               _M_use_local_data() _GLIBCXX_NOEXCEPT
     .           . .               {
     .           . .         #if __cpp_lib_is_constant_evaluated
     .           . .         	_M_init_local_buf();
-- line 363 ----------------------------------------
-- line 633 ----------------------------------------
     .           . .                *  @param  __a  Allocator to use (default is default allocator).
     .           . .                */
     .           . .         #if __cpp_deduction_guides && ! defined _GLIBCXX_DEFINING_STRING_INSTANTIATIONS
     .           . .               // _GLIBCXX_RESOLVE_LIB_DEFECTS
     .           . .               // 3076. basic_string CTAD ambiguity
     .           . .               template<typename = _RequireAllocator<_Alloc>>
     .           . .         #endif
     .           . .               _GLIBCXX20_CONSTEXPR
     6 (0.0%)    0 1 (0.0%)        basic_string(const _CharT* __s, const _Alloc& __a = _Alloc())
     7 (0.0%)    0 0               : _M_dataplus(_M_local_data(), __a)
     .           . .               {
     .           . .         	// NB: Not required, but considered best practice.
     3 (0.0%)    0 0         	if (__s == 0)
     .           . .         	  std::__throw_logic_error(__N("basic_string: "
     .           . .         				       "construction from null is not valid"));
     6 (0.0%)    0 1 (0.0%)  	const _CharT* __end = __s + traits_type::length(__s);
     5 (0.0%)    0 0         	_M_construct(__s, __end, forward_iterator_tag());
     4 (0.0%)    0 0               }
     .           . .         
     .           . .               /**
     .           . .                *  @brief  Construct string as multiple characters.
     .           . .                *  @param  __n  Number of characters.
     .           . .                *  @param  __c  Character to use.
     .           . .                *  @param  __a  Allocator to use (default is default allocator).
     .           . .                */
     .           . .         #if __cpp_deduction_guides && ! defined _GLIBCXX_DEFINING_STRING_INSTANTIATIONS
     .           . .               // _GLIBCXX_RESOLVE_LIB_DEFECTS
     .           . .               // 3076. basic_string CTAD ambiguity
     .           . .               template<typename = _RequireAllocator<_Alloc>>
     .           . .         #endif
     .           . .               _GLIBCXX20_CONSTEXPR
 2,800 (0.0%)    0 1 (0.0%)        basic_string(size_type __n, _CharT __c, const _Alloc& __a = _Alloc())
 2,800 (0.0%)    0 0               : _M_dataplus(_M_local_data(), __a)
 3,200 (0.1%)    0 1 (0.0%)        { _M_construct(__n, __c); }
     .           . .         
     .           . .         #if __cplusplus >= 201103L
     .           . .               /**
     .           . .                *  @brief  Move construct string.
     .           . .                *  @param  __str  Source string.
     .           . .                *
     .           . .                *  The newly-created string contains the exact contents of @a __str.
     .           . .                *  @a __str is a valid, but unspecified string.
-- line 674 ----------------------------------------
-- line 787 ----------------------------------------
     .           . .               /**
     .           . .                *  @brief  Construct string from a string_view.
     .           . .                *  @param  __t  Source object convertible to string view.
     .           . .                *  @param  __a  Allocator to use (default is default allocator).
     .           . .                */
     .           . .               template<typename _Tp, typename = _If_sv<_Tp, void>>
     .           . .         	_GLIBCXX20_CONSTEXPR
     .           . .         	explicit
 6,611 (0.1%)    0 1 (0.0%)  	basic_string(const _Tp& __t, const _Alloc& __a = _Alloc())
13,823 (0.2%)    0 2 (0.1%)  	: basic_string(__sv_wrapper(_S_to_string_view(__t)), __a) { }
     .           . .         #endif // C++17
     .           . .         
     .           . .               /**
     .           . .                *  @brief  Destroy the string instance.
     .           . .                */
     .           . .               _GLIBCXX20_CONSTEXPR
     .           . .               ~basic_string()
     .           . .               { _M_dispose(); }
-- line 804 ----------------------------------------
-- line 3520 ----------------------------------------
     .           . .         		 const _Allocator& = _Allocator())
     .           . .               -> basic_string<_CharT, _Traits, _Allocator>;
     .           . .         _GLIBCXX_END_NAMESPACE_CXX11
     .           . .         #endif
     .           . .         
     .           . .           template<typename _Str>
     .           . .             _GLIBCXX20_CONSTEXPR
     .           . .             inline _Str
 8,100 (0.1%)    0 2 (0.1%)      __str_concat(typename _Str::value_type const* __lhs,
     .           . .         		 typename _Str::size_type __lhs_len,
     .           . .         		 typename _Str::value_type const* __rhs,
     .           . .         		 typename _Str::size_type __rhs_len,
     .           . .         		 typename _Str::allocator_type const& __a)
     .           . .             {
     .           . .               typedef typename _Str::allocator_type allocator_type;
     .           . .               typedef __gnu_cxx::__alloc_traits<allocator_type> _Alloc_traits;
 1,200 (0.0%)    0 0               _Str __str(_Alloc_traits::_S_select_on_copy(__a));
 1,800 (0.0%)    0 1 (0.0%)        __str.reserve(__lhs_len + __rhs_len);
 1,200 (0.0%)    0 0               __str.append(__lhs, __lhs_len);
 1,200 (0.0%)    0 0               __str.append(__rhs, __rhs_len);
   300 (0.0%)    0 0               return __str;
 3,600 (0.1%)    0 2 (0.1%)      }
     .           . .         
     .           . .           // operator+
     .           . .           /**
     .           . .            *  @brief  Concatenate two strings.
     .           . .            *  @param __lhs  First string.
     .           . .            *  @param __rhs  Last string.
     .           . .            *  @return  New string with value of @a __lhs followed by @a __rhs.
     .           . .            */
-- line 3549 ----------------------------------------
-- line 3599 ----------------------------------------
     .           . .            *  @brief  Concatenate string and C string.
     .           . .            *  @param __lhs  First string.
     .           . .            *  @param __rhs  Last string.
     .           . .            *  @return  New string with @a __lhs followed by @a __rhs.
     .           . .            */
     .           . .           template<typename _CharT, typename _Traits, typename _Alloc>
     .           . .             _GLIBCXX_NODISCARD _GLIBCXX20_CONSTEXPR
     .           . .             inline basic_string<_CharT, _Traits, _Alloc>
 3,900 (0.1%)    0 1 (0.0%)      operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     .           . .         	      const _CharT* __rhs)
     .           . .             {
     .           . .               __glibcxx_requires_string(__rhs);
     .           . .               typedef basic_string<_CharT, _Traits, _Alloc> _Str;
     .           . .               return std::__str_concat<_Str>(__lhs.c_str(), __lhs.size(),
     .           . .         				     __rhs, _Traits::length(__rhs),
 6,600 (0.1%)    0 1 (0.0%)  				     __lhs.get_allocator());
 3,900 (0.1%)    0 2 (0.1%)      }
     .           . .           /**
     .           . .            *  @brief  Concatenate string and character.
     .           . .            *  @param __lhs  First string.
     .           . .            *  @param __rhs  Last string.
     .           . .            *  @return  New string with @a __lhs followed by @a __rhs.
     .           . .            */
     .           . .           template<typename _CharT, typename _Traits, typename _Alloc>
     .           . .             _GLIBCXX_NODISCARD _GLIBCXX20_CONSTEXPR
-- line 3623 ----------------------------------------
-- line 3643 ----------------------------------------
     .           . .             inline basic_string<_CharT, _Traits, _Alloc>
     .           . .             operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
     .           . .         	      basic_string<_CharT, _Traits, _Alloc>&& __rhs)
     .           . .             { return std::move(__rhs.insert(0, __lhs)); }
     .           . .         
     .           . .           template<typename _CharT, typename _Traits, typename _Alloc>
     .           . .             _GLIBCXX_NODISCARD _GLIBCXX20_CONSTEXPR
     .           . .             inline basic_string<_CharT, _Traits, _Alloc>
 1,800 (0.0%)    0 0             operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
     .           . .         	      basic_string<_CharT, _Traits, _Alloc>&& __rhs)
     .           . .             {
     .           . .         #if _GLIBCXX_USE_CXX11_ABI
     .           . .               using _Alloc_traits = allocator_traits<_Alloc>;
   300 (0.0%)    0 0               bool __use_rhs = false;
     .           . .               if _GLIBCXX17_CONSTEXPR (typename _Alloc_traits::is_always_equal{})
   600 (0.0%)    0 1 (0.0%)  	__use_rhs = true;
     .           . .               else if (__lhs.get_allocator() == __rhs.get_allocator())
     .           . .         	__use_rhs = true;
 1,200 (0.0%)    0 0               if (__use_rhs)
     .           . .         #endif
     .           . .         	{
 2,100 (0.0%)    0 0         	  const auto __size = __lhs.size() + __rhs.size();
 3,180 (0.1%)    0 1 (0.0%)  	  if (__size > __lhs.capacity() && __size <= __rhs.capacity())
     .           . .         	    return std::move(__rhs.insert(0, __lhs));
     .           . .         	}
 2,100 (0.0%)    0 1 (0.0%)        return std::move(__lhs.append(__rhs));
 1,200 (0.0%)    0 1 (0.0%)      }
     .           . .         
     .           . .           template<typename _CharT, typename _Traits, typename _Alloc>
     .           . .             _GLIBCXX_NODISCARD _GLIBCXX_NODISCARD _GLIBCXX20_CONSTEXPR
     .           . .             inline basic_string<_CharT, _Traits, _Alloc>
   600 (0.0%)    0 0             operator+(const _CharT* __lhs,
     .           . .         	      basic_string<_CharT, _Traits, _Alloc>&& __rhs)
 1,200 (0.0%)    0 0             { return std::move(__rhs.insert(0, __lhs)); }
     .           . .         
     .           . .           template<typename _CharT, typename _Traits, typename _Alloc>
     .           . .             _GLIBCXX_NODISCARD _GLIBCXX20_CONSTEXPR
     .           . .             inline basic_string<_CharT, _Traits, _Alloc>
     .           . .             operator+(_CharT __lhs,
     .           . .         	      basic_string<_CharT, _Traits, _Alloc>&& __rhs)
     .           . .             { return std::move(__rhs.insert(0, 1, __lhs)); }
     .           . .         
     .           . .           template<typename _CharT, typename _Traits, typename _Alloc>
     .           . .             _GLIBCXX_NODISCARD _GLIBCXX20_CONSTEXPR
     .           . .             inline basic_string<_CharT, _Traits, _Alloc>
 1,800 (0.0%)    0 0             operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
     .           . .         	      const _CharT* __rhs)
 3,300 (0.1%)    0 1 (0.0%)      { return std::move(__lhs.append(__rhs)); }
     .           . .         
     .           . .           template<typename _CharT, typename _Traits, typename _Alloc>
     .           . .             _GLIBCXX_NODISCARD _GLIBCXX20_CONSTEXPR
     .           . .             inline basic_string<_CharT, _Traits, _Alloc>
     .           . .             operator+(basic_string<_CharT, _Traits, _Alloc>&& __lhs,
     .           . .         	      _CharT __rhs)
     .           . .             { return std::move(__lhs.append(1, __rhs)); }
     .           . .         #endif
-- line 3698 ----------------------------------------
-- line 4158 ----------------------------------------
     .           . .           // DR 1261. Insufficent overloads for to_string / to_wstring
     .           . .         
     .           . .           _GLIBCXX_NODISCARD
     .           . .           inline string
     .           . .           to_string(int __val)
     .           . .         #if _GLIBCXX_USE_CXX11_ABI && (__CHAR_BIT__ * __SIZEOF_INT__) <= 32
     .           . .           noexcept // any 32-bit value fits in the SSO buffer
     .           . .         #endif
 4,400 (0.1%)    0 0           {
 1,200 (0.0%)    0 1 (0.0%)      const bool __neg = __val < 0;
 2,400 (0.0%)    0 0             const unsigned __uval = __neg ? (unsigned)~__val + 1u : __val;
 1,600 (0.0%)    0 0             const auto __len = __detail::__to_chars_len(__uval);
 4,400 (0.1%)    0 1 (0.0%)      string __str(__neg + __len, '-');
 2,800 (0.0%)    0 1 (0.0%)      __detail::__to_chars_10_impl(&__str[__neg], __len, __uval);
   400 (0.0%)    0 0             return __str;
 4,800 (0.1%)    0 1 (0.0%)    }
     .           . .         
     .           . .           _GLIBCXX_NODISCARD
     .           . .           inline string
     .           . .           to_string(unsigned __val)
     .           . .         #if _GLIBCXX_USE_CXX11_ABI && (__CHAR_BIT__ * __SIZEOF_INT__) <= 32
     .           . .           noexcept // any 32-bit value fits in the SSO buffer
     .           . .         #endif
     .           . .           {
-- line 4181 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/char_traits.h
--------------------------------------------------------------------------------
Ir__________ D1mr ILmr____ 

-- line 366 ----------------------------------------
    .           . .               lt(const char_type& __c1, const char_type& __c2) _GLIBCXX_NOEXCEPT
    .           . .               {
    .           . .         	// LWG 467.
    .           . .         	return (static_cast<unsigned char>(__c1)
    .           . .         		< static_cast<unsigned char>(__c2));
    .           . .               }
    .           . .         
    .           . .               static _GLIBCXX17_CONSTEXPR int
  500 (0.0%)    0 2 (0.1%)        compare(const char_type* __s1, const char_type* __s2, size_t __n)
    .           . .               {
  300 (0.0%)    0 0         	if (__n == 0)
    .           . .         	  return 0;
    .           . .         #if __cplusplus >= 201703L
  500 (0.0%)    0 0         	if (std::__is_constant_evaluated())
    .           . .         	  {
    .           . .         	    for (size_t __i = 0; __i < __n; ++__i)
    .           . .         	      if (lt(__s1[__i], __s2[__i]))
    .           . .         		return -1;
    .           . .         	      else if (lt(__s2[__i], __s1[__i]))
    .           . .         		return 1;
    .           . .         	    return 0;
    .           . .         	  }
    .           . .         #endif
  500 (0.0%)    0 1 (0.0%)  	return __builtin_memcmp(__s1, __s2, __n);
  200 (0.0%)    0 0               }
    .           . .         
    .           . .               static _GLIBCXX17_CONSTEXPR size_t
1,503 (0.0%)    0 1 (0.0%)        length(const char_type* __s)
    .           . .               {
    .           . .         #if __cplusplus >= 201703L
2,505 (0.0%)    0 0         	if (std::__is_constant_evaluated())
    .           . .         	  return __gnu_cxx::char_traits<char_type>::length(__s);
    .           . .         #endif
1,503 (0.0%)    0 1 (0.0%)  	return __builtin_strlen(__s);
1,002 (0.0%)    0 0               }
    .           . .         
    .           . .               static _GLIBCXX17_CONSTEXPR const char_type*
    .           . .               find(const char_type* __s, size_t __n, const char_type& __a)
    .           . .               {
    .           . .         	if (__n == 0)
    .           . .         	  return 0;
    .           . .         #if __cplusplus >= 201703L
    .           . .         	if (std::__is_constant_evaluated())
-- line 408 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/charconv.h
--------------------------------------------------------------------------------
Ir__________ D1mr____ ILmr____ 

-- line 47 ----------------------------------------
    .        .        .           template<typename _Tp>
    .        .        .             constexpr bool __integer_to_chars_is_unsigned
    .        .        .               = ! __gnu_cxx::__int_traits<_Tp>::__is_signed;
    .        .        .         #endif
    .        .        .         
    .        .        .           // Generic implementation for arbitrary bases.
    .        .        .           template<typename _Tp>
    .        .        .             _GLIBCXX14_CONSTEXPR unsigned
1,200 (0.0%) 0        1 (0.0%)      __to_chars_len(_Tp __value, int __base = 10) noexcept
    .        .        .             {
    .        .        .         #if __cpp_variable_templates
    .        .        .               static_assert(__integer_to_chars_is_unsigned<_Tp>, "implementation bug");
    .        .        .         #endif
    .        .        .         
  800 (0.0%) 0        0               unsigned __n = 1;
1,200 (0.0%) 0        0               const unsigned __b2 = __base  * __base;
1,600 (0.0%) 0        0               const unsigned __b3 = __b2 * __base;
2,000 (0.0%) 0        1 (0.0%)        const unsigned long __b4 = __b3 * __base;
    .        .        .               for (;;)
    .        .        .         	{
2,220 (0.0%) 0        0         	  if (__value < (unsigned)__base) return __n;
  630 (0.0%) 0        0         	  if (__value < __b2) return __n + 1;
    .        .        .         	  if (__value < __b3) return __n + 2;
    .        .        .         	  if (__value < __b4) return __n + 3;
    .        .        .         	  __value /= __b4;
    .        .        .         	  __n += 4;
    .        .        .         	}
  800 (0.0%) 0        1 (0.0%)      }
    .        .        .         
    .        .        .           // Write an unsigned integer value to the range [first,first+len).
    .        .        .           // The caller is required to provide a buffer of exactly the right size
    .        .        .           // (which can be determined by the __to_chars_len function).
    .        .        .           template<typename _Tp>
    .        .        .             _GLIBCXX23_CONSTEXPR void
4,400 (0.1%) 0        1 (0.0%)      __to_chars_10_impl(char* __first, unsigned __len, _Tp __val) noexcept
    .        .        .             {
    .        .        .         #if __cpp_variable_templates
    .        .        .               static_assert(__integer_to_chars_is_unsigned<_Tp>, "implementation bug");
    .        .        .         #endif
    .        .        .         
6,800 (0.1%) 5 (0.0%) 1 (0.0%)        constexpr char __digits[201] =
    .        .        .         	"0001020304050607080910111213141516171819"
    .        .        .         	"2021222324252627282930313233343536373839"
    .        .        .         	"4041424344454647484950515253545556575859"
    .        .        .         	"6061626364656667686970717273747576777879"
    .        .        .         	"8081828384858687888990919293949596979899";
1,200 (0.0%) 0        0               unsigned __pos = __len - 1;
1,600 (0.0%) 0        1 (0.0%)        while (__val >= 100)
    .        .        .         	{
    .        .        .         	  auto const __num = (__val % 100) * 2;
    .        .        .         	  __val /= 100;
    .        .        .         	  __first[__pos] = __digits[__num + 1];
    .        .        .         	  __first[__pos - 1] = __digits[__num];
    .        .        .         	  __pos -= 2;
    .        .        .         	}
1,200 (0.0%) 0        0               if (__val >= 10)
    .        .        .         	{
  270 (0.0%) 0        0         	  auto const __num = __val * 2;
  720 (0.0%) 0        0         	  __first[1] = __digits[__num + 1];
  450 (0.0%) 0        0         	  __first[0] = __digits[__num];
    .        .        .         	}
    .        .        .               else
1,860 (0.0%) 0        2 (0.1%)  	__first[0] = '0' + __val;
4,490 (0.1%) 0        0             }
    .        .        .         
    .        .        .         } // namespace __detail
    .        .        .         _GLIBCXX_END_NAMESPACE_VERSION
    .        .        .         } // namespace std
    .        .        .         #endif // C++11
    .        .        .         #endif // _GLIBCXX_CHARCONV_H

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/fs_dir.h
--------------------------------------------------------------------------------
Ir___________ D1mr ILmr____ 

-- line 69 ----------------------------------------
     .           . .             file_status(const file_status&) noexcept = default;
     .           . .             file_status(file_status&&) noexcept = default;
     .           . .             ~file_status() = default;
     .           . .         
     .           . .             file_status& operator=(const file_status&) noexcept = default;
     .           . .             file_status& operator=(file_status&&) noexcept = default;
     .           . .         
     .           . .             // observers
10,200 (0.2%)    0 0             file_type  type() const noexcept { return _M_type; }
     .           . .             perms      permissions() const noexcept { return _M_perms; }
     .           . .         
     .           . .             // modifiers
     .           . .             void       type(file_type __ft) noexcept { _M_type = __ft; }
     .           . .             void       permissions(perms __prms) noexcept { _M_perms = __prms; }
     .           . .         
     .           . .         #if __cpp_lib_three_way_comparison
     .           . .             friend bool
-- line 85 ----------------------------------------
-- line 161 ----------------------------------------
     .           . .             refresh()
     .           . .             { _M_type = symlink_status().type(); }
     .           . .         
     .           . .             void
     .           . .             refresh(error_code& __ec) noexcept
     .           . .             { _M_type = symlink_status(__ec).type(); }
     .           . .         
     .           . .             // observers
    30 (0.0%)    0 0             const filesystem::path& path() const noexcept { return _M_path; }
     .           . .             operator const filesystem::path& () const noexcept { return _M_path; }
     .           . .         
     .           . .             bool
     .           . .             exists() const
     .           . .             { return filesystem::exists(file_status{_M_file_type()}); }
     .           . .         
     .           . .             bool
     .           . .             exists(error_code& __ec) const noexcept
-- line 177 ----------------------------------------
-- line 270 ----------------------------------------
     .           . .             { return filesystem::last_write_time(_M_path); }
     .           . .         
     .           . .         
     .           . .             file_time_type
     .           . .             last_write_time(error_code& __ec) const noexcept
     .           . .             { return filesystem::last_write_time(_M_path, __ec); }
     .           . .         
     .           . .             file_status
   900 (0.0%)    0 1 (0.0%)      status() const
 1,200 (0.0%)    0 0             { return filesystem::status(_M_path); }
     .           . .         
     .           . .             file_status
     .           . .             status(error_code& __ec) const noexcept
     .           . .             { return filesystem::status(_M_path, __ec); }
     .           . .         
     .           . .             file_status
     .           . .             symlink_status() const
     .           . .             { return filesystem::symlink_status(_M_path); }
-- line 287 ----------------------------------------
-- line 395 ----------------------------------------
     .           . .           {
     .           . .           public:
     .           . .             typedef directory_entry        value_type;
     .           . .             typedef ptrdiff_t              difference_type;
     .           . .             typedef const directory_entry* pointer;
     .           . .             typedef const directory_entry& reference;
     .           . .             typedef input_iterator_tag     iterator_category;
     .           . .         
 3,200 (0.1%)    0 0             directory_iterator() = default;
     .           . .         
     .           . .             explicit
   400 (0.0%)    0 1 (0.0%)      directory_iterator(const path& __p)
   800 (0.0%)    0 1 (0.0%)      : directory_iterator(__p, directory_options::none, nullptr) { }
     .           . .         
     .           . .             directory_iterator(const path& __p, directory_options __options)
     .           . .             : directory_iterator(__p, __options, nullptr) { }
     .           . .         
     .           . .             directory_iterator(const path& __p, error_code& __ec)
     .           . .             : directory_iterator(__p, directory_options::none, __ec) { }
     .           . .         
     .           . .             directory_iterator(const path& __p, directory_options __options,
     .           . .         		       error_code& __ec)
     .           . .             : directory_iterator(__p, __options, &__ec) { }
     .           . .         
     .           . .             directory_iterator(const directory_iterator& __rhs) = default;
     .           . .         
     .           . .             directory_iterator(directory_iterator&& __rhs) noexcept = default;
     .           . .         
 4,000 (0.1%)    0 1 (0.0%)      ~directory_iterator() = default;
     .           . .         
     .           . .             directory_iterator&
     .           . .             operator=(const directory_iterator& __rhs) = default;
     .           . .         
     .           . .             directory_iterator&
     .           . .             operator=(directory_iterator&& __rhs) noexcept = default;
     .           . .         
     .           . .             const directory_entry& operator*() const noexcept;
 2,142 (0.0%)    0 0             const directory_entry* operator->() const noexcept { return &**this; }
     .           . .             directory_iterator&    operator++();
     .           . .             directory_iterator&    increment(error_code& __ec);
     .           . .         
     .           . .             __directory_iterator_proxy operator++(int)
     .           . .             {
     .           . .               __directory_iterator_proxy __pr{**this};
     .           . .               ++*this;
     .           . .               return __pr;
     .           . .             }
     .           . .         
     .           . .             friend bool
 1,600 (0.0%)    0 0             operator==(const directory_iterator& __lhs,
     .           . .                        const directory_iterator& __rhs) noexcept
     .           . .             {
 2,400 (0.0%)    0 1 (0.0%)        return !__rhs._M_dir.owner_before(__lhs._M_dir)
 2,600 (0.0%)    0 0         	&& !__lhs._M_dir.owner_before(__rhs._M_dir);
   800 (0.0%)    0 0             }
     .           . .         
     .           . .         #if __cplusplus >= 202002L
     .           . .             // _GLIBCXX_RESOLVE_LIB_DEFECTS
     .           . .             // 3719. Directory iterators should be usable with default sentinel
     .           . .             bool operator==(default_sentinel_t) const noexcept
     .           . .             { return !_M_dir; }
     .           . .         #endif
     .           . .         
     .           . .         #if __cpp_impl_three_way_comparison < 201907L
     .           . .             friend bool
 1,600 (0.0%)    0 1 (0.0%)      operator!=(const directory_iterator& __lhs,
     .           . .         	       const directory_iterator& __rhs) noexcept
 3,200 (0.1%)    0 0             { return !(__lhs == __rhs); }
     .           . .         #endif
     .           . .         
     .           . .           private:
     .           . .             directory_iterator(const path&, directory_options, error_code*);
     .           . .         
     .           . .             friend class recursive_directory_iterator;
     .           . .         
     .           . .             std::__shared_ptr<_Dir> _M_dir;
-- line 470 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/fs_ops.h
--------------------------------------------------------------------------------
Ir__________ D1mr ILmr____ 

-- line 121 ----------------------------------------
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           bool
    .           . .           equivalent(const path& __p1, const path& __p2, error_code& __ec) noexcept;
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           inline bool
    .           . .           exists(file_status __s) noexcept
9,000 (0.2%)    0 1 (0.0%)    { return status_known(__s) && __s.type() != file_type::not_found; }
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           inline bool
    .           . .           exists(const path& __p)
4,500 (0.1%)    0 1 (0.0%)    { return exists(status(__p)); }
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           inline bool
    .           . .           exists(const path& __p, error_code& __ec) noexcept
    .           . .           {
    .           . .             auto __s = status(__p, __ec);
    .           . .             if (status_known(__s))
    .           . .               {
-- line 142 ----------------------------------------
-- line 186 ----------------------------------------
    .           . .           [[nodiscard]]
    .           . .           inline bool
    .           . .           is_character_file(const path& __p, error_code& __ec) noexcept
    .           . .           { return is_character_file(status(__p, __ec)); }
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           inline bool
    .           . .           is_directory(file_status __s) noexcept
1,100 (0.0%)    0 1 (0.0%)    { return __s.type() == file_type::directory; }
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           inline bool
    .           . .           is_directory(const path& __p)
  900 (0.0%)    0 0           { return is_directory(status(__p)); }
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           inline bool
    .           . .           is_directory(const path& __p, error_code& __ec) noexcept
    .           . .           { return is_directory(status(__p, __ec)); }
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           bool is_empty(const path& __p);
-- line 207 ----------------------------------------
-- line 356 ----------------------------------------
    .           . .           [[nodiscard]]
    .           . .           file_status status(const path& __p);
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           file_status status(const path& __p, error_code& __ec) noexcept;
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           inline bool status_known(file_status __s) noexcept
5,500 (0.1%)    0 1 (0.0%)    { return __s.type() != file_type::none; }
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           file_status symlink_status(const path& __p);
    .           . .         
    .           . .           [[nodiscard]]
    .           . .           file_status symlink_status(const path& __p, error_code& __ec) noexcept;
    .           . .         
    .           . .           [[nodiscard]]
-- line 372 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/fs_path.h
--------------------------------------------------------------------------------
Ir__________ D1mr ILmr____ 

-- line 175 ----------------------------------------
    .           . .         #endif
    .           . .         
    .           . .           // The __effective_range overloads convert a Source parameter into
    .           . .           // either a basic_string_view<C> or basic_string<C> containing the
    .           . .           // effective range of the Source, as defined in [fs.path.req].
    .           . .         
    .           . .           template<typename _CharT, typename _Traits, typename _Alloc>
    .           . .             inline basic_string_view<_CharT>
1,500 (0.0%)    0 1 (0.0%)      __effective_range(const basic_string<_CharT, _Traits, _Alloc>& __source)
    .           . .             noexcept
2,000 (0.0%)    0 0             { return __source; }
    .           . .         
    .           . .           template<typename _CharT, typename _Traits>
    .           . .             inline basic_string_view<_CharT>
  200 (0.0%)    0 1 (0.0%)      __effective_range(const basic_string_view<_CharT, _Traits>& __source)
    .           . .             noexcept
  400 (0.0%)    0 0             { return __source; }
    .           . .         
    .           . .           // Return the effective range of an NTCTS.
    .           . .           template<typename _Source>
    .           . .             auto
    9 (0.0%)    0 1 (0.0%)      __effective_range(const _Source& __source)
    .           . .             {
    .           . .               // Remove a level of normal/safe iterator indirection, or decay an array.
    .           . .               using _Iter = decltype(std::__niter_base(__source));
    .           . .               using value_type = typename iterator_traits<_Iter>::value_type;
    .           . .         
    .           . .               if constexpr (__is_contiguous<_Iter>)
    6 (0.0%)    0 1 (0.0%)  	return basic_string_view<value_type>{&*__source};
    .           . .               else
    .           . .         	{
    .           . .         	  // _Source is an input iterator that iterates over an NTCTS.
    .           . .         	  // Create a basic_string by reading until the null character.
    .           . .         	  basic_string<__unified_u8_t<value_type>> __str;
    .           . .         	  _Source __it = __source;
    .           . .         	  for (value_type __ch = *__it; __ch != value_type(); __ch = *++__it)
    .           . .         	    __str.push_back(__ch);
    .           . .         	  return __str;
    .           . .         	}
   12 (0.0%)    0 0             }
    .           . .         
    .           . .           // The value type of a Source parameter's effective range.
    .           . .           template<typename _Source>
    .           . .             struct __source_value_type_impl
    .           . .             {
    .           . .               using type
    .           . .         	= typename __safe_iterator_traits<decay_t<_Source>>::value_type;
    .           . .             };
-- line 222 ----------------------------------------
-- line 322 ----------------------------------------
    .           . .             { __p.clear(); }
    .           . .         
    .           . .             path(string_type&& __source, format = auto_format)
    .           . .             : _M_pathname(std::move(__source))
    .           . .             { _M_split_cmpts(); }
    .           . .         
    .           . .             template<typename _Source,
    .           . .         	     typename _Require = __detail::_Path<_Source>>
7,212 (0.1%)    0 4 (0.1%)        path(_Source const& __source, format = auto_format)
9,616 (0.2%)    0 4 (0.1%)        : _M_pathname(_S_convert(__detail::__effective_range(__source)))
8,414 (0.1%)    0 6 (0.2%)        { _M_split_cmpts(); }
    .           . .         
    .           . .             template<typename _InputIterator,
    .           . .         	     typename _Require = __detail::_Path2<_InputIterator>>
    .           . .               path(_InputIterator __first, _InputIterator __last, format = auto_format)
    .           . .               : _M_pathname(_S_convert(__detail::__string_from_range(__first, __last)))
    .           . .               { _M_split_cmpts(); }
    .           . .         
    .           . .             template<typename _Source,
-- line 340 ----------------------------------------
-- line 347 ----------------------------------------
    .           . .             template<typename _InputIterator,
    .           . .         	     typename _Require = __detail::_Path2<_InputIterator>,
    .           . .         	     typename _Req2 = __detail::__value_type_is_char<_InputIterator>>
    .           . .               path(_InputIterator __first, _InputIterator __last, const locale& __loc,
    .           . .         	   format = auto_format)
    .           . .               : _M_pathname(_S_convert_loc(__first, __last, __loc))
    .           . .               { _M_split_cmpts(); }
    .           . .         
6,611 (0.1%)    0 1 (0.0%)      ~path() = default;
    .           . .         
    .           . .             // assignments
    .           . .         
    .           . .             path& operator=(const path&);
    .           . .             path& operator=(path&&) noexcept;
    .           . .             path& operator=(string_type&& __source);
    .           . .             path& assign(string_type&& __source);
    .           . .         
-- line 363 ----------------------------------------
-- line 532 ----------------------------------------
    .           . .             using const_iterator = iterator;
    .           . .         
    .           . .             iterator begin() const noexcept;
    .           . .             iterator end() const noexcept;
    .           . .         
    .           . .             /// Write a path to a stream
    .           . .             template<typename _CharT, typename _Traits>
    .           . .               friend std::basic_ostream<_CharT, _Traits>&
   78 (0.0%)    0 2 (0.1%)        operator<<(std::basic_ostream<_CharT, _Traits>& __os, const path& __p)
    .           . .               {
  102 (0.0%)    0 1 (0.0%)  	__os << std::quoted(__p.string<_CharT, _Traits>());
   12 (0.0%)    0 0         	return __os;
   72 (0.0%)    0 1 (0.0%)        }
    .           . .         
    .           . .             /// Read a path from a stream
    .           . .             template<typename _CharT, typename _Traits>
    .           . .               friend std::basic_istream<_CharT, _Traits>&
    .           . .               operator>>(std::basic_istream<_CharT, _Traits>& __is, path& __p)
    .           . .               {
    .           . .         	std::basic_string<_CharT, _Traits> __tmp;
    .           . .         	if (__is >> std::quoted(__tmp))
-- line 552 ----------------------------------------
-- line 610 ----------------------------------------
    .           . .             pair<const string_type*, size_t> _M_find_extension() const noexcept;
    .           . .         
    .           . .             // path::_S_convert creates a basic_string<value_type> or
    .           . .             // basic_string_view<value_type> from a basic_string<C> or
    .           . .             // basic_string_view<C>, for an encoded character type C,
    .           . .             // performing the conversions required by [fs.path.type.cvt].
    .           . .             template<typename _Tp>
    .           . .               static auto
1,202 (0.0%)    0 0               _S_convert(_Tp __str)
    .           . .               noexcept(is_same_v<typename _Tp::value_type, value_type>)
    .           . .               {
    .           . .         	if constexpr (is_same_v<typename _Tp::value_type, value_type>)
  601 (0.0%)    0 0         	  return __str; // No conversion needed.
    .           . .         #if !defined _GLIBCXX_FILESYSTEM_IS_WINDOWS && defined _GLIBCXX_USE_CHAR8_T
    .           . .         	else if constexpr (is_same_v<_Tp, std::u8string>)
    .           . .         	  // Calling _S_convert<char8_t> will return a u8string_view that
    .           . .         	  // refers to __str and would dangle after this function returns.
    .           . .         	  // Return a string_type instead, to avoid dangling.
    .           . .         	  return string_type(_S_convert(__str.data(),
    .           . .         					__str.data() + __str.size()));
    .           . .         #endif
    .           . .         	else
    .           . .         	  return _S_convert(__str.data(), __str.data() + __str.size());
1,202 (0.0%)    0 0               }
    .           . .         
    .           . .             template<typename _EcharT>
    .           . .               static auto
    .           . .               _S_convert(const _EcharT* __first, const _EcharT* __last);
    .           . .         
    .           . .             // _S_convert_loc converts a range of char to string_type, using the
    .           . .             // supplied locale for encoding conversions.
    .           . .         
-- line 641 ----------------------------------------
-- line 681 ----------------------------------------
    .           . .               using iterator = value_type*;
    .           . .               using const_iterator = const value_type*;
    .           . .         
    .           . .               _List();
    .           . .               _List(const _List&);
    .           . .               _List(_List&&) = default;
    .           . .               _List& operator=(const _List&);
    .           . .               _List& operator=(_List&&) = default;
4,808 (0.1%)    0 1 (0.0%)        ~_List() = default;
    .           . .         
    .           . .               _Type type() const noexcept
    .           . .               { return _Type(reinterpret_cast<uintptr_t>(_M_impl.get()) & 0x3); }
    .           . .         
    .           . .               void type(_Type) noexcept;
    .           . .         
    .           . .               int size() const noexcept; // zero unless type() == _Type::_Multi
    .           . .               bool empty() const noexcept; // true unless type() == _Type::_Multi
-- line 697 ----------------------------------------
-- line 1153 ----------------------------------------
    .           . .         	    }
    .           . .         	}
    .           . .               __detail::__throw_conversion_error();
    .           . .             }
    .           . .           /// @endcond
    .           . .         
    .           . .           template<typename _CharT, typename _Traits, typename _Allocator>
    .           . .             inline basic_string<_CharT, _Traits, _Allocator>
   36 (0.0%)    0 0             path::string(const _Allocator& __a) const
    .           . .             {
    .           . .               if constexpr (is_same_v<_CharT, value_type>)
   60 (0.0%)    0 0         	return { _M_pathname.c_str(), _M_pathname.length(), __a };
    .           . .               else
    .           . .         	return _S_str_convert<_CharT, _Traits>(_M_pathname, __a);
   24 (0.0%)    0 0             }
    .           . .         
    .           . .           inline std::string
    .           . .           path::string() const { return string<char>(); }
    .           . .         
    .           . .         #if _GLIBCXX_USE_WCHAR_T
    .           . .           inline std::wstring
    .           . .           path::wstring() const { return string<wchar_t>(); }
    .           . .         #endif
-- line 1175 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/new_allocator.h
--------------------------------------------------------------------------------
Ir__________ D1mr ILmr____ 

-- line 80 ----------------------------------------
    .           . .         #if __cplusplus >= 201103L
    .           . .               // _GLIBCXX_RESOLVE_LIB_DEFECTS
    .           . .               // 2103. propagate_on_container_move_assignment
    .           . .               typedef std::true_type propagate_on_container_move_assignment;
    .           . .         #endif
    .           . .         
    .           . .               __attribute__((__always_inline__))
    .           . .               _GLIBCXX20_CONSTEXPR
1,015 (0.0%)    0 0               __new_allocator() _GLIBCXX_USE_NOEXCEPT { }
    .           . .         
    .           . .               __attribute__((__always_inline__))
    .           . .               _GLIBCXX20_CONSTEXPR
  300 (0.0%)    0 0               __new_allocator(const __new_allocator&) _GLIBCXX_USE_NOEXCEPT { }
    .           . .         
    .           . .               template<typename _Tp1>
    .           . .         	__attribute__((__always_inline__))
    .           . .         	_GLIBCXX20_CONSTEXPR
    .           . .         	__new_allocator(const __new_allocator<_Tp1>&) _GLIBCXX_USE_NOEXCEPT { }
    .           . .         
    .           . .         #if __cplusplus >= 201103L
    .           . .               __new_allocator& operator=(const __new_allocator&) = default;
    .           . .         #endif
    .           . .         
    .           . .         #if __cplusplus <= 201703L
8,075 (0.1%)    0 1 (0.0%)        ~__new_allocator() _GLIBCXX_USE_NOEXCEPT { }
    .           . .         
    .           . .               pointer
    .           . .               address(reference __x) const _GLIBCXX_NOEXCEPT
    .           . .               { return std::__addressof(__x); }
    .           . .         
    .           . .               const_pointer
    .           . .               address(const_reference __x) const _GLIBCXX_NOEXCEPT
    .           . .               { return std::__addressof(__x); }
-- line 112 ----------------------------------------
-- line 118 ----------------------------------------
    .           . .         #else
    .           . .         # define _GLIBCXX_OPERATOR_NEW ::operator new
    .           . .         # define _GLIBCXX_OPERATOR_DELETE ::operator delete
    .           . .         #endif
    .           . .         
    .           . .               // NB: __n is permitted to be 0.  The C++ standard says nothing
    .           . .               // about what the return value is when __n == 0.
    .           . .               _GLIBCXX_NODISCARD _Tp*
   84 (0.0%)    0 3 (0.1%)        allocate(size_type __n, const void* = static_cast<const void*>(0))
    .           . .               {
    .           . .         #if __cplusplus >= 201103L
    .           . .         	// _GLIBCXX_RESOLVE_LIB_DEFECTS
    .           . .         	// 3308. std::allocator<void>().allocate(n)
    .           . .         	static_assert(sizeof(_Tp) != 0, "cannot allocate incomplete types");
    .           . .         #endif
    .           . .         
  132 (0.0%)    0 2 (0.1%)  	if (__builtin_expect(__n > this->_M_max_size(), false))
    .           . .         	  {
    .           . .         	    // _GLIBCXX_RESOLVE_LIB_DEFECTS
    .           . .         	    // 3190. allocator::allocate sometimes returns too little storage
    .           . .         	    if (__n > (std::size_t(-1) / sizeof(_Tp)))
    .           . .         	      std::__throw_bad_array_new_length();
    .           . .         	    std::__throw_bad_alloc();
    .           . .         	  }
    .           . .         
-- line 142 ----------------------------------------
-- line 143 ----------------------------------------
    .           . .         #if __cpp_aligned_new
    .           . .         	if (alignof(_Tp) > __STDCPP_DEFAULT_NEW_ALIGNMENT__)
    .           . .         	  {
    .           . .         	    std::align_val_t __al = std::align_val_t(alignof(_Tp));
    .           . .         	    return static_cast<_Tp*>(_GLIBCXX_OPERATOR_NEW(__n * sizeof(_Tp),
    .           . .         							   __al));
    .           . .         	  }
    .           . .         #endif
   48 (0.0%)    0 1 (0.0%)  	return static_cast<_Tp*>(_GLIBCXX_OPERATOR_NEW(__n * sizeof(_Tp)));
   24 (0.0%)    0 1 (0.0%)        }
    .           . .         
    .           . .               // __p is not permitted to be a null pointer.
    .           . .               void
   60 (0.0%)    0 3 (0.1%)        deallocate(_Tp* __p, size_type __n __attribute__ ((__unused__)))
    .           . .               {
    .           . .         #if __cpp_sized_deallocation
    .           . .         # define _GLIBCXX_SIZED_DEALLOC(p, n) (p), (n) * sizeof(_Tp)
    .           . .         #else
    .           . .         # define _GLIBCXX_SIZED_DEALLOC(p, n) (p)
    .           . .         #endif
    .           . .         
    .           . .         #if __cpp_aligned_new
    .           . .         	if (alignof(_Tp) > __STDCPP_DEFAULT_NEW_ALIGNMENT__)
    .           . .         	  {
    .           . .         	    _GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n),
    .           . .         				     std::align_val_t(alignof(_Tp)));
    .           . .         	    return;
    .           . .         	  }
    .           . .         #endif
   60 (0.0%)    0 1 (0.0%)  	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
   24 (0.0%)    0 0               }
    .           . .         
    .           . .         #undef _GLIBCXX_SIZED_DEALLOC
    .           . .         #undef _GLIBCXX_OPERATOR_DELETE
    .           . .         #undef _GLIBCXX_OPERATOR_NEW
    .           . .         
    .           . .         #if __cplusplus <= 201703L
    .           . .               __attribute__((__always_inline__))
    .           . .               size_type
    .           . .               max_size() const _GLIBCXX_USE_NOEXCEPT
   11 (0.0%)    0 0               { return _M_max_size(); }
    .           . .         
    .           . .         #if __cplusplus >= 201103L
    .           . .               template<typename _Up, typename... _Args>
    .           . .         	__attribute__((__always_inline__))
    .           . .         	void
    .           . .         	construct(_Up* __p, _Args&&... __args)
    .           . .         	noexcept(std::is_nothrow_constructible<_Up, _Args...>::value)
2,243 (0.0%)    0 4 (0.1%)  	{ ::new((void *)__p) _Up(std::forward<_Args>(__args)...); }
    .           . .         
    .           . .               template<typename _Up>
    .           . .         	__attribute__((__always_inline__))
    .           . .         	void
    .           . .         	destroy(_Up* __p)
    .           . .         	noexcept(std::is_nothrow_destructible<_Up>::value)
  303 (0.0%)    0 0         	{ __p->~_Up(); }
    .           . .         #else
    .           . .               // _GLIBCXX_RESOLVE_LIB_DEFECTS
    .           . .               // 402. wrong new expression in [some_] allocator::construct
    .           . .               __attribute__((__always_inline__))
    .           . .               void
    .           . .               construct(pointer __p, const _Tp& __val)
    .           . .               { ::new((void *)__p) _Tp(__val); }
    .           . .         
-- line 206 ----------------------------------------
-- line 225 ----------------------------------------
    .           . .         #endif
    .           . .         
    .           . .             private:
    .           . .               __attribute__((__always_inline__))
    .           . .               _GLIBCXX_CONSTEXPR size_type
    .           . .               _M_max_size() const _GLIBCXX_USE_NOEXCEPT
    .           . .               {
    .           . .         #if __PTRDIFF_MAX__ < __SIZE_MAX__
   23 (0.0%)    0 1 (0.0%)  	return std::size_t(__PTRDIFF_MAX__) / sizeof(_Tp);
    .           . .         #else
    .           . .         	return std::size_t(-1) / sizeof(_Tp);
    .           . .         #endif
    .           . .               }
    .           . .             };
    .           . .         
    .           . .         _GLIBCXX_END_NAMESPACE_VERSION
    .           . .         } // namespace
-- line 241 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/shared_ptr_base.h
--------------------------------------------------------------------------------
Ir__________ D1mr ILmr____ 

-- line 1060 ----------------------------------------
    .           . .         
    .           . .               // Throw bad_weak_ptr when __r._M_get_use_count() == 0.
    .           . .               explicit __shared_count(const __weak_count<_Lp>& __r);
    .           . .         
    .           . .               // Does not throw if __r._M_get_use_count() == 0, caller must check.
    .           . .               explicit
    .           . .               __shared_count(const __weak_count<_Lp>& __r, std::nothrow_t) noexcept;
    .           . .         
1,500 (0.0%)    0 1 (0.0%)        ~__shared_count() noexcept
    .           . .               {
2,000 (0.0%)    0 0         	if (_M_pi != nullptr)
    .           . .         	  _M_pi->_M_release();
1,500 (0.0%)    0 0               }
    .           . .         
    .           . .               __shared_count(const __shared_count& __r) noexcept
    .           . .               : _M_pi(__r._M_pi)
    .           . .               {
    .           . .         	if (_M_pi != nullptr)
    .           . .         	  _M_pi->_M_add_ref_copy();
    .           . .               }
    .           . .         
-- line 1080 ----------------------------------------
-- line 1109 ----------------------------------------
    .           . .               _M_unique() const noexcept
    .           . .               { return this->_M_get_use_count() == 1; }
    .           . .         
    .           . .               void*
    .           . .               _M_get_deleter(const std::type_info& __ti) const noexcept
    .           . .               { return _M_pi ? _M_pi->_M_get_deleter(__ti) : nullptr; }
    .           . .         
    .           . .               bool
5,000 (0.1%)    0 1 (0.0%)        _M_less(const __shared_count& __rhs) const noexcept
9,500 (0.2%)    0 1 (0.0%)        { return std::less<_Sp_counted_base<_Lp>*>()(this->_M_pi, __rhs._M_pi); }
    .           . .         
    .           . .               bool
    .           . .               _M_less(const __weak_count<_Lp>& __rhs) const noexcept
    .           . .               { return std::less<_Sp_counted_base<_Lp>*>()(this->_M_pi, __rhs._M_pi); }
    .           . .         
    .           . .               // Friend function injected into enclosing namespace and found by ADL
    .           . .               friend inline bool
    .           . .               operator==(const __shared_count& __a, const __shared_count& __b) noexcept
-- line 1126 ----------------------------------------
-- line 1516 ----------------------------------------
    .           . .         	: _M_ptr(__p), _M_refcount()
    .           . .         	{
    .           . .         	  _M_refcount._M_swap(__r._M_refcount);
    .           . .         	  __r._M_ptr = nullptr;
    .           . .         	}
    .           . .         
    .           . .               __shared_ptr(const __shared_ptr&) noexcept = default;
    .           . .               __shared_ptr& operator=(const __shared_ptr&) noexcept = default;
4,500 (0.1%)    0 0               ~__shared_ptr() = default;
    .           . .         
    .           . .               template<typename _Yp, typename = _Compatible<_Yp>>
    .           . .         	__shared_ptr(const __shared_ptr<_Yp, _Lp>& __r) noexcept
    .           . .         	: _M_ptr(__r._M_ptr), _M_refcount(__r._M_refcount)
    .           . .         	{ }
    .           . .         
    .           . .               __shared_ptr(__shared_ptr&& __r) noexcept
    .           . .               : _M_ptr(__r._M_ptr), _M_refcount()
-- line 1532 ----------------------------------------
-- line 1691 ----------------------------------------
    .           . .                *
    .           . .                * This function defines a strict weak ordering between two shared_ptr
    .           . .                * or weak_ptr objects, such that one object is less than the other
    .           . .                * unless they share ownership of the same pointer, or are both empty.
    .           . .                * @{
    .           . .               */
    .           . .               template<typename _Tp1>
    .           . .         	bool
2,000 (0.0%)    0 1 (0.0%)  	owner_before(__shared_ptr<_Tp1, _Lp> const& __rhs) const noexcept
5,000 (0.1%)    0 1 (0.0%)  	{ return _M_refcount._M_less(__rhs._M_refcount); }
    .           . .         
    .           . .               template<typename _Tp1>
    .           . .         	bool
    .           . .         	owner_before(__weak_ptr<_Tp1, _Lp> const& __rhs) const noexcept
    .           . .         	{ return _M_refcount._M_less(__rhs._M_refcount); }
    .           . .               /// @}
    .           . .         
    .           . .             protected:
-- line 1708 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/stl_function.h
--------------------------------------------------------------------------------
Ir__________ D1mr ILmr____ 

-- line 443 ----------------------------------------
    .           . .               }
    .           . .             };
    .           . .         
    .           . .           // Partial specialization of std::less for pointers.
    .           . .           template<typename _Tp>
    .           . .             struct less<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    .           . .             {
    .           . .               _GLIBCXX14_CONSTEXPR bool
2,500 (0.0%)    0 2 (0.1%)        operator()(_Tp* __x, _Tp* __y) const _GLIBCXX_NOTHROW
    .           . .               {
    .           . .         #if __cplusplus >= 201402L
2,500 (0.0%)    0 0         	if (std::__is_constant_evaluated())
    .           . .         	  return __x < __y;
    .           . .         #endif
2,500 (0.0%)    0 0         	return (__UINTPTR_TYPE__)__x < (__UINTPTR_TYPE__)__y;
1,000 (0.0%)    0 0               }
    .           . .             };
    .           . .         
    .           . .           // Partial specialization of std::greater_equal for pointers.
    .           . .           template<typename _Tp>
    .           . .             struct greater_equal<_Tp*> : public binary_function<_Tp*, _Tp*, bool>
    .           . .             {
    .           . .               _GLIBCXX14_CONSTEXPR bool
    .           . .               operator()(_Tp* __x, _Tp* __y) const _GLIBCXX_NOTHROW
-- line 466 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotated source file: /usr/include/c++/13/bits/unique_ptr.h
--------------------------------------------------------------------------------
Ir__________ D1mr ILmr____ 

-- line 168 ----------------------------------------
    .           . .               using pointer = typename _Ptr<_Tp, _Dp>::type;
    .           . .         
    .           . .               static_assert( !is_rvalue_reference<_Dp>::value,
    .           . .         		     "unique_ptr's deleter type must be a function object type"
    .           . .         		     " or an lvalue reference type" );
    .           . .         
    .           . .               __uniq_ptr_impl() = default;
    .           . .               _GLIBCXX23_CONSTEXPR
   30 (0.0%)    0 1 (0.0%)        __uniq_ptr_impl(pointer __p) : _M_t() { _M_ptr() = __p; }
    .           . .         
    .           . .               template<typename _Del>
    .           . .         	_GLIBCXX23_CONSTEXPR
    .           . .         	__uniq_ptr_impl(pointer __p, _Del&& __d)
    .           . .         	: _M_t(__p, std::forward<_Del>(__d)) { }
    .           . .         
    .           . .               _GLIBCXX23_CONSTEXPR
    .           . .               __uniq_ptr_impl(__uniq_ptr_impl&& __u) noexcept
-- line 184 ----------------------------------------
-- line 189 ----------------------------------------
    .           . .               __uniq_ptr_impl& operator=(__uniq_ptr_impl&& __u) noexcept
    .           . .               {
    .           . .         	reset(__u.release());
    .           . .         	_M_deleter() = std::forward<_Dp>(__u._M_deleter());
    .           . .         	return *this;
    .           . .               }
    .           . .         
    .           . .               _GLIBCXX23_CONSTEXPR
4,235 (0.1%)    0 2 (0.1%)        pointer&   _M_ptr() noexcept { return std::get<0>(_M_t); }
    .           . .               _GLIBCXX23_CONSTEXPR
    .           . .               pointer    _M_ptr() const noexcept { return std::get<0>(_M_t); }
    .           . .               _GLIBCXX23_CONSTEXPR
4,207 (0.1%)    0 2 (0.1%)        _Dp&       _M_deleter() noexcept { return std::get<1>(_M_t); }
    .           . .               _GLIBCXX23_CONSTEXPR
    .           . .               const _Dp& _M_deleter() const noexcept { return std::get<1>(_M_t); }
    .           . .         
    .           . .               _GLIBCXX23_CONSTEXPR
    .           . .               void reset(pointer __p) noexcept
    .           . .               {
    .           . .         	const pointer __old_p = _M_ptr();
    .           . .         	_M_ptr() = __p;
-- line 209 ----------------------------------------
-- line 309 ----------------------------------------
    .           . .                *
    .           . .                * @param __p  A pointer to an object of @c element_type
    .           . .                *
    .           . .                * The deleter will be value-initialized.
    .           . .                */
    .           . .               template<typename _Del = _Dp, typename = _DeleterConstraint<_Del>>
    .           . .         	_GLIBCXX23_CONSTEXPR
    .           . .         	explicit
    8 (0.0%)    0 1 (0.0%)  	unique_ptr(pointer __p) noexcept
    6 (0.0%)    0 0         	: _M_t(__p)
    6 (0.0%)    0 0                 { }
    .           . .         
    .           . .               /** Takes ownership of a pointer.
    .           . .                *
    .           . .                * @param __p  A pointer to an object of @c element_type
    .           . .                * @param __d  A reference to a deleter.
    .           . .                *
    .           . .                * The deleter will be initialized with @p __d
    .           . .                */
-- line 327 ----------------------------------------
-- line 390 ----------------------------------------
    .           . .         	unique_ptr(auto_ptr<_Up>&& __u) noexcept;
    .           . .         #pragma GCC diagnostic pop
    .           . .         #endif
    .           . .         
    .           . .               /// Destructor, invokes the deleter if the stored pointer is not null.
    .           . .         #if __cplusplus > 202002L && __cpp_constexpr_dynamic_alloc
    .           . .               constexpr
    .           . .         #endif
2,412 (0.0%)    0 3 (0.1%)        ~unique_ptr() noexcept
    .           . .               {
    .           . .         	static_assert(__is_invocable<deleter_type&, pointer>::value,
    .           . .         		      "unique_ptr's deleter must be invocable with a pointer");
1,809 (0.0%)    0 0         	auto& __ptr = _M_t._M_ptr();
2,412 (0.0%)    0 0         	if (__ptr != nullptr)
5,409 (0.1%)    0 1 (0.0%)  	  get_deleter()(std::move(__ptr));
1,206 (0.0%)    0 0         	__ptr = pointer();
2,412 (0.0%)    0 0               }
    .           . .         
    .           . .               // Assignment.
    .           . .         
    .           . .               /** @brief Move assignment operator.
    .           . .                *
    .           . .                * Invokes the deleter if this object owns a pointer.
    .           . .                */
    .           . .               unique_ptr& operator=(unique_ptr&&) = default;
-- line 414 ----------------------------------------
-- line 467 ----------------------------------------
    .           . .               _GLIBCXX23_CONSTEXPR
    .           . .               pointer
    .           . .               get() const noexcept
    .           . .               { return _M_t._M_ptr(); }
    .           . .         
    .           . .               /// Return a reference to the stored deleter.
    .           . .               _GLIBCXX23_CONSTEXPR
    .           . .               deleter_type&
1,803 (0.0%)    0 0               get_deleter() noexcept
2,404 (0.0%)    0 0               { return _M_t._M_deleter(); }
    .           . .         
    .           . .               /// Return a reference to the stored deleter.
    .           . .               _GLIBCXX23_CONSTEXPR
    .           . .               const deleter_type&
    .           . .               get_deleter() const noexcept
    .           . .               { return _M_t._M_deleter(); }
    .           . .         
    .           . .               /// Return @c true if the stored pointer is not null.
-- line 484 ----------------------------------------

--------------------------------------------------------------------------------
-- Annotation summary
--------------------------------------------------------------------------------
Ir_______________ D1mr__________ ILmr_________ 

  391,937  (6.7%)      7  (0.1%)   166  (6.0%)    annotated: files known & above threshold & readable, line numbers known
        0              0             0            annotated: files known & above threshold & readable, line numbers unknown
        0              0             0          unannotated: files known & above threshold & two or more non-identical
2,870,686 (48.7%) 11,920 (93.2%)   517 (18.6%)  unannotated: files known & above threshold & unreadable 
  271,152  (4.6%)    529  (4.1%) 1,180 (42.4%)  unannotated: files known & below threshold
2,355,478 (40.0%)    340  (2.7%)   921 (33.1%)  unannotated: files unknown

sre@cpp:~/debugging/multi-file/build$ 

