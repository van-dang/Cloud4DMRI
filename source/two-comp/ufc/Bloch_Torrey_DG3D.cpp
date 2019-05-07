// This code conforms with the UFC specification version 2.0.5
// and was automatically generated by FFC version 1.0.0.
//
// This code was generated with the option '-l dolfin' and
// contains DOLFIN-specific wrappers that depend on DOLFIN.
// 
// This code was generated with the following parameters:
// 
//   cache_dir:                      ''
//   convert_exceptions_to_warnings: False
//   cpp_optimize:                   False
//   cpp_optimize_flags:             '-O2'
//   epsilon:                        1e-14
//   error_control:                  False
//   form_postfix:                   True
//   format:                         'dolfin'
//   log_level:                      20
//   log_prefix:                     ''
//   optimize:                       True
//   output_dir:                     '.'
//   precision:                      15
//   quadrature_degree:              'auto'
//   quadrature_rule:                'auto'
//   representation:                 'quadrature'
//   split:                          True
//   swig_binary:                    'swig'
//   swig_path:                      ''

#include "Bloch_Torrey_DG3D.h"

/// Constructor
bloch_torrey_dg3d_finite_element_0::bloch_torrey_dg3d_finite_element_0() : ufc::finite_element()
{
    // Do nothing
}

/// Destructor
bloch_torrey_dg3d_finite_element_0::~bloch_torrey_dg3d_finite_element_0()
{
    // Do nothing
}

/// Return a string identifying the finite element
const char* bloch_torrey_dg3d_finite_element_0::signature() const
{
    return "FiniteElement('Discontinuous Lagrange', Cell('tetrahedron', Space(3)), 0, None)";
}

/// Return the cell shape
ufc::shape bloch_torrey_dg3d_finite_element_0::cell_shape() const
{
    return ufc::tetrahedron;
}

#ifndef UFC_BACKWARD_COMPATIBILITY
/// Return the topological dimension of the cell shape
unsigned int bloch_torrey_dg3d_finite_element_0::topological_dimension() const
{
    return 3;
}

/// Return the geometric dimension of the cell shape
unsigned int bloch_torrey_dg3d_finite_element_0::geometric_dimension() const
{
    return 3;
}
#endif
/// Return the dimension of the finite element function space
unsigned int bloch_torrey_dg3d_finite_element_0::space_dimension() const
{
    return 1;
}

/// Return the rank of the value space
unsigned int bloch_torrey_dg3d_finite_element_0::value_rank() const
{
    return 0;
}

/// Return the dimension of the value space for axis i
unsigned int bloch_torrey_dg3d_finite_element_0::value_dimension(unsigned int i) const
{
    return 1;
}

/// Evaluate basis function i at given point in cell
void bloch_torrey_dg3d_finite_element_0::evaluate_basis(unsigned int i,
                                   double* values,
                                   const double* coordinates,
                                   const ufc::cell& c) const
{
    // Extract vertex coordinates
    
    // Compute Jacobian of affine map from reference cell
    
    // Compute sub determinants
    
    // Compute determinant of Jacobian
    
    // Compute inverse of Jacobian
    
    // Compute constants
    
    // Get coordinates and map to the reference (FIAT) element
    
    
    // Reset values.
    *values = 0.0;
    
    // Array of basisvalues.
    double basisvalues[1] = {0.0};
    
    // Declare helper variables.
    
    // Compute basisvalues.
    basisvalues[0] = 1.0;
    
    // Table(s) of coefficients.
    static const double coefficients0[1] = \
    {1.0};
    
    // Compute value(s).
    for (unsigned int r = 0; r < 1; r++)
    {
      *values += coefficients0[r]*basisvalues[r];
    }// end loop over 'r'
}

/// Evaluate all basis functions at given point in cell
void bloch_torrey_dg3d_finite_element_0::evaluate_basis_all(double* values,
                                       const double* coordinates,
                                       const ufc::cell& c) const
{
    // Element is constant, calling evaluate_basis.
    evaluate_basis(0, values, coordinates, c);
}

