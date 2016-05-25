#include <iostream>
#include <fstream>
#include <math.h>
#include <fstream>
#include <Windows.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <tchar.h>
#include <string.h>

using namespace std;



void CONDUCTION_1D_UNIFORM_GRID(double T0 , double Q_vol_gen , int c1 ,int c2 , int c3 , int c4 , int N ,  double L , double W1 , double W2 , double W3 , double W4 , double T_inf , double epsilon_st)
{



	//STEP-1: User-Input
	double rho = 7750;
	double cp = 500;
	double k=16.2;
	int imax = N;

	/*
	1=west
	2=east
	3=north
	4=south
	*/

	//STEP-2: Geometrical Parameter and Stability criterion based time-step
	double alpha = k / (rho*cp);
	double Dx = L / (imax - 2);
	double Dt = 0.99*0.5* (Dx*Dx / alpha);
	double Q_gen = Q_vol_gen*Dx; // Total Heat Generation

						  //STEP-3: IC and BCs
	double * T = new double[imax];
	int i = 0;
	for (i = 0; i < imax; i++)
		T[i] = T0;

	switch (c1)
	{
	case 1:T[0] = W1; 
		break;
	case 2:T[0] = (0.5*W1*Dx/k)+T[1];
		break;
	case 3:T[0] = T[1];
		break;
	case 4:T[0] = ((2 * k*T[1]) + (W1*Dx*T_inf)) / (2 * k + W1*Dx);
		break;
	}

	switch (c2)
	{
	case 1:T[imax-1] = W2;
		break;
	case 2:T[imax - 1] = (0.5*W2*Dx / k) + T[imax-2];
		break;
	case 3:T[imax - 1] = T[imax - 2];
		break;
	case 4:T[imax - 1] = ((2 * k*T[imax - 2]) + (W2*Dx*T_inf)) / (2 * k + W2*Dx);
		break;
	}

	// Coordinates of face centers
	double *x = new double[imax];
	x[0] = 0;
	double C1 = (L / (imax-2));
	for (i = 1; i < imax-1; i++)
		x[i] = C1*i;

	 
	

	// Coordinates of Cell Centers; NEEDED FOR PLOTTING
	double *xc = new double[imax];
	xc[0] = 0;
	xc[imax-1] = L;
	for (i = 1; i < imax-1; i++)
		xc[i] = (x[i]+x[i-1])/2.0;
	

	double unsteadiness_nd = 1; 
	int n = 0;
	double * T_old = new double[imax];
	double *qx_old = new double[imax];
	double *Q_cond_old = new double[imax];
	for (i = 0; i < imax;i++)
	{T_old[i] = T[i];
	qx_old[i] = 0;
	Q_cond_old[i] = 0;
	}
	
	//==== Time-Marching for Explicit Unsteady State LAEs: START ====
	while (unsteadiness_nd >= epsilon_st)
	{
		
		n = n + 1;

		for (i = 0; i < imax; i++)
			T_old[i] = T[i];

		// STEP4: 4. Computation of conduction-flux and temperature
		for (i = 0; i < imax - 1; i++)
		{
			
			if ((i == 0) || (i == imax - 2))
				qx_old[i] = -k*(T_old[i + 1] - T_old[i]) / (Dx / 2.0);
			else
				qx_old[i] = -k*(T_old[i + 1] - T_old[i]) / Dx;
		}

		for (i = 1; i < imax - 1; i++)
		{
			Q_cond_old[i] = (qx_old[i - 1] - qx_old[i]);
			T[i] = T_old[i] + (Dt / (rho*cp*Dx))*(Q_cond_old[i] + Q_gen);
		}

		switch (c1)
		{
		case 1:T[0] = W1;
			break;
		case 2:T[0] = (0.5*W1*Dx / k) + T[1];
			break;
		case 3:T[0] = T[1];
			break;
		case 4:T[0] = ((2 * k*T[1]) + (W1*Dx*T_inf)) / (2 * k + W1*Dx);
			break;
		}

		switch (c2)
		{
		case 1:T[imax - 1] = W2;
			break;
		case 2:T[imax - 1] = (0.5*W2*Dx / k) + T[imax - 2];
			break;
		case 3:T[imax - 1] = T[imax - 2];
			break;
		case 4:T[imax - 1] = ((2 * k*T[imax - 2]) + (W2*Dx*T_inf)) / (2 * k + W2*Dx);
			break;
		}

		double max = 0;
		for (i = 0; i < imax; i++)
		{
			double diff = abs(T_old[i] - T[i]);
			if (diff > max)
				max = diff;
		}
		double unsteadiness = max / Dt;
		unsteadiness_nd = unsteadiness*L*L / (alpha*100); //STEP 5: Steady state converegnce criterion
		printf("Time step no. %2d, Unsteadiness = %8.5e\n", n, unsteadiness);
	}

	for (i = 0; i < imax; i++)
		cout << T[i]<<" ";

	//graphical output
	ofstream out;
	out.open("output.txt");
	out << imax << endl;
	for (i = 0; i < imax; i++)
		out << xc[i] << endl << T[i]<<endl;
	
	out.close();
	ofstream out3;
	out3.open("mesh.txt");
	out3 << (imax - 1)<<endl;
	out3 << 2<<endl;
	for (i = 0; i < imax - 1; i++)
		out3 << x[i] << endl;
	out3 << 0 << endl;
	out3 << (L/10) << endl;
	out3.close();
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Conduction\\MESH.exe"),
		NULL, NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Debug\\LinePlot.exe"),
		NULL, NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	
	cin >> i;

}






