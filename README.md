# Kinema
 
A 3D rigid-body physics engine written from scratch in C++.
 
> **Status: in progress.** Currently in Phase 1. The Vec3 math type is complete; the rest of the math library and the point-mass sandbox are still to come.
 
## Goals
 
- Learn physics by implementing it, and learn C++ along the way
- Keep the engine small, readable and fast, with performance-sensitive code where it matters
- Write the math library from scratch (no GLM)
## Roadmap
 
| Phase | Scope | Status |
|-------|-------|--------|
| 1 | Point-mass sandbox | In progress |
| 2 | Basic rigid bodies without rotation | Planned |
| 3 | Full rigid-body dynamics with rotation | Planned |
| 4 | Stable contact resolution | Optional, deferred |
 
### Phase 1 checklist
 
- [ ] Math library MVP
  - [x] `Vec3`
  - [ ] `Mat3`
  - [ ] `Quat`
- [ ] Particle representation (stores inverse mass)
- [ ] Semi-implicit Euler integrator
- [ ] Force generators (interface pattern)
- [ ] Simulation loop
## Design notes
 
- **Header-only math types.** `Vec3` and the other math primitives live entirely in headers so the compiler can inline them.
- **Fixed-size storage.** Math types use fixed-size arrays, not `std::vector`.
- **Inverse mass.** Particles store inverse mass, which avoids division and represents infinite mass (immovable objects) naturally.
- **Invariants matter.** Planned checks include quaternion unit-length drift and inertia tensor symmetry.
## Math library
 
### `Vec3` (done)
 
3D vector with addition, subtraction, scalar multiplication and division, dot product, cross product, length, normalization and negation.
 
### `Mat3` (planned)
 
Matrix-matrix and matrix-vector multiplication, transpose, determinant, inverse. Needed for inertia tensors in later phases.
 
### `Quat` (planned)
 
Quaternion multiplication, normalization, conjugate/inverse, vector rotation, construction from axis-angle.
 
## Building and testing
 
Requires a C++ compiler and [CMake](https://cmake.org/). Tests use [GoogleTest](https://github.com/google/googletest).
 
```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build
```
 
The `build/` directory is excluded via `.gitignore`.
 
## License
 
TBD
