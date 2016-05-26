
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
    int no;
	in >> no;
	

  // Create a table with some points in it
  vtkSmartPointer<vtkTable> table = 
    vtkSmartPointer<vtkTable>::New();
  vtkSmartPointer<vtkContextView> contextView;
 
  vtkSmartPointer<vtkFloatArray> arrX = 
    vtkSmartPointer<vtkFloatArray>::New();
  arrX->SetName("X ");
  table->AddColumn(arrX);
 
  vtkSmartPointer<vtkFloatArray> arrS = 
    vtkSmartPointer<vtkFloatArray>::New();
  arrS->SetName("Temperature");
  table->AddColumn(arrS);
 
  // Fill in the table with some example values
  int numPoints = no;
  
  table->SetNumberOfRows(numPoints);
  for (int i = 0; i < numPoints; ++i)
  {
	  
	  double pt;
	  in>>pt ;
      table->SetValue(i, 0, pt);
	  in >> pt;
      table->SetValue(i, 1, pt);
    
  }
 
  // Set up the view
  vtkSmartPointer<vtkContextView> view = 
    vtkSmartPointer<vtkContextView>::New();
  view->GetRenderer()->SetBackground(1.0, 1.0, 1.0);

 
  // Add multiple line plots, setting the colors etc
  vtkSmartPointer<vtkChartXY> chart = 
    vtkSmartPointer<vtkChartXY>::New();
  view->GetScene()->AddItem(chart);
  vtkPlot *line = chart->AddPlot(vtkChart::LINE);
  chart->SetTitle("TEMPERATURE");

 // chart->SetShowLegend(true);
  //auto legend = chart->GetLegend();
  chart->SetDrawAxesAtOrigin(true);
  chart->SetShowLegend(true);
 

  chart->GetAxis(vtkAxis::LEFT)->SetTitle("Temperature");
  

  chart->GetAxis(vtkAxis::BOTTOM)->SetTitle("X-coordinate");


  


#if VTK_MAJOR_VERSION <= 5
  line->SetInput(table, 0, 1);
#else
  line->SetInputData(table, 0, 1);
#endif
  line->SetColor(0, 255, 0, 255);
  line->SetWidth(1.0);
  line = chart->AddPlot(vtkChart::LINE);


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