void CONDUCTION_1D_NONUNIFORM_GRID(double T0, double Q_vol_gen, int c1, int c2, int c3, int c4, int N,  double L, double W1, double W2, double W3, double W4, double T_inf, double epsilon_st , double Beta)
{



	//STEP-1: User-Input
	double rho = 7750;
	double cp = 500;
	double k = 16.2;
	int imax = N;
	int i = 0;

	double *xi = new double[imax - 1];
	xi[0] = 0;
	double C1 = (L / (imax - 2));
	for (i = 1; i < imax - 1; i++)
		xi[i] = C1*i / L;

	double Beta_p1 = Beta + 1;
	double Beta_m1 = Beta - 1;
	double *x = new double[imax];
	for (i = 0; i < imax - 1; i++)
	{
		double Beta_p1_div_m1 = pow((Beta_p1 / Beta_m1), ((2 * xi[i]) - 1));
		double num = (Beta_p1*Beta_p1_div_m1) - Beta_m1;
		double den = 2 * (1 + Beta_p1_div_m1);
		x[i] = L*num / den;
	}

	

	// Coordinates of Cell Centers; NEEDED FOR PLOTTING
	double *xc = new double[imax];
	xc[0] = 0;
	xc[imax - 1] = L;
	for (i = 1; i < imax - 1; i++)
		xc[i] = (x[i] + x[i - 1]) / 2.0;
	

	/*
	1=west
	2=east
	3=north
	4=south
	*/
	
	//STEP-2: Geometrical Parameter and Stability criterion based time-step
	double alpha = k / (rho*cp);
	double *Dx = new double[imax - 1];
	double *dx = new double[imax - 1];
	for (i = 0; i < imax-1; i++)
	{
		dx[i] = xc[i + 1] - xc[i];
		if (i != 0)
		{
			Dx[i] = x[i] - x[i - 1];
		}
		else
			Dx[i] = 0;
	}
	double Dt = 1.0;
	double *Q_gen = new double[imax - 1];
	for(i=0;i<imax-1;i++)
		Q_gen[i]=Q_vol_gen*Dx[i]; // Total Heat Generation

	
								  
								  
								  //STEP-2: Coefficient of implicit LAEs
	double *aE = new double[imax - 1];
	double *aP0 = new double[imax - 1];
	double *aP = new double[imax - 1];
	for ( i = 0;i<imax - 1;i++)
		aE[i] = k / dx[i];
	
	for (i = 1; i < imax - 1; i++)
	{
		aP0[i] = rho*cp*Dx[i] / Dt;
		aP[i] = aP0[i] + aE[i] + aE[i - 1];
	}
	
								  
							  //STEP-3: IC and BCs
	double * T = new double[imax];
	
	for (i = 0; i < imax; i++)
		T[i] = T0;

	

	
	


	double unsteadiness_nd = 1;
	int n = 0;
	double * T_old = new double[imax];
	double *b = new double[imax];
	double *T_old_iter = new double[imax];



	



	for (i = 0; i < imax; i++)
	{
		T_old[i] = T[i];
		b[i] = 0;
		T_old_iter[i] = 0;
	}
	double max = 0;
	//==== Time-Marching for Explicit Unsteady State LAEs: START ====
	while (unsteadiness_nd >= epsilon_st)
	{

		switch (c1)
		{
		case 1:T[0] = W1;
			break;
		case 2:T[0] = (W1*dx[0] / k) + T[1];
			break;
		case 3:T[0] = T[1];
			break;
		case 4:T[0] = (( k*T[1]) + (W1*dx[0] * T_inf)) / ( k + W1*dx[0]);
			break;
		}

		switch (c2)
		{
		case 1:T[imax - 1] = W2;
			break;
		case 2:T[imax - 1] = (W2*dx[imax - 2] / k) + T[imax - 2];
			break;
		case 3:T[imax - 1] = T[imax - 2];
			break;
		case 4:T[imax - 1] = (( k*T[imax - 2]) + (W2*dx[imax - 2] * T_inf)) / ( k + W2*dx[imax - 2]);
			break;
		}

		n = n + 1;

		for (i = 0; i < imax; i++)
			T_old[i] = T[i];

			
		for (i = 1; i < imax - 1; i++)
		{
           b[i] = aP0[i]*T_old[i] + Q_gen[i];
		}

			// Inner-Loop for Iterative solution (by GS method) at each time step
		double epsilon = epsilon_st;   //Convergence Criterion
		int N = 0;  // Counter for iternation number
		double Error = 1; // some number greater than epsilon to start the while loop below
		while (Error >= epsilon)
		{
			for (i = 0; i < imax; i++)
				T_old_iter[i] = T[i]; // present iterative value stored as old one
				N = N + 1; // increase in the iteration counter
				for (i = 1; i < imax - 1;i++)
				{T[i] = aE[i] * T[i + 1] + aE[i - 1] * T[i - 1] + b[i];
				T[i] = T[i] / aP[i];
				}
				max = 0;
				for (i = 0; i < imax; i++)
				{
					double diff = abs(T_old_iter[i] - T[i]);
					if (diff > max)
						max = diff;
				}
			Error = max; // parameter to check convergence
		}
		

		 max = 0;
		for (i = 0; i < imax; i++)
		{
			double diff = abs(T_old[i] - T[i]);
			if (diff > max)
				max = diff;
		}
		double unsteadiness = max / Dt;
		unsteadiness_nd = unsteadiness*L*L / (alpha * 100); //STEP 5: Steady state converegnce criterion
		printf("Time step no. %5d, Unsteadiness_nd = %8.4e\n", n, unsteadiness_nd);

	}

	for (i = 0; i < imax; i++)
		cout << T[i] << " ";

	//graphical output
	ofstream out;
	out.open("output.txt");
	out << imax << endl;
	for (i = 0; i < imax; i++)
		out << xc[i] << endl << T[i] << endl;

	out.close();

	ofstream out3;
	out3.open("mesh.txt");
	out3 << (imax - 1) << endl;
	out3 << 2 << endl;
	for (i = 0; i < imax - 1; i++)
		out3 << x[i] << endl;
	out3 << 0 << endl;
	out3 << (L / 10) << endl;
	out3.close();
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Conduction\\MESH.exe"),
		NULL, NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Debug\\LinePlot.exe"),
		NULL, NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	
	cin >> i;

}


