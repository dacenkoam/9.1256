#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void one(){
    int j,i, m, n,k=0;
    int **a;
    int *b;
    printf("Vvedite kol-vo strok i stolbtsov\n");
    scanf("%d%d", &m, &n);
    a = (int**) malloc(m*sizeof(int*));
    for (i = 0; i < m; i++) {
        a[i] = (int*) malloc(n*sizeof(int));
    }
    b=(int*) calloc (m*n, sizeof(int));

    printf("Vvedite elementy massiva\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            b[i*n+j]=a[i][j];
    } }

    for(k=0; k<m*n; k++)
            printf("%d ",b[k]);
    printf("\n");
    for (i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
    free(b);
    return 0;
}


void two(){
    int j,i, m, n,k=0;
    int **a;
    int *b;
    printf("Vvedite kol-vo strok i stolbtsov\n");
    scanf("%d%d", &m, &n);
    a = (int**) malloc(m*sizeof(int*));
    for (i = 0; i < m; i++) {
        a[i] = (int*) malloc(n*sizeof(int));
    }
    b=(int*) calloc (m*n, sizeof(int));
    printf("Vvedite elementy massiva\n");
    for(k=0;k<m*n;k++){
        scanf("%d",&b[k]);
        a[k/n][k%n]=b[k];
        }

    for(i=0; i<m; i++, printf("\n"))
        for(j=0; j<n; j++)
            printf("%4d",a[i][j]);
    printf("\n");
    for (i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
    free(b);

}

int odin(){
    int n;
    while(1){
        printf("1 - preobrazovat' v odnomerny massiv \n2 - preobrazovat' v dvumerny massiv\n0 - exit\n");
        scanf("%d", &n);
        switch(n){
        case 1:
            one();
            break;
        case 2:
            two();
            break;
        case 0:
            return;
        }}

}
void linne(int **a, int m, int n){

        int i,j,k=0;
        for (i = 0; i < m; i++) {
        k=i+1;
        j=0;

        while((k>1)&&(j<n)) {
            a[i][j]=k;
            k--;j++;
        }


        while(j<n){
            a[i][j]=k;
            k++;j++;
        }
    }
}

void spiral(int **a, int m, int n){

    int i,j,k,s=1;
    for (j = 0; j < n; j++) {
            a[0][j] = s;
            s++;
        }
    for (i = 1; i < m; i++) {
            a[i][n - 1] = s;
            s++;
        }
    for (j = n - 2; j >= 0; j--) {
            if (a[m - 1][j]!=0)  break;
            a[m - 1][j] = s;
            s++;
        }
    for (i = m - 2; i > 0; i--) {
            if  ( a[i][0]!=0) break;
            a[i][0] = s;
            s++;
        }
    i = 1;
    j = 1;

    while (s <= m * n) {
            while (a[i][j + 1] == 0) {
                a[i][j] = s;
                s++;j++;

            }
            while (a[i + 1][j] == 0) {
                a[i][j] = s;
                s++;i++;

            }
            while (a[i][j - 1] == 0) {
                a[i][j] = s;
                s++;j--;

            }
            while ((a[i - 1][j] == 0) ||(s==m*n)) {
                a[i][j] = s;
                s++;i--;

            }
        }
}

int dva(){
    int **a;
    int m,n, i,j;
    printf("Vvedite kol-vo strok i stolbtsov\n");
    scanf("%d%d", &m, &n);
    a = (int**) malloc(m*sizeof(int*));
    for (i = 0; i < m; i++) {
        a[i] = (int*) calloc(n,sizeof(int));
    }

    int y;
    printf("1 - sdelat' tak\n1 2 3 4 5\n2 1 2 3 4\n3 2 1 2 3\n4 3 2 1 2\n5 4 3 2 1\n\n2 - sdelat' vot tak\n1  2  3  4  5\n16 17 18 19 6\n15 24 25 20 7\n14 23 22 21 8\n13 12 11 10 9\n");
    scanf("%d", &y);
    switch(y){
    case 1:
        linne(a,m,n);
        break;
    case 2:
        spiral(a,m,n);
        break;
    }
    for(i=0; i<m; i++, printf("\n"))
        for(j=0; j<n; j++)
            printf("%4d",a[i][j]);
    printf("\n");
    for (i = 0; i < m; i++) {
        free(a[i]);
    }
    free(a);
    return 0;
}
int diagonal(double **a, int n, int m){
    int k=0, index;
    double max;
    while (k < n)
  {
        max = fabs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
        if (fabs(a[i][k]) > max)
        {
            max = fabs(a[i][k]);
            index = i;
        }
        }//ищем максимум в столбце



        if (max < 0.000001)
        {
            printf("Something went wrong");
            return 0;  //столбец нулевой, всё плохо
        }
        int* temp = a[index];
        a[index] = a[k];
        a[k] = temp;     //меняем строки
        for (int i = k; i < n; i++)
            {
                double temp = a[i][k];
                if (fabs(temp) < 0.000001) continue;
                for (int j = 0; j < n+m; j++)
                    a[i][j] = a[i][j] / temp;//делим строку на элемент из главной диагонали
                if (i == k)  continue;
                for (int j = 0; j < n+m; j++)
                    a[i][j] = a[i][j] - a[k][j];//вычитаем строку из строк ниже этой строки
            }
    k++;
  }


    return 1;
}


