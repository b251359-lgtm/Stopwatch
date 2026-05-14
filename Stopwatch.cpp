#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

class DigitalTimer
{
private:
    int totalSeconds;

public:
    // Constructor
    DigitalTimer(int h, int m, int s)
    {
        totalSeconds = (h * 3600) + (m * 60) + s;
    }

    // Display Timer
    void displayTime()
    {
        int hours = totalSeconds / 3600;
        int minutes = (totalSeconds % 3600) / 60;
        int seconds = totalSeconds % 60;

        cout << setw(2) << setfill('0') << hours << " : "
             << setw(2) << setfill('0') << minutes << " : "
             << setw(2) << setfill('0') << seconds << endl;
    }

    // Start Timer
    void start()
    {
        while (totalSeconds >= 0)
        {
            system("cls");

            cout << "=====================================\n";
            cout << "        DIGITAL COUNTDOWN TIMER\n";
            cout << "=====================================\n\n";

            displayTime();

            if (totalSeconds == 0)
            {
                cout << "\nTIME'S UP!\n";
                break;
            }

            Sleep(1000); // 1000 milliseconds = 1 second

            totalSeconds--;
        }
    }
};

int main()
{
    int h, m, s;

    cout << "=====================================\n";
    cout << "        DIGITAL COUNTDOWN TIMER\n";
    cout << "=====================================\n\n";

    cout << "Enter Hours   : ";
    cin >> h;

    cout << "Enter Minutes : ";
    cin >> m;

    cout << "Enter Seconds : ";
    cin >> s;

    // Validation
    if (h < 0 || m < 0 || s < 0)
    {
        cout << "\nInvalid Input!\n";
        return 0;
    }

    if (m >= 60 || s >= 60)
    {
        cout << "\nMinutes and Seconds should be less than 60!\n";
        return 0;
    }

    DigitalTimer timer(h, m, s);

    timer.start();

    return 0;
}