void CONDUCTION_2D_UNIFORM_GRID(double T0, double Q_vol_gen, int c1, int c2, int c3, int c4, int N1,int N2, double L1,double L2 , double W1, double W2, double W3, double W4, double T_inf, double epsilon_st)
{



	//STEP-1: User-Input
	double rho = 7750;
	double cp = 500;
	double k = 16.2;
	int imax = N1, jmax = N2;

	/*
	1=west
	2=east
	3=north
	4=south
	*/

	//STEP-2: Geometrical Parameter and Stability criterion based time-step
	double alpha = k / (rho*cp);
	double Dx = L1 / (imax - 2);
	double Dy = L2 / (jmax - 2);
	double Dt = 1.0 * 0.5*pow((alpha*((1 /(pow(Dx , 2))) + (1 / (pow(Dy , 2))))) , -1);
	double Q_gen = Q_vol_gen*Dx*Dy; // Total Heat Generation

	int i = 0, j = 0;							 //STEP-3: IC and BCs
	double ** T;
	T=new double*[jmax];
	for (j = 0; j < jmax; j++)
		T[j] = new double[imax];
	for (i = 0; i < imax; i++)
		for(j=0;j<jmax;j++)
		T[j][i] = T0;

	switch (c1)
	{
	case 1:for(j=0;j<jmax;j++)
		T[j][0] = W1;
		break;
	case 2:for (j = 0; j<jmax; j++)
		T[j][0] = (0.5*W1*Dx / k) + T[j][1];
		break;
	case 3:for (j = 0; j<jmax; j++)
		T[j][0] = T[j][1];
		break;
	case 4:for (j = 0; j<jmax; j++)
		T[j][0] = ((2 * k*T[j][1]) + (W1*Dx*T_inf)) / (2 * k + W1*Dx);
		break;
	}

	switch (c2)
	{
	case 1:for (j = 0; j<jmax; j++)
		T[j][imax - 1] = W2;
		break;
	case 2:for (j = 0; j<jmax; j++)
		T[j][imax - 1] = (0.5*W2*Dx / k) + T[j][imax - 2];
		break;
	case 3:for (j = 0; j<jmax; j++)
		T[j][imax - 1] = T[j][imax - 2];
		break;
	case 4:for (j = 0; j<jmax; j++)
		T[j][imax - 1] = ((2 * k*T[j][imax - 2]) + (W2*Dx*T_inf)) / (2 * k + W2*Dx);
		break;
	}

	switch (c3)
	{
	case 1:for (i = 0; i<imax; i++)
		T[jmax-1][i] = W3;
		break;
	case 2:for (i = 0; i<imax; i++)
		T[jmax-1][i] = (0.5*W3*Dy / k) + T[jmax-2][i];
		break;
	case 3:for (i = 0; i<imax; i++)
		T[jmax-1][i] = T[jmax-2][i];
		break;
	case 4:for (i = 0; i<imax; i++)
		T[jmax-1][i] = ((2 * k*T[jmax-2][i]) + (W3*Dy*T_inf)) / (2 * k + W3*Dy);
		break;
	}

	switch (c4)
	{
	case 1:for (i = 0; i<imax; i++)
		T[0][i] = W4;
		break;
	case 2:for (i = 0; i<imax; i++)
		T[0][i] = (0.5*W4*Dy / k) + T[1][i];
		break;
	case 3:for (i = 0; i<imax; i++)
		T[0][i] = T[1][i];
		break;
	case 4:for (i = 0; i<imax; i++)
		T[0][i] = ((2 * k*T[1][i]) + (W4*Dy*T_inf)) / (2 * k + W4*Dy);
		break;
	}
	// Coordinates of face centers
	double *x = new double[imax];
	x[0] = 0;
	double C1 = (L1 / (imax - 2));
	for (i = 1; i < imax - 1; i++)
		x[i] = C1*i;
	double *y = new double[jmax];
	y[0] = 0;
	 C1 = (L2 / (jmax - 2));
	for (j = 1; j < jmax - 1; j++)
		y[j] = C1*j;



	// Coordinates of Cell Centers; NEEDED FOR PLOTTING
	double *xc = new double[imax];
	xc[0] = 0;
	xc[imax - 1] = L1;
	for (i = 1; i < imax - 1; i++)
		xc[i] = (x[i] + x[i - 1]) / 2.0;
	double *yc = new double[imax];
	yc[0] = 0;
	yc[imax - 1] = L2;
	for (j = 1; j < jmax - 1; j++)
		yc[j] = (y[j] + y[j - 1]) / 2.0;


	double unsteadiness_nd = 1;
	int n = 0;
	
	double ** T_old;
	T_old = new double*[jmax];
	for (j = 0; j < jmax; j++)
		T_old[j] = new double[imax];
	
	double ** qx_old;
	qx_old = new double*[jmax];
	for (j = 0; j < jmax; j++)
		qx_old[j] = new double[imax];

	double ** qy_old;
	qy_old = new double*[jmax];
	for (j = 0; j < jmax; j++)
		qy_old[j] = new double[imax];

	double ** Q_cond_old;
	Q_cond_old = new double*[jmax];
	for (j = 0; j < jmax; j++)
		Q_cond_old[j] = new double[imax];

	for (j = 0; j < jmax; j++)
	{

		for (i = 0; i < imax; i++)
		{
			T_old[j][i] = T[j][i];
			qx_old[j][i] = 0;
			qy_old[j][i] = 0;
			Q_cond_old[j][i] = 0;
		}
	}

	//==== Time-Marching for Explicit Unsteady State LAEs: START ====
	while (unsteadiness_nd >= epsilon_st)
	{

		n = n + 1;


		for (j = 0; j < jmax; j++)
		{
			for (i = 0; i < imax; i++)
			{
				T_old[j][i] = T[j][i];
			}
		}

		// STEP4: 4. Computation of conduction-flux and temperature
		for (j = 0; j < jmax - 1; j++)
		{
			for (i = 0; i < imax-1; i++)
			{
				if ((i == 0) || (i == imax - 2))
					qx_old[j][i] = -k*(T_old[j][i + 1] - T_old[j][i]) / (Dx / 2.0);
				else
					qx_old[j][i] = -k*(T_old[j][i + 1] - T_old[j][i]) / Dx ;

				if ((j == 0) || (j == jmax - 2))
					qy_old[j][i] = -k*(T_old[j+1][i ] - T_old[j][i]) / (Dy / 2.0);
				else
					qy_old[j][i] = -k*(T_old[j+1][i] - T_old[j][i]) / Dy;

			}
		}

		for (j = 1; j < jmax - 1; j++)
		{
			for (i = 1; i < imax - 1; i++)
			{
				Q_cond_old[j][i] = ((qx_old[j][i - 1] - qx_old[j][i])*Dy)+ ((qy_old[j - 1][i] - qy_old[j][i])*Dx);
				T[j][i] = T_old[j][i] + (Dt / (rho*cp*Dx*Dy))*(Q_cond_old[j][i] + Q_gen);
			}
		}
		switch (c1)
		{
		case 1:for (j = 0; j<jmax; j++)
			T[j][0] = W1;
			break;
		case 2:for (j = 0; j<jmax; j++)
			T[j][0] = (0.5*W1*Dx / k) + T[j][1];
			break;
		case 3:for (j = 0; j<jmax; j++)
			T[j][0] = T[j][1];
			break;
		case 4:for (j = 0; j<jmax; j++)
			T[j][0] = ((2 * k*T[j][1]) + (W1*Dx*T_inf)) / (2 * k + W1*Dx);
			break;
		}

		switch (c2)
		{
		case 1:for (j = 0; j<jmax; j++)
			T[j][imax - 1] = W2;
			break;
		case 2:for (j = 0; j<jmax; j++)
			T[j][imax - 1] = (0.5*W2*Dx / k) + T[j][imax - 2];
			break;
		case 3:for (j = 0; j<jmax; j++)
			T[j][imax - 1] = T[j][imax - 2];
			break;
		case 4:for (j = 0; j<jmax; j++)
			T[j][imax - 1] = ((2 * k*T[j][imax - 2]) + (W2*Dx*T_inf)) / (2 * k + W2*Dx);
			break;
		}

		switch (c3)
		{
		case 1:for (i = 0; i<imax; i++)
			T[jmax - 1][i] = W3;
			break;
		case 2:for (i = 0; i<imax; i++)
			T[jmax - 1][i] = (0.5*W3*Dy / k) + T[jmax - 2][i];
			break;
		case 3:for (i = 0; i<imax; i++)
			T[jmax - 1][i] = T[jmax - 2][i];
			break;
		case 4:for (i = 0; i<imax; i++)
			T[jmax - 1][i] = ((2 * k*T[jmax - 2][i]) + (W3*Dy*T_inf)) / (2 * k + W3*Dy);
			break;
		}

		switch (c4)
		{
		case 1:for (i = 0; i<imax; i++)
			T[0][i] = W4;
			break;
		case 2:for (i = 0; i<imax; i++)
			T[0][i] = (0.5*W4*Dy / k) + T[1][i];
			break;
		case 3:for (i = 0; i<imax; i++)
			T[0][i] = T[1][i];
			break;
		case 4:for (i = 0; i<imax; i++)
			T[0][i] = ((2 * k*T[1][i]) + (W4*Dy*T_inf)) / (2 * k + W4*Dy);
			break;
		}

		double max = 0;
		for (j = 0; j < jmax; j++)
		{
			for (i = 0; i < imax; i++)
			{
				double diff = abs(T_old[j][i] - T[j][i]);
				if (diff > max)
					max = diff;
			}
		}
		double unsteadiness = max / Dt;
		unsteadiness_nd = unsteadiness*L1*L2 / (alpha * 100); //STEP 5: Steady state converegnce criterion
		printf("Time step no. %2d, Unsteadiness = %8.5e\n", n, unsteadiness);
	}
	double min = T[0][0], max = T[0][0];

	for (j = 0; j < jmax; j++)
	{
		for (i = 0; i < imax; i++)
		{
			cout << T[j][i] << " ";
			if (T[j][i] > max)
				max = T[j][i];
			if (T[j][i] < min)
				min = T[j][i];
		}
		cout << endl;
	}
	//graphical output
	ofstream out;
	out.open("data.vtk");
	out << "# vtk DataFile Version 3.0" << endl << "vtk output" << endl << "ASCII" << endl << "DATASET POLYDATA" << endl;
	int no = imax*jmax;
	out << "POINTS " << no << " float" << endl;
	for (i = 0; i < imax; i++)
	{
		for (j = 0; j < jmax; j++)
		{
			out << (float)xc[i] << " " << (float)yc[j] << " 0" << endl;

		}
	}
	no = (imax - 1)*(jmax - 1);
	out << "POLYGONS " << no << " " << (no * 5) << endl;
	for (i = 0; i < imax - 1; i++)
	{
		for (j = 0; j < jmax - 1; j++)
		{
			no = (i*jmax) + j;
			out << "4 " << no << " " << (no + jmax) << " " << (no + jmax + 1) << " " << (no + 1) << endl;

		}
	}
	no = (imax - 1)*(jmax - 1);
	out << "CELL_DATA " << no << endl;
	no = imax*jmax;
	out << "POINT_DATA " << no << endl;
	out << "SCALARS nodal float" << endl << "LOOKUP_TABLE default" << endl;
	for (i = 0; i < imax; i++)
	{
		for (j = 0; j < jmax; j++)
		{
			out << (float)T[j][i] << endl;

		}
	}

	out.close();

	ofstream out3;
	out3.open("mesh.txt");
	out3 << (imax - 1) << endl;
	out3 << (jmax - 1) << endl;
	for (i = 0; i < imax - 1; i++)
		out3 << x[i] << endl;
	for (j = 0; j < jmax - 1; j++)
		out3 << y[j] << endl;
	out3.close();
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Conduction\\MESH.exe"),
		NULL, NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Debug\\FilledContours.exe"),
		TEXT(" data.vtk 20"), NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	ofstream out2;
	out2.open("m.txt");
	
	out2<< min<<endl;
	out2<< max; out2.close();
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Conduction\\LabelContours.exe"),
		TEXT(" data.vtk 20 "), NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	cout << "MAXIMUM TEMPERATURE " << max << endl;
	cout << "MINIMUM TEMPERATURE " << min << endl;
	
	cin >> i;
}