/// Evaluate order n derivatives of basis function i at given point in cell
void bloch_torrey_dg3d_finite_element_0::evaluate_basis_derivatives(unsigned int i,
                                               unsigned int n,
                                               double* values,
                                               const double* coordinates,
                                               const ufc::cell& c) const
{
    // Extract vertex coordinates
    const double * const * x = c.coordinates;
    
    // Compute Jacobian of affine map from reference cell
    const double J_00 = x[1][0] - x[0][0];
    const double J_01 = x[2][0] - x[0][0];
    const double J_02 = x[3][0] - x[0][0];
    const double J_10 = x[1][1] - x[0][1];
    const double J_11 = x[2][1] - x[0][1];
    const double J_12 = x[3][1] - x[0][1];
    const double J_20 = x[1][2] - x[0][2];
    const double J_21 = x[2][2] - x[0][2];
    const double J_22 = x[3][2] - x[0][2];
    
    // Compute sub determinants
    const double d_00 = J_11*J_22 - J_12*J_21;
    const double d_01 = J_12*J_20 - J_10*J_22;
    const double d_02 = J_10*J_21 - J_11*J_20;
    const double d_10 = J_02*J_21 - J_01*J_22;
    const double d_11 = J_00*J_22 - J_02*J_20;
    const double d_12 = J_01*J_20 - J_00*J_21;
    const double d_20 = J_01*J_12 - J_02*J_11;
    const double d_21 = J_02*J_10 - J_00*J_12;
    const double d_22 = J_00*J_11 - J_01*J_10;
    
    // Compute determinant of Jacobian
    double detJ = J_00*d_00 + J_10*d_10 + J_20*d_20;
    
    // Compute inverse of Jacobian
    const double K_00 = d_00 / detJ;
    const double K_01 = d_10 / detJ;
    const double K_02 = d_20 / detJ;
    const double K_10 = d_01 / detJ;
    const double K_11 = d_11 / detJ;
    const double K_12 = d_21 / detJ;
    const double K_20 = d_02 / detJ;
    const double K_21 = d_12 / detJ;
    const double K_22 = d_22 / detJ;
    
    // Compute constants
    
    // Get coordinates and map to the reference (FIAT) element
    
    
    // Compute number of derivatives.
    unsigned int num_derivatives = 1;
    for (unsigned int r = 0; r < n; r++)
    {
      num_derivatives *= 3;
    }// end loop over 'r'
    
    // Declare pointer to two dimensional array that holds combinations of derivatives and initialise
    unsigned int **combinations = new unsigned int *[num_derivatives];
    for (unsigned int row = 0; row < num_derivatives; row++)
    {
      combinations[row] = new unsigned int [n];
      for (unsigned int col = 0; col < n; col++)
        combinations[row][col] = 0;
    }
    
    // Generate combinations of derivatives
    for (unsigned int row = 1; row < num_derivatives; row++)
    {
      for (unsigned int num = 0; num < row; num++)
      {
        for (unsigned int col = n-1; col+1 > 0; col--)
        {
          if (combinations[row][col] + 1 > 2)
            combinations[row][col] = 0;
          else
          {
            combinations[row][col] += 1;
            break;
          }
        }
      }
    }
    
    // Compute inverse of Jacobian
    const double Jinv[3][3] = {{K_00, K_01, K_02}, {K_10, K_11, K_12}, {K_20, K_21, K_22}};
    
    // Declare transformation matrix
    // Declare pointer to two dimensional array and initialise
    double **transform = new double *[num_derivatives];
    
    for (unsigned int j = 0; j < num_derivatives; j++)
    {
      transform[j] = new double [num_derivatives];
      for (unsigned int k = 0; k < num_derivatives; k++)
        transform[j][k] = 1;
    }
    
    // Construct transformation matrix
    for (unsigned int row = 0; row < num_derivatives; row++)
    {
      for (unsigned int col = 0; col < num_derivatives; col++)
      {
        for (unsigned int k = 0; k < n; k++)
          transform[row][col] *= Jinv[combinations[col][k]][combinations[row][k]];
      }
    }
    
    // Reset values. Assuming that values is always an array.
    for (unsigned int r = 0; r < num_derivatives; r++)
    {
      values[r] = 0.0;
    }// end loop over 'r'
    
    
    // Array of basisvalues.
    double basisvalues[1] = {0.0};
    
    // Declare helper variables.
    
    // Compute basisvalues.
    basisvalues[0] = 1.0;
    
    // Table(s) of coefficients.
    static const double coefficients0[1] = \
    {1.0};
    
    // Tables of derivatives of the polynomial base (transpose).
    static const double dmats0[1][1] = \
    {{0.0}};
    
    static const double dmats1[1][1] = \
    {{0.0}};
    
    static const double dmats2[1][1] = \
    {{0.0}};
    
    // Compute reference derivatives.
    // Declare pointer to array of derivatives on FIAT element.
    double *derivatives = new double[num_derivatives];
    for (unsigned int r = 0; r < num_derivatives; r++)
    {
      derivatives[r] = 0.0;
    }// end loop over 'r'
    
    // Declare derivative matrix (of polynomial basis).
    double dmats[1][1] = \
    {{1.0}};
    
    // Declare (auxiliary) derivative matrix (of polynomial basis).
    double dmats_old[1][1] = \
    {{1.0}};
    
    // Loop possible derivatives.
    for (unsigned int r = 0; r < num_derivatives; r++)
    {
      // Resetting dmats values to compute next derivative.
      for (unsigned int t = 0; t < 1; t++)
      {
        for (unsigned int u = 0; u < 1; u++)
        {
          dmats[t][u] = 0.0;
          if (t == u)
          {
          dmats[t][u] = 1.0;
          }
          
        }// end loop over 'u'
      }// end loop over 't'
      
      // Looping derivative order to generate dmats.
      for (unsigned int s = 0; s < n; s++)
      {
        // Updating dmats_old with new values and resetting dmats.
        for (unsigned int t = 0; t < 1; t++)
        {
          for (unsigned int u = 0; u < 1; u++)
          {
            dmats_old[t][u] = dmats[t][u];
            dmats[t][u] = 0.0;
          }// end loop over 'u'
        }// end loop over 't'
        
        // Update dmats using an inner product.
        if (combinations[r][s] == 0)
        {
        for (unsigned int t = 0; t < 1; t++)
        {
          for (unsigned int u = 0; u < 1; u++)
          {
            for (unsigned int tu = 0; tu < 1; tu++)
            {
              dmats[t][u] += dmats0[t][tu]*dmats_old[tu][u];
            }// end loop over 'tu'
          }// end loop over 'u'
        }// end loop over 't'
        }
        
        if (combinations[r][s] == 1)
        {
        for (unsigned int t = 0; t < 1; t++)
        {
          for (unsigned int u = 0; u < 1; u++)
          {
            for (unsigned int tu = 0; tu < 1; tu++)
            {
              dmats[t][u] += dmats1[t][tu]*dmats_old[tu][u];
            }// end loop over 'tu'
          }// end loop over 'u'
        }// end loop over 't'
        }
        
        if (combinations[r][s] == 2)
        {
        for (unsigned int t = 0; t < 1; t++)
        {
          for (unsigned int u = 0; u < 1; u++)
          {
            for (unsigned int tu = 0; tu < 1; tu++)
            {
              dmats[t][u] += dmats2[t][tu]*dmats_old[tu][u];
            }// end loop over 'tu'
          }// end loop over 'u'
        }// end loop over 't'
        }
        
      }// end loop over 's'
      for (unsigned int s = 0; s < 1; s++)
      {
        for (unsigned int t = 0; t < 1; t++)
        {
          derivatives[r] += coefficients0[s]*dmats[s][t]*basisvalues[t];
        }// end loop over 't'
      }// end loop over 's'
    }// end loop over 'r'
    
    // Transform derivatives back to physical element
    for (unsigned int r = 0; r < num_derivatives; r++)
    {
      for (unsigned int s = 0; s < num_derivatives; s++)
      {
        values[r] += transform[r][s]*derivatives[s];
      }// end loop over 's'
    }// end loop over 'r'
    
    // Delete pointer to array of derivatives on FIAT element
    delete [] derivatives;
    
    // Delete pointer to array of combinations of derivatives and transform
    for (unsigned int r = 0; r < num_derivatives; r++)
    {
      delete [] combinations[r];
    }// end loop over 'r'
    delete [] combinations;
    for (unsigned int r = 0; r < num_derivatives; r++)
    {
      delete [] transform[r];
    }// end loop over 'r'
    delete [] transform;
}

