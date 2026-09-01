/*
 * Second-order field solver for the Poisson equation
 *
 *   div( eps grad phi ) = -rho
 *
 * on a Cartesian grid with embedded objects. The linear system is solved with
 * GMRES and an incomplete-LU preconditioner (KokkosKernels).
 */
#pragma once
#include "grid.hpp"
#include "linalg.hpp"
#include "poisson.hpp"
#include <Kokkos_Core.hpp>

template <typename World>
class PoissonSolver2ndOrder : PoissonSolver<PoissonSolver2ndOrder<World>> {
  private:
    World& world;
    double tol;
    int gmres_m;
    int max_restart;
    bool verbose;
    double ilut_drop_tol;
    int ilut_max_iter;
    double ilut_fill_limit;

  public:
    PoissonSolver2ndOrder(World& world,
                          double tol             = 1e-12,
                          int gmres_m            = 100,
                          int max_restart        = 30,
                          bool verbose           = false,
                          double ilut_drop_tol   = 1e-10,
                          int ilut_max_iter      = 500,
                          double ilut_fill_limit = 20.0);

    /// Solve for the potential field phi.
    void solve();

    /// Compute the electric field E = -grad phi from the solved potential.
    void compute_electric_field();
};
