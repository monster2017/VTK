vtk_module(vtkIOParallel
  GROUPS
    MPI
  DEPENDS
    vtkParallelCore
    vtkFiltersParallel
    vtkIONetCDF
    vtkexodusII
  TEST_DEPENDS
    vtkTestingCore
    vtkTestingRendering
    vtkParallelMPI
    vtkIOMPIImage
    vtkInteractionStyle
    vtkRenderingOpenGL
  )