/// Evaluate order n derivatives of all basis functions at given point in cell
void bloch_torrey_dg3d_finite_element_0::evaluate_basis_derivatives_all(unsigned int n,
                                                   double* values,
                                                   const double* coordinates,
                                                   const ufc::cell& c) const
{
    // Element is constant, calling evaluate_basis_derivatives.
    evaluate_basis_derivatives(0, n, values, coordinates, c);
}

/// Evaluate linear functional for dof i on the function f
double bloch_torrey_dg3d_finite_element_0::evaluate_dof(unsigned int i,
                                   const ufc::function& f,
                                   const ufc::cell& c) const
{
    // Declare variables for result of evaluation.
    double vals[1];
    
    // Declare variable for physical coordinates.
    double y[3];
    const double * const * x = c.coordinates;
    switch (i)
    {
    case 0:
      {
        y[0] = 0.25*x[0][0] + 0.25*x[1][0] + 0.25*x[2][0] + 0.25*x[3][0];
      y[1] = 0.25*x[0][1] + 0.25*x[1][1] + 0.25*x[2][1] + 0.25*x[3][1];
      y[2] = 0.25*x[0][2] + 0.25*x[1][2] + 0.25*x[2][2] + 0.25*x[3][2];
      f.evaluate(vals, y, c);
      return vals[0];
        break;
      }
    }
    
    return 0.0;
}

