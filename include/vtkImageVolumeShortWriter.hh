/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageVolumeShortWriter.hh
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 1993-1995 Ken Martin, Will Schroeder, Bill Lorensen.

This software is copyrighted by Ken Martin, Will Schroeder and Bill Lorensen.
The following terms apply to all files associated with the software unless
explicitly disclaimed in individual files. This copyright specifically does
not apply to the related textbook "The Visualization Toolkit" ISBN
013199837-4 published by Prentice Hall which is covered by its own copyright.

The authors hereby grant permission to use, copy, and distribute this
software and its documentation for any purpose, provided that existing
copyright notices are retained in all copies and that this notice is included
verbatim in any distributions. Additionally, the authors grant permission to
modify this software and its documentation for any purpose, provided that
such modifications are not distributed without the explicit consent of the
authors and that existing copyright notices are retained in all copies. Some
of the algorithms implemented by this software are patented, observe all
applicable patent law.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.


=========================================================================*/
// .NAME vtkImageVolumeShortWriter - Generic Writer.
// .SECTION Description
// vtkImageVolumeShortWriter will request a region slice by slice, and
// write it in a format which can be read by vtkImageVolumeShortReader.
// It does not put any header in the image files.


#ifndef __vtkImageVolumeShortWriter_h
#define __vtkImageVolumeShortWriter_h

#include <iostream.h>
#include <fstream.h>
#include "vtkImageCachedSource.hh"

class vtkImageVolumeShortWriter : public vtkObject
{
public:
  vtkImageVolumeShortWriter();
  ~vtkImageVolumeShortWriter();
  char *GetClassName() {return "vtkImageVolumeShortWriter";};
  
  void SetFileRoot(char *fileRoot);
  void Write();
  void Write(int *offset, int *size);
  void Write(int offset0, int offset1, int offset2, 
	     int size0, int size1, int size2);
  
  // Description:
  // Set/Get the number of the first image
  vtkSetMacro(First,int);
  vtkGetMacro(First,int);

  // Description:
  // Set/Get the Signed flag
  vtkSetMacro(Signed,int);
  vtkGetMacro(Signed,int);
  vtkBooleanMacro(Signed,int);

  // Description:
  // Set/Get the byte swapping
  vtkSetMacro(SwapBytes,int);
  vtkGetMacro(SwapBytes,int);
  vtkBooleanMacro(SwapBytes,int);
  
  // Description:
  // Set/Get the input object from the image pipline.
  vtkSetObjectMacro(Input,vtkImageSource);
  vtkGetObjectMacro(Input,vtkImageSource);
  
protected:
  // Get you input from this source
  vtkImageSource *Input;
  // Enumeration of image files start with this value (i.e. 0 or 1)
  int First;
  
protected:
  char *FileRoot;
  char *FileName;
  int Signed;
  int SwapBytes;
  
  void WriteSlice(vtkImageRegion *region);  
};

#endif


