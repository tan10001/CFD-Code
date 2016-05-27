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
#include <algorithm>

using namespace std;

void advection_2d_uniform_all_schemes()  //change w1,w2,w3 for diff schemes
{


	//user input
	double rho = 1000;
	double cp = 4180;
	double alpha = 10;//thermal diffusivity
	int L = 1;
	int H = 1;
	//change to N parameter
	double u = 1, v = 1;
	double epsilon_st = 0.008;
	double mx = rho*u; double my = rho*v;//check
	double k = 20; // thermal conductivity

										 //double L1 = 1, L2 = 1;
	double T0 = 300;
	double W1 = 273, W2 = 274; double W3 = 275, W4 = 276;//input temps of walls
	double w1, w2, w3; // coeff in advection scheme


					   /*
					   1=west
					   2=east
					   3=north
					   4=south
					   */

					   //STEP-2: Geometrical Parameter and Stability criterion based time-step
	int imax = 10;
	int jmax = 10;
	double L1 = 1, L2 = 1;
	//double alpha = k / (rho*cp);
	double Dx = L1 / (imax - 2);
	double Dy = L2 / (jmax - 2);
	double Dt_advec = 1 / ((abs(u) / Dx) + (abs(v) / Dy));
	double Dt_cond = 0.5/alpha*(1/((Dx*Dx)+1/(Dy*Dy)));
	 double Dt = min(Dt_advec, Dt_cond);
 	//double Q_gen = Q_vol_gen*Dx; // Total Heat Generation

	double Q_advec = 0;

	int i = 0, j = 0;							 //STEP-3: IC and BCs
	double ** T;
	T = new double*[jmax];
	for (j = 0; j < jmax; j++)
		T[j] = new double[imax];
	for (i = 0; i < imax; i++)
		for (j = 0; j < jmax; j++)
			T[j][i] = T0;


	for (j = 0; j < jmax; j++) // west side temp
		T[j][0] = W1;

	for (i = 0; i < imax; i++) // south side
		T[0][i] = W2;

	for (j = 0; j < jmax; j++) // east side 
		T[j][imax - 1] = W3;

	for (i = 0; i < imax; i++)  //north side 
		T[jmax - 1][i] = W4;






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

	double ** hx;
	hx = new double*[jmax];
	for (j = 0; j < jmax; j++)
		hx[j] = new double[imax];

	double ** hy;
	hy = new double*[jmax];
	for (j = 0; j < jmax; j++)
		hy[j] = new double[imax];

	double ** H_advec;
	H_advec = new double*[jmax];
	for (j = 0; j < jmax; j++)
		H_advec[j] = new double[imax];

	double ** qx;
	qx = new double*[jmax];
	for (j = 0; j < jmax; j++)
		qx[j] = new double[imax];

	double ** qy;
	qy = new double*[jmax];
	for (j = 0; j < jmax; j++)
		qy[j] = new double[imax];

	double ** Q_cond;
	Q_cond = new double*[jmax];
	for (j = 0; j < jmax; j++)
		Q_cond[j] = new double[imax];



	

	for (j = 0; j < jmax; j++)
	{

		for (i = 0; i < imax; i++)
		{
			T_old[j][i] = T[j][i];
			hx[j][i] = 0;
			hy[j][i] = 0;
			qx[j][i] = 0;
			qy[j][i] = 0;
			Q_cond[j][i] = 0;
			H_advec[j][i] = 0;
		}
	}

	//==== Time-Marching for Explicit Unsteady State LAEs: START ====
	while (unsteadiness_nd >= epsilon_st)
	{

		n = n + 1;



		// STEP4: 4. Computation of conduction-flux and temperature
		for (j = 1; j < jmax - 1; j++)  // enthalpy flux in xdirn 
		{
			for (i = 0; i < imax - 1; i++)
			{
				if (i == 0 || i == imax - 2)
				{
			
					qx[j][i] = -k*(T[j][i+1] - T[j][i]) / (Dx / 2);
					hx[j][i] = max(0, mx)*T[j][i] * cp + min(0, mx)*T[j][i + 1] * cp;
				}
				else
				{
					qx[j][i] = -k*(T[j][i+1] - T[j][i]) / Dx ;

					hx[j][i] = max(0, mx)*(w1*T[j][i + 1] + w2*T[j][i] + w3*T[j][i - 1])*cp + min(0, mx)*(w1*T[j][i] + w2*T[j][i + 1] + w3*T[j][i + 2])*cp;


				}


			}
		}
		for (i = 1; i < imax - 1; i++) //enthalpy flux in y dirn
		{
			for (j = 0; j < jmax - 1; j++)
			{
				if (j == 0 || j == jmax - 2)
				{
					qy[j][i] = -k*(T[j+1][i] - T[j][i]) / (Dy / 2);
					hy[j][i] = max(0, mx)*T[j][i] * cp + min(0, mx)*T[j][i+1] * cp;
				}
				else
				{
					qy[j][i] = -k*(T[j + 1][i] - T[j][i]) / Dy ;

					hy[j][i] = max(0, mx)*(w1*T[j + 1][i] + w2*T[j][i] + w3*T[j - 1][i])*cp + min(0, mx)*(w1*T[j][i] + w2*T[j + 1][i] + w3*T[j + 2][i])*cp;

				}


			}
		}

		for (i = 1; i < imax - 1; i++)
		{
			for (j = 1; j < jmax - 1; j++)
			{

				Q_cond[j][i] = (qx[j][i - 1] - qx[j][i])*Dy + (qy[j - 1][i] - qy[j][i])*Dx;
				H_advec[j][i] = (hx[j][i] - hx[j][i - 1])*Dy + (hy[j][i] - hy[j - 1][i])*Dx;   //calc Hadevection       
				T[j][i] = T_old[j][i] + (Dt / (rho*cp*Dx*Dy))*(Q_cond[j][i] -H_advec[j][i]); // calcultating new temps

			}
		}





		for (j = 0; j < jmax; j++) // loop to update old temps 
		{
			for (i = 0; i < imax; i++)
			{
				T_old[j][i] = T[j][i];
			}
		}


		/*double z = 0;

		for (int i = 1; i < imax - 1; i++)
		{
		for (int j = 1; j < jmax - 1; j++)
		{
		z = z + (T[j][i] - T_old[j][i])*(T[j][i] - T_old[j][i]); // summing up T minus T-old and squaring

		}
		}
		unsteadiness_nd = sqrt(z / ((imax - 2)*(jmax - 2)));//steady state stability criterion
		*/
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
		unsteadiness_nd = max;
		printf("Time step no. %2d, Unsteadiness = %8.5e\n", n, unsteadiness_nd);															//printf("Time step no. %2d, Unsteadiness = %8.5e\n", n, unsteadiness);

	}
}