/// Evaluate linear functionals for all dofs on the function f
void bloch_torrey_dg3d_finite_element_0::evaluate_dofs(double* values,
                                  const ufc::function& f,
                                  const ufc::cell& c) const
{
    // Declare variables for result of evaluation.
    double vals[1];
    
    // Declare variable for physical coordinates.
    double y[3];
    const double * const * x = c.coordinates;
    y[0] = 0.25*x[0][0] + 0.25*x[1][0] + 0.25*x[2][0] + 0.25*x[3][0];
    y[1] = 0.25*x[0][1] + 0.25*x[1][1] + 0.25*x[2][1] + 0.25*x[3][1];
    y[2] = 0.25*x[0][2] + 0.25*x[1][2] + 0.25*x[2][2] + 0.25*x[3][2];
    f.evaluate(vals, y, c);
    values[0] = vals[0];
}

/// Interpolate vertex values from dof values
void bloch_torrey_dg3d_finite_element_0::interpolate_vertex_values(double* vertex_values,
                                              const double* dof_values,
                                              const ufc::cell& c) const
{
    // Evaluate function and change variables
    vertex_values[0] = dof_values[0];
    vertex_values[1] = dof_values[0];
    vertex_values[2] = dof_values[0];
    vertex_values[3] = dof_values[0];
}

