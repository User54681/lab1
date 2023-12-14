#include <iostream>

const double e = 0.656722629;
const long double Pi = 3.14159265358;
const double eps = 0.00001;
const double a = 7689700;
const double mu = 0.33 * pow(10, 24) * 6.67430 * pow(10, -20);

double radFind(double teta, double p)
{
    return p / (1 + e * cos(teta));
}

double speedRad(double p, double teta)
{
    return sqrt(mu / p) * e * sin(teta);
}

double speedN(double p, double teta)
{
    return sqrt(mu / p) * (1 + e * cos(teta));
}

double fullSpeed(double p, double teta)
{
    double rad = speedRad(p, teta);
    double n = speedN(p, teta);
    return sqrt(rad * rad + n * n);
}

double excentricToTrue(double E)
{
    if (atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2 > 0)
    {
        return atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2;
    }
    else
    {
        return atan(sqrt((1 + e) / (1 - e)) * tan(E / 2)) * 2 + 2 * Pi;
    }
}

double iterationMethod(double Enext, double Enow, double M)
{

    if (fabs(Enow - Enext) < eps)
    {
        //std::cout << Enext << "\t";
        return Enext;//запись в файл
    }
    else
    {
        return iterationMethod(e * sin(Enext) + M, Enext, M);
    }
}

int main()
{
    for (int i = 0; i < 361; i++)
    {
        double p = a * (1 - e * e);
        double teta = excentricToTrue(iterationMethod(e * sin(i * 2 * Pi / 360) + (i * 2 * Pi / 360), i * 2 * Pi / 360, i * 2 * Pi / 360));
        //std::cout << i << "\t" << i * 2 * Pi / 360 << "\t" << i << "\t" << teta << "\t" << i << "\n";
        std::cout << radFind(teta, a * (1 - e * e)) << "\t" << speedRad(p, teta) << "\t" << speedN(p, teta) << "\t" << fullSpeed(p, teta) << "\t" << i << std::endl;
    }
}

