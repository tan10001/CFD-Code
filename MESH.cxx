#include <vtkVersion.h>
#include <vtkSmartPointer.h>
#include <vtkRectilinearGrid.h>
#include <vtkMath.h>
#include <vtkDataSetMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkShrinkFilter.h>
#include <vtkDoubleArray.h>
#include <fstream>

int main(int, char *[])
{

	ifstream in;
	in.open("mesh.txt");
	int imax, jmax;
	in >> imax;
	in >> jmax;
	double *x; x = new double[imax ];
	double *y; y = new double[jmax ];
	int i = 0, j = 0;
	for (i = 0; i < imax ; i++)
		in >> x[i];
	for (j = 0; j < jmax ; j++)
		in >> y[j];
	// Create a grid
	vtkSmartPointer<vtkRectilinearGrid> grid =
		vtkSmartPointer<vtkRectilinearGrid>::New();

	grid->SetDimensions(imax, jmax, 1);

	vtkSmartPointer<vtkDoubleArray> xArray =
		vtkSmartPointer<vtkDoubleArray>::New();
	for(i=0;i<imax;i++)
		xArray->InsertNextValue(x[i]);
	

	vtkSmartPointer<vtkDoubleArray> yArray =
		vtkSmartPointer<vtkDoubleArray>::New();
	for(j=0;j<jmax;j++)
	yArray->InsertNextValue(y[j]);

	vtkSmartPointer<vtkDoubleArray> zArray =
		vtkSmartPointer<vtkDoubleArray>::New();
	zArray->InsertNextValue(0.0);


	grid->SetXCoordinates(xArray);
	grid->SetYCoordinates(yArray);
	grid->SetZCoordinates(zArray);

	vtkSmartPointer<vtkShrinkFilter> shrinkFilter =
		vtkSmartPointer<vtkShrinkFilter>::New();
#if VTK_MAJOR_VERSION <= 5
	shrinkFilter->SetInputConnection(grid->GetProducerPort());
#else
	shrinkFilter->SetInputData(grid);
#endif
	shrinkFilter->SetShrinkFactor(.99);

	// Create a mapper and actor
	vtkSmartPointer<vtkDataSetMapper> mapper =
		vtkSmartPointer<vtkDataSetMapper>::New();
	mapper->SetInputConnection(shrinkFilter->GetOutputPort());

	vtkSmartPointer<vtkActor> actor =
		vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	// Visualize
	vtkSmartPointer<vtkRenderer> renderer =
		vtkSmartPointer<vtkRenderer>::New();
	vtkSmartPointer<vtkRenderWindow> renderWindow =
		vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->AddRenderer(renderer);
	vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();
	renderWindowInteractor->SetRenderWindow(renderWindow);

	renderer->AddActor(actor);

	renderWindow->Render();
	renderWindowInteractor->Start();

	return EXIT_SUCCESS;
}

/*
#include <vtkVersion.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkChartXY.h>
#include <vtkTable.h>
#include <vtkPlot.h>
#include <vtkFloatArray.h>
#include <vtkContextView.h>
#include <vtkContextScene.h>
#include <vtkPen.h>
#include <fstream>
#include <iostream>
#include "vtkAxis.h"
#include "vtkPlotPoints.h"




using namespace std;
 
int main(int, char *[])
{
	ifstream in;
	in.open("output.txt");
    int imax,jmax;
	in >> imax;
	in >> jmax;
	double *x; x = new double[imax-1];
	double *y; y = new double[jmax-1];
	double *xc; xc = new double[imax];
	double *yc; yc = new double[jmax];
	int i = 0, j = 0;
	for (i = 0; i < imax - 1; i++)
		in >> x[i];
	for (j = 0; j < jmax - 1; j++)
		in >> y[j];
	for (i = 0; i < imax ; i++)
		in >> xc[i];
	for (j = 0; j < jmax ; j++)
		in >> yc[j];
	

  // Create a table with some points in it
  vtkSmartPointer<vtkTable> table = 
    vtkSmartPointer<vtkTable>::New();
  vtkSmartPointer<vtkContextView> contextView;
 
  vtkSmartPointer<vtkFloatArray> arrX = 
    vtkSmartPointer<vtkFloatArray>::New();
  arrX->SetName("X ");
  table->AddColumn(arrX);
  for (j = 1; j < jmax; j++)
  {
	  vtkSmartPointer<vtkFloatArray> arrS =
		  vtkSmartPointer<vtkFloatArray>::New();
	  arrS->SetName("Y");
	  table->AddColumn(arrS);
  }
 
  
  
 
  // Set up the view
  vtkSmartPointer<vtkContextView> view = 
    vtkSmartPointer<vtkContextView>::New();
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);

  
  table->SetNumberOfRows((imax-1));
  // Horizontal lines
  for (i = 0; i < imax - 1; i++)
  {
	  table->SetValue(i, 0, x[i]);
	  for (j = 0; j < jmax - 1; ++j)
	  {
		  
		  table->SetValue(i, j+1, y[j]);
		 

	  }
  }
	  vtkSmartPointer<vtkChartXY> chart =
		  vtkSmartPointer<vtkChartXY>::New();
	  view->GetScene()->AddItem(chart);
	  vtkPlot *line = chart->AddPlot(vtkChart::LINE);
	  chart->SetTitle("MESH");

	  // chart->SetShowLegend(true);
	   //auto legend = chart->GetLegend();
	  chart->SetDrawAxesAtOrigin(true);
	  chart->SetShowLegend(true);


	  chart->GetAxis(vtkAxis::LEFT)->SetTitle("Y-coordinate");


	  chart->GetAxis(vtkAxis::BOTTOM)->SetTitle("X-coordinate");




	  for (j = 1; j < jmax; j++)
	  {
#if VTK_MAJOR_VERSION <= 5
		  line->SetInput(table, 0, j);
#else
		  line->SetInputData(table, 0, j);
#endif

		  line->SetColor(0, 255, 0, 255);
		  line->SetWidth(1.0);
		  line = chart->AddPlot(vtkChart::LINE);
	  }

 //points
  vtkPlot *points = chart->AddPlot(vtkChart::POINTS);
  points->SetInputData(table.GetPointer(), 0, 1);
  points->SetColor(0, 0, 0, 255);
  points->SetWidth(1.0);
 points->SetLabel("CELL CENTRE");
  vtkPlotPoints::SafeDownCast(points)->SetMarkerStyle(vtkPlotPoints::CIRCLE);

// Start interactor
view->GetInteractor()->Initialize();
view->GetInteractor()->Start();

return EXIT_SUCCESS;
}
*/