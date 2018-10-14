#include<iostream>
#include<cstdio>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

 
//main avec la fonction decomposition utilisant la méthode LU, et la résolution de système
    
int main(int argc, char **argv){


        void decomposition(float[][500], float[][500], float[][500], int n);
	void resolution(float [][500], float [][500], float [][500], float [][500], float [][500], int n);
	void output(float[][500], int);

        float A[500][500], L[500][500], U[500][500], B[500][500], X[500][500], Y[500][500];
	int n = 0, i = 0, j = 0; //initialisation des indices


	//Affichage pour l'initialisation de la matrice A et la matrice B
        cout << "Enter size of A : "; //taille de la matrice a
	cin >> n; //valable pour B
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++)
		{
			A[i][j]=rand();
			B[i][j]=rand();
		}
	}
	


        decomposition(A, L, U, n); // on applique la décomposition lu à la matrice A que l'on vient de rentrer
	resolution(B,L,U,Y,X,n);  // on applique la résolution d'équation grâce à la méthode de remontée et descente	

	


	cout << "\nX result\n\n";
	output(X, n);


        return 0;

    }

//fonction de la décomposition 

	void decomposition(float A[][500], float L[][500], float U[][500], int n)
	{
		int i = 0, j = 0, k = 0;

		for (i = 0; i < n; i++) //matrice L and U
		{
			for (j = 0; j < n; j++)
			{
				if (j < i)
					L[j][i] = 0;
				else
				{
					L[j][i] = A[j][i];
				 	for (k = 0; k < i; k++)
					{
						L[j][i] = L[j][i] - L[j][k] * U[k][i];
					}
				}
			}
			for (j = 0; j < n; j++)   // matrice U
			{
				if (j < i)
					U[i][j] = 0;
				else if (j == i)
					U[i][j] = 1;
				else
				{
					U[i][j] = A[i][j] / L[i][i];
					for (k = 0; k < i; k++)
					{
						U[i][j] = U[i][j] - ((L[i][k] * U[k][j]) / L[i][i]);
					}
				}
			}
		}
	}

// Résolution du système LU X = B avec A=LU

	void resolution(float B[][500], float L[][500], float U[][500],float Y[][500], float X[][500], int n)

    	{
		// y=l^(-1)*b

        	int i = 0, j = 0,k=0;

		Y[0][0] = (B[0][0])/(L[0][0]);//facile à calculer
		for (k = 0; k < n; k++)
		{
        		for (i = 1; i < n; i++) //matrice Y
			{

	    			Y[i][k] = (1/(L[i][i]))*(B[i][k]);
            			for (j = 0; j < i; j++)
	   			{
					Y[i][k] = Y[i][k] - (L[i][j]*Y[j][k])/L[i][i] ;
	    			}

         		}
		}
		//x=u^(-1)*y

        	X[n-1][n-1]=(Y[n-1][n-1])/ U[n-1][n-1]; //facile à calculer
  		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n-1; i++)   // matrice X
			{
	    			X[i][k] = (1/(U[i][i]))*(Y[i][k]);
            			for (j = i+1; j < n; j++)
	    			{
					X[i][k] = X[i][k]- (U[i][j]*X[j][k])/U[i][i] ;
				}
			}
    		}
	}
           



//fonction pour le document output 

	void output(float x[][500], int n)
	{
		int i = 0, j = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				printf("%f ", x[i][j]);
			}
		cout << "\n";
		}
	}

	
