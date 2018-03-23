// running.c -- A useful program for runners
#include <stdio.h>
const int S_PER_M = 60;         // seconds in 1 minute
const int S_PER_H = 3600;       // seconds in 1 hour
const double M_PER_K = 0.62137; // miles in 1 kilometer
int main(void)
{
    double distk, distm;        // distance runned (count in kilometer and mile, seperately)
    double rate;                // average speed (count in km/h)
    int min, sec;               // time usage runned (count in minute and second, seperately)
    int time;                   // time usage runned (count in second)
    double mtime;               // time usage running 1 mile, count in second
    int mmin, msec;             // time usage running 1 mile, count in minute and second, seperately
    printf("This program converts your time for a metric race\n");
    printf("to a time for running a mile and to your average\n");
    printf("speed in miles per hour.\n");
    printf("Please enter, in kilometers, the distance run.\n");
    scanf("%lf", &distk);       // %lf reprensents reading a double variable
    printf("Next enter the time in minutes and seconds.\n");
    printf("Begin by entering the minutes.\n");
    scanf("%d", &min);
    printf("Now enter the seconds.\n");
    scanf("%d", &sec);
    time = S_PER_M * min + sec; // convert time into seconds
    distm = M_PER_K * distk;    // convert kilometers into miles
    rate = distm / time * S_PER_H;  // mile/s * s/hour = mile/h
    mtime = (double)time / distm;   // time/distance = time usage running 1 mile
    mmin = (int)mtime / S_PER_M;    // calculate minutes
    msec = (int)mtime % S_PER_M;    // calculate seconds left
    printf("You ran %1.2f km (%1.2f miles) in %d min, %d sec.\n", distk, distm, min, sec);
    printf("That pace corresponds to running a mile in %d min, ", mmin);
    printf("%d sec.\nYour average speed was %1.2f mph.\n", msec, rate);
    return 0;
}