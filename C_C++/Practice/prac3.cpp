#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function to calculate the maximum volume given the surface area S
double calculate_max_volume(double S)
{
    // Derived formula to calculate max volume using given surface area
    double base_area = S / 5; // Approximate optimal base area
    double a = sqrt(base_area);
    double h = sqrt(S / 2.0 - base_area);

    double aa = sqrt( S/( 1+1/sqrt(2)));
    return (aa * aa * aa) / 6.0;
}

int main()
{
    double S;
    cout << fixed << setprecision(4); // Set precision for output

    // Read input until a negative value is encountered
    while (cin >> S && S >= 0)
    {
        double max_volume = calculate_max_volume(S);
        cout << max_volume << endl;
    }

    return 0;
}
