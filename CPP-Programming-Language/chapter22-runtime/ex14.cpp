#include <iostream>
#include <cmath>
#include <stdint.h>
#include <X11/Xlib.h>

// Build with:
// g++ -o ex14 ex14.cpp -lX11

// The distribution is a bit clumpy, which I understand as a normal
// pattern for random numbers. Looks a little like static on a TV.
// Overall, the distribution is uniform across all parts of the window.
namespace runtime {
    class Randint {
        uint32_t randx;
    public:
        Randint(int32_t s = 0) : randx(s) { }
        void seed(int32_t s) { randx = s; }

        static int32_t abs(int32_t x) { return x & 0x7fffffff; }
        static double max() { return 2147483648.0; }
        int32_t draw() { return randx = randx * 1103515245 + 12345; }
        double fdraw() { return abs(draw())/max(); }
        int32_t operator()() { return abs(draw()); }
    };

    class Urand : public Randint {
        int32_t n;
    public:
        Urand(int32_t nn) : n(nn) { }
        int32_t operator()() { int32_t r = n*fdraw(); return (r == n) ? n-1 : r; }
    };
}

void draw(Display* disp, Window win) {
    GC gc = XCreateGC(disp, win, 0, 0);
    XSetForeground(disp, gc, 0x0000ff);
    runtime::Urand rand(400);
    for (int i = 0; i < 100000; i++) {
        int x = rand();
        int y = rand();
        XDrawPoint(disp, win, gc, x, y);
    }
    XFreeGC(disp, gc);
}

int main() {
    using namespace std;

    Display* disp;
    Window win;

    if (!(disp = XOpenDisplay(NULL))) {
        cerr << "Unable to open display.\n";
        return 1;
    }

    int screen = DefaultScreen(disp);
    win = XCreateSimpleWindow(disp, RootWindow(disp, screen), 0, 0, 400, 400, 0, 0, 0xffffff);
    if (!win) {
        cerr << "Could not create window.\n";
        return 1;
    }

    Atom wm_delete = XInternAtom(disp, "WM_DELETE_WINDOW", false);
    XSetWMProtocols(disp, win, &wm_delete, 1);
    XSelectInput(disp, win, StructureNotifyMask | ExposureMask);
    XMapWindow(disp, win);
    for (;;) {
        XEvent e;
        XNextEvent(disp, &e);
        if (e.type == MapNotify || e.type == Expose)
            draw(disp, win);
        else if (e.xclient.data.l[0] == wm_delete)
            break;
    }

    XCloseDisplay(disp);
}


/* Output */

/*
$g++ -o main *.cpp
/tmp/ccZ2JPGW.o: In function `draw(_XDisplay*, unsigned long)':
main.cpp:(.text+0x26): undefined reference to `XCreateGC'
main.cpp:(.text+0x42): undefined reference to `XSetForeground'
main.cpp:(.text+0x9e): undefined reference to `XDrawPoint'
main.cpp:(.text+0xb7): undefined reference to `XFreeGC'
/tmp/ccZ2JPGW.o: In function `main':
main.cpp:(.text+0xcf): undefined reference to `XOpenDisplay'
main.cpp:(.text+0x152): undefined reference to `XCreateSimpleWindow'
main.cpp:(.text+0x190): undefined reference to `XInternAtom'
main.cpp:(.text+0x1ad): undefined reference to `XSetWMProtocols'
main.cpp:(.text+0x1c5): undefined reference to `XSelectInput'
main.cpp:(.text+0x1d8): undefined reference to `XMapWindow'
main.cpp:(.text+0x1ee): undefined reference to `XNextEvent'
main.cpp:(.text+0x238): undefined reference to `XCloseDisplay'
collect2: error: ld returned 1 exit status
 */ 