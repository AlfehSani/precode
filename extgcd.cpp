#include<bits/stdc++.h>
typedef long long int lll;
using namespace std;
lll gcd (lll a, lll b, lll &x , lll &y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	lll x1, y1;
	lll d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

bool find_any_solution (lll a, lll b, lll c, lll & x0, lll & y0, lll & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}
// for one shift x += b/g,y-=a/g ,total change =a+b/g
void shift_solution (lll & x, lll & y, lll a, lll b, lll cnt) {
	x += cnt * b;
	y -= cnt * a;
}

lll find_all_solutions (lll a, lll b, lll c, lll minx, lll maxx, lll miny, lll maxy) {
	lll x, y, g;
	if (! find_any_solution (a, b, c, x, y, g)) return 0;
	a /= g;  b /= g;
	lll sign_a = a > 0 ? +1 : -1;
	lll sign_b = b > 0 ? +1 : -1;
	shift_solution (x, y, a, b, (minx - x) / b);
	if (x < minx)
		shift_solution (x, y, a, b, sign_b);
	if (x > maxx) return 0;
	lll lx1 = x;
	shift_solution (x, y, a, b, (maxx - x) / b);
	if (x > maxx)
		shift_solution (x, y, a, b, -sign_b);
	lll rx1 = x;
	shift_solution (x, y, a, b, - (miny - y) / a);
	if (y < miny)
        shift_solution (x, y, a, b, -sign_a);
	if (y > maxy) return 0;
	lll lx2 = x;
	shift_solution (x, y, a, b, - (maxy - y) / a);
	if (y > maxy)
		shift_solution (x, y, a, b, sign_a);
	lll rx2 = x;
	if (lx2 > rx2) swap (lx2, rx2);
	lll lx = max (lx1, lx2);
	lll rx = min (rx1, rx2);
	return (rx - lx) / abs(b) + 1;
}
int main()
{
    find_all_solutions(a,b,q,0,p,0,p);
}