#ifndef UFC_BACKWARD_COMPATIBILITY
/// Map coordinate xhat from reference cell to coordinate x in cell
void bloch_torrey_dg3d_finite_element_0::map_from_reference_cell(double* x,
                                            const double* xhat,
                                            const ufc::cell& c) const
{
    throw std::runtime_error("map_from_reference_cell not yet implemented (introduced in UFC 2.0).");
}

/// Map from coordinate x in cell to coordinate xhat in reference cell
void bloch_torrey_dg3d_finite_element_0::map_to_reference_cell(double* xhat,
                                          const double* x,
                                          const ufc::cell& c) const
{
    throw std::runtime_error("map_to_reference_cell not yet implemented (introduced in UFC 2.0).");
}
#endif
/// Return the number of sub elements (for a mixed element)
unsigned int bloch_torrey_dg3d_finite_element_0::num_sub_elements() const
{
    return 0;
}

/// Create a new finite element for sub element i (for a mixed element)
ufc::finite_element* bloch_torrey_dg3d_finite_element_0::create_sub_element(unsigned int i) const
{
    return 0;
}

#ifndef UFC_BACKWARD_COMPATIBILITY
/// Create a new class instance
ufc::finite_element* bloch_torrey_dg3d_finite_element_0::create() const
{
    return new bloch_torrey_dg3d_finite_element_0();
}
#endif

/// Constructor


#ifndef UFC_BACKWARD_COMPATIBILITY
bloch_torrey_dg3d_dofmap_0::bloch_torrey_dg3d_dofmap_0() : ufc::dofmap()
#else
bloch_torrey_dg3d_dofmap_0::bloch_torrey_dg3d_dofmap_0() : ufc::dof_map()
#endif
{
    _global_dimension = 0;
}

/// Destructor
bloch_torrey_dg3d_dofmap_0::~bloch_torrey_dg3d_dofmap_0()
{
    // Do nothing
}

/// Return a string identifying the dofmap
const char* bloch_torrey_dg3d_dofmap_0::signature() const
{
    return "FFC dofmap for FiniteElement('Discontinuous Lagrange', Cell('tetrahedron', Space(3)), 0, None)";
}

/// Return true iff mesh entities of topological dimension d are needed
bool bloch_torrey_dg3d_dofmap_0::needs_mesh_entities(unsigned int d) const
{
    switch (d)
    {
    case 0:
      {
        return false;
        break;
      }
    case 1:
      {
        return false;
        break;
      }
    case 2:
      {
        return false;
        break;
      }
    case 3:
      {
        return true;
        break;
      }
    }
    
    return false;
}

/// Initialize dofmap for mesh (return true iff init_cell() is needed)
bool bloch_torrey_dg3d_dofmap_0::init_mesh(const ufc::mesh& m)
{
    _global_dimension = m.num_entities[3];
    return false;
}

/// Initialize dofmap for given cell
void bloch_torrey_dg3d_dofmap_0::init_cell(const ufc::mesh& m,
                              const ufc::cell& c)
{
    // Do nothing
}

/// Finish initialization of dofmap for cells
void bloch_torrey_dg3d_dofmap_0::init_cell_finalize()
{
    // Do nothing
}

#ifndef UFC_BACKWARD_COMPATIBILITY
/// Return the topological dimension of the associated cell shape
unsigned int bloch_torrey_dg3d_dofmap_0::topological_dimension() const
{
    return 3;
}

/// Return the geometric dimension of the associated cell shape
unsigned int bloch_torrey_dg3d_dofmap_0::geometric_dimension() const
{
    return 3;
}
#endif
/// Return the dimension of the global finite element function space
unsigned int bloch_torrey_dg3d_dofmap_0::global_dimension() const
{
    return _global_dimension;
}

#ifndef UFC_BACKWARD_COMPATIBILITY
/// Return the dimension of the local finite element function space for a cell
unsigned int bloch_torrey_dg3d_dofmap_0::local_dimension(const ufc::cell& c) const
{
    return 1;
}

