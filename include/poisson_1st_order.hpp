/*
 * First-order field solver for the Poisson equation
 *
 *   div( eps grad phi ) = -rho
 *
 * on a Cartesian grid with embedded objects, using red-black Gauss-Seidel
 * relaxation.
 */
#pragma once
#include "poisson.hpp"
#include <Kokkos_Core.hpp>

template <typename World>
class PoissonSolver1stOrder : PoissonSolver<PoissonSolver1stOrder<World>> {
  private:
    World& world;
    double tol;
    Kokkos::View<double**> phi_old;
    Kokkos::View<double**> eps; // physical permittivity at each cell, built from eps_p/eps_m
    double omega;
    int max_iter; // max iterations for the solver

  public:
    /**
     * Using omega to control the relaxation rate of Gauss-Seidel iterations
     * For problem with Dirichlet boundaries, optimal omega is given by
     * omega     = 2.0 / (1.0 + (sin(pi / (nx - 2 * ngc))));
     * For mixed boundary conditions, a lower value is needed or it won't converge
     */
    PoissonSolver1stOrder(World& world, double tol = 1e-6, int max_iter = 1e5, float omega = 1.9);

    /**
     * Build the physical permittivity field from the region permittivity
     * fields `eps_p` and `eps_m`.
     */
    void construct_permittivity();

    /// Solve for the potential field phi.
    void solve();

    /// Compute the electric field E = -grad phi from the solved potential.
    void compute_electric_field() const;
};
