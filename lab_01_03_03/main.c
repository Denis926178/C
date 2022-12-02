#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double speed, boost, time, travel;
    scanf("%lf%lf%lf", &speed, &boost, &time);

    travel = speed * time + boost * time * time / 2;

    printf("%lf\n", travel);

    return EXIT_SUCCESS;
}