void CONDUCTION_2D_NONUNIFORM_GRID(double T0, double Q_vol_gen, int c1, int c2, int c3, int c4, int N1, int N2, double L1, double L2, double W1, double W2, double W3, double W4, double T_inf, double epsilon_st, double Beta)
{



	//STEP-1: User-Input
	double rho = 7750;
	double cp = 500;
	double k = 16.2;
	int imax = N1, jmax = N2;

	/*
	1=west
	2=east
	3=north
	4=south
	*/

	//STEP-2: Geometrical Parameter and Stability criterion based time-step
	double alpha = k / (rho*cp);
	
	int i = 0, j = 0;
	double *xi = new double[imax - 1];
	xi[0] = 0;
	double C1 = (L1 / (imax - 2));
	for (i = 1; i < imax - 1; i++)
		xi[i] = C1*i / L1;

	double *yj = new double[jmax - 1];
	yj[0] = 0;
	C1 = (L2 / (jmax - 2));
	for (j = 1; j < jmax - 1; j++)
		yj[j] = C1*j / L1;

	double Beta_p1 = Beta + 1;
	double Beta_m1 = Beta - 1;
	double *x = new double[imax];
	for (i = 0; i < imax - 1; i++)
	{
		double Beta_p1_div_m1 = pow((Beta_p1 / Beta_m1), ((2 * xi[i]) - 1));
		double num = (Beta_p1*Beta_p1_div_m1) - Beta_m1;
		double den = 2 * (1 + Beta_p1_div_m1);
		x[i] = L1*num / den;
	}
	double *y = new double[jmax];
	for (j = 0; j < jmax - 1; j++)
	{
		double Beta_p1_div_m1 = pow((Beta_p1 / Beta_m1), ((2 * yj[j]) - 1));
		double num = (Beta_p1*Beta_p1_div_m1) - Beta_m1;
		double den = 2 * (1 + Beta_p1_div_m1);
		y[j] = L2*num / den;
	}

	// Coordinates of Cell Centers; NEEDED FOR PLOTTING
	double *xc = new double[imax];
	xc[0] = 0;
	xc[imax - 1] = L1;
	for (i = 1; i < imax - 1; i++)
		xc[i] = (x[i] + x[i - 1]) / 2.0;
	double *yc = new double[jmax];
	yc[0] = 0;
	yc[jmax - 1] = L2;
	for (j = 1; j < jmax - 1; j++)
		yc[j] = (y[j] + y[j - 1]) / 2.0;

	double *Dx = new double[imax - 1];
	double *dx = new double[imax - 1];
	for (i = 0; i < imax - 1; i++)
	{
		dx[i] = xc[i + 1] - xc[i];
		if (i != 0)
		{
			Dx[i] = x[i] - x[i - 1];
		}
		else
			Dx[i] = 0;
	}

	double *Dy = new double[jmax - 1];
	double *dy = new double[jmax - 1];
	for (j = 0; j < jmax - 1; j++)
	{
		dy[j] = yc[j + 1] - yc[j];
		if (j != 0)
		{
			Dy[j] = y[j] - y[j - 1];
		}
		else
			Dy[j] = 0;
	}



								 //STEP-3: IC and BCs
	double ** T;
	T = new double*[jmax];
	for (j = 0; j < jmax; j++)
		T[j] = new double[imax];
	for (i = 0; i < imax; i++)
		for (j = 0; j<jmax; j++)
			T[j][i] = T0;

	double ** aN;
	aN = new double*[jmax];
	for (j = 0; j < jmax; j++)
		aN[j] = new double[imax];

	double ** aE;
	aE = new double*[jmax];
	for (j = 0; j < jmax; j++)
		aE[j] = new double[imax];

	double ** aP;
	aP = new double*[jmax];
	for (j = 0; j < jmax; j++)
		aP[j] = new double[imax];

	double ** aP0;
	aP0 = new double*[jmax];
	for (j = 0; j < jmax; j++)
		aP0[j] = new double[imax];

	for (j = 0; j < jmax; j++)
	{

		for (i = 0; i < imax; i++)
		{
			aE[j][i] = 0;
			aP[j][i] = 0;
			aN[j][i] = 0;
			aP0[j][i] = 0;
		}
	}
	double Dt = 5000, max = 0;
	//STEP-2: Coefficient of implicit LAEs
	for (j = 1; j < jmax - 1; j++)
	{
		for (i = 0; i < imax - 1; i++)
		{
			aE[j][i]=k*Dy[j] / dx[i];
		}
	}
	for (j = 0; j < jmax - 1; j++)
	{
		for (i = 1; i < imax - 1; i++)
		{
			aN[j][i] = k*Dx[i] / dy[j];
		}
	}
	for (j = 1; j < jmax - 1; j++)
	{
		for (i = 1; i < imax - 1; i++)
		{
			aP0[j][i] = rho*cp*Dx[i] * Dy[j] / Dt;
			aP[j][i] = aP0[j][i] + aE[j][i] + aE[j][i - 1] + aN[j][i] + aN[j - 1][i];
		}
	}
	

	double ** T_old_iter;
	T_old_iter = new double*[jmax];
	for (j = 0; j < jmax; j++)
		T_old_iter[j] = new double[imax];


	double ** T_old;
	T_old = new double*[jmax];
	for (j = 0; j < jmax; j++)
		T_old[j] = new double[imax];

	double ** b;
	b = new double*[jmax];
	for (j = 0; j < jmax; j++)
		b[j]=new double[imax];



	double unsteadiness_nd = 1;
	int n = 0;

	
	//==== Time-Marching for Explicit Unsteady State LAEs: START ====
	while (unsteadiness_nd >= epsilon_st)
	{

		n = n + 1;

		switch (c1)
		{
		case 1:for (j = 0; j < jmax; j++)
			T[j][0] = W1;
			break;
		case 2:for (j = 0; j < jmax; j++)
			T[j][0] = (W1*dx[0] / k) + T[j][1];
			break;
		case 3:for (j = 0; j < jmax; j++)
			T[j][0] = T[j][1];
			break;
		case 4:for (j = 0; j < jmax; j++)
			T[j][0] = ((k*T[j][1]) + (W1*dx[0] * T_inf)) / (k + W1*dx[0]);
			break;
		}

		switch (c2)
		{
		case 1:for (j = 0; j < jmax; j++)
			T[j][imax - 1] = W2;
			break;
		case 2:for (j = 0; j < jmax; j++)
			T[j][imax - 1] = (W2*dx[imax - 2] / k) + T[j][imax - 2];
			break;
		case 3:for (j = 0; j < jmax; j++)
			T[j][imax - 1] = T[j][imax - 2];
			break;
		case 4:for (j = 0; j < jmax; j++)
			T[j][imax - 1] = ((k*T[j][imax - 2]) + (W2*dx[imax - 2] * T_inf)) / (k + W2*dx[imax - 2]);
			break;
		}

		switch (c3)
		{
		case 1:for (i = 0; i < imax; i++)
			T[jmax - 1][i] = W3;
			break;
		case 2:for (i = 0; i < imax; i++)
			T[jmax - 1][i] = (W3*dy[jmax - 2] / k) + T[jmax - 2][i];
			break;
		case 3:for (i = 0; i < imax; i++)
			T[jmax - 1][i] = T[jmax - 2][i];
			break;
		case 4:for (i = 0; i < imax; i++)
			T[jmax - 1][i] = ((k*T[jmax - 2][i]) + (W3*dy[jmax - 2] * T_inf)) / (k + W3*dy[jmax - 2]);
			break;
		}

		switch (c4)
		{
		case 1:for (i = 0; i < imax; i++)
			T[0][i] = W4;
			break;
		case 2:for (i = 0; i < imax; i++)
			T[0][i] = (W4*dy[0] / k) + T[1][i];
			break;
		case 3:for (i = 0; i < imax; i++)
			T[0][i] = T[1][i];
			break;
		case 4:for (i = 0; i < imax; i++)
			T[0][i] = ((k*T[1][i]) + (W4*dy[0] * T_inf)) / (k + W4*dy[0]);
			break;
		}

		


		for (j = 0; j < jmax; j++)
		{
			for (i = 0; i < imax; i++)
			{
				T_old[j][i] = T[j][i];
			}
		}

		for (j = 1; j < jmax - 1; j++)
		{
			for (i = 1; i < imax - 1; i++)
				b[j][i] = aP0[j][i] * T_old[j][i] + Q_vol_gen*Dx[i] * Dy[j];
		}

		// Inner-Loop for Iterative solution (by GS method) at each time step
		double epsilon = epsilon_st;   //Convergence Criterion
		int N = 0;  // Counter for iternation number
		double Error = 1; // some number greater than epsilon to start the while loop below
		while (Error >= epsilon)
		{
			N = N + 1; // increase in the iteration counter
		//boundary condition
			switch (c1)
			{
			case 1:for (j = 0; j < jmax; j++)
				T[j][0] = W1;
				break;
			case 2:for (j = 0; j < jmax; j++)
				T[j][0] = (W1*dx[0] / k) + T[j][1];
				break;
			case 3:for (j = 0; j < jmax; j++)
				T[j][0] = T[j][1];
				break;
			case 4:for (j = 0; j < jmax; j++)
				T[j][0] = ((k*T[j][1]) + (W1*dx[0] * T_inf)) / (k + W1*dx[0]);
				break;
			}

			switch (c2)
			{
			case 1:for (j = 0; j < jmax; j++)
				T[j][imax - 1] = W2;
				break;
			case 2:for (j = 0; j < jmax; j++)
				T[j][imax - 1] = (W2*dx[imax - 2] / k) + T[j][imax - 2];
				break;
			case 3:for (j = 0; j < jmax; j++)
				T[j][imax - 1] = T[j][imax - 2];
				break;
			case 4:for (j = 0; j < jmax; j++)
				T[j][imax - 1] = ((k*T[j][imax - 2]) + (W2*dx[imax - 2] * T_inf)) / (k + W2*dx[imax - 2]);
				break;
			}

			switch (c3)
			{
			case 1:for (i = 0; i < imax; i++)
				T[jmax - 1][i] = W3;
				break;
			case 2:for (i = 0; i < imax; i++)
				T[jmax - 1][i] = (W3*dy[jmax - 2] / k) + T[jmax - 2][i];
				break;
			case 3:for (i = 0; i < imax; i++)
				T[jmax - 1][i] = T[jmax - 2][i];
				break;
			case 4:for (i = 0; i < imax; i++)
				T[jmax - 1][i] = ((k*T[jmax - 2][i]) + (W3*dy[jmax - 2] * T_inf)) / (k + W3*dy[jmax - 2]);
				break;
			}

			switch (c4)
			{
			case 1:for (i = 0; i < imax; i++)
				T[0][i] = W4;
				break;
			case 2:for (i = 0; i < imax; i++)
				T[0][i] = (W4*dy[0] / k) + T[1][i];
				break;
			case 3:for (i = 0; i < imax; i++)
				T[0][i] = T[1][i];
				break;
			case 4:for (i = 0; i < imax; i++)
				T[0][i] = ((k*T[1][i]) + (W4*dy[0] * T_inf)) / (k + W4*dy[0]);
				break;
			}




			for (j = 0; j < jmax; j++)
			{
				for (i = 0; i < imax; i++)
				{
					T_old_iter[j][i] = T[j][i];
				}
			}
			// present iterative value stored as old one

			for (j = 1; j < jmax - 1; j++)
			{
				for (i = 1; i < imax - 1; i++)
				{
					T[j][i] = aE[j][i] * T[j][i + 1] + aE[j][i - 1] * T[j][i - 1] + aN[j][i] * T[j + 1][i] + aN[j - 1][i] * T[j - 1][i] + b[j][i];
					T[j][i] = T[j][i] / aP[j][i];
				}
			}
			max = 0;
			for (j = 0; j < jmax; j++)
			{
				for (i = 0; i < imax; i++)
				{
					double diff = abs(T_old_iter[j][i] - T[j][i]);
					if (diff > max)
						max = diff;
				}
			}
			Error = max; // parameter to check convergence
		}

		max = 0;
		for (j = 0; j < jmax; j++)
		{
			for (i = 0; i < imax; i++)
			{
				double diff = abs(T_old[j][i] - T[j][i]);
				if (diff > max)
					max = diff;
			}
		}
		double unsteadiness = max / Dt;
		unsteadiness_nd = unsteadiness*L1*L2 / (alpha * 100); //STEP 5: Steady state converegnce criterion
		printf("Time step no. %5d, Unsteadiness) = %8.4e\n", n, unsteadiness_nd);
	}
		



	double min = T[0][0]; max = T[0][0];
		
	for (j = 0; j < jmax; j++)
	{
		for (i = 0; i < imax; i++)
		{
			cout << T[j][i] << " ";
			if (T[j][i] > max)
				max = T[j][i];
			if (T[j][i] < min)
				min = T[j][i];
		}
		cout << endl;
	}
	
	
	//graphical output
	ofstream out;
	out.open("data.vtk");
	out << "# vtk DataFile Version 3.0" << endl<< "vtk output"<<endl<<"ASCII"<<endl<<"DATASET POLYDATA"<<endl;
	int no = imax*jmax;
	out << "POINTS " << no << " float" << endl;
	for (i = 0; i < imax; i++)
	{
		for (j = 0; j < jmax; j++)
		{
			out << (float)xc[i] << " " <<(float) yc[j] << " 0" << endl;

		}
	}
	no = (imax - 1)*(jmax - 1);
	out << "POLYGONS " << no << " "<<(no*5) << endl;
	for (i = 0; i < imax-1; i++)
	{
		for (j = 0; j < jmax - 1; j++)
		{
			no = (i*jmax)+j;
				out << "4 " << no << " " << (no + jmax) << " " << (no + jmax + 1) << " " << (no + 1) << endl;
			
		}
	}
	no = (imax - 1)*(jmax - 1);
	out << "CELL_DATA " << no << endl;
	no = imax*jmax;
	out << "POINT_DATA " << no << endl;
	out << "SCALARS nodal float" << endl<<"LOOKUP_TABLE default"<<endl;
	for (i = 0; i < imax; i++)
	{
		for (j = 0; j < jmax; j++)
		{
			out << (float)T[j][i]<<endl;

		}
	}

	out.close();

	ofstream out3;
	out3.open("mesh.txt");
	out3 << (imax - 1) << endl;
	out3 << (jmax - 1) << endl;
	for (i = 0; i < imax - 1; i++)
		out3 << x[i] << endl;
	for (j = 0; j < jmax - 1; j++)
		out3 << y[j] << endl;
	out3.close();
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Conduction\\MESH.exe"),
		NULL, NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Debug\\FilledContours.exe"),
		TEXT(" data.vtk 20"), NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	ofstream out2;
	out2.open("m.txt");

	out2 << min << endl;
	out2 << max; out2.close();
	CreateProcess
	(
		TEXT("C:\\Users\\Ankush\\Documents\\Visual Studio 2015\\Projects\\Conduction\\Conduction\\LabelContours.exe"),
		TEXT(" data.vtk 20 "), NULL, NULL, FALSE,
		CREATE_NO_WINDOW,
		NULL, NULL,
		&si,
		&pi
	);
	cout << "MAXIMUM TEMPERATURE " << max << endl;
	cout << "MINIMUM TEMPERATURE " << min << endl; 
	
	cin >> i;
	
}

int main()

{
	//CONDUCTION_2D_NONUNIFORM_GRID(30, 50000, 1, 2, 4, 3, 12, 12, 1, 1, 100, 10000, 100, 0, 30, 0.0001, 1.2);
	//CONDUCTION_2D_UNIFORM_GRID(30, 50, 1, 1, 1, 1, 12, 12, 1, 1, 100, 300, 400, 200, 0, 0.0001);
	CONDUCTION_1D_NONUNIFORM_GRID(30, 50, 1, 4, 0, 0, 12, 0.01, 0, 1000, 0, 0, 100, 0.0001, 1.2);
	//CONDUCTION_1D_UNIFORM_GRID(30, 50000, 1, 1, 0, 0, 12, 0.01, 0, 100, 0, 0, 0,0.0001);
	return 1;
}