void advection_2d_nonuniform(double Beta) //all parameters later passed through main
{

	//STEP-1: User-Input
	double rho = 7750;
	double cp = 500;
	//double k = 16.2;
	int imax = 10, jmax = 10;
	double L1 = 100, L2 = 110;
	double epsilon_st = 0.008;
	double u = 1, v = 2;
	double T0 = 293;
	double W3, W4;
	double mx = rho*u;
	double my = rho*v;
	double W1 = 343, W2 = 345; // input boundary conditions
	double w_plus1x, w_plus2x, w_plus3x, w_minus1x, w_minus2x, w_minus3x;
	double w_plus1y, w_plus2y, w_plus3y, w_minus1y, w_minus2y, w_minus3y;
	int which_scheme = 1;// tells the scheme to be used
	double k = 30;//thermal conductivity





						 /*
						 1=west
						 2=east
						 3=north
						 4=south
						 */

						 //STEP-2: Geometrical Parameter and Stability criterion based time-step
						 //double alpha = k / (rho*cp);

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
	double Dt = 5000;
	//double Dt = (1 / ((abs(u) / Dx[(int)ceil((imax - 2) / 2)]) + (abs(v) / Dy[(int)ceil((jmax - 2) / 2)])));

	//STEP-3: IC and BCs
	double ** T;
	T = new double*[jmax];
	for (j = 0; j < jmax; j++)
		T[j] = new double[imax];
	for (i = 0; i < imax; i++)
	{
		for (j = 0; j < jmax; j++)
		{
			T[j][i] = T0;

		}
	}

	//bc for temp

	for (j = 0; j < jmax; j++) // west side temp
	{
		T[j][0] = W1;
		T[j][imax - 1] = W2;
	}
	for (i = 0; i < imax; i++) // south side

	{
		T[0][i] = W3;
		T[jmax - 1][i] = W4;
	}



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
	double  max = 0;
	//STEP-2: Coefficient of implicit LAEs
	for (j = 1; j < jmax - 1; j++)
	{
		for (i = 0; i < imax - 1; i++)
		{
			aE[j][i] = -min(0, mx)*Dy[j]*cp + (k/dx[i])*Dy[j] ;

		}
	}
	for (j = 0; j < jmax - 1; j++)
	{
		for (i = 1; i < imax - 1; i++)
		{
			aN[j][i] = -min(0, my)*Dx[i]*cp + (k/dy[j])*Dx[i];
		}
	}
	for (j = 1; j < jmax - 1; j++)
	{
		for (i = 1; i < imax - 1; i++)
		{
			aP0[j][i] = rho*Dx[i] * Dy[j] *cp/ Dt;
			aP[j][i] = aP0[j][i] + aE[j][i] + aE[j][i - 1] + aN[j][i] + aN[j - 1][i];
		}
	}


	double ** Tx_plus;
	Tx_plus = new double*[jmax];
	for (j = 0; j < jmax; j++)
		Tx_plus[j] = new double[imax];


	double ** Tx_minus;
	Tx_minus = new double*[jmax];
	for (j = 0; j < jmax; j++)
		Tx_minus[j] = new double[imax];

	double ** Ty_plus;
	Ty_plus = new double*[jmax];
	for (j = 0; j < jmax; j++)
		Ty_plus[j] = new double[imax];


	double ** Ty_minus;
	Ty_minus = new double*[jmax];
	for (j = 0; j < jmax; j++)
		Ty_minus[j] = new double[imax];

	double ** b;
	b = new double*[jmax];
	for (j = 0; j < jmax; j++)
		b[j] = new double[imax];

	double ** T_old_iter;
	T_old_iter = new double*[jmax];
	for (j = 0; j < jmax; j++)
		T_old_iter[j] = new double[imax];


	double ** T_old;
	T_old = new double*[jmax];
	for (j = 0; j < jmax; j++)
		T_old[j] = new double[imax];

	double ** Q_advec;
	Q_advec = new double*[jmax];
	for (j = 0; j < jmax; j++)
		Q_advec[j] = new double[imax];

	double unsteadiness_nd = 1;
	int n = 0;



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

		for (i = 1; i < imax - 2; i++)
		{
			for (j = 1; j < jmax - 1; j++)
			{
				// to use diff values of w for diff schemes

				if (which_scheme == 0)  // FOU scheme
				{
					w_plus1x = w_plus3x = w_minus1x = w_minus3x = 0;
					w_plus1y = w_plus3y = w_minus1y = w_minus3y = 0;
					w_plus2x = w_plus2y = 1; // check if both plus and minus are same sign(mostly yes)
					w_plus2y = w_minus2y = 1;



				}

				else if (which_scheme == 1)  // SOU scheme
				{



					w_plus1x = w_minus1x = 0;
					w_minus1y = w_minus1y = 0;
					w_plus2x = (2 * Dx[i] + Dx[i - 1]) / (Dx[i] + Dx[i - 1]);
					w_minus2x = (2 * Dx[i + 1] + Dx[i + 2]) / (Dx[i + 1] + Dx[i + 2]);
					w_plus3x = -Dx[i] / (Dx[i] + Dx[i - 1]);
					w_minus3x = -Dx[i + 1] / (Dx[i + 1] + Dx[i + 2]);
					w_plus2y = (2 * Dy[j] + Dy[j - 1]) / (Dy[j] + Dy[j - 1]);
					w_minus2y = (2 * Dy[j + 1] + Dy[j + 2]) / (Dy[j + 1] + Dy[j + 2]);
					w_plus3y = -Dy[j] / (Dy[j] + Dy[j - 1]);
					w_minus3y = -Dy[j + 1] / (Dy[j + 1] + Dy[j + 2]);



				}
				else if (which_scheme == 2)  // QUICK
				{

					w_plus1x = Dx[i] * (2 * Dx[i] + Dx[i - 1]) / ((Dx[i] + Dx[i + 1])*(Dx[i + 1] + 2 * Dx[i] + Dx[i - 1]));
					w_minus1x = Dx[i + 1] * (2 * Dx[i + 1] + Dx[i + 2]) / ((Dx[i] + Dx[i + 1])*(Dx[i] + 2 * Dx[i + 1] + Dx[i + 2]));
					w_plus2x = Dx[i + 1] * (2 * Dx[i] + Dx[i - 1]) / ((Dx[i] + Dx[i + 1])*(Dx[i + 1] + Dx[i - 1]));
					w_minus2x = Dx[i] * (2 * Dx[i + 1] + Dx[i + 2]) / ((Dx[i] + Dx[i + 1])*(Dx[i] + Dx[i + 2]));
					w_plus3x = -(Dx[i] * Dx[i + 1]) / ((Dx[i] + Dx[i - 1])*(Dx[i] + 2 * Dx[i + 1] + Dx[i - 1]));
					w_minus3x = -(Dx[i] * Dx[i + 1]) / ((Dx[i + 1] + Dx[i + 2])*(Dx[i] + 2 * Dx[i + 1] + Dx[i + 2]));
					w_plus1y = Dy[j] * (2 * Dy[j] + Dy[j - 1]) / ((Dy[j] + Dy[j + 1])*(Dy[j + 1] + 2 * Dy[j] + Dy[j - 1]));
					w_minus1y = Dy[j + 1] * (2 * Dy[j + 1] + Dy[j + 2]) / ((Dy[j] + Dy[j + 1])*(Dy[j] + 2 * Dy[j + 1] + Dy[j + 2]));
					w_plus2y = Dy[j + 1] * (2 * Dy[j] + Dy[j - 1]) / ((Dy[j] + Dy[j + 1])*(Dy[j + 1] + Dy[j - 1]));
					w_minus2y = Dy[j] * (2 * Dy[j + 1] + Dy[j + 2]) / ((Dy[j] + Dy[j + 1])*(Dy[j] + Dy[j + 2]));
					w_plus3y = -Dy[j] * Dy[j + 1] / ((Dy[j] + Dy[j - 1])*(Dy[j] + 2 * Dy[j + 1] + Dy[j - 1]));
					w_minus3y = -Dy[j] * Dy[j + 1] / ((Dy[j+1] + Dy[j + 2])*(Dy[j] + 2 * Dy[j + 1] + Dy[j + 2]));



				}
				else  //CD scheme
				{

					w_plus1x = Dx[i - 1] / (Dx[i - 1] + Dx[i + 1]);
					w_plus2x = Dx[i + 1] / (Dx[i - 1] + Dx[i + 1]);
					w_plus3x = w_minus3x = 0;
					w_minus1x = w_plus2x;
					w_minus2x = w_plus1x;
					w_plus1y =  Dy[j - 1] / (Dy[j - 1] + Dy[j + 1]);
					w_plus2y = Dy[j + 1] / (Dy[j - 1] + Dy[j + 1]);
					w_minus1y = w_plus1y;
					w_minus2y = w_plus2y;
					w_plus3y = w_minus3y = 0;


				}

				Tx_plus[j][i] = w_plus1x*T[j][i + 1] + (w_plus2x - 1)*T[j][i] + w_plus3x*T[j][i - 1];
				Tx_minus[j][i] = w_minus1x*T[j][i] + (w_minus2x - 1)*T[j][i + 1] + w_minus3x*T[j][i + 2];

			}
		}

		for (i = 1; i < imax - 1; i++)
		{
			for (j = 1; j < jmax - 2; j++)
			{
				// to use diff values of w for diff schemes

				if (which_scheme == 0)  // FOU scheme
				{
					w_plus1x = w_plus3x = w_minus1x = w_minus3x = 0;
					w_plus1y = w_plus3y = w_minus1y = w_minus3y = 0;
					w_plus2x = w_plus2y = 1; // check if both plus and minus are same sign(mostly yes)
					w_plus2y = w_minus2y = 1;



				}

				else if (which_scheme == 1)  // SOU scheme
				{




					w_plus1x = w_minus1x = 0;
					w_minus1y = w_minus1y = 0;
					w_plus2x = (2 * Dx[i] + Dx[i - 1]) / (Dx[i] + Dx[i - 1]);
					w_minus2x = (2 * Dx[i + 1] + Dx[i + 2]) / (Dx[i + 1] + Dx[i + 2]);
					w_plus3x = -Dx[i] / (Dx[i] + Dx[i - 1]);
					w_minus3x = -Dx[i + 1] / (Dx[i + 1] + Dx[i + 2]);
					w_plus2y = (2 * Dy[i] + Dy[i - 1]) / (Dy[i] + Dy[i - 1]);
					w_minus2x = (2 * Dy[i + 1] + Dy[i + 2]) / (Dy[i + 1] + Dy[i + 2]);
					w_plus3y = -Dy[i] / (Dy[i] + Dy[i - 1]);
					w_minus3y = -Dy[i + 1] / (Dy[i + 1] + Dy[i + 2]);


				}
				else if (which_scheme == 2)  // QUICK
				{

					w_plus1x = Dx[i] * (2 * Dx[i] + Dx[i - 1]) / ((Dx[i] + Dx[i + 1])*(Dx[i + 1] + 2 * Dx[i] + Dx[i - 1]));
					w_minus1x = Dx[i + 1] * (2 * Dx[i + 1] + Dx[i + 2]) / ((Dx[i] + Dx[i + 1])*(Dx[i] + 2 * Dx[i + 1] + Dx[i + 2]));
					w_plus2x = Dx[i + 1] * (2 * Dx[i] + Dx[i - 1]) / ((Dx[i] + Dx[i + 1])*(Dx[i + 1] + Dx[i - 1]));
					w_minus2x = Dx[i] * (2 * Dx[i + 1] + Dx[i + 2]) / ((Dx[i] + Dx[i + 1])*(Dx[i] + Dx[i + 2]));
					w_plus3x = -(Dx[i] * Dx[i + 1]) / ((Dx[i] + Dx[i - 1])*(Dx[i] + 2 * Dx[i + 1] + Dx[i - 1]));
					w_minus3x = -(Dx[i] * Dx[i + 1]) / ((Dx[i + 1] + Dx[i + 2])*(Dx[i] + 2 * Dx[i + 1] + Dx[i + 2]));
					w_plus1y = Dy[i] * (2 * Dy[i] + Dy[i - 1]) / ((Dy[i] + Dy[i + 1])*(Dy[i + 1] + 2 * Dy[i] + Dy[i - 1]));
					w_minus1y = Dy[i + 1] * (2 * Dy[i + 1] + Dy[i + 2]) / ((Dy[i] + Dy[i + 1])*(Dy[i] + 2 * Dy[i + 1] + Dy[i + 2]));
					w_plus2y = Dy[i + 1] * (2 * Dy[i] + Dy[i - 1]) / ((Dy[i] + Dy[i + 1])*(Dy[i + 1] + Dy[i - 1]));
					w_minus2y = Dy[i] * (2 * Dy[i + 1] + Dy[i + 2]) / ((Dy[i] + Dy[i + 1])*(Dy[i] + Dy[i + 2]));

                                        w_plus3y = -Dy[j] * Dy[j + 1] / ((Dy[j] + Dy[j - 1])*(Dy[j] + 2 * Dy[j + 1] + Dy[j - 1]));
					w_minus3y = -Dy[j] * Dy[j + 1] / ((Dy[j+1] + Dy[j + 2])*(Dy[j] + 2 * Dy[j + 1] + Dy[j + 2]));







				}
				else  //CD scheme
				{


					w_plus1x = Dx[i - 1] / (Dx[i - 1] + Dx[i + 1]);
					w_plus2x = Dx[i + 1] / (Dx[i - 1] + Dx[i + 1]);
					w_plus3x = w_minus3x = 0;
					w_minus1x = w_plus2x;
					w_minus2x = w_plus1x;
					w_plus1y = Dy[j - 1] / (Dy[j - 1] + Dy[j + 1]);
					w_plus2y = Dy[j + 1] / (Dy[j - 1] + Dy[j + 1]);
					w_plus3y = w_minus3y = 0;
					w_minus1y = w_plus1y;
					w_minus2y = w_plus2y;


				}

				Ty_plus[j][i] = w_plus1y*T[j + 1][i] + (w_plus2y - 1)*T[j][i] + w_plus3y*T[j - 1][i];
				Ty_minus[j][i] = w_minus1y*T[j][i] + (w_minus2y - 1)*T[j + 1][i] + w_minus3y*T[j + 2][i];

			}
		}

		for (j = 1; j < jmax - 1; j++) //loop for finding Q_advec
		{
			for (i = 1; i < imax - 1; i++)
			{

				Q_advec[j][i] = ((max(0, mx)*Tx_plus[i - 1][j] + min(0, mx)*Tx_minus[i - 1][j]) - (max(0, mx)*Tx_plus[j][i] + min(0, mx)*Tx_minus[j][i]))*Dy[j] + ((max(0, my)*Ty_plus[j - 1][i] + min(0, my)*Ty_minus[j - 1][i]) - (max(0, my)*Ty_plus[j][i] + min(0, my)*Ty_minus[j][i]))*Dx[i];

			}
		}

		for (j = 1; j < jmax - 1; j++)
		{
			for (i = 1; i < imax - 1; i++)
				b[j][i] = aP0[j][i] * T_old[j][i] + Q_advec[j][i];
		}
		// Inner-Loop for Iterative solution (by GS method) at each time step
		double epsilon = epsilon_st;   //Convergence Criterion
		int N = 0;  // Counter for iternation number
		double Error = 1; // some number greater than epsilon to start the while loop below
		while (Error >= epsilon)
		{
			N = N + 1; // increase in the iteration counter
					   //boundary condition
			for (j = 0; j < jmax; j++)
			{
				for (i = 0; i < imax; i++)
				{
					T_old_iter[j][i] = T[j][i];
				}
			}
			// present iterative value stored as old one


			for (i = 0; i < imax - 1; i++)
			{
				for (j = 0; j < jmax - 1; j++)
				{
					
					
					T[j][i] = aE[j][i] * T[j][i] + (aE[j][i - 1] + mx*Dy[j])*T[j][i - 1] + aN[j][i] * T[j + 1][i] + (aN[j - 1][i] + my*Dx[i])*T[j - 1][i] + b[j][i];
					T[j][i] /= aP[j][i];
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
		unsteadiness_nd = max; // parameter to check convergence

	}

}



int main()

{

	advection_2d_uniform_all_schemes();
//	advection_2d_nonuniform(1.2);
	return 0;

}
