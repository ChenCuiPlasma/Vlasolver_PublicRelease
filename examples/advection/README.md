# Advection Test

Pure advection — the Vlasov equation without a Poisson solver. A Gaussian density pulse is initialized at $x = 0.2$ and advects with constant velocity $(v_x, v_y) = (0.1, 0)$ through a $[0,1] \times [0, 0.5]$ domain containing a semi-circular obstacle (center at $(0.375, 0)$, radius $0.125$); the pulse flows around it since no electric field couples back.

All boundaries are periodic. This case verifies the advection operator against the exact advected solution.

Post-processing scripts are included in this folder.
