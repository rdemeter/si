# Compilarea testului incluzând flag-urile de coverage (gcov)
gcc -fprofile-arcs -ftest-coverage test_led_control.c led_control.c -o test_runner
# Rularea executabilului de test
./test_runner
# Generarea raportului de code coverage
gcov led_control.c

# Generează fișierul de date lcov din fișierele .gcda/.gcno generate la rulare
lcov --capture --directory . --output-file coverage.info
# Generează pagini HTML bazate pe acel fișier
genhtml coverage.info --output-directory out_html
