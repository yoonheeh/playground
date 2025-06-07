# Build
In `lto` directory, 
```
mkdir build
cd build
cmake ..
cmake --build .
```
Running the above will produce two executables in the `build` folder:
 - `wihtout_lto_so`
 - `with_lto`

# Benchmarking
Good tool you can use to benchmark performance between the two executables
without having to worry about CPU warm-ups, etc. is `hyperfine`.
On Ubuntu, you can install it by
```
sudo apt install hyperfine
```
Once you have `hyperfine` ready, we can compare the performance between 
the two executables, with and without LTO. Once again, this is to run 
inside the `build` folder:
```
hyperfine './without_lto_so' './with_lto'
```
You will see something like this:
```hyperfine './without_lto_so' './with_lto'
Benchmark 1: ./without_lto_so
  Time (mean ± σ):      1.690 s ±  0.011 s    [User: 1.688 s, System: 0.001 s]
  Range (min … max):    1.679 s …  1.715 s    10 runs
 
Benchmark 2: ./with_lto
  Time (mean ± σ):      1.572 s ±  0.037 s    [User: 1.571 s, System: 0.000 s]
  Range (min … max):    1.534 s …  1.661 s    10 runs
 
Summary
  './with_lto' ran
    1.07 ± 0.03 times faster than './without_lto_so'

```
Note that depending on the CPU, the actual time measurement will vary.
