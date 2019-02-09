from datetime import datetime
from math import cos, sin, ceil, pi

now = datetime.now()

print(now.strftime("%H:%M:%S"))

clockSize = 20
clock = [[' ' for i in range(clockSize)] for i in range(clockSize)]

def setTime2Clock(time, clock):
    minute = time.minute
    hour = time.hour%12 + minute/60
    mth = -minute/60 * (2*pi) + pi/2
    hth = -hour/12 * (2*pi) + pi/2
    clockRadius = int(ceil(clockSize/2))

    for i in range(clockRadius):
        y = - (clockRadius + int(round(sin(mth)*i)) - 1)
        x = clockRadius + int(round(cos(mth)*i)) - 1
        clock[y][x] = '*'

    for i in range(clockRadius):
        y = - (clockRadius + int(round(sin(hth)*i)) - 1)
        x = clockRadius + int(round(cos(hth)*i)) - 1
        clock[y][x] = '#'

    return clock


def showClock(clock):
    for r in clock:
        for c in r:
            print(c, end=' ')
        print()


clock = setTime2Clock(now, clock)
showClock(clock)