/// Return the maximum dimension of the local finite element function space
unsigned int bloch_torrey_dg3d_dofmap_0::max_local_dimension() const
{
    return 1;
}
#else

/// Return the dimension of the local finite element function space for a cell
unsigned int bloch_torrey_dg3d_dofmap_0::local_dimension() const
{
    return 1;
}

/// Return the maximum dimension of the local finite element function space
unsigned int bloch_torrey_dg3d_dofmap_0::geometric_dimension() const
{
    return 3;
}

#endif
/// Return the number of dofs on each cell facet
unsigned int bloch_torrey_dg3d_dofmap_0::num_facet_dofs() const
{
    return 0;
}

/// Return the number of dofs associated with each cell entity of dimension d
unsigned int bloch_torrey_dg3d_dofmap_0::num_entity_dofs(unsigned int d) const
{
    switch (d)
    {
    case 0:
      {
        return 0;
        break;
      }
    case 1:
      {
        return 0;
        break;
      }
    case 2:
      {
        return 0;
        break;
      }
    case 3:
      {
        return 1;
        break;
      }
    }
    
    return 0;
}

/// Tabulate the local-to-global mapping of dofs on a cell
void bloch_torrey_dg3d_dofmap_0::tabulate_dofs(unsigned int* dofs,
                                  const ufc::mesh& m,
                                  const ufc::cell& c) const
{
    dofs[0] = c.entity_indices[3][0];
}

/// Tabulate the local-to-local mapping from facet dofs to cell dofs
void bloch_torrey_dg3d_dofmap_0::tabulate_facet_dofs(unsigned int* dofs,
                                        unsigned int facet) const
{
    switch (facet)
    {
    case 0:
      {
        
        break;
      }
    case 1:
      {
        
        break;
      }
    case 2:
      {
        
        break;
      }
    case 3:
      {
        
        break;
      }
    }
    
}

/// Tabulate the local-to-local mapping of dofs on entity (d, i)
void bloch_torrey_dg3d_dofmap_0::tabulate_entity_dofs(unsigned int* dofs,
                                  unsigned int d, unsigned int i) const
{
    if (d > 3)
    {
    throw std::runtime_error("d is larger than dimension (3)");
    }
    
    switch (d)
    {
    case 0:
      {
        
        break;
      }
    case 1:
      {
        
        break;
      }
    case 2:
      {
        
        break;
      }
    case 3:
      {
        if (i > 0)
      {
      throw std::runtime_error("i is larger than number of entities (0)");
      }
      
      dofs[0] = 0;
        break;
      }
    }
    
}

/// Tabulate the coordinates of all dofs on a cell
void bloch_torrey_dg3d_dofmap_0::tabulate_coordinates(double** coordinates,
                                         const ufc::cell& c) const
{
    const double * const * x = c.coordinates;
    
    coordinates[0][0] = 0.25*x[0][0] + 0.25*x[1][0] + 0.25*x[2][0] + 0.25*x[3][0];
    coordinates[0][1] = 0.25*x[0][1] + 0.25*x[1][1] + 0.25*x[2][1] + 0.25*x[3][1];
    coordinates[0][2] = 0.25*x[0][2] + 0.25*x[1][2] + 0.25*x[2][2] + 0.25*x[3][2];
}

#ifndef UFC_BACKWARD_COMPATIBILITY
/// Return the number of sub dofmaps (for a mixed element)
unsigned int bloch_torrey_dg3d_dofmap_0::num_sub_dofmaps() const
{
    return 0;
}

/// Create a new dofmap for sub dofmap i (for a mixed element)
ufc::dofmap* bloch_torrey_dg3d_dofmap_0::create_sub_dofmap(unsigned int i) const
{
    return 0;
}

/// Create a new class instance
ufc::dofmap* bloch_torrey_dg3d_dofmap_0::create() const
{
    return new bloch_torrey_dg3d_dofmap_0();
}
#else

