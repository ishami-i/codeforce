#include <iostream>

using namespace std;

int main() {
    cout << "Enter the height of the tower in meters: ";
    double x;
    cin >> x;

    const double grav {9.8};

    int sec = 0;

    while(true) {
        double dist_cov = 0.5 * grav * sec * sec;
        double current_position = x - dist_cov;

        if (current_position <= 0.0) {
            cout << "At " << sec << "seconds, the ball is on the ground.";
            break; 
        }

        cout << "At " << sec << " seconds, the ball is at height: " << current_position << "meters";
        sec++;
    }
    return 0;
}