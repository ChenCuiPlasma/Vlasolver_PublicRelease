# Vlasolver: A Parallel Multi-dimensional Grid-Based Kinetic Vlasov Solver

A parallel multi-dimensional grid-based kinetic Vlasov solver for computational plasma dynamics, with primary applications in electric propulsion plasma modeling, plasma-object interactions, low-temperature plasma, and fundamental plasma dynamics simulation. Because the solver evolves the velocity distribution function directly on a phase-space grid, its solutions are free of the statistical particle noise inherent to particle-in-cell methods.

Plasma flow past a star-shaped dielectric obstacle:
| Number density (ion) | Potential |
|--|--|
| ![Star density](examples/star/figures/number_density.png) | ![Star potential](examples/star/figures/potential.png) |

## 1. Authors and Maintainers

- Chen Cui (University of Virginia) — author and lead maintainer
- James Robertson — maintainer
- Hunt Feng — maintainer

## 2. Release Status

This repository is a public snapshot (v1.0.0) of Vlasolver, released under the Apache-2.0 license. It contains the solver framework headers, the numerical core of the Vlasov update, example problem configurations with representative results, and Python post-processing tools.

## 3. Models and Equations for Vlasolver

The solver evolves the Vlasov-Poisson system describing electrostatic collisionless plasma behavior. The Vlasov equation advances the particle velocity distribution function of each species in phase space, coupled with the self-consistent electric potential from the Poisson equation. Macroscopic plasma properties derive from moments of the distribution function. Two electron closures are provided: fully kinetic (every species evolved kinetically) and Boltzmann (only ions evolved kinetically). All quantities are normalized to the Debye length, the thermal velocity, and the plasma frequency.

## 4. Simulation Methods and Computing Algorithm

The implementation discretizes both physical and velocity space into computational meshes. The solving strategy incorporates:

- Operator splitting techniques
- Semi-Lagrangian time integration
- Third-order positive flux conservation (PFC) with a positivity-preserving flux limiter
- Field solvers for the variable-coefficient Poisson equation
- Support for objects embedded in the simulation domain (dielectric or conducting obstacles, non-planar walls, surface-charging bodies)

The notation xDyV describes phase space capability (x physical dimensions, y velocity dimensions).

## 5. Current Capabilities of Phase Space Dimensions

- **1D1V** through **3D3V** phase space configurations

## 6. Code Structure

Header-only C++ library organized into modular groups (`include/`): Grid (`grid.hpp`), World (`world.hpp`), Vlasov solver (`vlasov.hpp`), Poisson solvers (`poisson.hpp`, `poisson_1st_order.hpp`, `poisson_2nd_order.hpp`), Diagnostics (`writer.hpp`), and Utilities (`linalg.hpp`).

## 7. Parallelization and Performance Portability

The code is built on the [Kokkos](https://github.com/kokkos/kokkos) ecosystem and runs on CPUs and GPUs from a single source (CUDA, HIP, OpenMP, Serial backends). Sparse linear algebra uses KokkosKernels. Diagnostics are written in HDF5 (VTKHDF format) for visualization with ParaView or the included Python tools.

## 8. Install Requirements

C++20 and CMake (≥ 3.22), with the following libraries:

| Dependency | Version |
|---|---|
| Kokkos | ≥ 4.5 |
| KokkosKernels | ≥ 4.5 |
| HDF5 | ≥ 1.14 |
| HighFive | ≥ 2.10 |
| libinih | (system) |

## 9. Examples and Post-Processing

Each folder under `examples/` holds an input file, post-processing scripts, and representative results: plasma flow past a charged cylinder, plasma flow past a star-shaped dielectric obstacle, planar and rough-wall plasma sheaths, a kinetic sheath at a dielectric wall, an orbital-motion-limited sheath around a charging dust grain, and an advection verification test. The included Python package (`pyproject.toml`) provides visualization and analysis tools for the HDF5 output.

## 10. Publications

Development and applications of the Vlasolver code line are documented in peer-reviewed publications, including:

- C. Cui and J. Wang, "Grid-based Vlasov simulation of collisionless plasma expansion," *Physics of Plasmas* 28, 093510 (2021).
- C. Cui and J. Wang, "Development of a parallel multi-dimensional grid-based Vlasov solver for plasma plume simulation," *AIAA Propulsion and Energy Forum* (2021).
- C. Cui and J. Wang, "Vlasov simulations of electric propulsion beam," *Plasma Sources Science and Technology* 33, 125005 (2024).

## 11. License and Citation

Apache License 2.0 (see `LICENSE`). To cite this repository, see `CITATION.cff`.
