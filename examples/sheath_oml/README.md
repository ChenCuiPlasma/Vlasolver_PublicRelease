# 2D Orbital-Motion-Limited (OML) Sheath (Full Two-Species)

A **full two-species** (electron + ion) Vlasov-Poisson simulation of a plasma sheath forming around a circular dielectric dust grain.

## Physics

- **Domain**: $[-20, 20]\lambda_D \times [-20, 20]\lambda_D$ in $(x, y)$
- **Normalization**: $T_i/T_e = 1$, $m_i/m_e = 100$
- **Boundary conditions**: Maxwellian injection and Dirichlet potential (fixed to 0) at 4 walls
- **Initial distribution**: Maxwellian for both species
- **Charging dust**: Dust is dielectric with $\epsilon=5$ and surface charge accumulates as it absorbs plasma

Parameters are configured in `input.ini`. Post-processing scripts are included in this folder.

## Results

![Potential](figures/potential.png)

![Potential Profile](figures/potential_profiles.png)