/// Return the number of sub dofmaps (for a mixed element)
unsigned int bloch_torrey_dg3d_dofmap_0::num_sub_dof_maps() const
{
    return 0;
}

/// Create a new dofmap for sub dofmap i (for a mixed element)
ufc::dof_map* bloch_torrey_dg3d_dofmap_0::create_sub_dof_map(unsigned int i) const
{
    return 0;
}

#endif

/// Constructor
bloch_torrey_dg3d_cell_integral_0_0::bloch_torrey_dg3d_cell_integral_0_0() : ufc::cell_integral()
{
    // Do nothing
}

/// Destructor
bloch_torrey_dg3d_cell_integral_0_0::~bloch_torrey_dg3d_cell_integral_0_0()
{
    // Do nothing
}

/// Tabulate the tensor for the contribution from a local cell
void bloch_torrey_dg3d_cell_integral_0_0::tabulate_tensor(double* A,
                                    const double * const * w,
                                    const ufc::cell& c) const
{
    // Extract vertex coordinates
    const double * const * x = c.coordinates;
    
    // Compute Jacobian of affine map from reference cell
    const double J_00 = x[1][0] - x[0][0];
    const double J_01 = x[2][0] - x[0][0];
    const double J_02 = x[3][0] - x[0][0];
    const double J_10 = x[1][1] - x[0][1];
    const double J_11 = x[2][1] - x[0][1];
    const double J_12 = x[3][1] - x[0][1];
    const double J_20 = x[1][2] - x[0][2];
    const double J_21 = x[2][2] - x[0][2];
    const double J_22 = x[3][2] - x[0][2];
    
    // Compute sub determinants
    const double d_00 = J_11*J_22 - J_12*J_21;
    const double d_10 = J_02*J_21 - J_01*J_22;
    const double d_20 = J_01*J_12 - J_02*J_11;
    
    // Compute determinant of Jacobian
    double detJ = J_00*d_00 + J_10*d_10 + J_20*d_20;
    
    // Compute inverse of Jacobian
    
    // Set scale factor
    const double det = std::abs(detJ);
    
    // Cell Volume.
    
    // Compute circumradius.
    
    
    // Facet Area (divide by two because 'det' is scaled by area of reference triangle).
    
    // Array of quadrature weights.
    static const double W1 = 0.166666666666667;
    // Quadrature points on the UFC reference element: (0.25, 0.25, 0.25)
    
    // Value of basis functions at quadrature points.
    // Reset values in the element tensor.
    for (unsigned int r = 0; r < 1; r++)
    {
      A[r] = 0.0;
    }// end loop over 'r'
    // Number of operations to compute geometry constants: 1.
    double G[1];
    G[0] = W1*det;
    
    // Compute element tensor using UFL quadrature representation
    // Optimisations: ('eliminate zeros', True), ('ignore ones', True), ('ignore zero tables', True), ('optimisation', 'simplify_expressions'), ('remove zero terms', True)
    
    // Loop quadrature points for integral.
    // Number of operations to compute element tensor for following IP loop = 1
    // Only 1 integration point, omitting IP loop.
    
    // Number of operations for primary indices: 1
    // Number of operations to compute entry: 1
    A[0] += G[0];
}

 #ifndef UFC_BACKWARD_COMPATIBILITY 
/// Tabulate the tensor for the contribution from a local cell
/// using the specified reference cell quadrature points/weights
void bloch_torrey_dg3d_cell_integral_0_0::tabulate_tensor(double* A,
                     const double * const * w,
                     const ufc::cell& c,
                     unsigned int num_quadrature_points,
                     const double * const * quadrature_points,
                     const double* quadrature_weights) const
{
    throw std::runtime_error("Quadrature version of tabulate_tensor not yet implemented (introduced in UFC 2.0).");
}
#endif

/// Constructor
bloch_torrey_dg3d_form_0::bloch_torrey_dg3d_form_0() : ufc::form()
{
    // Do nothing
}