void root(double **a, int n, int m){     //обратный ход
    for (int i = n - 1; i > -1; i--)
    {
        for (int row = i - 1; row > -1; row--)
        {
            double b = a[row][i] / a[i][i];
            for (int col = n+m; col > -1; col--)
                a[row][col] = a[row][col] - a[i][col] * b;

        }
    }



}

int multiplication(double **a, double **aa, double **c, int n)
{   int i,j,k;


  // Умножение матриц

    for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
    {
        c[i][j] = 0;
        for(k = 0; k < n; k++)
            c[i][j] += a[i][k+n] * aa[k][j];
    }




  return 0;}

int pyat()
{
    int j,i, n=2,k=0;
    double **a;
    printf("Vvedite kol-vo uravneniy\n");
    scanf("%d", &n);
    a = (double**) malloc(n*sizeof(double*));
    for (i = 0; i < n; i++) {
        a[i] = (double*) malloc((n+1)*sizeof(double));
    }
    printf("Введите коэффициенты в виде:\nа11 а12 а13 ... а1n b1\nа21 а22 а23 ... а2n b2\n... ... ... ... ... ...\nam1 am2 am3 ... amn bn\n");
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            scanf("%lf",&a[i][j]);
    } }
    int t = diagonal(a,n,1);
    if (t!=0){
    printf("Единицы на главной диагонали\n");
    for(i=0; i<n; i++, printf("\n"))
        for(j=0; j<n+1; j++)
            printf("%8.4lf  ",a[i][j]);
    root(a,n,1);
    printf("Единичная матрица \n");
    for(i=0; i<n; i++, printf("\n"))
        for(j=0; j<n+1; j++)
            printf("%8.4lf  ",a[i][j]);
    printf("Корни уравнения:");
    for (int i = 0; i < n; i++)
        printf("\n%lf   ", a[i][n]);}

    return 0;
}






int shest()
{
    int j,i,  n=2,k=0;

    double **a,**aa, **c;
    double el;
    printf("Введите количество строк\n");
    scanf("%d", &n);
    a = (double**) malloc(n*sizeof(double*)); //матрица (вводимая матрица|единичная матрица)
    aa = (double**) malloc(n*sizeof(double*)); //копия левой половины матрицы
    c = (double**) malloc(n*sizeof(double*));  //массив произведения
    for (i = 0; i < n; i++) {
        a[i] = (double*) calloc(2*n, sizeof(double));
        aa[i] = (double*) calloc(n, sizeof(double));
        c[i] = (double*) calloc(n, sizeof(double));
    }
    printf("Введите коэффициенты\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&el);
            a[i][j]=el;
            aa[i][j]=el;
    } }

    for(i=0;i<n;i++){
            a[i][i+n]=1;
    }
    printf("\nВведённая матрица:\n");
    for(i=0; i<n; i++, printf("\n"))
        for(j=0; j<2*n; j++)
            printf("%8.4lf  ",a[i][j]);
    printf("\n");
    int t = diagonal(a,n,n);
    if (t!=0){
//        for(i=0; i<n; i++, printf("\n"))
//            for(j=0; j<2*n; j++)
//                printf("%8.4lf  ",a[i][j]);
//        printf("\n");
        root(a,n,n);
        printf("\nПриведение матрицы слева к единичному виду:\n");
        for(i=0; i<n; i++, printf("\n"))
            for(j=0; j<2*n; j++)
                printf("%8.4lf  ",a[i][j]);
        printf("\nПолученная обратная матрица:\n");
        for(i=0; i<n; i++, printf("\n"))
            for(j=n; j<2*n; j++)
                printf("%8.4lf  ",a[i][j]);
        multiplication(a,aa,c, n);
        printf("\nПроизведение матриц:\n");
        for(i=0; i<n; i++, printf("\n"))
            for(j=0; j<n; j++)
                printf("%8.4lf  ",c[i][j]);

}

    return 0;
}

int main(){
    int nnn;
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    while (1){
    printf("\n1 - 9.1 \n2 - 9.2\n5 - 9.5 \n6 - 9.6 \n0 - leave\n");
    scanf("%d",&nnn);
    switch(nnn){
    case 1:
        odin();
        break;

    case 2:
        dva();
        break;

    case 5:
        pyat();
        break;
    case 6:
        shest();
        break;

    case 0:return 0;
    }}



}