/// Destructor
bloch_torrey_dg3d_form_0::~bloch_torrey_dg3d_form_0()
{
    // Do nothing
}

/// Return a string identifying the form
const char* bloch_torrey_dg3d_form_0::signature() const
{
    return "Form([Integral(Product(Argument(FiniteElement('Discontinuous Lagrange', Cell('tetrahedron', Space(3)), 0, None), 0), Argument(FiniteElement('Discontinuous Lagrange', Cell('tetrahedron', Space(3)), 0, None), 1)), Measure('cell', 0, None))])";
}

/// Return the rank of the global tensor (r)
unsigned int bloch_torrey_dg3d_form_0::rank() const
{
    return 2;
}

/// Return the number of coefficients (n)
unsigned int bloch_torrey_dg3d_form_0::num_coefficients() const
{
    return 0;
}
 #ifndef UFC_BACKWARD_COMPATIBILITY 
/// Return the number of cell domains
unsigned int bloch_torrey_dg3d_form_0::num_cell_domains() const
{
    return 1;
}

/// Return the number of exterior facet domains
unsigned int bloch_torrey_dg3d_form_0::num_exterior_facet_domains() const
{
    return 0;
}

/// Return the number of interior facet domains
unsigned int bloch_torrey_dg3d_form_0::num_interior_facet_domains() const
{
    return 0;
}
#else

/// Return the number of cell domains
unsigned int bloch_torrey_dg3d_form_0::num_cell_integrals() const
{
    return 1;
}

/// Return the number of exterior facet domains
unsigned int bloch_torrey_dg3d_form_0::num_exterior_facet_integrals() const
{
    return 0;
}

/// Return the number of interior facet domains
unsigned int bloch_torrey_dg3d_form_0::num_interior_facet_integrals() const
{
    return 0;
}

#endif

/// Create a new finite element for argument function i
ufc::finite_element* bloch_torrey_dg3d_form_0::create_finite_element(unsigned int i) const
{
    switch (i)
    {
    case 0:
      {
        return new bloch_torrey_dg3d_finite_element_0();
        break;
      }
    case 1:
      {
        return new bloch_torrey_dg3d_finite_element_0();
        break;
      }
    }
    
    return 0;
}

 #ifndef UFC_BACKWARD_COMPATIBILITY 
/// Create a new dofmap for argument function i
ufc::dofmap* bloch_torrey_dg3d_form_0::create_dofmap(unsigned int i) const
{
    switch (i)
    {
    case 0:
      {
        return new bloch_torrey_dg3d_dofmap_0();
        break;
      }
    case 1:
      {
        return new bloch_torrey_dg3d_dofmap_0();
        break;
      }
    }
    
    return 0;
}
#else

/// Create a new dofmap for argument function i
ufc::dof_map* bloch_torrey_dg3d_form_0::create_dof_map(unsigned int i) const
{
    switch (i)
    {
    case 0:
      {
        return new bloch_torrey_dg3d_dofmap_0();
        break;
      }
    case 1:
      {
        return new bloch_torrey_dg3d_dofmap_0();
        break;
      }
    }
    
    return 0;
}
#endif
/// Create a new cell integral on sub domain i
ufc::cell_integral* bloch_torrey_dg3d_form_0::create_cell_integral(unsigned int i) const
{
    switch (i)
    {
    case 0:
      {
        return new bloch_torrey_dg3d_cell_integral_0_0();
        break;
      }
    }
    
    return 0;
}

/// Create a new exterior facet integral on sub domain i
ufc::exterior_facet_integral* bloch_torrey_dg3d_form_0::create_exterior_facet_integral(unsigned int i) const
{
    return 0;
}

/// Create a new interior facet integral on sub domain i
ufc::interior_facet_integral* bloch_torrey_dg3d_form_0::create_interior_facet_integral(unsigned int i) const
{
    return 0;
}

